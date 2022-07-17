#include <iostream>
#include <conio.h>

using namespace std;

struct listaC{
    listaC *next;
    int data;
};

//declaramos los subprogramas
listaC *crearListacircular(listaC *&head, listaC *list, int data);
void leerListaC(listaC *head);
int contador(listaC* head, int data);
void buscardatoaborrarC(listaC *&head, listaC *&x, listaC *&y, int data);
void buscarmenor(listaC *head, listaC *&minor);
//programa principal
int main(){
    cout<<"write how many items you want to insert: ";
    int n, data;
    cin>>n;
    //definimos las dos listas necesarias
    listaC *list, *head;
    list = NULL;
    head = new listaC();
    //seccion para llenar la lista
    {
        for(int i=0; i<n; i++){
            cout<<"Element: ";
            cin>>data;
            list = crearListacircular(head, list, data);
        }
        leerListaC(head);
        cout<<"\n\nPress enter to go to the next section... ";
        getch();
        system("CLS");
    }
    //seccion para eliminar elementos
    {
        leerListaC(head);
        cout<<"\n\nWrite the element to delete: ";
        cin>>data;
        listaC *x, *y;
        n = contador(head, data);
        if(n > 0){
            for(int i = 0; i < n; i++){
                buscardatoaborrarC(head, x, y, data);
            }
            cout<<"\nthe element was deleted from the list, the resultant list...\n";
        }
        else{
            cout<<"It element doesn't exist in this list...";
        }
        leerListaC(head);
        cout<<"\n\nPress enter to go to the next section... ";
        getch();
    }
    //seccion para buscar el elemento menor y su direccion de nodo
    {
        listaC *minor;
        buscarmenor(head, minor);
        cout<<"\n\n\nAditionally we gonna show you the smallest number in the list: "<<minor->data<<" and it direction are: "<<minor;
        getch();
    }
}

//definimos los subprogramas
//LLENADO GENERICO DE LISTA SIN ORDEN
/*Para crear la lista recibimos la cabecera como puntero y referencia, y ya el resto de manera basica*/
listaC *crearListacircular(listaC *&head, listaC *list, int data){
    listaC *p;
    p = new listaC(); //definimos el espacio
    p->data = data;

    if(list == NULL){
        p->next = head;
    }else{
        /*el header siempre estara ligado al ultimo elemento que ingresamos por lo que
        para ligar al siguiente elemento de la lista del nuevo elemento que ingreso
        aprovechamos este evento, y hacemos p en su liga igual a header en su liga, asi 
        se completa el circulo*/
        p->next = head->next; //revisar paint para ver esto de manera grafica
    }
    head->next = p; //la cabeza se liga al ultimo elemento que ingreso
    return p;
}
//LECTURA DE LISTA CIRCULAR
void leerListaC(listaC *head){
    listaC *p;
    p = head->next;
    while(p != head){
        cout<<p->data<<" -> ";
        p = p->next;
    }
}
//CONTADOR DE N VECES QUE ESTA UN DATO
int contador(listaC *head, int data){
    listaC *p;
    int counter = 0;
    p = head->next;
    while(p != head){
        if(p->data == data){
            counter++;
        }
        p = p->next;
    }
    return counter;
}
//BUSCAR DATO A BORRAR Y BORRAR
void buscardatoaborrarC(listaC *&head, listaC *&x, listaC *&y, int data){
    y = NULL;
    x = head->next;
    //recorre la lista donde x va un elemento delante de y
    //donde en caso de llega a la posicion necesaria tendremos que y en su liga sera el elemento buscado
    while((x != head) && (x->data != data)){
        y = x;
        x = x->next;
    }
    if(y == NULL){
        head->next = x->next;
    }else{
        y->next = x->next;
    }    
    free(x);
}
//BUSCAR MENOR
void buscarmenor(listaC *head, listaC *&minor){
    listaC *p;
    int min = 999999999;
    p = head->next;
    while(p != head){
        if(p->data < min){
            minor = p;
        }
        p = p->next;
    }
}