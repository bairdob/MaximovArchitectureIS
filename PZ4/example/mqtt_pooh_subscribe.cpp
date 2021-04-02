#include <stdlib.h>
#include <stdio.h>
#include "mosquitto.h"
#include <iostream>
#include <iostream>
#include <cmath>
#include <iomanip> // setw()
#include "include/pid.cpp"
#include "include/engine.cpp"
#include "include/bear.cpp"
#include "include/flying_bear.cpp"

#define mqtt_host "localhost"
#define mqtt_port 1883 
#define mqtt_topic "state" 

std::string getCMD(){
    int rc;
    struct mosquitto_message *msg;
    mosquitto_lib_init();

    rc = mosquitto_subscribe_simple(
                &msg, 1, true,
                mqtt_topic, 0,
                mqtt_host, mqtt_port,
                NULL, 60, true,
                NULL, NULL,
                NULL, NULL);

    if(rc){
        printf("Error: %s\n", mosquitto_strerror(rc));
        mosquitto_lib_cleanup();
        //return rc;
    }
    printf("%s/%s\n", msg->topic, (char *)msg->payload);
    
    mosquitto_message_free(&msg);
    mosquitto_lib_cleanup();

    return (char *)msg->payload;;

}

int main(){
const float dt = 0.1; // s
    FlyingBear Pooh(1, 10); //(mass, duploHeight)
    std::string CMD;
    do {
        CMD = getCMD();
        if (CMD == "Pooh Empty"){
            Pooh.fly_up(dt);
        }
        if (CMD == "Pooh Eat") {
            if (abs(Pooh.getHollowHeight() - Pooh.getHeight()) < 0.1) Pooh.eat(dt);
        }
        if (CMD == "Pooh Full") {
            if (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01) Pooh.fly_down_extra(dt);
        }
        if (Pooh.getHeight() < 0) CMD = "Pooh Full";
    }while (CMD != "Pooh Full");
    return 0;
}
