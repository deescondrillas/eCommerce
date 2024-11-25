//descripción: atributos y métodos de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Token.hpp"
#include <cmath>
#include <ctime>

//builders
Token::Token(): limiteMax(0), pago(false) {
    //obteniendo el año y el mes
    time_t tiempo = time(nullptr);
    tm *const t = localtime(&tiempo);
    int anio = t->tm_year - 100;
    int mes = t->tm_mon + 1;
    //asignando una caducidad de un año
    cad = aTexto(mes) + '/' + aTexto(anio + 1);
    //generando una tarjeta aleatoria
    randNum = aTexto(aleatorio(16));
    randCod = aTexto(aleatorio(3));
}
Token::~Token() {

}
//setters
void Token::setLim(int limite) {
    limiteMax = limite;
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
bool Token::getPago() {
    return pago;
}
//methods
void Token::pagar() {
    pago = true;
}
int Token::aleatorio(int digitos) {
    time_t stamp = pow(time(nullptr),2);
    int potencia = pow(10, digitos);
    return stamp % potencia;
}
string Token::aTexto(int numero) {
    return to_string(numero);
}
