import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) 
udp_host = socket.gethostname()
udp_port = 12345
msg="Hello, what time is it? "
sock.sendto(msg.encode('UTF-8'),(udp_host,udp_port))
tm,addr=sock.recvfrom(1024)
print("time is %s "%str(tm.decode()))
sock.close()