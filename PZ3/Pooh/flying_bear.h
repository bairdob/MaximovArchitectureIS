#ifndef _fbear_h
#define _fbear_h
#include "engine.h"
#include "bear.h"


class FlyingBear : public Bear
{
private:
	Engine fan;
public:
	FlyingBear();
	FlyingBear(float nm, float nh);
	~FlyingBear();
	void fly_up(float dt); 
	void fly_down_extra(float dt);
	//void fly_down(float dt); // TO DO ПЛАВНОЕ ОПУСКАНИЕ
	virtual void eat(float dt);
	virtual void show();
};


#endif