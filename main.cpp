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

//registrarDatos imprime el nombre de usuario de todos los registrados
void registroUsuarios();

//buscor recibe un nombre de usuario y busca el índice de un objeto en Clientes que coincida
//de lo contrario un 404 not found
int buscador(string);

//estatus: terminada
int main() {
    principal();
    return 0;
}

//estatus: terminada
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

//estatus: terminada
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

//estatus: terminada
void principal() {
    clear();
    string seleccion;
    label("Cliente");

    cout << "¿Qué desea hacer?" << endl;
    cout << "   1. Crear una cuenta" << endl;
    cout << "   2. Realizar un pago" << endl;
    cout << "   3. Mis datos" << endl;
    cout << "   4. Registro de usuarios" << endl;
    cout << "   5. Salir del sistema" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;

    while (seleccion != "1" && seleccion != "2" && seleccion != "3" && seleccion != "4" && seleccion != "5") {
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
            registroUsuarios();
            break;
        case 5:
            break;
        default:
            cout << "Error";
            break;
    }
}

//estatus: terminada
void crearCuenta() {
    clear();
    string _usuario, _clave, convert;
    double _capital;
    string _num, _cod, _mes, _anio, _cad;
    label("Crear una cuenta");

    cout << "A continuación ingrese la información solicitada, o 'c' para cancelar" << endl;
    cout << "   Nombre de usuario (sin espacios):   ";
    cin >> _usuario;
    if (_usuario == "c") {
        principal();
    }
    else {

        cout << "   Contraseña:                         ";
        cin >> _clave;

        cout << "   Saldo (numérico):                   ";
        cin >> convert;
        _capital = stoi(convert);
        while (_capital < 0) {
            cout << "No puede introducir cantidades negativas.";
            cout << "\n   Dinero disponible (numérico):       ";
            cin >> convert;
            _capital = stoi(convert);
        }

        Clientes[contador].setUsuario(_usuario);
        Clientes[contador].setClave(_clave);
        Clientes[contador].setCapital(_capital);

        cout << "\n   Número de tarjeta (16 dígitos):     ";
        cin >> _num;
        while (_num.length() != 16) {
            cout << "Tamaño incorrecto, intente de nuevo";
            cout << "\n   Número de tarjeta (16 dígitos):     ";
            cin >> _num;
        }

        cout << "   Código (CVV, tres dígitos):         ";
        cin >> _cod;
        while (_cod.length() != 3) {
            cout << "Código incorrecto, intente de nuevo";
            cout << "\n   Código (CVV, tres dígitos):         ";
            cin >> _cod;
        }

        cout << "   Fecha de caducidad (mes):           ";
        cin >> _mes;
        while (_mes.length() != 2 || stoi(_mes) < 1 || stoi(_mes) > 12) {
            cout << "Mes no válido, intente de nuevo." << endl;
            cout << "   Fecha de caducidad (mes):           ";
            cin >> _mes;
        }

        cout << "   Fecha de caducidad (año):           ";
        cin >> _anio;
        while (_anio.length() != 2 || stoi(_anio) < 25) {
            cout << "Año no válido, intente de nuevo." << endl;
            cout << "   Fecha de caducidad (año):           ";
            cin >> _anio;
        }

        _cad = _mes + "/" + _anio;
        Clientes[contador].setTarjeta(_num, _cod, _cad);

        cout << "\nCuenta creada. Escriba algo para regresar al menú anterior." << endl;
        cin >> _cod;
        contador++;
        principal();
    }
}

//estatus: terminada
void realizarPago() {
    clear();
    double _monto;
    int decision;
    string _usuario, _clave, convert;
    time_t tiempo = time(nullptr);

    label("Realizar un pago");

    //cliente
    cout << "\nNombre de usuario:   ";
    cin >> _usuario;
    while (buscador(_usuario) == 404 && _usuario != "c") {
        cout << "\nEste nombre de usuario no está registrado. Escriba una opción válida o 'c' para cancelar" << endl;
        cout << "Nombre de usuario:   ";
        cin >> _usuario;
        if (_usuario == "c") {
            principal();
        }
    }
    if (_usuario != "c") {
        cout << "Contraseña:          ";
        cin >> _clave;
        while (_clave != Clientes[buscador(_usuario)].getClave() && _clave != "c") {
            cout << "\nContraseña incorrecta. intente de nuevo o escriba 'c' para cancelar" << endl;
            cout << "Contraseña:          ";
            cin >> _clave;
            if (_clave == "c") {
                break;
            }
        }

        //pago
        if (60 - tiempo + Clientes[buscador(_usuario)].getTarjeta().getToken().getTimestamp() < 0) {
            //Crear Token
            cout << "Cantidad a pagar:    ";
            cin >> convert;
            _monto = stoi(convert);
            //revisar que el monto sea válido
            while (_monto > Clientes[buscador(_usuario)].getCapital() || _monto < 0) {
                cout << "El límite máximo no puede ser superior al saldo total ni negativo. Ingrese una cantidad válida" << endl;
                cout << "Cantidad a pagar:    ";
                cin >> convert;
                _monto = stoi(convert);
            }
            //asignar valor y pagar
            Clientes[buscador(_usuario)].pagar(_monto);
            cout << "\nSe creó un token temporal de 60 segundos para realizar el pago" << endl;
            Clientes[buscador(_usuario)].getTarjeta().getToken().printToken();
            double cobro = Clientes[buscador(_usuario)].getCapital();
            Clientes[buscador(_usuario)].setCapital(cobro - _monto);
            Clientes[buscador(_usuario)].updateHistorial(_monto);
        }
        else {
            //Imprimir ya hay
            cout << "\nYa hay un token activo. Espere " << 60 - tiempo + Clientes[buscador(_usuario)].getTarjeta().getToken().getTimestamp() << " segundos más" << endl;
        }

        cout << "\nEscriba algo para regresar al menú" << endl;
        cin >> _usuario;
    }
    principal();
}

