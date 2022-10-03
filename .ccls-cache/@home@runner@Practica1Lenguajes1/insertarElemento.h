#ifndef INSERTAR_H
#define INSERTAR_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class insertarElemento{
 private: 
   Nodo *&lista;
   int n;
   Nodo *siguiente;
 public:
   insertarElemento(Nodo *&, int);
   void insertarLista(Nodo *&lista, int n);
};

#endif