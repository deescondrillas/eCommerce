//descripción: programa principal
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Cliente.cpp"
#include <stdlib.h>

void clear();
void label(string);
void principal();
void comprador();
void vendedor();

int main() {
    //
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

    cout << "Bienvenido al sistema de pagos seguros. Por favor, identifíquese" << endl;
    cout << "   1. Soy cliente" << endl;
    cout << "   2. Soy vendedor" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;
    while (seleccion != "1" && seleccion != "2") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    if (seleccion == "1") {
        comprador();
    }
    else {
        vendedor();
    }
}

void comprador() {
    clear();
    label("Cliente");
}

void vendedor() {
    clear();
    label("Vendedor");
}
