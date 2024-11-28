//descripción: definición de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Token.cpp"

using namespace std;

class Tarjeta {
    public:
        //builders
        Tarjeta();
        Tarjeta(string, string, string);
        ~Tarjeta();
        //setters
        void setNum(string);
        void setCod(string);
        void setCad(string);
        //getters
        string getNum();
        string getCod();
        string getCad();
        Token getToken();
        //methods
        void imprime();
        void pagar(double);

    private:
        string num;
        string cod;
        string cad;
        Token randTarj;
};
