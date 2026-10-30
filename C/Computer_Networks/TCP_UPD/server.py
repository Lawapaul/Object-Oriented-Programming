import socket

def udp_server():
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    server_socket.bind(('localhost',12346))
    print("Conncecting.....")
    while True:
        message,client_address=server_socket.recvfrom(1024)
        print(f"Message Received: {message.decode()} from {client_address}")
        reply=input("Enter Reply: ")
        server_socket.sendto(reply.encode(),client_address)

if __name__=="__main__":
    udp_server()