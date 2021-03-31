all: mqtt_subscribe

mqtt_subscribe: mqtt_subscribe.o 
	g++ mqtt_subscribe.o -o mqtt_subscribe -lmosquitto

mqtt_subscribe.o: mqtt_subscribe.cpp
	g++ -c mqtt_subscribe.cpp -I /usr/local/Cellar/mosquitto/2.0.9/include
	
clean:
	rm -rf *.o mqtt_subscribe