## **Algorithm for Stop-and-Wait ARQ Simulation**  

This program simulates the **Stop-and-Wait Automatic Repeat Request (ARQ)** protocol, which is a reliable data transfer protocol used in computer networks. It ensures the correct delivery of packets using acknowledgments (ACKs) and retransmissions.

---

## ✅ **Stop-and-Wait ARQ Overview**  

- **Stop-and-Wait ARQ** is a simple error control mechanism.  
- The sender sends **one packet** at a time and waits for an acknowledgment (**ACK**) from the receiver.  
- If the acknowledgment is received within a specified **timeout** period, the sender proceeds to send the next packet.  
- If no acknowledgment is received (ACK lost or corrupted), the sender **retransmits** the same packet after the timeout.

---

## ✅ **Algorithm Explanation**  

### **Step 1: Initialize Variables**
- Start by seeding the random number generator using `srand(time(0))`.  
- Define variables:
  - `packet = 1` → Tracks the current packet number.
  - `ack_received` → Simulates whether an acknowledgment is received.  
- Constants are defined for:
  - `TIMEOUT = 3` → The time duration the sender waits for an acknowledgment.
  - `TOTAL_PACKETS = 5` → Total number of packets to be sent.

---

### **Step 2: Send Packet**
- The sender transmits the current packet using:
  ```c
  printf("Sender: Sending packet %d...\n", packet);
  ```
- The `sleep(1)` function simulates the time it takes for the packet to reach the receiver.

---

### **Step 3: Simulate Acknowledgment (ACK)**  
- The function `simulate_acknowledgment()` is called to simulate a 70% chance of receiving a successful acknowledgment using:
  ```c
  return rand() % 10 < 7;  
  ```
  - `rand() % 10` generates a random number between **0** and **9**.
  - If the number is **less than 7**, it simulates a successful acknowledgment (70% success rate).
  - If the number is **7, 8, or 9**, it simulates an acknowledgment loss (30% failure rate).

---

### **Step 4: Check Acknowledgment**
- If an acknowledgment is received:  
  ```c
  if (ack_received) {
      printf("Receiver: ACK for packet %d received.\n\n", packet);
      packet++;  // Move to the next packet
  }
  ```
  - The sender moves to the next packet by incrementing the `packet` variable.

- If an acknowledgment is lost or corrupted:  
  ```c
  else {
      printf("Receiver: ACK for packet %d lost! Retransmitting...\n\n", packet);
      sleep(TIMEOUT);  // Simulate timeout before retransmission
  }
  ```
  - The sender waits for **3 seconds** (timeout) before retransmitting the same packet.

---

### **Step 5: Repeat Until All Packets Are Sent**
- The loop continues using:
  ```c
  while (packet <= TOTAL_PACKETS)
  ```
  - The sender keeps sending and retransmitting until all packets (up to `TOTAL_PACKETS`) are successfully acknowledged.

---

### **Step 6: Display Completion Message**
- Once all packets are acknowledged, the sender prints:
  ```c
  printf("All packets sent successfully!\n");
  ```
  - The simulation ends.

---

## ✅ **Summary of the Algorithm**  

1. **Initialization**:  
    - Set packet number to 1.  
    - Define timeout and total number of packets.  
2. **Send Packet**:  
    - Print a message indicating the packet is sent.  
    - Simulate acknowledgment using a random function.  
3. **Check Acknowledgment**:  
    - If ACK is received, move to the next packet.  
    - If ACK is lost, wait for the timeout period and retransmit the packet.  
4. **Repeat** until all packets are successfully sent and acknowledged.  
5. **End** the program with a success message.  

---

Let me know if you'd like further explanations or test scenarios! 😊
