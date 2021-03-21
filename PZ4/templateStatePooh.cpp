#include <iostream>
#include <string>


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


int main(){
	PoohStateContext *pooh = new PoohStateContext(new PoohEmptyState());
	//pooh->freeze(); //debug 
	pooh->fly();
	//pooh->freeze(); //debug
	pooh->freeze();
	pooh->fly();
	return 0;
}