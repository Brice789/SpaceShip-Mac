#include <iostream>
#include <string>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include <cmath>
#include <random>
#include <ctime>
#include <SDL.h>


#include "Controller.hpp"

const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;

int main(int argc, char* argv[]) {


    int FPS = 60;
    int shipsize = 32;
    int missileSize = 20;

    Controller* controller = new Controller(FPS, shipsize, missileSize);
    controller->LauchGame();
    delete controller;  // N'oubliez pas de supprimer le contrôleur pour éviter les fuites de mémoire
    return 0;


}


 








    // Framework fmw(60, 32, 20);
    //  =====  code a été transféré le constructeur de Model =======

    // double screenHeight = fmw.GetScreenHeight();
    // double screenWidth = fmw.GetScreenWidth();
    
    // Spaceship spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0);
    


    // double missileStartX = 340;
    // double missileStartY = spaceship.GetY() + spaceship.GetSize() / 2 + 10;
    // Missile missile(missileStartX, missileStartY, 10, 0, 0, 0);

    // =============================================================

    // std::vector<Asteroid> asteroids;

    // std::mt19937 gen(time(nullptr));
    // std::uniform_real_distribution<> disPos(0.0, 1.0);
    // std::uniform_real_distribution<> disSize(50.0, 150.0);


    
  
    // for (int i = 0; i < NUM_ASTEROIDS; i++) {
    //     double x = disPos(gen) * screenWidth;
    //     double y = disPos(gen) * screenHeight;
    //     double size = disSize(gen);
    //     asteroids.push_back(Asteroid(x, y, size, disPos(gen), disPos(gen)));
    // }

    // while (1) 
    // {

    //     time_t currentTime = time(nullptr);
    // if (currentTime - startTime >= 7) {
    //     for (int i = 0; i < NUM_ASTEROIDS; i++) {
    //         double x = disPos(gen) * screenWidth;
    //         double y = disPos(gen) * screenHeight;
    //         double size = disSize(gen);
    //         asteroids.push_back(Asteroid(x, y, size, disPos(gen), disPos(gen)));
    //     }
    //     startTime = currentTime;
    // }

    //     for (Asteroid &asteroid : asteroids) {
    //         asteroid.Move(screenWidth, screenHeight);
    //         fmw.DrawAsteroid(asteroid.GetX(), asteroid.GetY(), asteroid.GetSize());
    //     }

        // int input = fmw.GetInput();
        // fmw.Update();

        // switch (input)
        // {
        //     case SDLK_ESCAPE: 
        //         return 0;         
        //         break;
        //     case SDLK_UP:
        //         spaceship.SpeedUp(1);
        //         break;
        //     case SDLK_DOWN:
        //         spaceship.SpeedDown(1);
        //         break;
        //     case SDLK_RIGHT:
        //         spaceship.Rotate(-15.0);
        //         break;
        //     case SDLK_LEFT:
        //         spaceship.Rotate(15.0);
        //         break;
        //     case SDLK_SPACE:
        //         missile.SetX(spaceship.GetX());
        //         missile.SetY(spaceship.GetY());
        //         missile.SetXSpeed(cos(spaceship.GetAngle() * M_PI / 180.0) * MISSILE_SPEED); 
        //         missile.SetYSpeed(-sin(spaceship.GetAngle() * M_PI / 180.0) * MISSILE_SPEED);
        //         break;
        //     default:
        //         break;
        // }

        // spaceship.Move(screenHeight, screenWidth);
        // missile.Move(screenWidth, screenHeight);
        // fmw.DrawShip(spaceship.GetX(), spaceship.GetY(), spaceship.GetAngle(), 1, true);
        // fmw.DrawMissile(missile.GetX(), missile.GetY());
    // }





/////////////////////////////////////////////////////////////////////////////


// #include <iostream>
// #include <string>
// #include "framework.hpp"
// #include "FlyingObject.hpp"
// #include "Asteroid.hpp"
// #include "Missile.hpp"
// #include "Spaceship.hpp"
// #include <cmath>
// #include <random>
// #include <ctime>
// #include <SDL.h>

// const double MISSILE_SPEED = 5.0;
// const int NUM_ASTEROIDS = 10;

// int main(int argc, char* argv[]) {
//     Framework fmw(60, 32, 20);

//     double screenHeight = fmw.GetScreenHeight();
//     double screenWidth = fmw.GetScreenWidth();
    
//     Spaceship spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0);
    
//     while (1) 
//     {

//         int input = fmw.GetInput();
//         fmw.Update();

//         switch (input)
//         {
//             case SDLK_ESCAPE: 
//                 return 0;         
//                 break;
//             case SDLK_UP:
//                 spaceship.SpeedUp(1);
//                 break;
//             case SDLK_DOWN:
//                 spaceship.SpeedDown(1);
//                 break;
//             case SDLK_RIGHT:
//                 spaceship.Rotate(-15.0);
//                 break;
//             case SDLK_LEFT:
//                 spaceship.Rotate(15.0);
//                 break;
//             case SDLK_SPACE:

//                 break;
//             default:
//                 break;
//         }

//         spaceship.move(screenHeight, screenWidth);
//         fmw.DrawShip(spaceship.GetX(), spaceship.GetY(), spaceship.GetAngle(), 1, true);

//     }
// }
