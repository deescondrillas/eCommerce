//descripción: atributos y métodos de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas
#include <iostream>
using namespace std;
#include <string>
#include "Cliente.hpp"
#include "Tarjeta.hpp"


string Cliente::getName() {
    return name;
}
string Cliente::getEmail() {
    return email;
}
string Cliente::getPassword() {
    //metodo para seguridad a la hora de obtener contraseña (autentificacion de 2 pasos, clave segura, etc)
    return password;
}
string Cliente::getAddress() {
    return address;
}
void Cliente::setName(string vName) {
    name = vName;
}
void Cliente::setEmail(string vEmail) {
    email = vEmail;
}
void Cliente::setPassword(string vPassword) {
    // si es primera vez, realizar la creación. Crear metodo para actualizar la conteraseña.
    password = vPassword;
}
void Cliente::setAddress(string vAddress) {
    address = vAddress;
}
void Cliente::getData() {
    cout << "Nombre del Cliente: " << getName() << ". Email: " << getEmail() << ". Contraseña: " << getPassword() << ". Dirección: " << getAddress() << endl;
}
