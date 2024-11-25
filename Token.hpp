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
        //setters
        void setLim(int);
        //getters
        string getNum();
        string getCod();
        string getCad();
        int getLim();
        bool getPago();
        int getTimestamp();
        //methods
        void pagar();
        string aTexto(int);
        int aleatorio(int);

    private:
        string randNum;
        string randCod;
        string cad;
        int limiteMax;
        bool pago;
        int timestamp;
};
