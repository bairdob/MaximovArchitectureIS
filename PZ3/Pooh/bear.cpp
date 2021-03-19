#ifndef _BEAR_SOURCE_
#define _BEAR_SOURCE_

#include <iostream>
#include <iomanip>
#include "bear.h"
#include "pid.cpp"
#include "engine.cpp"


Bear::Bear(){};
Bear::Bear(float nm, float nh){
	mass = nm;
	hollowHeight = nh;
	max_mass = 1.3;
	velocity = 0;
	acceleration = 0;
	height = 0;
	time = 0;
};

Bear::~Bear(){};

float Bear::getHeight(){return height;};

float Bear::getMass(){return mass;};

float Bear::getMaxMass(){return max_mass;};

float Bear::getAcceleration(){return acceleration;};

float Bear::getHollowHeight(){return hollowHeight;};

float Bear::getSpeed(){return velocity;};

void Bear::eat(float dt){
	cout << "eating" << std::endl;
	mass += 0.1;
};

void Bear::show(){
	std::cout << std::setprecision(3) << fixed << "\t h = "<< height << " a = "<< acceleration << " v = "<< velocity<<" m = " << mass;
}

// void Bear::fly_up(float dt){
// 	Engine Fan; 
// 	double dh = 0;
// 	PIDImpl pid (dt, 100, 0, 0.03, 0.01, 0);

// 	for (int i = 0; i < 160; ++i){
// 		if (abs(hollowHeight - height) > 0.1 && mass < 1.3 ) Fan.setPower(pid.calculate(hollowHeight, height)); 

// 		if (Fan.getPower() !=0){
//             height = height + dh; 
//             dh = velocity * dt;
//             acceleration = (Fan.getPower()+ 9.8*mass)/mass; 
//             velocity = velocity+ acceleration * dt;
//         }	else{
//        			height = height+ dh;
//             	dh = -velocity * dt;
//             	velocity =  acceleration * dt;
//         }
 
            
//         if (abs(hollowHeight - height) < 0.1 ) Bear::eat(dt);
      
//         time = time + dt;
//     	Bear::show();
//     	std::cout << " power = " << Fan.getPower() <<std::endl;        
//     }
// };


#endif
