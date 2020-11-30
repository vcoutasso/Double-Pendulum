#include <cmath>
#include <armadillo>

#include "double_pendulum.hpp"

/*
* Default constructor for a system with two identical pendulums of size (20, 200), uniforn weight distribution (cenmter of mass at (10, 100))
* and initial thetas of 90º with respect to the downward vertical position.
* The pivots are placed so that both the pivots the center of mass are colinear (one at the top, the other at the bottom of pendulum 1).
*/
DoublePendulum::DoublePendulum() {

    gravity = 9.81;

    theta1 = M_PI / 2;
    theta2 = M_PI / 2;

    R1Length = 200;
    R2Length = 200;

    m1 = 10;
    m2 = 10;

    R1 = { R1Length * sin(theta1), -R1Length * cos(theta1) };
    R2 = { R2Length * sin(theta2), -R2Length * cos(theta2) };

    // Offset of the pivot (y axis)
    double offset = 15;

    // Place pivots exactly at the pendulum's x axis center, and respecting the offset in the y axis
    P1 = { R1Length * 0.05, offset };
    P2 = { R1Length * 0.05, R1Length - offset };

    L1 = { fabs(P1[0] - P2[0]), fabs(P1[1] - P2[1]) };
    L1Length = arma::norm(L1);

    X1 = { R1Length * 0.1 / 2, R1Length / 2 };
    X2 = L1 + R2;

    phi = acos(arma::dot(L1, R1) / (arma::norm(L1) * arma::norm(R1)));

    X1 = R1;
    X2 = L1 + R2;

    I1 = 0;
    I2 = 0;

    sf::Color colorGray(128, 128, 128);

    // Initialize graphical elements that represent the system
    pend1.setSize(sf::Vector2f(R1Length * 0.1, R1Length));
    pend1.setOrigin(P1[0], P1[1]);
    pend1.setFillColor(colorGray);
    pend1.setPosition(1280 / 2, 720 / 2);
    pend1.setOutlineColor(sf::Color::Black);
    pend1.setOutlineThickness(2);

    pivot1.setRadius(3);
    pivot1.setOutlineThickness(1.25);
    pivot1.setFillColor(colorGray);
    pivot1.setOutlineColor(sf::Color::Black);
    pivot1.setOrigin(pivot1.getRadius(), pivot1.getRadius());

    pivot2.setRadius(3);
    pivot2.setOutlineThickness(1.25);
    pivot2.setFillColor(colorGray);
    pivot2.setOutlineColor(sf::Color::Black);
    pivot2.setOrigin(pivot2.getRadius(), pivot2.getRadius());

    pend2.setSize(sf::Vector2f(R2Length * 0.1, R2Length));
    pend2.setOrigin(P2[0], R1Length - P2[1]);
    pend2.setFillColor(colorGray);
    pend2.setOutlineColor(sf::Color::Black);
    pend2.setOutlineThickness(2);

}

void DoublePendulum::draw(sf::RenderWindow *window) {
    
    // Change positions according to attributes
    pend1.setRotation(-theta1 * 180 / M_PI); // Negative angles to match the references' illustration
    pend2.setRotation(-theta2 * 180 / M_PI);
    pivot1.setPosition(pend1.getTransform().transformPoint(P1[0], P1[1]));
    pivot2.setPosition(pend1.getTransform().transformPoint(P2[0], P2[1]));
    pend2.setPosition(pend1.getTransform().transformPoint(P2[0], P2[1]));

    // Draw new state on `window`
    window->draw(pend1);
    window->draw(pend2);
    window->draw(pivot1);
    window->draw(pivot2);
}
