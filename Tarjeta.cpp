//descripción: atributos y métodos de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Tarjeta.hpp"
#include <iostream>

//builders
Tarjeta::Tarjeta(): num("NULL"), cod("NULL"), cad("NULL") {

}
Tarjeta::Tarjeta(string _num, string _cod, string _cad): num(_num), cod(_cod), cad(_cad) {

}
Tarjeta::~Tarjeta() {

}
//setters
void Tarjeta::setNum(string vNum) {
    num = vNum;
}
void Tarjeta::setCod(string vCod) {
    cod = vCod;
}
void Tarjeta::setCad(string vCad) {
    cad = vCad;
}
//getters
string Tarjeta::getNum() {
   return num;
}
string Tarjeta::getCod() {
    return cod;
}
string Tarjeta::getCad() {
    return cad;
}
Token Tarjeta::getToken() {
    return randTarj;
}
//methods
void Tarjeta::imprime() {
    cout << "Número de tarjeta:  " << num << endl;
    cout << "Código de tarjeta:  " << cod << endl;
    cout << "Fecha de tarjeta:   " << cad << endl;
}
void Tarjeta::setLim(double maximo) {
    randTarj.setLim(maximo);
}
