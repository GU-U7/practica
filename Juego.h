#pragma once

#include<random>

class Juego{

    public:
    Juego(Juego &other) = delete;
    void operator=(const Juego &) = delete;
    static Juego* getInstance();
    int generarNumero();

    private:
    Juego() = default;
    static Juego *juego;
    std::random_device rd;
};

Juego* Juego::getInstance(){
    if(juego == nullptr)
        juego = new Juego();
    return juego;
}

int Juego::generarNumero(){
    return rd()%100+1;
}