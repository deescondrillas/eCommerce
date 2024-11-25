//descripción: programa principal
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Cliente.cpp"

int main() {
    time_t stamp = time(nullptr);
    cout << ctime(&stamp);

    time_t tiempo = time(nullptr);
    tm *const t = localtime(&tiempo);
    int anio = t->tm_year - 100;
    int mes = t->tm_mon + 1;
    cout << anio << ' ' << mes;
    return 0;
}
