#ifndef SUMAPROMIMPARES_H
#define SUMAPROMIMPARES_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class sumaPromImpares{
 private: 
   Nodo *&lista;
   Nodo *siguiente;
 public:
   sumaPromImpares(Nodo *&);
   void SPImpares(Nodo *&lista);
};

#endif