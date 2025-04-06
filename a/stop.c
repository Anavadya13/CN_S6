Stop-and-Wait ARQ is a simple error control mechanism.
The sender sends one packet at a time and waits for an acknowledgment (ACK) from the receiver.
If the acknowledgment is received within a specified timeout period, the sender proceeds to send the next packet.
If no acknowledgment is received (ACK lost or corrupted), the sender retransmits the same packet after the timeout.
  Step 1: Initialize Variables
Start by seeding the random number generator using srand(time(0)).
Define variables:
packet = 1 → Tracks the current packet number.
ack_received → Simulates whether an acknowledgment is received.
Constants are defined for:
TIMEOUT = 3 → The time duration the sender waits for an acknowledgment.
TOTAL_PACKETS = 5 → Total number of packets to be sent.
  Step 2: Send Packet
The sender transmits the current packet using:
printf("Sender: Sending packet %d...\n", packet);
The sleep(1) function simulates the time it takes for the packet to reach the receiver.
  Step 3: Simulate Acknowledgment (ACK)
The function simulate_acknowledgment() is called to simulate a 70% chance of receiving a successful acknowledgment using:
return rand() % 10 < 7;
rand() % 10 generates a random number between 0 and 9.
If the number is less than 7, it simulates a successful acknowledgment (70% success rate).
If the number is 7, 8, or 9, it simulates an acknowledgment loss (30% failure rate).
  Step 4: Check Acknowledgment
  If an acknowledgment is received: 
The sender moves to the next packet by incrementing the packet variable.
 If an acknowledgment is lost or corrupted:
The sender waits for 3 seconds (timeout) before retransmitting the same packet.
  Step 5: Repeat Until All Packets Are Sent
Using while loop the sender keeps sending and retransmitting until all packets (up to TOTAL_PACKETS) are successfully acknowledged.
  Step 6: Display Completion Message
Once all packets are acknowledged, the sender prints:
All packets sent successfully!
The simulation ends.
