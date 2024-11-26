//descripción: definición de la clase
//fecha: nov, 24 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include <string>

using namespace std;

class Token {
    public:
        //builders
        Token();
        ~Token();
        //getters
        string getNum();
        string getCod();
        string getCad();
        int getLim();
        bool getProceso();
        int getTimestamp();
        //methods
        void pagar(double);
        string aTexto(int);
        int aleatorio(int);
        void printToken();

    private:
        string randNum;
        string randCod;
        string cad;
        double limiteMax;
        bool proceso;
        int timestamp;
};
