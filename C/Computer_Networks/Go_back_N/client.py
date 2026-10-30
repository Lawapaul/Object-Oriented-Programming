import socket
import time  # Corrected the module import

# Function to simulate Go-Back-N ARQ client
def go_back_n_client(window_size=4):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 8080)
    client_socket.settimeout(2)  # Timeout for ACKs

    # Messages to send
    messages = ["Hello", "Go", "Back", "N", "Protocol", "Simulation"]
    base = 0  # Base of the sliding window
    seq_num = 0  # Next sequence number to send

    while base < len(messages):
        # Send packets within the window
        while seq_num < base + window_size and seq_num < len(messages):
            message_to_send = f"{seq_num}{messages[seq_num]}"
            client_socket.sendto(message_to_send.encode(), server_address)
            print(f"Sent packet: {messages[seq_num]} with seq_num: {seq_num}")
            seq_num += 1

        # Wait for ACKs or timeout
        try:
            ack, server = client_socket.recvfrom(1024)
            ack_message = ack.decode()
            ack_num = int(ack_message[3:])  # Extract ACK number
            print(f"Received {ack_message}")

            # Slide the window
            base = ack_num + 1
        except socket.timeout:
            print("Timeout! Resending window...")
            # Go back and resend all unacknowledged packets
            seq_num = base  # Reset seq_num to base for retransmission
            time.sleep(1)

    client_socket.close()

# Run the client
if __name__ == "__main__":
    go_back_n_client()
