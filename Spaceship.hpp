#include <iostream>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include <cmath>

///////////////////////////////////////////////////
//                   Classe Spaceship
///////////////////////////////////////////////////

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP


class Spaceship : public FlyingObject {
private:
    double angle;
    double velocityX;
    double velocityY;

public:
    Spaceship(double x, double y, double size, double initialAngle);
    double GetAngle() override;
    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    void Rotate(double rotationAngle);
    bool UpdatePosition(double screenWidth, double screenHeight);
    void Move(double screenWidth, double screenHeight) override;

    string GetTypeName() override;

    bool warning = false;

    void SetWarning(bool state) { warning = state; }
    bool IsWarning() const { return warning; }
};

#endif // SPACESHIP_HPP
