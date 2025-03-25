## **Algorithm for Concurrent Time Server and Client Using UDP**  

This project consists of a simple **UDP (User Datagram Protocol)** based client-server system where:  
- **Server** listens for requests from the client and responds with the current system time.  
- **Client** sends a time request to the server and receives the server's response displaying the current time.  

UDP is a **connectionless protocol** that is used for faster data transmission without maintaining a connection between the client and the server.  

---

## ✅ **Algorithm Explanation**

### **Part 1: Server Algorithm**
The server follows these steps:

1. **Create a UDP Socket**  
    - A socket is created using the `socket()` function.  
    - `AF_INET` specifies IPv4, and `SOCK_DGRAM` specifies UDP (Datagram Socket).  
    ```c
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    ```

2. **Initialize and Configure Server Address**  
    - The server uses the `INADDR_ANY` to accept requests from any available network interface.  
    - `htons(PORT)` ensures the port number is in the correct network byte order.  
    ```c
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    ```

3. **Bind the Socket**  
    - The `bind()` function attaches the socket to the specified port and IP address.  
    ```c
    bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    ```

4. **Wait for Client Requests**  
    - The server continuously waits for incoming requests using `recvfrom()`.  
    - UDP being connectionless means the server does not establish a direct connection with the client.  
    ```c
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
    ```

5. **Process the Request**  
    - After receiving a request, the server logs the client’s IP address using `inet_ntoa()`.  
    ```c
    printf("Received request from client: %s\n", inet_ntoa(client_addr.sin_addr));
    ```

6. **Fetch Current Time**  
    - The server uses `time()` to get the current system time and `ctime()` to format it as a readable string.  
    ```c
    time_t current_time = time(NULL);
    char *time_str = ctime(&current_time);
    ```

7. **Send the Time to Client**  
    - The server sends the formatted time back to the client using `sendto()`.  
    ```c
    sendto(sockfd, time_str, strlen(time_str), 0, (struct sockaddr *)&client_addr, addr_len);
    ```

8. **Continue the Process**  
    - The server remains in an infinite loop to listen for further requests.

---

### **Part 2: Client Algorithm**
The client follows these steps:

1. **Create a UDP Socket**  
    - Similar to the server, the client creates a socket using `socket()`.  
    ```c
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    ```

2. **Configure Server Address**  
    - The client specifies the server’s IP address (localhost in this case) and the port number using `inet_addr()`.  
    ```c
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ```

3. **Send Time Request**  
    - The client sends a simple text message `"TIME_REQUEST"` to the server using `sendto()`.  
    ```c
    sendto(sockfd, request_message, strlen(request_message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    ```

4. **Receive the Response**  
    - After sending the request, the client waits for the server’s response using `recvfrom()`.  
    ```c
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    ```

5. **Display the Time**  
    - The received time (sent by the server) is printed using `printf()`.  
    ```c
    printf("Current time from server: %s\n", buffer);
    ```

6. **Close the Socket**  
    - After receiving the time, the client closes the socket using `close()`.  
    ```c
    close(sockfd);
    ```

---

## ✅ **Summary of the Algorithm**  

### **Server Algorithm**  
1. Create a UDP socket using `socket()`.  
2. Configure the server’s IP address and port number.  
3. Bind the socket using `bind()`.  
4. Wait for incoming requests using `recvfrom()`.  
5. Process the client request.  
6. Fetch and format the current system time using `time()` and `ctime()`.  
7. Send the formatted time back to the client using `sendto()`.  
8. Repeat for further requests.  

### **Client Algorithm**  
1. Create a UDP socket using `socket()`.  
2. Configure the server's IP address and port number.  
3. Send a time request to the server using `sendto()`.  
4. Wait for the server’s response using `recvfrom()`.  
5. Display the received time.  
6. Close the socket using `close()`.  

---

## ✅ **Additional Notes**  
- **Concurrency**: Since UDP is connectionless, the server can handle multiple clients at the same time without maintaining a connection state.  
- **Reliability**: UDP does not guarantee delivery of packets. If guaranteed delivery is required, TCP should be used instead.  
- **Time Synchronization**: This simple implementation is useful for basic time synchronization, but for more precise applications, protocols like **NTP (Network Time Protocol)** are used.

Let me know if you'd like further clarifications or examples!
