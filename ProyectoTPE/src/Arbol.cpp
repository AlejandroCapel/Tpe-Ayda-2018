#include "Arbol.h"
template class Arbol<int>;//parametrizacion Implicita

template<typename T>
Arbol<T>::Arbol()
{
    raiz = NULL;
    ContadorNodos = 0;
}

template<typename T>
Arbol<T>::~Arbol()
{
    EliminarArbol(raiz);
    cout<<endl<<"Arbol Destruido";
}

template<typename T>
void Arbol<T>::EliminarArbol(NodoArbol *&nodo)
{
    if (nodo!=NULL){
        EliminarArbol(nodo->der);
        EliminarArbol(nodo->izq);
        delete nodo;
    }

}

template<typename T>
void Arbol<T>::AgregarR(T valor,NodoArbol *&nodo)
{

    if (nodo == NULL ){
        NodoArbol *NodoTemp = new NodoArbol;
        NodoTemp->dato=valor;
        NodoTemp->der= NULL;
        NodoTemp->izq= NULL;
        nodo=NodoTemp;
    }else{
        if (valor >= nodo->dato){
            AgregarR(valor,nodo->der);
        }else{
            AgregarR(valor,nodo->izq);
        }
    }
}
template<typename T>
void Arbol<T>::Agregar(T valor)
{
    AgregarR(valor, raiz);
    ContadorNodos++;
}

template<typename T>
bool Arbol<T>::VerificarVacioP()
{
    if (raiz==NULL){
        return true;
    }else{
        return false;
    }
}

template<typename T>
bool Arbol<T>::VerificarVacio()
{
    if (VerificarVacioP())
    {
        cout<<"El Arbol es vacio"<<endl;
    }else{
        cout<<"El Arbol no es vacio"<<endl;
    }
}

template<typename T>
Lista Arbol<T>::ListarR(NodoArbol *nodo)
{
    if (nodo!=NULL) {
        Arbol::ListarR(nodo->izq);
        ListaArbol.agregarUltimo(nodo->dato);
        Arbol::ListarR(nodo->der);
    }
}

template<typename T>
Lista Arbol<T>::Listar()
{
    Lista<int> ListaArbol;
    ListarR(raiz);
}


template<typename T>
int Arbol<T>::VerificarCantidad()
{
    return ContadorNodos;
}

template <typename T>
bool Arbol<T>::VerificarPertenenciaR(T valor,NodoArbol *nodo)
{
    if (nodo!=NULL){
        if (nodo->dato!=valor){
            return VerificarPertenenciaR(valor,nodo->der) || VerificarPertenenciaR(valor,nodo->der) || false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}

template<typename T>
bool Arbol<T>::VerificarPertenencia(T valor)
{
    if (VerificarPertenenciaR(valor,raiz)){
        cout<<"El Valor pertenece al arbol"<<endl;
        return true;
    }else{
        cout<<"El valor no pertenece al arbol"<<endl;
        return false;
    }
}
