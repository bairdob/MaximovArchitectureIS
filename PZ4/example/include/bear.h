#ifndef _bear_h
#define _bear_h


class Bear{
protected:
	float mass;
	float hollowHeight;	
	float max_mass;
	float velocity;
	float acceleration;
	float height;
	float time;
public:
    Bear();
	Bear(float nm, float nH);
	~Bear();
	virtual void eat(float dt);
	float getHeight();
	float getMass();
	float getMaxMass();
	float getAcceleration();
	float getHollowHeight();
	float getSpeed();
	virtual void show();
};


#endif