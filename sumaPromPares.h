#ifndef SUMAPROMPARES_H
#define SUMAPROMPARES_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class sumaPromPares{
 private: 
   Nodo *&lista;
   Nodo *siguiente;
 public:
   sumaPromPares(Nodo *&);
   void SPPares(Nodo *&lista);
};

#endif