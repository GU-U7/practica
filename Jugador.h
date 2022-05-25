#pragma once

#include"Juego.h"

class Jugador{
    public:
    Jugador() = default;
    Jugador(Juego* j, const int& opcion){
        if(!j->opciones[opcion])
            j->opciones[opcion] = true;
    }
};