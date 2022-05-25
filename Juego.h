#pragma once

class Juego{

    public:
    Juego(Juego &other) = delete;
    void operator=(const Juego &) = delete;
    static Juego* getInstance();
    
    private:
    Juego() = default;
    static Juego *juego;
};

Juego* Juego::getInstance(){
    if(juego == nullptr)
        juego = new Juego();
    return juego;
}