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
	std::cout << std::setprecision(3) << fixed << "\t h = "<< height << " a = "<< acceleration << " v = "<< velocity<<" m = " << mass<<" t = " << time;
}


#endif
