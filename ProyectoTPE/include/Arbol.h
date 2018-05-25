#include <iostream>
#include "Lista.h"

using namespace std;

template<typename T>
class Arbol : public Lista{
    private:
        struct NodoArbol
        {
            T dato;
            NodoArbol *der;
            NodoArbol *izq;
        };
        NodoArbol *raiz;
        int ContadorNodos;
        nodo *PrimeroLista

        //parte privada de metodos
        void AgregarR(T, NodoArbol*&);
        bool VerificarPertenenciaR(T, NodoArbol*);
        PrimeroLista ListarR(NodoArbol*);
        bool VerificarVacioP();
        void EliminarArbol(NodoArbol*&);
    public:
        Arbol();
        ~Arbol();
        void Agregar(T);
        bool VerificarPertenencia(T);
        int VerificarCantidad();
        bool VerificarVacio();
        PrimeroLista Listar();
};
