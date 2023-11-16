#ifndef VIEW_HPP_
#define VIEW_HPP_

// #include "Framework.hpp"
#include "FlyingObject.hpp"
#include "framework.hpp"


#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include "Missile.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>

// class View {
//     public :
//         View(Framework* fmw);
//         void rafraichir(std::vector<FlyingObject*> flyingObjects);
//     private :
//         Framework* framework;
// };
// #endif


class View {
public:
    View(Framework* framework);
    void rafraichir(const std::vector<FlyingObject*>& flyingObjects);

private:
    Framework* framework;
};


// View::View(Framework* framework) : framework(framework) {}

// void View::rafraichir(const std::vector<FlyingObject*>& flyingObjects) {
//     for (FlyingObject* obj : flyingObjects) {
//         framework->DrawMissile(obj->GetX(), obj->GetY());
//     }
// }

#endif
