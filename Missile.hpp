
///////////////////////////////////////////////////
//                   Classe Missile
///////////////////////////////////////////////////

#ifndef MISSILE_HPP_
#define MISSILE_HPP_



#include <string>
#include "include/SDL2/SDL.h"
#include "FlyingObject.hpp"

#include <iostream>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>



class Missile : public FlyingObject 
{
    public:
        // Getters
        // double GetX() ;
        // double GetY();
        // double GetXSpeed();
        // double GetYSpeed();
        // double GetSize();
        // Setters
        // void SetX(double x);
        // void SetY(double y);
        // void SetXSpeed(double xSpeed);
        // void SetYSpeed(double ySpeed);
        // void SetSize(double size);


       Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle);


      // bool move(double screenWidth, double screenHeight);

        //    bool IsActive() const { return active; }
        //    void Activate() { active = true; }
        //    void Deactivate() { active = false; }


        void Move (double screenHeight, double screenWidth)override;

        //void move();


        void position();

        void Activate();
        void Deactivate();
        bool IsActive() const;

        Missile(double startX, double startY, double size, double xSpeed, double ySpeed);

        //void move(double screenWidth, double screenHeight);

        double GetX() const;
        double GetY() const;
        void SetX(double newX) override;
        void SetY(double newY) override;
        void SetXSpeed(double newXSpeed) override;
        void SetYSpeed(double newYSpeed) override;


        std::string GetTypeName() override;

    

    private:
        double m_angle; 
         bool active;
         double x, y;
         double xSpeed, ySpeed;
};
#endif