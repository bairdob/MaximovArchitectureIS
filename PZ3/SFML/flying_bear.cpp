#ifndef _FBEAR_SOURCE_
#define _FBEAR_SOURCE_


#include <iostream>
#include "flying_bear.h"
#include "bear.cpp"
#include "pid.cpp"
#include "engine.cpp"

FlyingBear::FlyingBear() : Bear(){};

FlyingBear::FlyingBear(float nm, float nh) : Bear(nm, nh){};

FlyingBear::~FlyingBear(){};

void FlyingBear::show(){
	Bear::show();
    std::cout << " power = " << fan.getPower() <<std::endl;
}

void FlyingBear::fly_up(float dt){
	double dh = 0;
	PIDImpl pid (dt, 100, 0, 0.03, 0.01, 0);
	cout << "fly up" << std::endl;
	while (abs(hollowHeight - height) > 0.1){
		fan.setPower(pid.calculate(hollowHeight, height)); 
		if (fan.getPower() !=0){
			globalHeight = height;
            height = height + dh; 
            dh = velocity * dt;
            acceleration = (fan.getPower()+ 9.8*mass)/mass; 
            velocity = velocity+ acceleration * dt;
        }	
        else {
       			height = height+ dh;
            	dh = -velocity * dt;
            	velocity =  acceleration * dt;
        }
        time = time + dt;
        
	   // FlyingBear::show();
    }
}

void FlyingBear::fly_down_extra(float dt){
	double dh = 0;
	PIDImpl pid (dt, 100, 0, 0.03, 0.01, 0);
	cout << "fly down extra" << std::endl;
	while (height > 0){
		height = height+ dh;
    	dh = velocity * dt;
    	velocity =  velocity + acceleration * dt;
    	acceleration = -(fan.getPower()+ 9.8*mass)/mass; //
        time = time + dt;
	    //FlyingBear::show();
    }
}

void FlyingBear::eat(float dt){
	double dh = 0;
	PIDImpl pid (dt, 100, 0, 0.03, 0.01, 0);
	while (mass < max_mass){
		if (abs(hollowHeight - height) < 0.1 ) {
	    	Bear::eat(dt);
	    }
		if (abs(hollowHeight - height) > 0.1 && mass < 1.3 ) fan.setPower(pid.calculate(hollowHeight, height)); 
		if (fan.getPower() !=0){
				    
	       height = height + dh; 
	        dh = velocity * dt;
            acceleration = (fan.getPower()+ 9.8*mass)/mass; 
            velocity = velocity+ acceleration * dt;
        }	else {
       			height = height+ dh;
            	dh = -velocity * dt;
            	velocity =  acceleration * dt;
        }
	    time = time + dt;
	    //FlyingBear::show();
	}
};


#endif
