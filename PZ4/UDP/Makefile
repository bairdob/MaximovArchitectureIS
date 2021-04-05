all: udpServer udpClient


udpServer:udpServer.o 
	g++ -o udpServer udpServer.o 

udpServer.o:udpServer.cpp
	g++ -c udpServer.cpp

udpClient:udpClient.o 
	g++ -o udpClient udpClient.o 


udpClient.o:udpClient.cpp
	g++ -c udpClient.cpp

clean:
	rm *.o
	rm udpServer udpClient

