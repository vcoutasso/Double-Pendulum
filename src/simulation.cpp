#include <iostream>

#include "simulation.hpp"

Simulation::Simulation() {

    fps = 60;
    windowWidth = 1280;
    windowHeight = 720;
    timeStep = 0.01f;

    double_pendulums.push_back(DoublePendulum());

    createWindow();
}

void Simulation::createWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create window
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Rigid Double Pendulum Simulation", sf::Style::Default, settings);
}

void Simulation::clearWindow() {
    // A nice little color for our background
    window->clear(sf::Color(255, 229, 204));
}

// Main method of the simulation. This is where all the calculations are performed, as well as handling the elements of the window
void Simulation::start() {

    sf::Clock clock;

    while (window->isOpen()) {

        sf::Event event;

        // Event handling
        while (window->pollEvent(event)) {

            switch (event.type){
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q)
                        window->close();
                    break;
                default:
                    break;
            }
        }

        clearWindow();

        for (auto dp : double_pendulums)
            dp.draw(window);

        // Wait until next frame's turn
        if (clock.getElapsedTime().asSeconds() <= 1.f / fps)
            sf::sleep(sf::seconds((1.f / fps) - clock.getElapsedTime().asSeconds()));

        // Update window
        window->display();

        // Restart clock
        clock.restart();
    }
}

Simulation::~Simulation() {
    delete this->window;
}
