#ifndef ELIMINARELEMENTO_H
#define ELIMINARELEMENTO_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class eliminarElemento{
 private: 
   Nodo *&lista;
   int n;
   Nodo *siguiente;
 public:
   eliminarElemento(Nodo *&, int);
   void eliminarLista(Nodo *&lista, int n);
};

#endif