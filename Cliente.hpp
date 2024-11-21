//descripción: definición de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas
#pragma once
using namespace std;
#include <string>
#include "Tarjeta.hpp"

class Cliente {
    public:
        Cliente();
        ~Cliente();
        string getName();
        string getEmail();
        string getPassword();
        string getAddress();
        void setName(string name);
        void setEmail(string email);
        void setPassword(string password);
        void setAddress(string address);
        void getData();
    private:
        string name;
        string password;
        string address;
        string email;
        Tarjeta tarjeta;
};