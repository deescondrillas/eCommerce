//descripción: definición de la clase
//fecha: nov, 20 - 2024
//autores: Víctor Ayrton Urrutia & Franco De Escondrillas

#include <string>

using namespace std;

class Token {
    public:
        Token();
        ~Token();

        string getNum();
        string getCod();
        string getCad();

        string aTexto(int);
        string fecha(int, int);

    private:
        int randNum;
        int randCod;
        int randMes;
        int randYear;
};
