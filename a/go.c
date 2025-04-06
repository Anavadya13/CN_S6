The sender can send multiple packets defined by the window size without waiting for ACKs.
If an ACK is lost or a packet is not acknowledged, the sender retransmits from the last unacknowledged packet (it "goes back" and re-sends from that point).
  Defines:
TOTAL_PACKETS: the total number of packets to send.
WINDOW_SIZE: how many packets can be sent without waiting for ACKs (sliding window size).
Simulates a random acknowledgment (ACK) reception:
70% chance to return true (ACK received).
30% chance to return false (ACK lost).
srand(time(0)) seeds the random number generator for different results each run.
  
base → The first packet in the current window (the lowest unacknowledged packet).
next_seq_num → The next packet number to be sent.

  1. Sending Packets Within the Window
Sends packets from base to base + WINDOW_SIZE - 1.
Packets are sent optimistically (without waiting for ACKs).
Keeps sending until the window is full or total packets are sent.
Waits 1 second to simulate delay.
Iterates through sent packets in the current window, expecting ACKs.
  2. Waiting for ACKs
The sender now checks for ACKs of sent packets.
If ACK is received: continue.
If any ACK is lost, Go-Back-N kicks in:
The sender "goes back" to that packet.
Print a message.
Set next_seq_num to that lost packet (simulate retransmission from there).
Break the loop (stop waiting for other ACKs).
  3. Sliding the Window
Update base to next_seq_num, i.e., slide the window.
Sleep before starting the next window send cycle.
Once acknowledgments are received or retransmissions scheduled, the window's base moves up to the next unacknowledged packet.
Completion message once all packets are acknowledged.

  ************************************************
  Input:

TOTAL_PACKETS: Total number of packets to send.

WINDOW_SIZE: Maximum packets that can be sent without waiting for ACKs.

Steps:

Initialize base = 1, next_seq_num = 1.

While base ≤ TOTAL_PACKETS:

Print window sending info.

While next_seq_num < base + WINDOW_SIZE and next_seq_num ≤ TOTAL_PACKETS:

"Send" packet next_seq_num.

Increment next_seq_num.

Wait for a short time (sleep(1)).

For each packet in current window [base, next_seq_num - 1]:

Simulate ACK:

If ACK received: print success.

If ACK lost:

Print failure.

Set next_seq_num = i (packet lost).

Break (stop checking further ACKs).

Set base = next_seq_num (slide window).

Wait (sleep(1)).

Print completion message.
