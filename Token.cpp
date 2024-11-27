//descripción: atributos y métodos de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Token.hpp"
#include <iostream>
#include <cmath>
#include <ctime>

//builders
Token::Token(): randNum("NULL"), randCod("NULL"), cad("NULL"), limiteMax(0), proceso(false), timestamp(0) {

}
Token::~Token() {

}
//getters
string Token::getNum() {
    return randNum;
}
string Token::getCod() {
    return randCod;
}
string Token::getCad() {
    return cad;
}
int Token::getLim() {
    return limiteMax;
}
bool Token::getProceso() {
    return proceso;
}
int Token::getTimestamp() {
    return timestamp;
}
//methods
void Token::pagar(double cantidad) {
    //obteniendo el año y el mes
    time_t tiempo = time(nullptr);
    tm *const t = localtime(&tiempo);
    int anio = t->tm_year - 100;
    int mes = t->tm_mon + 1;
    //checar condición
    if (proceso) {
        cout << "\nYa hay un token activo. Espere " << 120 + timestamp - tiempo << " segundos más." << endl;
    }
    else {
        //asignando una caducidad de un año
        cad = aTexto(mes) + '/' + aTexto(anio + 1);
        //generando una tarjeta aleatoria
            //corregir num
        randNum = aTexto(aleatorio(16));
        randCod = aTexto(aleatorio(3));
        timestamp = tiempo;
        proceso = true;
        limiteMax = cantidad;
    }
}
int Token::aleatorio(int digitos) {
    time_t stamp = time(nullptr);
    long long int randomNum = pow(stamp, 2);
    long long int potencia = pow(10, digitos);
    return randomNum % potencia;
}
string Token::aTexto(int numero) {
    return to_string(numero);
}
void Token::printToken() {
    cout << "\nNúmero de token:   " << randNum << endl;
    cout << "Clave temporal:    " << randCod << endl;
    cout << "Caducidad:         " << cad << endl;
    cout << "Cantidad pagada:   " << limiteMax << endl;
}
