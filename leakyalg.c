Let's go through the code step by step as an **algorithm** with a detailed explanation for each line.

---

## **Algorithm for Leaky Bucket Congestion Control**

### **Step 1: Input and Initialization**

- **Variables** are declared to store:
  - `bucket_capacity`: Maximum capacity of the bucket.
  - `leak_rate`: The rate at which packets leak (transmit) from the bucket.
  - `num_packets`: Total number of packets arriving in the network.

- **Prompt and Input:**  
  - The user is asked to input values for the bucket capacity, leak rate, and number of packets.
  - `scanf()` stores these values.

- **Array Declaration:**  
  - An integer array `packets[]` of size `num_packets` is declared to store the size of each incoming packet.

- **Packet Input:**  
  - The user enters the size of each packet.
  - The sizes are stored in the `packets[]` array using a `for` loop.

## **Step 2: Leaky Bucket Simulation**

- **Function Declaration and Initialization:**  
  - `leakyBucket()` is a function to simulate the leaky bucket algorithm.
  - The variable `bucket` is initialized to **0**, representing the empty bucket at the start.

- **Output Header:**  
  - Displays column names for clarity during the simulation.  
  - Columns:
    - **Time:** The current time step.
    - **Incoming:** The number of packets arriving.
    - **Bucket:** The packets in the bucket.
    - **Leaked:** The number of packets leaked (transmitted).
    - **Remaining:** Packets left in the bucket.

---

### **Step 3: Processing Each Packet**

- **Simulation Loop:**  
  - The loop runs for every packet using `i` as the time step (`i+1` for display).
  - Prints the current time step and packet size using `printf()`.

- **Add Incoming Packets:**  
  - The packet size from `packets[i]` is added to the current `bucket` size.

### **Step 4: Check for Overflow**

- **Overflow Handling:**  
  - If the bucket exceeds its capacity, the overflow is detected using `bucket > bucket_capacity`.
  - The extra packets are discarded (dropped).
  - The bucket is set to its maximum capacity using `bucket = bucket_capacity`.
  - It prints a message showing the bucket is full and how many packets were dropped.

- **No Overflow:**  
  - If no overflow occurs, it simply prints the current bucket size.

### **Step 5: Leak Packets**

- **Leak Process:**  
  - The number of packets leaked (transmitted) is calculated using a conditional (ternary) operator:
  - If the `bucket` contains more packets than the `leak_rate`, it leaks at the leak rate.
  - Otherwise, it leaks all remaining packets (if fewer than the leak rate).
  - The bucket size is then reduced by the leaked packets using `bucket -= leaked`.

- **Display Results:**  
  - It prints the number of packets leaked and the remaining packets in the bucket.


## **Step 6: Empty the Bucket After Processing**

- **Draining the Bucket:**  
  - After all packets are processed, the bucket may still contain packets.
  - A `while` loop runs until the bucket becomes empty (`bucket > 0`).
  - At each step:
    - Packets leak using the same logic as before.
    - The state of the bucket is printed with `0` for the **Incoming** packets (since no new packets are arriving).
    - Time is incremented for each leak step.

## **Step 7: Final Output and End of Program**

- **Program Completion:**  
  - The function ends, and the program terminates successfully.

---

---

## **Summary of the Algorithm in Simple Steps**
1. Initialize the bucket, leak rate, and packet information.
2. For each time step:
    - Add incoming packets to the bucket.
    - Check for overflow and discard excess packets if needed.
    - Leak packets at a constant rate.
    - Print the current state of the bucket.
3. After processing all packets:
    - Continue leaking until the bucket becomes empty.
4. End the simulation.
