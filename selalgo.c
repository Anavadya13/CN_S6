## **Selective Repeat ARQ Simulation in C**

This code simulates the **Selective Repeat Automatic Repeat Request (ARQ)** protocol, which is a reliable data transmission protocol used in computer networks.

---

## ✅ **Overview of Selective Repeat ARQ**  

- **Selective Repeat ARQ** allows the sender to transmit multiple frames using a **sliding window**.
- If a frame is **lost** or its acknowledgment (**ACK**) is lost, only that specific frame is **retransmitted**.
- Unlike **Go-Back-N ARQ** (which retransmits all frames from the point of failure), **Selective Repeat** retransmits only the frames that failed.
- The receiver maintains a buffer for storing out-of-order frames until the correct frame is received.

---

## ✅ **Algorithm Explanation**  

### **1. Initialization**  
- `WINDOW_SIZE = 4` → Number of frames the sender can send without waiting for ACKs.  
- `TOTAL_FRAMES = 10` → Total frames to be sent.  
- `LOSS_PROBABILITY = 20` → 20% chance of frame or acknowledgment loss.  
- Arrays:
  - `sent_frames[]` → Tracks which frames are sent.
  - `ack_received[]` → Tracks which frames are acknowledged.  
- `base` → The first frame in the current sliding window.

---

### **2. Simulation of Frame Transmission**  
- `send_frame()` simulates the frame transmission using a **random probability** of loss:
  ```c
  int rand_value = rand() % 100;
  if (rand_value < LOSS_PROBABILITY) {
      printf("Frame %d lost during transmission!\n", frame_number);
      return 0; // Frame lost
  }
  printf("Frame %d sent successfully.\n", frame_number);
  return 1; // Frame sent successfully
  ```
- It uses `sleep(1)` to simulate network delay.

---

### **3. Simulation of Acknowledgment Reception**  
- `receive_ack()` simulates the reception of acknowledgments with a chance of loss:
  ```c
  int rand_value = rand() % 100;
  if (rand_value < LOSS_PROBABILITY) {
      printf("Acknowledgment for frame %d lost!\n", frame_number);
      return 0; // ACK lost
  }
  printf("Acknowledgment for frame %d received.\n", frame_number);
  return 1; // ACK received
  ```
- If the acknowledgment is lost, the sender will wait and retransmit the frame.

---

### **4. Selective Repeat ARQ Simulation**  
The main function `selective_repeat_arq()` follows these steps:  

1. **Send Frames**  
    - The sender sends all frames within the sliding window if they haven't been sent:  
    ```c
    if (!sent_frames[i]) {
        sent_frames[i] = send_frame(i);
    }
    ```
2. **Check for Acknowledgments**  
    - After sending frames, the sender checks for acknowledgments:  
    ```c
    if (sent_frames[i] && !ack_received[i]) {
        ack_received[i] = receive_ack(i);
    }
    ```
3. **Slide the Window**  
    - If the acknowledgment for the base frame is received, the window is slid forward:  
    ```c
    while (base < TOTAL_FRAMES && ack_received[base]) {
        printf("Sliding window forward. Frame %d fully acknowledged.\n", base);
        base++;
    }
    ```

---

## ✅ **Example Walkthrough**  

- **Window Size:** 4  
- **Total Frames:** 10  
- **Loss Probability:** 20%  
- Initial state:  
  ```
  Frames: 0 1 2 3 | 4 5 6 7 8 9
  Window: [0 1 2 3]
  ```
1. **Send Frames 0 to 3.**  
2. **Receive Acknowledgments.**  
    - Frame 1 is acknowledged.  
    - Frame 2 is lost.  
3. **Slide Window if Possible.**  
    - Frame 0 and 1 are acknowledged, so the window slides to:  
    ```
    Window: [2 3 4 5]
    ```
4. **Retransmit Frame 2.**  
5. **Repeat Until All Frames Are Acknowledged.**

---

## ✅ **Final Summary of Algorithm**  

1. **Initialization:**  
    - Set `WINDOW_SIZE`, `TOTAL_FRAMES`, and `LOSS_PROBABILITY`.  
2. **Send Frames:**  
    - Transmit frames within the sliding window.  
3. **Check Acknowledgments:**  
    - Simulate acknowledgment reception with the possibility of loss.  
4. **Retransmit Lost Frames:**  
    - Resend frames if acknowledgments are lost.  
5. **Slide the Window:**  
    - If the base frame is acknowledged, move the window forward.  
6. **Repeat:**  
    - Continue until all frames are sent and acknowledged.  

---

Would you like further clarification on any specific part or a step-by-step test case simulation? 😊
