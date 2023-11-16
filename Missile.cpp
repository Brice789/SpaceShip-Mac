///////////////////////////////////////////////////
//                   Classe Missile
///////////////////////////////////////////////////
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>


///////////////
// Constructeur
///////////////
// * x, y : position dans l'écran
// * size : diamètre du missile
// * speed : vitesse de déplacement
// * angle : orientation



Missile::Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle)
: FlyingObject(x, y, size, xSpeed, ySpeed), m_angle(angle) {
    this->active = false; // Initially the missile should not be active
}


std::string Missile::GetTypeName() {
    return "Missile";
}


void Missile::Move(double screenWidth, double screenHeight) {
    if (IsActive()) {
        x += xSpeed;
        y += ySpeed;

        std::cout << "Missile position X: " << x << " Y: " << y << std::endl;

        // Check if the missile is out of screen bounds and deactivate if it is
        if (x > screenWidth || x < 0 || y > screenHeight || y < 0) {
            Deactivate(); // Deactivate the missile if it goes off-screen
            std::cout << "Missile deactivated due to leaving screen." << std::endl;
        }
    }
}


double Missile::GetX() const {
    return x;
}

double Missile::GetY() const {
    return y;
}

void Missile::SetX(double newX) {
    x = newX;
}

void Missile::SetY(double newY) {
    y = newY;
}

void Missile::SetXSpeed(double newXSpeed) {
    xSpeed = newXSpeed;
}

void Missile::SetYSpeed(double newYSpeed) {
    ySpeed = newYSpeed;
}

void Missile::Activate() {
    active = true;
}

void Missile::Deactivate() {
    active = false;
}

bool Missile::IsActive() const {
    return active;
}




// Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
// bool move(double screenWidth, double screenHeight);


// bool Missile::move(double screenWidth, double screenHeight) //: FlyingObject(x, y, size, xSpeed, ySpeed)
// {
//     // Mettez ici la logique pour déplacer l'objet
//     // Par exemple :
//     x += xSpeed;
//     y += ySpeed;
//     if (x > screenWidth)
//     {
//         x = 0;
//     }
//      if (x < 0)
//     {
//         x = screenWidth;
//     }
//     if (y > screenHeight)
//     {
//         y = 0;
//     }
//       if (y < 0)
//     {
//         y = screenHeight;
//     }

//     // Vérifiez si l'objet est sorti des limites de l'écran
//     if (x > screenWidth || x < 0 || y > screenHeight || y < 0) {
//         xSpeed =0;
//         ySpeed =0;

//         return true; // L'objet est sorti de l'écran
//     } else {
//         return false; // L'objet est toujours à l'intérieur de l'écran
//     }
// }






// Getters
// double Missile::GetX()
// {
//     return x;
// }
// double Missile::GetY() 
// {
//     return y;
// }


// void Missile::SetX(double x)
// {
//     this->x = x;
// }

// void Missile::SetY(double y)
// {
//     this->y = y;
// }

// void Missile::SetXSpeed(double xSpeed)
// {
//     this->xSpeed = xSpeed;
// }

// void Missile::SetYSpeed(double ySpeed)
// {
//     this->ySpeed = ySpeed;
// }

// void Missile::SetSize(double size)
// {
//     this->size = size;
// }








// Missile::Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle)
// : FlyingObject(x, y, size, xSpeed, ySpeed), m_angle(angle)
// {
//     this->m_angle = angle;
// };