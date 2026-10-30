import socket
import time

# Function to simulate Stop-and-Wait ARQ client
def stop_and_wait_arq_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 8080)
    client_socket.settimeout(2)  # Timeout for ACK
    messages = ["Hello", "Stop", "And", "Wait", "ARQ"]
    seq_num = 0

    for message in messages:
        while True:
            # Send the message with the sequence number
            message_to_send = f"{seq_num}{message}"
            client_socket.sendto(message_to_send.encode(), server_address)
            print(f"Sent packet: {message} with seq_num: {seq_num}")

            try:
                # Wait for ACK
                ack, server = client_socket.recvfrom(1024)
                ack_message = ack.decode()
                if ack_message == f"ACK{seq_num}":
                    print(f"Received {ack_message}, moving to next packet.")
                    seq_num = 1 - seq_num  # Toggle sequence number
                    break
                else:
                    print("Received wrong ACK, resending packet...")
            except socket.timeout:
                print("Timeout! Resending packet...")
                time.sleep(1)  # Wait before resending

    client_socket.close()

# Run the client
if __name__ == "__main__":
    stop_and_wait_arq_client()
