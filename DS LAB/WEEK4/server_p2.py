import socket
import time

#create socket object:
serversocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#get local macjhine name
host=socket.gethostname()
port=9991
#bind to port
serversocket.bind((host,port))
serversocket.listen(5)

while True:
	clientsocket,addr=serversocket.accept()
	print("got a connection from%s"%(str(addr)))
	currentTime=time.ctime(time.time())+"\r\n"
	clientsocket.send(currentTime.encode("ascii"))
	clientsocket.close()