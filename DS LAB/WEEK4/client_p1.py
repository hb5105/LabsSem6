import socket
host='127.0.0.1'
port=2053

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
	s.connect((host,port))
	s.sendall(b'hello')
	data=s.recv(1024)
	print("recieved connection")
	print("server: ",data.decode())
	s.close()