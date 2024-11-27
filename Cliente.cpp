//descripción: atributos y métodos de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Cliente.hpp"
#include <iostream>

using namespace std;

//builders
Cliente::Cliente(): usuario("NULL"), clave("NULL"), capital(0), tarjeta(Tarjeta()) {

}
Cliente::Cliente(string _usuario, string _clave, double _capital, Tarjeta _tarjeta): usuario(_usuario), clave(_clave), capital(_capital), tarjeta(_tarjeta) {

}
Cliente::~Cliente() {

}
//setters
void Cliente::setUsuario(string vUsuario) {
    usuario = vUsuario;
}
void Cliente::setClave(string vClave) {
    clave = vClave;
}
void Cliente::setCapital(double vCapital) {
    capital = vCapital;
}
void Cliente::setTarjeta(string vNum, string vCod, string vCad) {
    tarjeta.setNum(vNum);
    tarjeta.setCod(vCod);
    tarjeta.setCad(vCad);
}
void Cliente::setLim(double maximo){
    tarjeta.setLim(maximo);
}
//getters
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
//methods
void Cliente::updateHistorial(int vCompra) {
    int i = 0;
    while (historial[i] != 0) {
        i++;
    }
    if (i == 0) {
        i = vCompra;
    }
}
void Cliente::printHistorial() {
    int i = 0;
    while (historial[i] != 0) {
        cout << "Monto de compra: " << historial[i] << endl;
    }
}
void Cliente::printDatos() {
    cout << "Usuario:            " << usuario << endl;
    cout << "Contraseña:         " << clave << endl;
    cout << "Capital disponible: " << capital << endl;

    tarjeta.imprime();

    cout << "Historial de compras: " << endl;
    //printHistorial();
}
