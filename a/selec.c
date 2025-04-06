Selective Repeat ARQ allows the sender to transmit multiple frames using a sliding window.
If a frame is lost or its acknowledgment (ACK) is lost, only that specific frame is retransmitted.
Unlike Go-Back-N ARQ (which retransmits all frames from the point of failure), Selective Repeat retransmits only the frames that failed.
The receiver maintains a buffer for storing out-of-order frames until the correct frame is received.
  1. Initialization
WINDOW_SIZE = 4 → Number of frames the sender can send without waiting for ACKs.
TOTAL_FRAMES = 10 → Total frames to be sent.
LOSS_PROBABILITY = 20 → 20% chance of frame or acknowledgment loss.
Arrays:
sent_frames[] → Tracks which frames are sent.
ack_received[] → Tracks which frames are acknowledged.
base → The first frame in the current sliding window.
  2. Simulation of Frame Transmission
send_frame() simulates the frame transmission using a random probability of loss:
It uses sleep(1) to simulate network delay.
  3. Simulation of Acknowledgment Reception
receive_ack() simulates the reception of acknowledgments with a chance of loss:
If the acknowledgment is lost, the sender will wait and retransmit the frame.
  4. Selective Repeat ARQ Simulation
The main function selective_repeat_arq() follows these steps:
  Send Frames
The sender sends all frames within the sliding window if they haven't been sent:
  Check for Acknowledgments
After sending frames, the sender checks for acknowledgments:
  Slide the Window
If the acknowledgment for the base frame is received, the window is slid forward:
Repeat:
Continue until all frames are sent and acknowledged.

  ************************************************

  1. Initialization
1.1. Initialize sent_frames[TOTAL_FRAMES] to 0 — to track if each frame has been sent.
1.2. Initialize ack_received[TOTAL_FRAMES] to 0 — to track if acknowledgment has been received.
1.3. Set base = 0 — the starting index of the sliding window.
1.4. Seed the random number generator using current time for randomness.

2. Main Transmission Loop (Repeat until all frames are acknowledged)
While base < TOTAL_FRAMES do:

3. Send Unsent Frames within the Window
3.1. For i = base to base + WINDOW_SIZE - 1
   If i < TOTAL_FRAMES and sent_frames[i] == 0:
     Call send_frame(i)
     If successful:
       Set sent_frames[i] = 1
     Else:
       Leave sent_frames[i] = 0 (lost, to resend later)

4. Receive Acknowledgments for Sent Frames
4.1. For i = base to base + WINDOW_SIZE - 1
   If i < TOTAL_FRAMES, sent_frames[i] == 1 and ack_received[i] == 0:
     Call receive_ack(i)
     If acknowledgment is received:
       Set ack_received[i] = 1
     Else:
       Leave ack_received[i] = 0 (ACK lost, will retry later)

5. Slide the Window Forward
5.1. While base < TOTAL_FRAMES and ack_received[base] == 1:
   Print "Sliding window forward. Frame base fully acknowledged."
   Increment base = base + 1

6. Repeat Steps 3 to 5 Until All Frames Are Sent and Acknowledged
7. Completion
7.1. Once base == TOTAL_FRAMES, print:
    “All frames sent and acknowledged successfully.”


