//descripción: definición de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Tarjeta.cpp"

using namespace std;

class Cliente {
    public:
        //builders
        Cliente();
        Cliente(string, string, double, Tarjeta);
        ~Cliente();
        //setters
        void setUsuario(string);
        void setClave(string);
        void setCapital(double);
        void setTarjeta(string, string, string);
        //getters
        string getUsuario();
        string getClave();
        double getCapital();
        Tarjeta getTarjeta();
        //methods
        void printDatos();
        void updateHistorial(int);
        void printHistorial();
        void setLim(double);

    private:
        string usuario;
        string clave;
        double capital;
        double historial[10];
        Tarjeta tarjeta;
};
