#ifndef __DOUBLE_PENDULUM_H_
#define __DOUBLE_PENDULUM_H_

#include <SFML/Graphics.hpp>
#include <armadillo>

class DoublePendulum {
    private:


        // Representation of the pendulums
        sf::RectangleShape pend1;
        sf::RectangleShape pend2;

        // Representation of the pivots
        sf::CircleShape pivot1;
        sf::CircleShape pivot2;

        double gravity;

        // Pivot vector coordinates
        arma::vec P1;
        arma::vec P2;

        // Center of mass vector coordinates
        arma::vec X1;
        arma::vec X2;

        // Vector from pivot to center of mass
        arma::vec R1;
        arma::vec R2;
        // Respective lengths
        double R1Length;
        double R2Length;

        // Angle at pivot between R and the downward vertical position [rad]
        double theta1;
        double theta2;

        // Vector from pivot 1 to pivot 2
        arma::vec L1;
        // Respective length
        double L1Length;

        // Angle from R1 to L1 [rad]
        double phi;

        // Mass of the pendulums [kg]
        double m1;
        double m2;

        // Rotation interia about the center of mass of the pendulums
        double I1;
        double I2;


    public:

        // Default constructor
        DoublePendulum();

};

#endif // __DOUBLE_PENDULUM_H_
