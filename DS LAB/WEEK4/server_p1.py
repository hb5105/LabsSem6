import socket

host='127.0.0.1'
port=2053 #port used by server #port to listen on

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
	s.bind((host,port))
	s.listen()
	conn, addr=s.accept()

	with conn:
		print('connected by',addr)
		while True:
			data=conn.recv(1024)
			if data:
				print("client :",data.decode())


			data=input("enter message to client\n")
			if not data:
				break;
			conn.sendall(bytearray(data,'utf-8'))
	conn.close()
	s.close()