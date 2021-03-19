#ifndef _ENGINE_SOURCE_
#define _ENGINE_SOURCE_


#include <stdio.h>
#include "engine.h"

Engine::Engine(){
	power = 0;
}

Engine::~Engine(){}

void Engine::setPower(float p){
	power = p;
}

float Engine::getPower(){
	return power;
}


#endif