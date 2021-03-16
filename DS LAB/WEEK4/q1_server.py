import socket
import time 
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) 
udp_host = socket.gethostname()
udp_port = 12345
sock.bind((udp_host,udp_port)) 
while True:
	print("Waiting ")
	data,addr = sock.recvfrom(1024)
	print( "Received Messages:",data.decode()," from",addr)
	print("sending time to client")
	currentTime= time.ctime(time.time())+"\r\n"
	sock.sendto(currentTime.encode('ascii'),addr)
	if not data:
		break
sock.close()