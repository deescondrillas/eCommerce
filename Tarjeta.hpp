//descripción: definición de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include "Token.cpp"

using namespace std;

class Tarjeta {
    public:
        Tarjeta();
        Tarjeta(string, string, string);
        ~Tarjeta();

        string getNum();
        string getCod();
        string getCad();

        void setNum(string);
        void setCod(string);
        void setCad(int, int);

        void imprime();

    private:
        int randNum;
        int randCod;
        int randMes;
        int randYear;
};
