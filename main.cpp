//descripción: programa principal
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Cliente.cpp"
    // #include <string>
    // #include <iostream>
#include <stdlib.h>

    // using namespace std;

void clear();
void label(string);
void principal();
void comprador();
void crearCuenta();
void realizarPago();
void editarDatos();
void vendedor();
void realizarCobro();

int main() {
    principal();
    return 0;
}

void clear() {
    #ifdef _WIN32
        system("clc");
    #endif
    #ifdef __APPLE__
        system("clear");
    #endif
    #ifdef __linux__
        system("clear");
    #endif
    #ifdef __unix__
        system("clear");
    #endif
}

void label(string title) {
    int len = title.length();
    string bar = " --";
    for (int i = 0; i < len; i++) {
        bar += '-';
    }

    cout << '\n' << bar << endl;
    cout << "| " << title << " |" << endl;
    cout << bar << '\n' << endl;
}

void principal() {
    clear();
    string seleccion;
    label("Principal");

    cout << "Bienvenido al sistema de pagos seguros. Por favor, identifíquese." << endl;
    cout << "   1. Soy cliente" << endl;
    cout << "   2. Soy vendedor" << endl;
    cout << "   3. Salir del sistema" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;

    while (seleccion != "1" && seleccion != "2" && seleccion != "3") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    int option = stoi(seleccion);
    switch (option) {
        case 1:
            comprador();
            break;
        case 2:
            vendedor();
            break;
        case 3:
            clear();
            label("Muchas gracias");
            break;
        default:
            cout << "Error";
            break;
    }
}

void comprador() {
    clear();
    string seleccion;
    label("Cliente");

    cout << "¿Qué desea hacer?" << endl;
    cout << "   1. Crear una cuenta" << endl;
    cout << "   2. Realizar un pago" << endl;
    cout << "   3. Editar mis datos" << endl;
    cout << "   4. Regresar al menú" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;

    while (seleccion != "1" && seleccion != "2" && seleccion != "3" && seleccion != "4") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    int option = stoi(seleccion);
    switch (option) {
        case 1:
            crearCuenta();
            break;
        case 2:
            realizarPago();
            break;
        case 3:
            editarDatos();
            break;
        case 4:
            principal();
            break;
        default:
            cout << "Error";
            break;
    }
}

void vendedor() {
    clear();
    string seleccion;
    label("Vendedor");

    cout << "¿Qué desea hacer?" << endl;
    cout << "   1. Realizar un cobro" << endl;
    cout << "   2. Regresar al menú" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;
    while (seleccion != "1" && seleccion != "2") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    int option = stoi(seleccion);
    switch (option) {
        case 1:
            realizarCobro();
            break;
        case 2:
            principal();
            break;
        default:
            cout << "Error";
            break;
    }
}

void crearCuenta() {
    clear();
    string _usuario, _clave, _capital;
    string _num, _cod, _cad;
    label("Crear una cuenta");

    cout << "A continuación, por favor ingrese la información solicitada o 'c' para cancelar." << endl;
    cout << "   Nombre de usuario:  ";
    cin >> _usuario;
    if (_usuario == "c") {
        comprador();
    }
    else {
        cout << "   Contraseña:         ";
        cin >> _clave;
        cout << "   Dinero disponible:  ";
        cin >> _capital;
    }
}

void realizarPago(){
    clear();
    int maximo;
    label("Realizar un pago");

    cout << "Próximamente" << endl;
}

void editarDatos() {
    clear();
    string seleccion;
    label("Editar mis datos");

    cout << "Próximamente" << endl;
}

void realizarCobro() {
    clear();
    string _num, _cod, _cad;
    label("Realizar un cobro");

    cout << "Próximamente" << endl;
}
