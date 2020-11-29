#include "simulation.hpp"

int main(int argc, char *argv[]) {

    Simulation sim;

    sim.start();

    // Get rid of warning while argc and argv arent being used
    (void)argc;
    (void)argv;

    return 0;
}
