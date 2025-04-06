Step 1: Input and Initialization
  Variables are declared to store:
    bucket_capacity: Maximum capacity of the bucket.
    leak_rate: The rate at which packets leak (transmit) from the bucket.
    num_packets: Total number of packets arriving in the network.
  Prompt and Input:
    The user is asked to input values for the bucket capacity, leak rate, and number of packets.
    scanf() stores these values.
  Array Declaration:
  An integer array packets[] of size num_packets is declared to store the size of each incoming packet.
  Packet Input:
  The user enters the size of each packet.
  The sizes are stored in the packets[] array using a for loop.
Step 2: Leaky Bucket Simulation
  Function Declaration and Initialization:
leakyBucket() is a function to simulate the leaky bucket algorithm.
The variable bucket is initialized to 0, representing the empty bucket at the start.
  Output Header:
Displays column names for clarity during the simulation.
Columns:
Time: The current time step.
Incoming: The number of packets arriving.
Bucket: The packets in the bucket.
Leaked: The number of packets leaked (transmitted).
Remaining: Packets left in the bucket.
Step 3: Processing Each Packet
Simulation Loop:
The loop runs for every packet using i as the time step (i+1 for display).
Prints the current time step and packet size using printf().
  Add Incoming Packets:
The packet size from packets[i] is added to the current bucket size.
Step 4: Check for Overflow
Overflow Handling:
If the bucket exceeds its capacity, the overflow is detected using bucket > bucket_capacity.
The extra packets are discarded (dropped).
The bucket is set to its maximum capacity using bucket = bucket_capacity.
It prints a message showing the bucket is full and how many packets were dropped.
  No Overflow:
If no overflow occurs, it simply prints the current bucket size.
Step 5: Leak Packets
  Leak Process:
The number of packets leaked (transmitted) is calculated using a conditional (ternary) operator:
If the bucket contains more packets than the leak_rate, it leaks at the leak rate.
Otherwise, it leaks all remaining packets (if fewer than the leak rate).
The bucket size is then reduced by the leaked packets using bucket -= leaked.
Display Results:
It prints the number of packets leaked and the remaining packets in the bucket.
Step 6: Empty the Bucket After Processing
Draining the Bucket:
After all packets are processed, the bucket may still contain packets.
A while loop runs until the bucket becomes empty (bucket > 0).
At each step:
Packets leak using the same logic as before.
The state of the bucket is printed with 0 for the Incoming packets (since no new packets are arriving).
Time is incremented for each leak step.
Step 7: Final Output and End of Program
Program Completion:
The function ends, and the program terminates successfully.
........................
  1. Initialize variables: bsize, n, out, bucket as integers.
 2. Read and store the bucket size (bsize) from the user.
 3. Read and store the number of inputs (n) from the user.
 4. Read and store the packet outgoing rate (out) from the user.
 5. Read and store the incoming packet size (in) from the user.
 6. If in is less than or equal to the available space in the bucket (bsize - bucket), then:
 1. Add the incoming packet size (in) to the bucket (bucket += in).
 7. If in is greater than the available space in the bucket (bsize - bucket), then:
 1. Calculate the number of dropped packets (in - (bsize - bucket)).
 2. 7.2-Set the bucket size (bucket) to its maximum capacity (bsize).
 3. Print the number of dropped packets.
 8. Print the bucket status (bucket packets out of bsize).
 9. Subtract the packet outgoing rate (out) from the bucket size (bucket).
 10. Print the bucket status after outgoing packets (bucket packets out of bsize).
 11. Decrement the value of n by 1.
 12. Repeat steps 5 to 11 until n becomes zero




