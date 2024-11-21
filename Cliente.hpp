//descripción: definición de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#pragma once
#include "Tarjeta.cpp"

using namespace std;

class Cliente {
    public:
        Cliente();
        Cliente(string, string, double, Tarjeta);
        ~Cliente();

        string getUsuario();
        string getClave();
        double getCapital();
        Tarjeta getTarjeta();

        void setUsuario(string);
        void setClave(string);
        void setCapital(double);
        void setTarjeta(Tarjeta);

        void printCuenta();
        void updateHistorial();
        void printHistorial();

    private:
        string usuario;
        string clave;
        double capital;
        double historial[10];
        Tarjeta tarjeta;
};
