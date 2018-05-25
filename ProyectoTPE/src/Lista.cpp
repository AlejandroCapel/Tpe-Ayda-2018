#include "Lista.h"
#include <cstddef>
#include <iostream>
using namespace std;

template class Lista<int>;//parametrizacion Implicita


template <typename T>

Lista<T>::Lista()
{
  primero = NULL;
  ultimo = NULL;
};

template <typename T>

Lista<T>::~Lista()
{
  eliminarLista();
}

template <typename T>

void Lista<T>::agregarPrimero(const T dato)
{
  nodo *nuevonodo = new nodo;
  nuevonodo->n = dato;
  nuevonodo->sig = NULL;
  if (primero == NULL)
  {
    primero = nuevonodo;
    ultimo = primero;
  }
  else
  {
    nuevonodo->sig = primero;
    primero = nuevonodo;
  }
}

template <typename T>

void Lista<T>::agregarUltimo(const T dato)
{
  nodo *nuevonodo = new nodo;
  nuevonodo->n = dato;
  nuevonodo->sig = NULL;
  if (primero == NULL)
  {
    primero = nuevonodo;
    ultimo = nuevonodo;
  }
  else
  {
    ultimo->sig = nuevonodo;
    ultimo = nuevonodo;
  }
}

template <typename T>

void Lista<T>::agregarNodo(const int pos, T dato)
{
  nodo* nuevoNodo = new nodo;
  nuevoNodo->n = dato;
  nuevoNodo->sig = NULL;
  nodo *buscador,*auxiliar;
  int posicion = 2; //si quiere agregar el nuevo dato al principio, esta la propiedad agregarPrimero
  if (primero != NULL)
  {
    buscador = primero->sig;
    auxiliar = primero;
    while ((posicion < pos) && (buscador != NULL))
    {
      buscador = buscador->sig;
      auxiliar = auxiliar->sig;
      posicion++;
    }
    if ((posicion == pos) && (buscador != NULL))
    {
      nuevoNodo->sig = buscador;
      auxiliar->sig = nuevoNodo;
    }
    else
    {
      cout<<"No se puede insertar en esa posicion"<<endl;
    }
  }
  else
  {
    cout << "No existe esa posicion (la lista esta vacia)"<< endl;
  }
}

template <typename T>

int Lista<T>::cantidadElementos()
{
  int cantidad = 0;
  if (primero == NULL)
  {
  }
  else
  {
    nodo *contador = primero;
    cantidad++;
    while (contador->sig != NULL)
    {
      cantidad++;
      contador = contador->sig;
    }
  }
  return cantidad;
}

template <typename T>

bool Lista<T>::estaEnLista(const T datoBuscado)
{
  nodo *buscador = primero;
  if (buscador != NULL)
  {
    while ((buscador->n != datoBuscado)&&(buscador->sig != NULL))
          buscador = buscador->sig;
    if (buscador->n == datoBuscado)
      return true;
    else
      return false;
  }
  return false;
}

template <typename T>

bool Lista<T>::estaVacia()
{
  if (primero == NULL)
    return true;
  else
    return false;
}

template <typename T>

void Lista<T>::eliminarNodo(const T dato)
{
  if(estaEnLista(dato))
    {
      nodo *eliminar = primero;
      if (eliminar->sig == NULL)//si hay un solo nodo en la lista
      {
        delete eliminar;
        primero = NULL;
        ultimo = NULL;
      }
      else
      {
        nodo *aux = primero;
        eliminar = eliminar->sig;
        while (eliminar->n != dato)
        {
          aux = aux->sig;
          eliminar = eliminar->sig;
        }
        if (eliminar == ultimo)
        {
          ultimo = aux;
          delete eliminar;
        }
        else
        {
          aux->sig = aux->sig->sig;
          delete eliminar;
        }
      }
    }
}

template <typename T>

void Lista<T>::eliminarLista()
{
  nodo *eliminar = primero;
  while (primero != NULL)
  {
    primero = primero->sig;
    delete eliminar;
    eliminar = primero;
  }
}
