#include<iostream>
#include"Juego.h"
#include"Estrategia.h"
#include"Jugador.h"

// INICIALIZAR EL SINGLETON
Juego * Juego::juego = 0;

int main(){
    // OBTENER SINGLETON
    Juego* juego = Juego::getInstance();

    std::cout<<"Bienvenido al juego, las estrategias son las siguientes:\n1. Ganar por 5 pares\n2. Ganar por 5 impares\n3. Ganar por numero primo\n4. Ganar por 3 multiplos de 10\n5. Ganar por 2 multiplos de 25"<<std::endl;

    // ANHADIR LAS ESTRATEGIAS
    juego->attachEstrategia(new Est_5_Pares);
    juego->attachEstrategia(new Est_5_Impares);
    juego->attachEstrategia(new Est_Primo);
    juego->attachEstrategia(new Est_3_Multiplos_10);
    juego->attachEstrategia(new Est_2_Multiplos_25);

    // ESPERAR HASTA QUE TODOS HAYAN SELECCIONADO LAS OPCIONES
    while(!juego->iniciarJuego()){
        // CREACION DE JUGADORES
        for(int i = 0; i<juego->getNEstrategias(); i++){
            Jugador player(juego, i);
        }
    }

}