//estatus: terminada
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
        principal();
    }
    else {
        //Pedir usuario
        cout << "\nNombre de usuario:   ";
        cin >> _usuario;
        //validar usuario
        while (buscador(_usuario) == 404 && _usuario != "c") {
            cout << "\nEste nombre de usuario no está registrado. Escriba una opción válida o 'c' para cancelar" << endl;
            cout << "Nombre de usuario:   ";
            cin >> _usuario;
            if (_usuario == "c") {
                principal();
            }
        }
        if (_usuario != "c") {
            cout << "Contraseña:          ";
            cin >> _clave;
            while (_clave != Clientes[buscador(_usuario)].getClave() && _clave != "c") {
                cout << "\nContraseña incorrecta. intente de nuevo o escriba 'c' para cancelar" << endl;
                cout << "Contraseña:          ";
                cin >> _clave;
                if (_clave == "c") {
                    principal();
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

//estatus: terminada
void mostrarDatos(int queCliente) {
    clear();
    string wait;
    label("Mis datos");
    //mostrar los datos
    Clientes[queCliente].printDatos();
    cout << "\nEscriba algo para regresar al menú principal" << endl;
    cin >> wait;
    principal();
}

//estatus: terminada
void cambiarDatos(int queCliente) {
    clear();
    double _capital;
    string seleccion, _num, _cod, _mes, _anio, _cad, convert;
    label("Cambiar datos");

    cout << "¿Qué dato desea cambiar?" << endl;
    cout << "   1. Usuario" << endl;
    cout << "   2. Contraseña" << endl;
    cout << "   3. Capital" << endl;
    cout << "   4. Tarjeta" << endl;
    cout << "Introduzca una opción: ";
    cin >> seleccion;

    while (seleccion != "1" && seleccion != "2" && seleccion != "3" && seleccion != "4") {
        cout << "\nIntroduzca una opción válida: ";
        cin >> seleccion;
    }

    int option = stoi(seleccion);
    switch (option) {
    //cambiar usuario
        case 1:
            cout << "   Nuevo usuario: ";
            cin >> seleccion;
            Clientes[queCliente].setUsuario(seleccion);
            break;
    //cambiar contraseña
        case 2:
            cout << "   Nueva contraseña: ";
            cin >> seleccion;
            Clientes[queCliente].setClave(seleccion);
            break;
    //cambiar saldo
        case 3:
            cout << "   Modificar saldo: ";
            cin >> convert;
            _capital = stoi(convert);
            while (_capital < 0) {
                cout << "No puede introducir cantidades negativas.";
                cout << "\n   Dinero disponible (numérico):       ";
                cin >> convert;
                _capital = stoi(convert);
            }
            break;
        //cambiar tarjeta
        case 4:
            cout << "\n   Nuevo número de tarjeta (16 dígitos):     ";
            cin >> _num;
            while (_num.length() != 16) {
                cout << "\nTamaño incorrecto, intente de nuevo";
                cout << "\n   Nuevo número de tarjeta (16 dígitos):     ";
                cin >> _num;
            }

            cout << "   Nuevo código (CVV, tres dígitos):         ";
            cin >> _cod;
            while (_cod.length() != 3) {
                cout << "Código incorrecto, intente de nuevo";
                cout << "\n   Código (CVV, tres dígitos):         ";
                cin >> _cod;
            }

            cin >> _mes;
            while (_mes.length() != 2 || stoi(_mes) < 1 || stoi(_mes) > 12) {
                cout << "Mes no válido, intente de nuevo." << endl;
                cout << "   Fecha de caducidad (mes):           ";
                cin >> _mes;
            }

            cout << "   Fecha de caducidad (año):           ";
            cin >> _anio;
            while (_anio.length() != 2 || stoi(_anio) < 25) {
                cout << "Año no válido, intente de nuevo." << endl;
                cout << "   Fecha de caducidad (año):           ";
                cin >> _anio;
            }

            _cad = _mes + "/" + _anio;
            Clientes[contador].setTarjeta(_num, _cod, _cad);
            break;
        //visualizar errores
        default:
            cout << "Error";
            break;
    }
    cout << "\nCambio realizado. Escriba algo para regresar al menú anterior" << endl;
    cin >> _cod;
    principal();
}

//estatus: terminada
void registroUsuarios() {
    clear();
    string wait;
    label("Registro");
    if (contador == 0) {
        cout << "No hay usuarios registrados" << endl;
    }
    else {
        cout << "Usuarios registrados:" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "   • " << Clientes[i].getUsuario() << endl;
        }
    }
    cout << "\nEscriba cualquier cosa para volver al menú principal" << endl;
    cin >> wait;
    principal();
}

//estatus: terminada
int buscador(string _nombre) {
    for (int i = 0; i < 16; i++) {
        if (_nombre == Clientes[i].getUsuario()) {
            return i;
        }
    }
    return 404;
}
