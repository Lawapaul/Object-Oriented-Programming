import socket

def selective_repeat_receiver():
    receiver_window_size = 4  # Sliding window size
    expected_sequence_number = 0
    buffer = {}
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 9999))
    print("Server ready, waiting for packets...")

    while True:
        message, client_address = server_socket.recvfrom(1024)
        seq_num = int(message.decode().split()[0])
        packet_data = message.decode().split()[1]

        if seq_num == expected_sequence_number:
            print(f"Received packet {seq_num} with data: {packet_data}")
            expected_sequence_number += 1
            # Acknowledge the correct packet
            ack_message = f"ACK {seq_num}"
            server_socket.sendto(ack_message.encode(), client_address)

            # Deliver in-order packets from buffer
            while expected_sequence_number in buffer:
                print(f"Delivered buffered packet {expected_sequence_number}")
                del buffer[expected_sequence_number]
                expected_sequence_number += 1

        elif expected_sequence_number <= seq_num < expected_sequence_number + receiver_window_size:
            print(f"Out of order packet {seq_num}, buffering...")
            buffer[seq_num] = packet_data
            # Acknowledge out-of-order packet
            ack_message = f"ACK {seq_num}"
            server_socket.sendto(ack_message.encode(), client_address)
        else:
            print(f"Packet {seq_num} ignored.")
            continue

if __name__ == "__main__":
    selective_repeat_receiver()
