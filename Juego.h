#pragma once

#include<random>
#include<Estrategia.h>
#include<list>
#include<vector>
#include<iostream>

class Juego{

    public:
    Juego(Juego &other) = delete;
    void operator=(const Juego &) = delete;
    static Juego* getInstance();

    bool iniciarJuego();
    void attachEstrategia(Estrategia* est);

    private:
    std::vector<Estrategia*> estrategias;
    std::vector<bool>opciones;
    std::random_device rd;

    Juego() = default;
    int generarNumero();
    void victoria(const int& indice);

    static Juego *juego;
};

void Juego::victoria(const int& indice){
    std::cout<<"El jugador con la estrategia Nro "<<indice<<" ha ganado";
}

void Juego::attachEstrategia(Estrategia* est){
    estrategias.push_back(est);
    opciones.push_back(false);
}

bool Juego::iniciarJuego(){
    for(int i = 0; i<opciones.size(); i++){
        if(!opciones[i])
            return false;
    }

    while(1){
        int generado = generarNumero();
        for(int i = 0; i<estrategias.size(); i++){
            if(estrategias[i]->ejecutar(generado)){
                victoria(i);
                return true;
            }
        }
    }
}

Juego* Juego::getInstance(){
    if(juego == nullptr)
        juego = new Juego();
    return juego;
}

int Juego::generarNumero(){
    return rd()%100+1;
}