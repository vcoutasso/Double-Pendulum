#include <iostream>
#include <cmath>
#include <armadillo>

#include "double_pendulum.hpp"

DoublePendulum::DoublePendulum() {

    gravity = 9.81;

    theta1 = M_PI;
    theta2 = M_PI;

    R1Length = 150;
    R2Length = 150;

    m1 = 10;
    m2 = 10;

    R1 = { R1Length * sin(theta1), -R1Length * cos(theta1) };
    R2 = { R2Length * sin(theta2), -R2Length * cos(theta2) };

    P1 = { 10, 15 };
    P2 = { 10, 135 };

    //L1 = { L1Length * sin(theta1 + phi), -L1Length * cos(theta1 + phi) };
    L1 = { fabs(P1[0] - P2[0]), fabs(P1[1] - P2[1]) };
    L1Length = arma::norm(L1);

    X1 = { 10, 75 };
    X2 = L1 + R2;

    phi = acos(arma::dot(L1, R1) / (arma::norm(L1) * arma::norm(R1)));

    X1 = R1;
    X2 = L1 + R2;

    I1 = 0;
    I2 = 0;

}
