#ifndef __SIM_H_
#define __SIM_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "double_pendulum.hpp"

typedef struct {

} Pendulum;

class Simulation {
    private:
        /** Attributes **/

        // Vector containing all independent double pendulum systems that will be part of the simulation
        std::vector<DoublePendulum> double_pendulums;

        /* Simulation parameters */

        // SFML window parameters
        int windowWidth;
        int windowHeight;

        // SFML window
        sf::RenderWindow *window;

        // Target FPS
        int fps;

        // Time step
        float timeStep;

        /** Methods **/

        // Creates the SFML window and assigns it to the `window` attribute
        void createWindow();

        // Clear window painting it with a nice beige color
        void clearWindow();


    public:

        // Default constructor
        Simulation();
        // Parametrized constructor
        Simulation(int a);
        // Default destructor
        ~Simulation();

        void start();
   
};

#endif // __SIM_H_
