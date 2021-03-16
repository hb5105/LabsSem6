import socket
host='127.0.0.1'
port=31621
s=socket.socket()
name=input(str("enter your name"))
print("trying to connect with ",host,'(',port,')\n')
s.connect((host,port))
print('connected\n')

s.send(name.encode())
s_name=s.recv(1024)
s_name	=s_name.decode()
print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")
while True:
	message=s.recv(1024)
	message=message.decode()
	print(s_name,":",message)
	message=input("ME:")
	if message=="[e]":
		message="left chat room"
		s.send(message.encode())
		print('\n')
		break
	s.send(message.encode())
