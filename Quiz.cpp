/*

    Realizado por:
        
   	Geffrys

*/


#include <iostream>
#include <conio.h>
using namespace std;

//ESTRUCTURA DE NODO CIRCULAR DOBLEMENTE LIGADO
struct circular{
    int fibo;
    circular *ld;
    circular *li;
};

//subprograma para fibonnaci
int fibo();
int first = 0; //valores para apoyarnos en fibo 
int last = 1;
//SUBPROGRAMAS COMPONENTES
circular *creardobleC(circular *&list, int data, circular *&head);
void leerdobleizquiedaderecha(circular *list, circular *head);
void leerdoblederechaizquierda(circular *lista, circular *head);
//PROGRAMA PRINCIPAL
int main(){
    int n, data;
    cout<<"digite el valor de n: ";
    cin>>n;
    circular *list, *head;
    list = NULL;
    head = new circular();
    //ciclo de llenado de la lista
    for(int i = 0; i < n; i++){
        if(i == 0){
                list = creardobleC(list, first, head);
        }
        else if(i == 1){
            data = 1;
            list = creardobleC(list, last, head); 
        }
        else{
            data = fibo();
            list = creardobleC(list, data, head);
        }  
    }
    //EXTRA
    cout<<"de izquierda a derecha: \n";
    leerdobleizquiedaderecha(list, head);
    cout<<endl;
    //LO QUE PEDIA EL PROGRAMA COMO TAL
    cout<<"de derecha a izquierda: \n";
    leerdoblederechaizquierda(list, head);
    getch();
}
//FUNCION FIBO
int fibo(){
    int fibon;
    fibon = first + last;
    first = last;
    last = fibon;
    return fibon;
}
//CREAR NODO NO ORDENADO
circular *creardobleC(circular *&list, int data, circular *&head){
    circular *p;
    p = new circular();
    p->fibo = data;
    if(list == NULL){
        head->ld = p;
        head->li = p;
        p->ld = head;
        p->li = head;
    }else{
        p->ld = list;
        list->li = p;
        head->ld = p;
        p->li = head;
    }
    return p;
}
//LECTURA DE NODO EN AMBAS DIRECCIONES
void leerdobleizquiedaderecha(circular *list, circular *head){
    circular *p;
    p = head->ld;
    while(p != head){
        cout<<p->fibo<<" -> ";
        p = p->ld;
    }
}
void leerdoblederechaizquierda(circular *lista, circular *head){
    circular *p;
    p = head->li;
    while(p != head){
        cout<<p->fibo<<" -> ";
        p = p->li;
    }
}
