#pragma once

#include"Juego.h"

class Jugador{
    public:
    Jugador() = default;
    Jugador(Juego* juego, const int& i);
};

Jugador::Jugador(Juego* juego, const int& i){
    juego->seleccionarEstrategia(i);
}