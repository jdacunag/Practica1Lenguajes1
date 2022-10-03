#ifndef BUSCARELEMENTO_H
#define BUSCARELEMENTO_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class buscarElemento{
 private: 
   Nodo *&lista;
   int n;
   Nodo *siguiente;
 public:
   buscarElemento(Nodo *&, int);
   void buscarLista(Nodo *&lista, int n);
};

#endif