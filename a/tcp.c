Create a socket.  Set the server info. Attach the socket to your address and port . Start listening. Accept the (connection request). Receive the client’s message.Send a reply back. exit
Create the client socket. Set server address. 127.0.0.1 is localhost.Make a call to the server..Send your message ("Hello Server"). Listen for a response.Print what the server replied.. exit
  
  ********************************
1. Start the server program. 
2. Include necessary libraries such as <stdio.h>, <string.h>, <stdlib.h>, <unistd.h>, and 
<arpa/inet.h>. 
3. Create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`. This sets up an 
endpoint for communication. 
4. Configure the server address structure: 
- Set the address family to `AF_INET` (IPv4). 
- Set the IP address to `INADDR_ANY` (bind to any local address). 
- Set the port number using `htons(8080)`. 
5. Bind the socket to the server address using `bind()`. This associates the socket with 
the specified port. 
6. Set up the server to listen for incoming connections using `listen()`. This prepares 
the server to accept clients. 
  Call listen(sockfd, 5) to allow incoming connections
  The number 5 is the backlog — max pending connections allowed
7. Accept a client connection using `accept()`, which waits for a client to connect. 
  This returns a new socket newsock for communication with the client
8. Receive data from the client using `recv()` and store it in a buffer. 
  Use read(newsock, buffer, sizeof(buffer)) to receive the client's message
9. Process the received message (print it or perform operations). 
10. Send a response back to the client using `send()`. 
  Call send(newsock, "Hello from server", 17, 0) to send a message back
11. Close the client socket and the server socket. 
  Close both the connected client socket newsock and the listening socket sockfd

1. Start the client program. 
2. Include necessary libraries such as <stdio.h>, <string.h>, <stdlib.h>, <unistd.h>, and 
<arpa/inet.h>. 
3. Create a TCP socket using `socket(AF_INET, SOCK_STREAM, 0)`.
4. Configure the server address structure: 
- Set the address family to `AF_INET` (IPv4). 
- Set the IP address of the server (e.g., "127.0.0.1"). 
- Set the port number using `htons(8080)`. 
5. Establish a connection to the server using `connect()`. This initiates communication. 
  Call connect(sockfd, (struct sockaddr *)&server, sizeof(server)) to initiate the connection
6. Send data to the server using `send()`. 
  Use send(sockfd, buffer, strlen(buffer), 0) to send the message "Hello Server"
7. Wait for a response from the server using `recv()` and store the received data. 
  Use read(sockfd, buffer, sizeof(buffer)) to receive reply
8. Print the server’s response using printf("Response: %s\n", buffer)
9. Close the client socket with close(sockfd). 
10. Stop the client program.
