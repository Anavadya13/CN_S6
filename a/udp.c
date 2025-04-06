Server : 
S0: Start 
S1: Include Necessary Headers and declare variables: 
sockfd – Socket descriptor for the server,  
struct sockaddr_in server, client – Structures for storing server and client 
addresses,  
char buffer[1024] – Buffer to store received data, 
socklen_t len – Variable to store the size of the client’s address. 
S2: Create UDP Socket: 
Call socket(AF_INET, SOCK_DGRAM, 0) to create a UDP socket. 
If the socket creation fails (returns -1), handle the error. 
S3: Set Up Server Address: 
Set the server’s address: 
server.sin_family = AF_INET, 
server.sin_addr.s_addr = INADDR_ANY, 
server.sin_port = htons(8080). 
S4: Bind the Socket to the Server Address: 
Call bind(sockfd, (struct sockaddr *)&server, sizeof(server)); to bind the socket 
to the specified address and port. 
If binding fails (returns -1), handle the error. 
S5: Wait for Data from Client: 
Print "Waiting for data..." to indicate that the server is ready. 
Call recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &len);  
to wait for a message from the client and store the data in buffer. 
S6: Display the Message: 
Print the received message using printf("Message from client: %s\n", buffer);.
S7: Respond to Client: 
Call sendto(sockfd, "Hello from server", 17, 0, (struct sockaddr *)&client, len); 
to send a response message to the client. 
S8: Close the socket using close(sockfd) after communication is finished. 
S9: Stop 
  ***************************
Client : 
S1: Include Necessary Headers and Declare Variables  
sockfd – Client socket descriptor. 
struct sockaddr_in server – Structure for storing server address. 
char buffer[1024] = "Hello from client"; – Message to send to the server. 
char response[1024]; – Buffer to store the server’s response. 
socklen_t len – Variable to store the size of the server’s address. 
S2: Create UDP Socket: 
Call socket(AF_INET, SOCK_DGRAM, 0) to create a UDP socket. 
If the socket creation fails (returns -1), handle the error. 
S3: Set Up Server Address: 
server.sin_family = AF_INET, 
server.sin_port = htons(8080), 
server.sin_addr.s_addr = inet_addr("127.0.0.1"). 
S4: Send Data to Server: 
Call sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server, len); to 
send the message to the server. 
Print "Message sent to server" to indicate the message has been sent. 
S5: Receive Response from Server: 
Call recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr 
*)&server, &len); to wait for the server’s response and store it in response. 
Print the server's response using printf("Message from server: %s\n", 
response);.  
S6: Close the Socket using close(sockfd) after communication is finished. 
S7: Stop
