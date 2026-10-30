import socket

def tcp_client(expression,host='localhost',port=12345):
    client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client_socket.connect((host,port))
    client_socket.sendall(expression.encode())
    result=client_socket.recv(1024).decode()
    print(f"Result: {result}")

if __name__ == "__main__":
    while True:
        expression=input("Enter Expression: ")
        if(expression.lower()=='quit'):
            break
        tcp_client(expression)