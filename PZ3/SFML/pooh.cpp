#include <iostream>
#include <cmath>
#include <iomanip> // setw()
#include "pid.cpp"
#include "engine.cpp"
#include "bear.cpp"
#include "flying_bear.cpp"


int main() {
    const float dt = 0.1; // s
    FlyingBear Pooh(1, 10); //(mass, duploHeight)
    Pooh.fly_up(dt);
    //cout << globalHeight;
    if (abs(Pooh.getHollowHeight() - Pooh.getHeight()) < 0.1) Pooh.eat(dt);
    if (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01) Pooh.fly_down_extra(dt);
    return 0;
}    