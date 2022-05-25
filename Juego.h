#pragma once

#include<iostream>
#include<list>
#include<random>
#include<vector>
#include"Estrategia.h"

class Juego{

    public:
    Juego(Juego &other) = delete;
    void operator=(const Juego &) = delete;
    static Juego* getInstance();

    bool iniciarJuego();
    void attachEstrategia(Estrategia* est);
    int getNEstrategias();
    void seleccionarEstrategia(const int &i);
    void mensaje(const int &i);

    protected:
    static Juego *juego;
    std::vector<Estrategia*> estrategias;
    std::vector<bool>opciones;
    std::random_device rd;

    Juego();
    int generarNumero();
    void victoria(const int& indice);

};

Juego* Juego::getInstance(){
    if(juego == nullptr)
        juego = new Juego();
    return juego;
}

void Juego::mensaje(const int &i){
    std::cout<<"Numero generado: "<<i<<std::endl;
}

Juego::Juego(){}

void Juego::seleccionarEstrategia(const int &i){
    if(!opciones[i])
        opciones[i] = true;
}

int Juego::getNEstrategias(){
    return estrategias.size();
}

void Juego::victoria(const int& indice){
    std::cout<<"El jugador con la estrategia Nro "<<indice+1<<" ha ganado";
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
        mensaje(generado);
        for(int i = 0; i<estrategias.size(); i++){
            if(estrategias[i]->ejecutar(generado)){
                victoria(i);
                return true;
            }
        }
    }
}

int Juego::generarNumero(){
    return rd()%100+1;
}