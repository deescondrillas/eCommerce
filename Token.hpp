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
        //methods
        string aTexto(int);
        int aleatorio(int);

    private:
        string randNum;
        string randCod;
        string fecha;
};
