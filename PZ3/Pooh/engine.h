#ifndef _engine_h
#define _engine_h


class Engine{
protected:
	float power;
public:
	Engine();
	~Engine();
	void setPower(float p);
	float getPower();
};


#endif