import socket
import time
import random

# Configuring the client
def selective_repeat_sender():
    sender_window_size = 4  # Sliding window size
    total_packets = 10
    timeout = 2  # Timeout in seconds
    packets = [f"Packet {i}" for i in range(total_packets)]
    base = 0
    next_sequence_number = 0
    acks_received = [False] * total_packets
    timers = [None] * total_packets
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 9999)

    def send_packet(seq_num):
        message = f"{seq_num} {packets[seq_num]}"
        client_socket.sendto(message.encode(), server_address)
        timers[seq_num] = time.time()

    def resend_packet(seq_num):
        if not acks_received[seq_num]:
            print(f"Timeout for packet {seq_num}. Resending...")
            send_packet(seq_num)

    while base < total_packets:
        while next_sequence_number < base + sender_window_size and next_sequence_number < total_packets:
            send_packet(next_sequence_number)
            next_sequence_number += 1

        try:
            client_socket.settimeout(timeout)
            ack_message, _ = client_socket.recvfrom(1024)
            ack_num = int(ack_message.decode().split()[1])
            print(f"Received ACK for packet {ack_num}")
            acks_received[ack_num] = True
            while base < total_packets and acks_received[base]:
                base += 1
        except socket.timeout:
            print("Timeout occurred. Resending unacknowledged packets...")
            for i in range(base, next_sequence_number):
                if time.time() - timers[i] > timeout:
                    resend_packet(i)

if __name__ == "__main__":
    selective_repeat_sender()
