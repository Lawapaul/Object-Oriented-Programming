import socket

def udp_client():
    client_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    server_address=('localhost',12345)
    while True:
        message=input("Enter Message: ")
        client_socket.sendto(message.encode(),server_address)
        print("Message Sent!!!!")
        reply,_=client_socket.recvfrom(1024)
        print(f"Result: {reply.decode()}")

if __name__=="__main__":
    udp_client()