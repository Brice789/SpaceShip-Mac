#include "Model.hpp"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>


const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;

Model::Model(int screenWidth, int screenHeight, Framework* framwework) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

    /*
    double screenHeight = fmw.GetScreenHeight();
    double screenWidth = fmw.GetScreenWidth();
    //pas de beoin de demander au framework le screenheight et screenwidth car on les a en parametre
    
    Spaceship spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0);
    */

    spaceship = new Spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0);
    flyingObjects.push_back(spaceship);


     // double missileStartX = 340;
    // double missileStartY = spaceship.GetY() + spaceship.GetSize() / 2 + 10;
     //Missile missile(missileStartX, missileStartY, 10, 0, 0, 0);


    missile = new Missile(340, spaceship->GetY() + spaceship->GetSize() / 2 + 10, 10, 0, 0, 0);
    flyingObjects.push_back(missile);


    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> disPos(0.0, 1.0);
    std::uniform_real_distribution<> disSize(20.0, 75.0);


    for (int i = 0; i < NUM_ASTEROIDS; i++)
    {
        double x = rand() % (int)screenWidth;
        double y = rand() % (int)screenHeight;
        double angle = rand() % 360;
        double speed = rand() % 5 + 1;
        flyingObjects.push_back(new Asteroid(x, y, angle, disPos(gen), disPos(gen)));
    }

    for (FlyingObject* flyingObject : flyingObjects) 
    //     {
    //         flyingObject->Move(m_screenWidth, m_screenHeight);
    //     }

    time_t currentTime = time(nullptr);

    // while (1) 
    // {
    //     time_t startTime = time(nullptr);
    //     if (currentTime - startTime >= 7) 
    //     {
    //     for (int i = 0; i < NUM_ASTEROIDS; i++) 
    //     {
    //         double x = disPos(gen) * screenWidth;
    //         double y = disPos(gen) * screenHeight;
    //         double size = disSize(gen);
    //         flyingObjects.push_back( new Asteroid(x, y, size, disPos(gen), disPos(gen)));
    //     }
    //     startTime = currentTime;
    //     }
    //     for (FlyingObject* flyingObject : flyingObjects) 
    //     {
    //         flyingObject->Move(m_screenWidth, m_screenHeight);
    //     }
    // }


}





void Model::majData() {
    spaceship->SetWarning(false); // Réinitialiser l'état d'alerte à chaque frame

    for (FlyingObject* flyingObject : flyingObjects) {
        flyingObject->Move(m_screenWidth, m_screenHeight);

        // Détecter les collisions avec les astéroïdes
        if (flyingObject->GetTypeName() == "Asteroid" && FlyingObject::Collide(spaceship, flyingObject)) {
            spaceship->SetWarning(true);
        }
    }
}


















void Model::appliqueAction(int input) {
    switch (input)
    {
        case SDLK_ESCAPE: 
            exit(0);        
            break;
        case SDLK_UP:
            // spaceship->SpeedUp(1);
            avancerVaisseau();
            break;
        case SDLK_DOWN:
            // spaceship->SpeedDown(1);
            decelerervaiseau();
            break;
        case SDLK_RIGHT:
            // spaceship->Rotate(-15.0);
            tournerVaisseau();
            break;
        case SDLK_LEFT:
            // spaceship->Rotate(15.0);
            tournerVaisseau();
            break;
        case SDLK_SPACE:
            missile->IsActive();
            tirerMissile();
            break;
        default:
            break;
    }
}

void Model::avancerVaisseau() {
    spaceship->SpeedUp(1);
}

void Model::decelerervaiseau() {
    spaceship->SpeedDown(1);
}

void Model::tournerVaisseau() {
    spaceship->Rotate(-15.0);
}

void Model::tirerMissile() 
{
    std::cout << "Attempting to fire missile." << std::endl;
if (!missile->IsActive()) { // Only fire if there isn't an active missile
        // Calculate the front position of the spaceship
        double frontX = spaceship->GetX() + std::cos(spaceship->GetAngle() * M_PI / 180.0) * spaceship->GetSize();
        double frontY = spaceship->GetY() + std::sin(spaceship->GetAngle() * M_PI / 180.0) * spaceship->GetSize();
        
        missile->SetX(frontX);
        missile->SetY(frontY);

        // Set the missile's speed
        missile->SetXSpeed(std::cos(spaceship->GetAngle() * M_PI / 180.0) * MISSILE_SPEED);
        missile->SetYSpeed(-std::sin(spaceship->GetAngle() * M_PI / 180.0) * MISSILE_SPEED);

        missile->Activate(); // Activate the missile
    }
}

// void Model::majData() {
//     std::cout << "Updating game objects." << std::endl;
//     for (FlyingObject* flyingObject : flyingObjects) {
//         flyingObject->Move(m_screenWidth, m_screenHeight);
//     }
// }

std::vector<FlyingObject*> Model::GetFlyingObjects() {
    return flyingObjects; // ou tout autre code pour retourner vos objets volants
}


void Model::CreateAsteroids(int numberOfAsteroids) {
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> disPos(0.0, 1.0);
    std::uniform_real_distribution<> disSize(50.0, 150.0);

    for (int i = 0; i < numberOfAsteroids; i++) {
        double x = rand() % (int)m_screenWidth;
        double y = rand() % (int)m_screenHeight;
        double angle = rand() % 360;
        double speed = rand() % 5 + 1;
        flyingObjects.push_back(new Asteroid(x, y, angle, disPos(gen), disPos(gen)));
    }
}



void Model::UpdateObjects() {
    for (FlyingObject* flyingObject : flyingObjects) {
        flyingObject->Move(m_screenWidth, m_screenHeight);
    }
}
