#include<iostream>
#include"Juego.h"
#include"Estrategia.h"
#include"Jugador.h"


int main(){
    Juego* juego = Juego::getInstance();

    juego->attachEstrategia(new Est_5_Pares);
    juego->attachEstrategia(new Est_5_Impares);
    juego->attachEstrategia(new Est_Primo);
    juego->attachEstrategia(new Est_3_Multiplos_10);
    juego->attachEstrategia(new Est_2_Multiplos_25);

    while(!juego->iniciarJuego()){
        for(int i = 0; i<juego->getNEstrategias(); i++){
            // Jugador player(juego, i);
            juego->seleccionarEstrategia(i);
        }
    }

}