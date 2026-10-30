import socket

# Function to simulate Go-Back-N ARQ server
def go_back_n_server():
    # Create a UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # Allow port reuse
    server_socket.bind(('localhost', 8080))
    print("Server is up and running...")

    # Initialize expected sequence number
    expected_seq_num = 0

    while True:
        # Receive a message from the client
        message, client_address = server_socket.recvfrom(1024)
        received_data = message.decode()

        # Extract sequence number and data
        if len(received_data) > 1:
            seq_num = int(received_data[0])  # Sequence number
            data = received_data[1:]        # Data payload
        else:
            print("Invalid packet received")
            continue

        # Process the received packet
        if seq_num == expected_seq_num:
            print(f"Received valid packet: {data} with seq_num: {seq_num}")
            expected_seq_num += 1  # Move to the next expected sequence number

            # Send ACK for the received packet
            ack_message = f"ACK{seq_num}"
            server_socket.sendto(ack_message.encode(), client_address)
        else:
            print(f"Expected seq_num: {expected_seq_num}, but received seq_num: {seq_num}. Discarding packet.")

            # Resend ACK for the last correctly received packet
            last_ack = f"ACK{expected_seq_num - 1}"  # Last valid ACK
            server_socket.sendto(last_ack.encode(), client_address)

if __name__ == "__main__":
    go_back_n_server()
