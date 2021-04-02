all: mqtt_subscribe stateTemplate_plus_mqttPublish mqtt_pooh_subscribe

mqtt_subscribe: mqtt_subscribe.o 
	g++ mqtt_subscribe.o -o mqtt_subscribe -lmosquitto

mqtt_subscribe.o: mqtt_subscribe.cpp
	g++ -c mqtt_subscribe.cpp -I /usr/local/Cellar/mosquitto/2.0.9/include

stateTemplate_plus_mqttPublish: stateTemplate_plus_mqttPublish.o 
	g++ stateTemplate_plus_mqttPublish.o -o stateTemplate_plus_mqttPublish -lmosquitto

stateTemplate_plus_mqttPublish.o: stateTemplate_plus_mqttPublish.cpp
	g++ -c stateTemplate_plus_mqttPublish.cpp -I /usr/local/Cellar/mosquitto/2.0.9/include

mqtt_pooh_subscribe: mqtt_pooh_subscribe.o 
	g++ mqtt_pooh_subscribe.o -o mqtt_pooh_subscribe -lmosquitto

mqtt_pooh_subscribe.o: mqtt_pooh_subscribe.cpp
	g++ -c mqtt_pooh_subscribe.cpp -I /usr/local/Cellar/mosquitto/2.0.9/include	
	
clean:
	rm -rf *.o mqtt_subscribe stateTemplate_plus_mqttPublish mqtt_pooh_subscribe