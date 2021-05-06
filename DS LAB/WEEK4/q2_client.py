import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) 
udp_host = socket.gethostname()
udp_port = 12345
msg=input("Enter the message here: ")
sock.sendto(msg.encode('UTF-8'),(udp_host,udp_port))
while True:
 data,addr = sock.recvfrom(1024)
 print( "Received Message:",data.decode())
 msg=input('Enter your message here: ')
 sock.sendto(msg.encode('UTF-8'),addr)
 if data.decode()=='exit':
		break
sock.close()