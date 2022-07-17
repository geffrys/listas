#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Definimos la estructura nodo...
struct nodo{
    int info;
    nodo *siguiente;
};

//la lista esta declarada globalmente por eso cualquier subprograma la puede recibir.
nodo *cabecera = NULL;

//DECLARACION DE SUBPROGRAMAS...
void menu(void);
void insertar_ordenadamente(void);
void recorrer(nodo *lista);
void insertar_principio(void);
void borrar_dato(nodo*, int);

//PROGRAMA PRINCIPAL...
int main(){
    menu();
}

void menu(){
    int option, dato;
    do{
        cout<<"\n\t1 - Insertar datos ordenadamente.\n";
        cout<<"\n\t2 - Insertar datos al principio.\n";
        cout<<"\n\t3 - Insertar datos al final.\n";
        cout<<"\n\t4 - Borrar dato.\n";
        cout<<"\n\t5 - Ordenar lista ascendentemente.\n";
        cout<<"\n\t6 - Mostrar todos los datos.\n";

        cout<<"\n\t0 - Finalizar.\n";
        cout<<"\n\n\tSeleccionar una opcion: ";
        cin>>option;
        switch(option){
            case 0: cout<<"\n\nFinaliza y vacia la memoria";
                    exit(0);
            case 1: insertar_ordenadamente(); break;
            case 2: insertar_principio(); break;
            case 4: cout<<"escriba dato a borrar: "; cin>>dato;
                borrar_dato(cabecera, dato); break;
            case 6: recorrer(cabecera); break;
            default: 
                cout<<"\n\nOpcion invalida!!!!!";
        }        

    }while(option);
}

//INSERTAR ORDENADAMENTE
//SUBPROGRAMAS Y FUNCIONES PARA INSERTAR ORDENADAMENTE
nodo *buscar_donde(nodo *lista, int dato);
void insertar(nodo *lista, nodo *y, int dato);

void insertar_ordenadamente(){
    int cant, dato;
    cout<<"Digite la cantidad de nodos de la lista a crear: ";
    cin>>cant;
    int i=1; //lo iniciamos en 1 para ser mas user friendly
    while(i<=cant){
        cout<<"Ingrese el dato "<<i<<" de la lista: ";
        cin>>dato;
        nodo *y; 
        y = buscar_donde(cabecera, dato);
        insertar(cabecera, y, dato);
        i++;
    }
}
//IMPLEMENTACION DE SUBPROGRAMAS Y FUNCIONES
nodo *buscar_donde(nodo *lista, int dato){
    nodo *p = lista;
    nodo *y = NULL;
    while(p!=NULL && p->info < dato){
        y=p;
        p=p->siguiente;
    }
    return y;
}
void insertar(nodo *lista, nodo *y, int dato){
    //CONSEGUIR REGISTRO
    nodo *nuevo = NULL; 
    nuevo = (nodo *)malloc(sizeof(nodo));
    //ASIGNAMOS EL DATO
    nuevo->info=dato;
    nuevo->siguiente=NULL;

    if(y==NULL){
        nuevo->siguiente=lista;
        cabecera=nuevo;
    }
    else{
        nuevo->siguiente=y->siguiente;
        y->siguiente=nuevo;
    }
}

//RECORRER
void recorrer(nodo *lista){
    if(lista==NULL){
        cout<<"\nLa lista esta vacia....!!!";
    }
    else{
        nodo *recorre = NULL;
        recorre = lista;
        while(recorre!=0){
            cout<<"\n\nDato: "<<recorre->info;
            cout<<"\n\nPosicion: "<<recorre;
            cout<<"\n\nApunta a: "<<recorre->siguiente;

            recorre=recorre->siguiente;
        }
    }
}

//INSERTAR AL PRINCIPIO
void insertar_principio(){

}

//BORRAR DATO
void borrar_dato(nodo *lista, int dato){
    nodo *recorrer = NULL, *y = NULL;
    recorrer = lista;
    while((recorrer != NULL) && (recorrer->info != dato)){
        y = recorrer;
        recorrer = recorrer->siguiente;
    }
    if(recorrer  == NULL){
        cout<<"el dato no fue encontrado";
    }
    else if(y == NULL){
        cabecera = recorrer->siguiente;
        cout<<"el dato"<<dato<<" fue borrado de la lista.";
    }
    else{
        y->siguiente = recorrer->siguiente;
        cout<<"el dato "<<dato<<" fue borrado";
    }
    free(recorrer);
}
