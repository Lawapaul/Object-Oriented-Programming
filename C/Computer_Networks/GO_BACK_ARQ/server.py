import socket

# Function to simulate Stop-and-Wait ARQ server
def stop_and_wait_arq_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 8080))
    print("Server is up and running...")
    expected_seq_num = 0

    while True:
        message, client_address = server_socket.recvfrom(1024)
        received_data = message.decode()
        seq_num = int(received_data[0])
        data = received_data[1:]
        
        if seq_num == expected_seq_num:
            print(f"Received valid packet: {data} with seq_num: {seq_num}")
            expected_seq_num = 1 - expected_seq_num  # Toggle expected sequence number
            # Send ACK
            ack_message = f"ACK{seq_num}"
            server_socket.sendto(ack_message.encode(), client_address)
        else:
            print(f"Discarding out-of-order packet: {data} with seq_num: {seq_num}")

# Run the server
if __name__ == "__main__":
    stop_and_wait_arq_server()
