#ifndef LaberintoSolver_H
#define LaberintoSolver_H

#include "MazeGenerator.h"

/**
 * Puntero a función que se va a utilizar como callback
 */
typedef void (*Funcion)(unsigned x, unsigned y, int valor);

class LaberintoSolver {
private:
    Funcion callback;
    MazeGenerator *m;
    unsigned w, h;

public:

    LaberintoSolver(Funcion callback, MazeGenerator *m);

    bool solve(unsigned x, unsigned y);

    void run();
};

#endif