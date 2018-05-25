#ifndef LISTA_H
#define LISTA_H
template <typename T>

class Lista
{
  struct nodo
  {
    T n;
    nodo *sig;
  };
  nodo *primero, *ultimo;

public:
  Lista();
  ~Lista();
  void agregarPrimero(const T);
  void agregarUltimo(const T);
  void agregarNodo(const int pos, T);
  int cantidadElementos();
  void eliminarNodo(const T);
  void eliminarLista();
  bool estaEnLista(const T);
  bool estaVacia();
};


#endif // LISTA_H
