#ifndef NUMMENOR_H
#define NUMMENOR_H


struct Nodo{
 int dato;
 Nodo *siguiente;
};

class numMenor{
 private: 
   Nodo *&lista;
   Nodo *siguiente;
 public:
   numMenor(Nodo *&);
   void numeroMenor(Nodo *&lista);
};

#endif