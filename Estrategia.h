class Estrategia{
    public:
    virtual bool ejecutar(const int& num) = 0;
};

class Estrategia_Contador:public Estrategia{
    protected:
    int contador = 0;
};

class Est_5_Pares: public Estrategia_Contador{
    public:
    virtual bool ejecutar(const int& num) override;
};

bool Est_5_Pares::ejecutar(const int& num){
    if(num%2==0) 
        contador++;
    return contador == 5;
}

class Est_5_Impares: public Estrategia_Contador{
    public:
    virtual bool ejecutar(const int& num) override;
};

bool Est_5_Impares::ejecutar(const int& num){
    if(num%2==1) 
        contador++;
    return contador == 5;
}

class Est_Primo: public Estrategia{
    public:
    virtual bool ejecutar(const int& num) override;
};

bool Est_Primo::ejecutar(const int& num){
    for(int i = 2; i<num; i++){
        if(num%i == 0)
            return false;
    }
    return true;
}

class Est_3_Multiplos_10: public Estrategia_Contador{
    public:
    virtual bool ejecutar(const int& num) override;
};

bool Est_3_Multiplos_10::ejecutar(const int& num){
    if(num%10==0) 
        contador++;
    return contador == 3;
}

class Est_2_Multiplos_25: public Estrategia_Contador{
    public:
    virtual bool ejecutar(const int& num) override;
};

bool Est_2_Multiplos_25::ejecutar(const int& num){
    if(num%25==0) 
        contador++;
    return contador == 2;
}