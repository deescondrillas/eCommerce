//descripción: programa principal
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

//inclusión de clases
#include "Cliente.cpp"

//librerías adicionales
#include <stdlib.h>

//Variables globales
Cliente Clientes[16];
int contador = 0;
//Definición de funciones

//clear limpia la terminal
void clear();

//label imprime títulos con un estilo predefinido
void label(string);

//principal genera el menú principal
void principal();

//comprador genera el menú para el cliente
void comprador();

//crearCuenta edita un objeto de Clientes[] para crear un usuario
void crearCuenta();

//realizarPago permite crear una tarjeta digital temporal (class Token)
void realizarPago();

//editarDatos permite que el usuario cambie o muestre sus datos
void editarDatos();

//mostrarDatos muestra todos los datos del usuario
void mostrarDatos(int);

//cambiarDatos cambia los datos del usuario
void cambiarDatos(int);

//vendedor genera el menú para el vendedor
void vendedor();

//realizarCobro permite al vendedor cobrar
void realizarCobro();

//buscor recibe un nombre de usuario y busca el índice de un objeto en Clientes que coincida
//de lo contrario un 404 not found
int buscador(string);

//estatus: - en proceso
int main() {
    principal();
    return 0;
}

//estatus: - terminada
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

//estatus: - terminada
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

//estatus: - terminada
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

//estatus: - terminada
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

//estatus: - terminada
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

//estatus: - terminado
void crearCuenta() {
    clear();
    string _usuario, _clave;
    double _capital;
    string _num, _cod, _cad;
    label("Crear una cuenta");

    cout << "A continuación ingrese la información solicitada, o 'c' para cancelar." << endl;
    cout << "   Nombre de usuario (sin espacios):   ";
    cin >> _usuario;
    if (_usuario == "c") {
        comprador();
    }
    else {

        cout << "   Contraseña:                         ";
        cin >> _clave;

        cout << "   Dinero disponible (numérico):       ";
        cin >> _capital;
        Clientes[contador].setUsuario(_usuario);
        Clientes[contador].setClave(_clave);
        Clientes[contador].setCapital(_capital);

        cout << "\n   Número de tarjeta (16 dígitos):     ";
        cin >> _num;
        while (_num.length() != 16) {
            cout << "\nTamaño incorrecto, intente de nuevo";
            cout << "\n   Número de tarjeta (16 dígitos):     ";
            cin >> _num;
        }

        cout << "   Código (CVV, tres dígitos):         ";
        cin >> _cod;

        cout << "   Fecha de caducidad 'xx/xx':         ";
        cin >> _cad;
        Clientes[contador].setTarjeta(_num, _cod, _cad);

        cout << "\nCuenta creada. Escriba algo para regresar al menú anterior." << endl;
        cin >> _cod;
        contador++;
        comprador();
    }
}

//estatus: - pendiente
void realizarPago(){
    clear();
    int maximo;
    label("Realizar un pago");

    cout << "Próximamente" << endl;
}

//estatus: - terminada
void editarDatos() {
    clear();
    int quien;
    string seleccion, _usuario, _clave;
    label("Editar mis datos");
    //Menú de la sección
    cout << "¿Qué desea hacer?" << endl;
    cout << "   1. Mostrar mis datos" << endl;
    cout << "   2. Cambiar mis datos" << endl;
    cout << "   3. Regresar al menú" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;
    while (seleccion != "1" && seleccion != "2" && seleccion != "3") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    int option = stoi(seleccion);
    if (option == 3) {
        comprador();
    }
    else {
        //Pedir usuario
        cout << "\nNombre de usuario:   ";
        cin >> _usuario;
        //validar usuario
        while (buscador(_usuario) == 404 && _usuario != "c") {
            cout << "\nEste nombre de usuario no está registrado. Escriba una opción válida o 'c' para cancelar." << endl;
            cout << "Nombre de usuario:   ";
            cin >> _usuario;
            if (_usuario == "c") {
                comprador();
            }
        }
        if (_usuario != "c") {
            cout << "Contraseña:          ";
            cin >> _clave;
            while (_clave != Clientes[buscador(_usuario)].getClave() && _clave != "c") {
                cout << "\nContraseña incorrecta. intente de nuevo o escriba 'c' para cancelar." << endl;
                cout << "Contraseña:          ";
                cin >> _clave;
                if (_clave == "c") {
                    comprador();
                }
            }

            switch (option) {
                case 1:
                    mostrarDatos(buscador(_usuario));
                    break;
                case 2:
                    cambiarDatos(buscador(_usuario));
                    break;
                default:
                    cout << "Error";
                    break;
            }
        }
    }
}

//estatus: - casi terminada (falta historial)
void mostrarDatos(int queCliente) {
    clear();
    string wait;
    label("Mis datos");
    //mostrar los datos
    Clientes[queCliente].printDatos();
    cout << "\nEscriba algo para regresar al menú principal." << endl;
    cin >> wait;
    principal();
}

//estatus: - pendiente
void cambiarDatos(int queCliente) {
    cout << "proximamente" << endl;
}

//estatus: - pendiente
void realizarCobro() {
    clear();
    string _num, _cod, _cad;
    label("Realizar un cobro");

    cout << "Próximamente" << endl;
}

//estatus: - terminada
int buscador(string _nombre) {
    for (int i = 0; i < 16; i++) {
        if (_nombre == Clientes[i].getUsuario()) {
            return i;
        }
    }
    return 404;
}
