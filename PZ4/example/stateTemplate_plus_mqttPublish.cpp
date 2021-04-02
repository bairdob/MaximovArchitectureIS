
#include <mosquitto.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class PoohState;
class PoohStateContext;
class PoohEmptyState;
class PoohEatState;
class PoohFullState;




class PoohState{
    std::string name;
public: 
    PoohState(const std::string& name) : name(name) {};
    std::string GetName(){return name;};
    virtual ~PoohState(){};
    virtual void fly(PoohStateContext *) = 0; // "= 0" abstractClass
    virtual void freeze(PoohStateContext *) = 0;
};

class PoohStateContext{
private:
    PoohState *state;
public:
    PoohStateContext(PoohState *state) : state(state){};
    void fly(){
        std::cout << state->GetName() << "..." << std::endl;
        state->fly(this);
    }
    void freeze(){
        std::cout << state->GetName() << "..." << std::endl;
        state->freeze(this);
    }
    void SetState(PoohState *state_new){
        std::cout << "Chaging state from " << state->GetName()
                  << " to " << state_new->GetName() << "..." << std::endl;
        delete state;
        state = state_new;
    }    
    PoohState* GetState(){
        return state;
    }
    ~PoohStateContext(){
        delete state;
    }
};

class PoohEmptyState : public PoohState{
public:
    PoohEmptyState() : PoohState("Pooh Empty"){};
    virtual void fly(PoohStateContext *state);
    virtual void freeze(PoohStateContext *state);
};

class PoohEatState : public PoohState{
public:
    PoohEatState() : PoohState("Pooh Eat"){};
    virtual void fly(PoohStateContext *state);
    virtual void freeze(PoohStateContext *state);
};

class PoohFullState : public PoohState{
public:
    PoohFullState() : PoohState("Pooh Full"){};
    void fly(PoohStateContext *state);
    void freeze(PoohStateContext *state);
};

void PoohEmptyState::fly(PoohStateContext *state){
    std::cout << "Flying up" << std::endl;
    state->SetState(new PoohEatState());
    //publish_pooh_data(mosq, pooh);
}

void PoohEmptyState::freeze(PoohStateContext *state){
    std::cout << "Already Standing on the ground" << std::endl;
}

void PoohEatState::fly(PoohStateContext *state){
    std::cout << "Pooh cannot fly, eating" << std::endl;
}

void PoohEatState::freeze(PoohStateContext *state){
    std::cout << "Eating" << std::endl;
    state->SetState(new PoohFullState());
}

void PoohFullState::fly(PoohStateContext *state){
    std::cout << "Flying down" << std::endl;
}

void PoohFullState::freeze(PoohStateContext *state){
    std::cout << "Only way to fly down" << std::endl;
}


void on_connect(struct mosquitto *mosq, void *obj, int reason_code)
{
    printf("on_connect: %s\n", mosquitto_connack_string(reason_code));
    if(reason_code != 0){
        mosquitto_disconnect(mosq);
    }

}

void on_publish(struct mosquitto *mosq, void *obj, int mid)
{
    printf("Message with mid %d has been published.\n", mid);
}


std::string get_state(PoohStateContext *pooh)
{
    sleep(1); /* Prevent a storm of messages - this pretend sensor works at 1Hz */
    std::string temp = pooh->GetState()->GetName();
    return temp;
}

void publish_pooh_data(struct mosquitto *mosq,PoohStateContext *pooh)
{
    char payload[20];
    std::string temp;
    int rc;
    temp = get_state(pooh);
    rc = mosquitto_publish(mosq, NULL, "state", temp.size(), temp.c_str(), 2, false);
    if(rc != MOSQ_ERR_SUCCESS){
        fprintf(stderr, "Error publishing: %s\n", mosquitto_strerror(rc));
    }
}


int main(int argc, char *argv[])
{
    struct mosquitto *mosq;
    int rc;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if(mosq == NULL){
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_publish_callback_set(mosq, on_publish);

    rc = mosquitto_connect(mosq, "localhost", 1883, 60);
    if(rc != MOSQ_ERR_SUCCESS){
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return 1;
    }

    rc = mosquitto_loop_start(mosq);
    if(rc != MOSQ_ERR_SUCCESS){
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return 1;
    }

    PoohStateContext *pooh = new PoohStateContext(new PoohEmptyState());

    enum CMD {fly_up = 1, eat, fly_down};
    int read;
    std::cout << "Commands:"<< " 1-fly_up" << " 2-eat" <<  " 3-fly_down" << std::endl;
    do{ std::cin >> read;
        switch (read){
        case fly_up:
            publish_pooh_data(mosq,pooh);
            break;
        case eat:
            pooh->fly();
            publish_pooh_data(mosq,pooh);
            break;
        case fly_down:
            pooh->freeze();
            publish_pooh_data(mosq,pooh);
            break;
        default:
            break;
    }
    } while(get_state(pooh) != "Pooh Full");

    mosquitto_lib_cleanup();
    return 0;
}
