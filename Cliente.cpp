//descripción: atributos y métodos de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Cliente.hpp"
#include <iostream>

using namespace std;

string Cliente::getUsuario() {
    return usuario;
}
string Cliente::getClave() {
    return clave;
}
double Cliente::getCapital() {
        return capital;
}
Tarjeta Cliente::getTarjeta() {
    return tarjeta;
}

void Cliente::setUsuario(string vUsuario) {
    usuario = vUsuario;
}
void Cliente::setClave(string vClave) {
    clave = vClave;
}
void Cliente::setCapital(double vCapital) {
    capital = vCapital;
}
void Cliente::setTarjeta(Tarjeta tarjet) {
    tarjeta = tarjet;
}
/*void Cliente::updateHistorial() {

}*/
