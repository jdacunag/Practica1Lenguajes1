#ifndef MOSTRARELEMENTO_H
#define MOSTRARELEMENTO_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class mostrarElemento{
 private: 
   Nodo *&lista;
   Nodo *siguiente;
 public:
   mostrarElemento(Nodo *&);
   void mostrarLista(Nodo *&lista);
};

#endif