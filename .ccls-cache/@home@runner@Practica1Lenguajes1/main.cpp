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
Nodo *repetidos = NULL;

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

  cout<<endl<<"Elemento "<<n<<" insertado a lista correctamente"<<endl;
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
void eliminarElemento(Nodo *&lista, int n){
  //Ver si la lista no esta vacia
  if(lista != NULL){
    Nodo *_borrar;
    Nodo *anterior = NULL;

    _borrar = lista;
    //Recorrer la lista
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
      cout<<"¡Elemento eliminado con exito!"<<endl;
    }
    else{
      anterior->siguiente = _borrar->siguiente;
      delete _borrar;
      cout<<"¡Elemento eliminado con exito!"<<endl;
    }
  }
}

//Calcular suma promedio de pares
void SPPares(Nodo *lista){
  if(lista != NULL){
   int cont = 0;
   int suma = 0;
   Nodo *actual = new Nodo();
   actual = lista;
   while (actual != NULL){
     if(actual->dato % 2 == 0){
       cont++;
       suma += actual->dato;
      }
     actual = actual->siguiente;
    }
   if(cont==0){
     cout<<"No hay números pares"<<endl;
    }
   int sumaPromP = suma/cont;
   cout<<"Suma promedio de los pares: "<<sumaPromP<<endl;
  }
  else{
    cout<<"No hay numeros en la lista..."<<endl;
  }
}

//Calcular suma promedio de impares
void SPImpares(Nodo *lista){
  if(lista != NULL){
   int cont = 0;
   int suma = 0;
   Nodo *actual = new Nodo();
   actual = lista;
   while (actual != NULL){
     if(actual->dato % 2 == 1){
       cont++;
       suma += actual->dato;
      }
     actual = actual->siguiente;
    }
   if(cont==0){
     cout<<"No hay números impares"<<endl;
    }
   int sumaPromImp = suma/cont; 
   cout<<"Suma promedio de los impares: "<<sumaPromImp<<endl;
  }
  else{
    cout<<"No hay numeros en la lista..."<<endl;
  }
}

//Calcular numero menor de la lista
void numeroMenor(Nodo *lista){
  int menor = 999;
  bool flag = true;
  if(lista == NULL){
    cout<<"No hay elementos en la lista"<<endl;
    flag = false;
  }
  while(lista != NULL){
    if(lista->dato < menor){
      menor = lista->dato;
    }
    lista = lista->siguiente;
  }
  if(flag == true){
    cout<<"El numero menor de la lista es: "<<menor<<endl;
  }
}

//Calcular numero mayor de la lista
void numeroMayor(Nodo *lista){
  int mayor = 0;
  bool flag = true;
  if(lista == NULL){
    cout<<"No hay elementos en la lista"<<endl;
    flag = false;
  }
  while(lista != NULL){
    if(lista->dato > mayor){
      mayor = lista->dato;
    }
    lista = lista->siguiente;
  }
  if(flag == true){
    cout<<"El numero mayor de la lista es: "<<mayor<<endl;
  }
}

/*
bool contiene(int busc){
  Nodo * actual = new Nodo();
  actual = lista;
  while(actual != NULL){
    if(actual->dato == busc){
      return true;
    }
    actual = actual->siguiente;
  }
  return false;
}
//Mostrar elementos repetidos de la lista
void mostrarRepetidos(Nodo *lista){
  Nodo *a = new Nodo();
  a = lista;

  while(a->siguiente != NULL){
    Nodo *b = new Nodo();
    b = a->siguiente;

    while(b != NULL){
      cout<<repetidos.contiene(a->dato)<<endl;
      if(a->dato == b->dato){
        cout<<repetidos.contiene(a->dato)<<endl;
        if(!repetidos.contiene(a->dato)){
          cout<<repetidos.contiene(a->dato)<<endl;
        }
        else{
          b = b->siguiente;
          continue;
        }
      }
      b = b->siguiente;
    }
    a = a->siguiente;
  }
}
*/

//Eliminar elementos repetidos de la lista
void eliminarRepetidos(Nodo *lista){
  Nodo *actual = new Nodo();
  actual = lista;
  int llenar = 0;

  while(actual != NULL){
    int contador = llenar;
    Nodo *eliminar = new Nodo();
    eliminar = actual->siguiente;

    while(eliminar != NULL){
      contador = contador + 1;
      if(actual->dato == eliminar->dato){
        actual->siguiente = eliminar->siguiente;
        delete eliminar;
        contador--;
        cout<<"¡Elementos repetidos eliminados con exito!"<<endl;
      }
      eliminar = eliminar->siguiente;
    }
    actual = actual->siguiente;
    llenar = llenar + 1;
  }
}

//main
int main() {
  int dato;

  //MENÚ para realizar todas las acciones del código
  
  cout<<"¡Bienvenido usuario!"<<endl;
  int opcion;
  do{
   cout<<endl<<"Elige el número de lo que deseas hacer..."<<endl;
   cout<<""<<endl;
   cout<<"1. Insertar elementos a la lista"<<endl<<"2. Mostrar elementos de la lista"<<endl<<"3. Buscar elementos en la lista"<<endl<<"4. Eliminar elementos de la lista"<<endl<<"5. Calcular suma promedio de los números pares"<<endl<<"6. Calcular suma promedio de los números impares"<<endl<<"7. Calcular número menor de la lista"<<endl<<"8. Calcular número mayor de la lista"<<endl<<"9. Mostrar elementos repetidos de la lista"<<endl<<"0. Eliminar elementos repetidos de la lista"<<endl<<endl<<"--Ingrese el número 99 para salir--"<<endl;

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
     break;
     case 5:
     SPPares(lista);
     cout<<""<<endl;
     break;
     case 6:
     SPImpares(lista);
     cout<<""<<endl;
     break;
     case 7:
     numeroMenor(lista);
     cout<<""<<endl;
     break;
     case 8:
     numeroMayor(lista);
     cout<<""<<endl;
     break;
     //case 9:
     case 0:
     eliminarRepetidos(lista);
     cout<<""<<endl;
     break;
     default:
     break;
    }
  }while(opcion != 99);

  cout<<endl<<"¡GRACIAS!"<<endl;
  
  getchar();
  return 0;
} 