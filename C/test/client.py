import socket

def udp_client():
    client_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    server_address=('localhost',12345)
    while True:
        message=input("Enter Message: ")
        print(f"Message sent: {message}")
        client_socket.sendto(message.encode(),server_address)
        print("Message sent!!!")
        reply,_=client_socket.recvfrom(1024)
        print(f"Reply: {reply.decode()}")

if __name__=="__main__":
    udp_client()
        
        