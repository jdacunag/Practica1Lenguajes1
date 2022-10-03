#ifndef NUMMAYOR_H
#define NUMMAYOR_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class numMayor{
 private: 
   Nodo *&lista;
   Nodo *siguiente;
 public:
   numMayor(Nodo *&);
   void numeroMayor(Nodo *&lista);
};

#endif