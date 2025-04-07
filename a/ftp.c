ALGORITHM: 
Server : 
S0: Start 
S1: Include Necessary Headers and Declare Variables 
Date: 03/03/25 
● Include <stdio.h>, <stdlib.h>, <string.h>, <unistd.h>, and <arpa/inet.h>. 
● Declare: 
o server_socket – Socket descriptor for the server. 
o client_socket – Socket descriptor for the client. 
o struct sockaddr_in server_addr, client_addr – Structures for storing 
server and client addresses. 
o socklen_t addr_len – Variable to store the size of the client’s address. 
o char buffer[1024] – Buffer to store file data. 
o char filename[1024] – Buffer to store the requested filename. 
S2: Create TCP Socket 
● Call socket(AF_INET, SOCK_STREAM, 0) to create a TCP socket. 
● If the socket creation fails (returns -1), print an error message and exit. 
S3: Set Up Server Address 
● Assign values to server_addr: 
o server_addr.sin_family = AF_INET (Use IPv4). 
o server_addr.sin_addr.s_addr = INADDR_ANY (Bind to all available 
interfaces). 
o server_addr.sin_port = htons(8080) (Convert port number to network 
byte order). 
S4: Bind the Socket to the Server Address 
● Call bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) 
to bind the socket to the specified address and port. 
● If binding fails, print an error message and exit. 
S5: Start Listening for Connections 
● Call listen(server_socket, 3) to listen for incoming client connections.
  If listening fails, print an error message and exit. 
● Print "Server is listening on port 8080". 
S6: Accept Client Connection in a Loop 
● Start an infinite loop: 
o Call accept(server_socket, (struct sockaddr *)&client_addr, &addr_len). 
o If accept fails, print an error message and exit. 
o Print "Client connected". 
S7: Handle Client Request 
● Call recv(client_socket, filename, BUFFER_SIZE, 0) to receive the requested 
filename from the client. 
● If recv fails, print "Error receiving filename" and close the socket. 
S8: Open Requested File 
● Call fopen(filename, "r") to open the requested file. 
● If the file does not exist: 
o Send "File not found" to the client. 
o Print "File not found" and close the client socket. 
● If the file exists: 
o Read file content using fgets in a loop. 
o Send file content to the client using send(client_socket, buffer, 
strlen(buffer), 0). 
o Clear the buffer after each iteration using memset(buffer, 0, 
BUFFER_SIZE). 
o Print "File sent to client". 
S9: Close File and Client Socket 
● Close the file using fclose(file). 
● Close the client socket using close(client_socket). 
● Go back to Step S6 to accept the next client. 
S10: Close Server Socket (After Loop Ends) 
● Close the server socket using close(server_socket). 
● End. 
Client: 
S0: Start 
S1: Include Necessary Headers and Declare Variables 
● Include <stdio.h>, <stdlib.h>, <string.h>, <unistd.h>, and <arpa/inet.h>. 
● Declare: 
o client_socket – Socket descriptor for the client. 
o struct sockaddr_in server_addr – Structure for storing server address. 
o char buffer[1024] – Buffer to store received data. 
o char filename[1024] – Buffer to store the filename.
  S2: Create TCP Socket 
● Call socket(AF_INET, SOCK_STREAM, 0) to create a TCP socket. 
● If the socket creation fails (returns -1), print an error message and exit. 
S3: Set Up Server Address 
● Assign values to server_addr: 
o server_addr.sin_family = AF_INET (Use IPv4). 
o server_addr.sin_port = htons(8080) (Convert port number to network 
byte order). 
o server_addr.sin_addr.s_addr = inet_addr("127.0.0.1") (Set server IP to 
localhost). 
S4: Connect to the Server 
● Call connect(client_socket, (struct sockaddr *)&server_addr, 
sizeof(server_addr)). 
● If connection fails, print "Connection failed" and exit. 
S5: Get Filename from User 
● Print "Enter the filename to request: ". 
● Read the filename using scanf("%s", filename). 
S6: Send Filename to Server 
● Call send(client_socket, filename, strlen(filename), 0) to send the filename to 
the server. 
S7: Receive and Display File Content 
● Print "File content received:". 
● Start a loop: 
o Call recv(client_socket, buffer, BUFFER_SIZE, 0). 
o If data is received, print the buffer. 
o Clear the buffer using memset(buffer, 0, BUFFER_SIZE). 
● When no more data is received, exit the loop. 
S8: Close Client Socket and End 
● Close the client socket using close(client_socket). 
● End. 
If the socket creation fails (returns -1), handle the error. 
