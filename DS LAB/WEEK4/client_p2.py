import socket

#create socket objet
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

#get local machine name
host=socket.gethostname()
port=9991
#connection to hostname on the port
s.connect((host,port))
#recieve no more than 1024 bytes
tm=s.recv(1024)
print('current time from server',tm.decode())
s.close()