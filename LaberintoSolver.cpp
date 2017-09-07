#include "LaberintoSolver.h"

#include "Pila.h"

typedef struct {
    unsigned y;
    unsigned x;
}coord;


/**
 * Función recursiva para solucionar el laberinto
 * @param x Posición x de la celda actual
 * @param y Posición y de la celda actual
 * @return true si la celda es parte de la solución, sino false
 */
bool LaberintoSolver::solve(unsigned x, unsigned y) {
    Pila<coord> pila;
    bool termine = false;
    coord actual = {x, y};

    pila.push(actual);

    while(!pila.esVacia()){
        actual = pila.peek();

        m->visitar(x, y);
        callback(x, y, 1);

        if(x == w -1 && y == h -1) {
            callback(x, y, 2);
            return true;
        }
        int celda = m->getData(x, y);

        if((x == w - 1 && y == h - 1) || termine){
            callback(x, y, 2);
            termine = true;
            pila.pop();
        } else if((celda & 0x02) && y != h -1 && !m->esVisitado(x, y + 1)){
            coord tmp = {x, y + 1};
            pila.push(tmp);
        }else if((celda & 0x04) && x != w -1 && !m->esVisitado(x + 1, y)){
            coord tmp = {x + 1, y};
            pila.push(tmp);
        }else if((celda & 0x04) && y != 0 && !m->esVisitado(x, y - 1)){
            coord tmp = {x, y - 1};
            pila.push(tmp);
        }else if((celda & 0x04) && x != 0 && !m->esVisitado(x - 1, y)){
            coord tmp = {x - 1, y};
            pila.push(tmp);
        }else{
            callback(x, y, 0);
        }

    }

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