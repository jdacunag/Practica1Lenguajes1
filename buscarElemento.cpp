#include<iostream>
#include<stdlib.h>
using namespace std;

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

void buscarLista(Nodo *lista, int n){
  bool esta = false;
  Nodo *actual = new Nodo();
  actual = lista;
  while((actual != NULL) && (actual->dato <= n)){
    if(actual->dato == n){
      esta = true;
    }
    actual = actual->siguiente;
  }
  if(esta == true){
    cout<<"Numero "<<n<<" se encuentra en la lista"<<endl;
  }
  else{
    cout<<"El número "<<n<<" no se encuentra en la lista"<<endl;
  }
}