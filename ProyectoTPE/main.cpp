#include <iostream>
#include <fstream>
#include "include/arbol.h"
#include "include/Lista.h"
#include <ctime>
using namespace std;

void cargar_coleccion(string path); //Agregar como par�metro la estructura donde se almacenar�n las palabras.
void buscar_palabra(string pathBusqueda, string pathResultado); //Agregar como par�metro la estructura donde se buscar�n las palabras.

int main()
{
    cargar_coleccion("Datasets\\Coleccion_1.txt");
    buscar_palabra("Datasets\\Busqueda_1.txt", "Resultado_1.txt");
    return 0;
}

//Abre el txt indicado por la ruta(path), itera por todas las palabras
//y las carga en el contenedor pasado por par�metro
void cargar_coleccion(string path) {
    ifstream origen(path.c_str());
    if (!origen.is_open())
        cout << "No se pudo abrir el archivo: " << path << endl;
    else {
        while (!origen.eof()) {
            string palabra;
            origen >> palabra;
            cout << palabra << endl;
            //Almacenar la palabra en el contenedor.
        }
    }
}

void buscar_palabra(string pathBusqueda, string pathResultado) {
    ifstream busqueda(pathBusqueda.c_str());
    if (!busqueda.is_open())
        cout << "No se pudo abrir el archivo: " << pathBusqueda << endl;
    else {
        ofstream resultado(pathResultado.c_str(), ios::trunc);
        while (!busqueda.eof()) {
            string palabra;
            busqueda >> palabra;
            //Buscar la palabra en la coleccion
            cout << palabra << endl;
            //Almacenar el resultado
            resultado << palabra << ",Resultado,Costo" << endl;
        }
    }
}
