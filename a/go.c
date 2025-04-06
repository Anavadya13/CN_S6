The sender can send multiple packets defined by the window size without waiting for ACKs.
If an ACK is lost or a packet is not acknowledged, the sender retransmits from the last unacknowledged packet (it "goes back" and re-sends from that point).
  Variables:
base → The first packet in the current window (the lowest unacknowledged packet).
next_seq_num → The next packet number to be sent.
simulate_acknowledgment() → Simulates ACK success or loss with a 70% chance of success (rand() % 10 < 7).
  1. Sending Packets Within the Window
Sends packets from base to base + WINDOW_SIZE - 1.
Packets are sent optimistically (without waiting for ACKs).
  2. Waiting for ACKs
The sender now checks for ACKs of sent packets.
If an ACK is received, it continues.
If any ACK is lost, Go-Back-N kicks in:
The sender "goes back" to that packet.
next_seq_num is reset, and all following packets are retransmitted.
  3. Sliding the Window
Once acknowledgments are received or retransmissions scheduled, the window's base moves up to the next unacknowledged packet.
