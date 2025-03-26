
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // for sleep()

#define TIMEOUT 3  // Timeout duration in seconds
#define TOTAL_PACKETS 5  // Number of packets to send

int simulate_acknowledgment() {
    // Simulate a 70% chance of successful acknowledgment
    return rand() % 10 < 7;
}

int main() {
    srand(time(0));  // Seed for random number generation

    int packet = 1;
    int ack_received;

    while (packet <= TOTAL_PACKETS) {
        printf("Sender: Sending packet %d...\n", packet);

        // Simulate waiting for acknowledgment
        sleep(1);  // Simulate transmission delay
        ack_received = simulate_acknowledgment();

        if (ack_received) {
            printf("Receiver: ACK for packet %d received.\n\n", packet);
            packet++;  // Move to the next packet
        } else {
            printf("Receiver: ACK for packet %d lost! Retransmitting...\n\n", packet);
            sleep(TIMEOUT);  // Simulate timeout before retransmission
        }
    }


    Client Code (Sender)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define TIMEOUT 3  // Timeout in seconds

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char packet[50];
    struct timeval tv;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Client: Connected to server.\n");

    // Set socket timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    int packet_number = 1;
    while (packet_number <= 5) {
        sprintf(packet, "%d", packet_number);
        printf("Client: Sending packet %d...\n", packet_number);
        send(sock, packet, strlen(packet), 0);

        // Wait for ACK
        int valread = read(sock, buffer, BUFFER_SIZE);

        if (valread > 0 && strcmp(buffer, "ACK") == 0) {
            printf("Client: ACK received for packet %d\n\n", packet_number);
            packet_number++;
        } else {
            printf("Client: Timeout! Retransmitting packet %d...\n\n", packet_number);
        }

        memset(buffer, 0, BUFFER_SIZE);  // Clear buffer
    }

    printf("Client: All packets sent successfully.\n");
    close(sock);
    return 0;
}

    printf("All packets sent successfully!\n");
    return 0;
}
