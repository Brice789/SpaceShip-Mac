#include "View.hpp"
#include <string>
#include <iostream>
#include "framework.hpp"
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>

View::View(Framework* framework) : framework(framework) {}

void View::rafraichir(const std::vector<FlyingObject*>& flyingObjects) {
    for(FlyingObject* obj : flyingObjects) {
        std::string type = obj->GetTypeName();

        if (type == "Spaceship") {
            framework->DrawShip(obj->GetX(), obj->GetY(), obj->GetAngle(), 1, true);
        } 
        else if (type == "Missile") {
            // Dynamic cast to check if the object is a Missile
            Missile* missile = dynamic_cast<Missile*>(obj);
            // If the cast is successful and the missile is active, draw it
            if (missile && missile->IsActive()) {
                framework->DrawMissile(missile->GetX(), missile->GetY());
            }
        } 
        else if (type == "Asteroid") {
            framework->DrawAsteroid(obj->GetX(), obj->GetY(), obj->GetSize());
        }
    }
    framework->Update();
}


