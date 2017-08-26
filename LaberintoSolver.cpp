#include "LaberintoSolver.h"


/**
 * Función recursiva para solucionar el laberinto
 * @param x Posición x de la celda actual
 * @param y Posición y de la celda actual
 * @return true si la celda es parte de la solución, sino false
 */
bool LaberintoSolver::solve(unsigned x, unsigned y) {
    m->visitar(x, y);
    callback(x, y, 1);
    callback(x, y, 0); //Encontre
    return false;
}

/**
 * Constructor de LaberintoSolver
 * @param callback Función callback que hace algo según si es solución o no la celda actual
 * @param m Laberinto a solucionar
 */
LaberintoSolver::LaberintoSolver(Funcion callback, MazeGenerator *m) {
    this->callback = callback;
    this->m = m;
    this->w = m->getW();
    this->h = m->getH();
}

/**
 * Ejecuta el solver desde la posición 0 0
 */
void LaberintoSolver::run() {
    solve(0, 0);
}