#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
 int dato;
 Nodo *siguiente;
};

void insertarLista(Nodo *&, int n);
void mostrarLista(Nodo *);
Nodo *lista = NULL;

//insertar elemento en la lista
void insertarLista(Nodo *&lista,int n){
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo->dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2;

  while((aux1 != NULL) && (aux1->dato < n)){
    aux2 = aux1;
    aux1 = aux1->siguiente;
  }

  if(lista == aux1){
    lista = nuevo_nodo;
  }
  else{
    aux2->siguiente = nuevo_nodo;
  }
  nuevo_nodo->siguiente = aux1;

  cout<<"\tElemento "<<n<<" insertado a lista correctamente";
}

//mostrar elementos de la lista
void mostrarLista(Nodo *lista){
  Nodo *actual = new Nodo();
  actual = lista;
  while (actual != NULL){
    cout<<actual->dato<<" -> ";
    actual = actual->siguiente;
  }
}

//buscar elementos de la lista
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

//Eliminar elemento de la lista
void eliminarElemento(Nodo *lista, int n){
  if(lista != NULL){
    Nodo *_borrar;
    Nodo *anterior = NULL;

    _borrar = lista;

    while((_borrar != NULL) && (_borrar->dato != n)){
      anterior = _borrar;
      _borrar = _borrar->siguiente;
    }
    if(_borrar == NULL){
      cout<<"No se ha encontrado el elemento a borrar"<<endl;
    }
    else if(anterior == NULL){
      lista = lista->siguiente;
      delete _borrar;
    }
    else{
      anterior->siguiente = _borrar->siguiente;
      delete _borrar;
    }
  }
}


//main
int main() {
  int dato;

  //MENÚ
  cout<<"¡Bienvenido usuario!"<<endl;
  int opcion;
  do{
   cout<<"Elige el número de lo que deseas hacer..."<<endl;
   cout<<""<<endl;
   cout<<"1. Insertar elementos a la lista"<<endl<<"2. Mostrar elementos de la lista"<<endl<<"3. Buscar elementos en la lista"<<endl<<"4. Eliminar elementos de la lista"<<endl<<"5. Calcular suma promedio de los números pares"<<endl<<"6. Calcular suma promedio de los números impares"<<endl<<"7. Calcular número menor de la lista"<<endl<<"8. Calcular número mayor de la lista"<<endl<<"9. Mostrar elementos repetidos de la lista"<<endl<<"0. Eliminar elementos repetidos de la lista"<<endl<<endl<<"--Presione cualquier otra tecla para salir--"<<endl;

   cin>>opcion;
   switch(opcion){
     case 1:
     cout<<"Ingrese un número: "<<endl;
     cin>>dato;
     insertarLista(lista, dato);
     break;
     case 2:
     mostrarLista(lista);
     cout<<""<<endl;
     break;
     case 3:
     cout<<"Ingrese el número para buscar: "<<endl;
     cin>>dato;
     buscarLista(lista, dato);
     cout<<""<<endl;
     break;
     case 4:
     cout<<"Ingrese el número que quiere eliminar: "<<endl;
     cin>>dato;
     eliminarElemento(lista, dato);
     cout<<"¡Elemento eliminado con exito!"<<endl;
     break;
     //case 5:
     //case 6:
     //case 7:
     //case 8:
     //case 9:
     //case 0:
     //default;
    }
  }while(opcion != 10);
  getchar();
  return 0;
}