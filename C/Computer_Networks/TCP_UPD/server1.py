import socket

def expression_evaluate(expression):
    try:
        return str(eval(expression))
    except Exception as e:
        return f"Error: {e}"

def tcp_server(host='localhost',port=12345):
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_socket.bind((host,port))
    server_socket.listen(5)
    print("Listening.....")
    while True:
        client_socket,client_address=server_socket.accept()
        try:
            expression=client_socket.recv(1024).decode()
            result=expression_evaluate(expression)
            print(f"Result: {result}")
            client_socket.sendall(result.encode(),client_address)
        except Exception as e:
            return f"Error"
        finally:
            client_socket.close()

if __name__=="__main__":
    tcp_server()