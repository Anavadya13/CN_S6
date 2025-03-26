## **Go-Back-N ARQ Simulation Using TCP**

This code simulates the **Go-Back-N Automatic Repeat Request (ARQ)** protocol, which is used for reliable data transmission in computer networks. 

### ✅ **Overview of Go-Back-N ARQ**  
- **Go-Back-N** is a sliding window protocol.  
- The sender can send multiple packets (up to a defined window size) without waiting for acknowledgments (ACKs).  
- However, if a packet is lost or an acknowledgment is not received within the timeout period, the sender **retransmits all packets** starting from the unacknowledged packet.  
- The receiver acknowledges packets using cumulative acknowledgments (meaning ACK `n` confirms all previous packets up to `n` have been received).  

---

## ✅ **Algorithm Explanation**  

### **1. Initialization**  
- The sender and receiver establish a **TCP connection** using sockets.
- `PORT = 8080` and `BUFFER_SIZE = 1024` are used for communication.
- The sender sets the **window size** to `WINDOW_SIZE = 4`, which is the number of packets sent before waiting for acknowledgments.
- The server has a **30% chance of ACK loss** using `LOSS_PROBABILITY = 30`.

---

### **2. Server Algorithm (Receiver)**  

**Step 1:** Create a TCP Socket  
- The server uses `socket()` to create a socket for communication using TCP (`SOCK_STREAM`).  

**Step 2:** Bind and Listen for Client  
- `bind()` attaches the socket to the specified port.
- `listen()` waits for incoming connection requests from the client.  

**Step 3:** Accept Client Connection  
- `accept()` establishes a connection when a client attempts to connect.  

**Step 4:** Receive Packets from Client  
- The server reads packets using `read()` and simulates a packet acknowledgment using:  
  ```c
  ack = atoi(buffer);
  printf("Server: Received packet %d\n", ack);
  ```

**Step 5:** Simulate ACK Loss  
- The server simulates a 30% ACK loss using:  
  ```c
  if (rand() % 100 < LOSS_PROBABILITY) {
      printf("Server: ACK for packet %d lost!\n\n", ack);
  }
  ```
- If an ACK is not lost, the server sends the acknowledgment using `send()`:  
  ```c
  sprintf(buffer, "%d", ack);
  send(new_socket, buffer, strlen(buffer) + 1, 0);
  ```

---

### **3. Client Algorithm (Sender)**  

**Step 1:** Create a TCP Socket  
- The client creates a socket using `socket()` and connects to the server using `connect()`.

**Step 2:** Configure the Timeout**  
- The client uses `setsockopt()` to set a **3-second timeout** for receiving ACKs:
  ```c
  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
  ```

**Step 3:** Send Packets Using Sliding Window  
- The sender sends packets within the window size using:
  ```c
  while (next_to_send < base + WINDOW_SIZE && next_to_send <= TOTAL_PACKETS) {
      printf("Client: Sending packet %d\n", next_to_send);
      sprintf(buffer, "%d", next_to_send);
      send(sock, buffer, strlen(buffer) + 1, 0);
      next_to_send++;
  }
  ```

**Step 4:** Wait for Acknowledgment  
- The client waits for an acknowledgment using `read()`:
  ```c
  int valread = read(sock, buffer, BUFFER_SIZE);
  ```

**Step 5:** Process Acknowledgment  
- If an ACK is received:  
  ```c
  ack = atoi(buffer);
  printf("Client: ACK received for packet %d\n", ack);
  ```
  - The window slides to the next packet (`base = ack + 1`).
- If a timeout occurs, the client retransmits all packets from the last unacknowledged packet using:  
  ```c
  printf("Client: Timeout! Retransmitting from packet %d...\n", base);
  next_to_send = base;
  ```

---

## ✅ **Summary of the Algorithm**  

### **Server (Receiver)**  
1. Create a TCP socket.  
2. Bind and listen on the specified port.  
3. Accept incoming client connection.  
4. Receive packets from the client.  
5. Simulate acknowledgment with a chance of loss.  
6. Send ACK to the client if no loss occurs.  
7. Repeat until all packets are received.  

### **Client (Sender)**  
1. Create a TCP socket and connect to the server.  
2. Configure the timeout for acknowledgments.  
3. Send packets using the sliding window approach.  
4. Wait for acknowledgment from the server.  
5. On successful ACK, slide the window to the next packet.  
6. On timeout or lost ACK, retransmit packets starting from the base packet.  
7. Repeat until all packets are acknowledged.  

---

## ✅ **Example Walkthrough**  

- **Window Size:** 4  
- **Total Packets:** 10  
- **Loss Probability:** 30%  
- **Timeout:** 3 seconds  

1. Client sends packets **1, 2, 3, 4**.  
2. Server sends ACK for **1, 2** but loses ACK for **3**.  
3. Client waits for ACK. After a timeout, it retransmits packets **3, 4, 5, 6**.  
4. This process continues until all 10 packets are successfully acknowledged.  

---

## ✅ **Final Thoughts**  
- This Go-Back-N simulation accurately demonstrates how packet loss, acknowledgment loss, and timeouts are handled in real-world networks.  
- TCP implementations use similar mechanisms for reliable data transmission using sliding window protocols.  

Let me know if you'd like further modifications or explanations! 😊
