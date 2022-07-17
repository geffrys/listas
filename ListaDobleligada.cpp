#include <iostream>
#include <conio.h>

using namespace std;

struct doble{
    doble *ld;
    doble *li;
    int data;
};

//fibonnaci
int first = 0; 
int last = 1;
int fibo();

//subprogramas
doble *creardoble(doble *list, int data);
void readlefttoright(doble *list);
void readrighttoleft(doble *list);
doble *ultimo(doble *list);
int counterPair(doble *list);
doble *findpair(doble *list);
void deleted(doble *&list, doble *&y);
int counterUnpair(doble *list);
doble *findunpair(doble *list);
//PROGRAMA PRINCIPAL
int main(){
    int n, data;
    cout<<"Times to repeat fibonnaci sequence: ";
    cin>>n;
    //Declaramos la listas
    doble *list;
    //en este pedazo se define la lista
    {      
        for(int i = 0; i < n; i++){
            if(i == 0){
                data = 0;
                list = creardoble(NULL, data);
            }
            else if(i == 1){
                data = 1;
                list = creardoble(list, data);
            }
            else{
                data = fibo();
                list = creardoble(list, data);
            }  
        }
        cout<<"reading the list left to right: \n";
        readlefttoright(list);
        cout<<"\nReading list right to left: \n";
        readrighttoleft(list);
        getch();
    }
    //EN ESTE PEDAZO LE PEDIREMOS AL USUARIO SI QUIERE ELIMINAR PARES O IMPARES
    int option, counter;
    system("CLS");
    {
        cout<<"Want to delete some numbers of the list: \n <1> To delete the pair numbers \n <2> To delete the unpair numbers \n <3> To Exit\nYour option: ";
        cin>>option;
        cout<<"\nlist before deleting items: \n";
        readrighttoleft(list);
        doble *y;
        switch(option){
            case 1: counter = counterPair(list) ;
                for(int i = 0; i < counter; i++){
                    y = findpair(list);
                    deleted(list, y);
                }
                break;
            case 2: counter = counterUnpair(list);
                for(int i = 0; i < counter; i++){
                    y = findunpair(list);
                    deleted(list, y);
                }
            break;
            case 3: exit(1);
        }
        cout<<"\n\nthe resultant list: \n";
        readrighttoleft(list);
        getch();
    }
    
}
//FUNCION FIBONACCI
int fibo(){
    int fibon;
    fibon = first + last;
    first = last;
    last = fibon;
}
//CREAR NODOS DE MANERA NO ORGANIZADA
doble *creardoble(doble *list, int data){
    doble *p;
    p = new doble();
    p->data = data;
    if(list == NULL){
        p->ld = NULL;
        p->li = NULL;
    }
    else if(list != NULL){
        p->ld = list;
        list->li = p;
        p->li = NULL;
    }
    return p;
}
//LEER DE IZQUIERDA A DERECHA
void readlefttoright(doble *list){
    doble *p;
    p = list;
    while(p != NULL){
        cout<<p->data<<" -> ";
        p = p->ld;
    }
}
//BUSCAR LA POSICION DEL ULTIMO NUMERO PARA LEER LA LISTA DE DERECHA A IZQUIERDA
doble *ultimo(doble *list){
    if(list == NULL){
        return 0;
    }
    doble *p;
    p = list;
    while(p->ld != NULL){
        p = p->ld;
    }
    return p;
}
//LEER DE DERECHA A IZQUIERDA
void readrighttoleft(doble *list){
    doble *p;
    p = ultimo(list);
    while(p!=NULL){
        cout<<p->data<<" -> ";
        p = p->li;
    }
}
//BORRAR DATO PAR
int counterPair(doble *list){
    doble *p;
    p = list;
    int counter = 0;
    while(p != NULL){
        if(p->data % 2 == 0){
            counter++;
        }
        p=p->ld;
    }
    return counter;
}
//BUSCAR DATO PAR
doble *findpair(doble *list){
    if(list == 0){
        return 0;
    }
    doble *y;
    y = list;
    while((y != 0) && (y->data % 2 != 0)){
        y = y->ld;
    }
    return y;
}
//BORRAR
void deleted(doble *&list, doble *&y){
    if(y->li == 0){
        list = y->ld;
        if(list != 0){
            list->li = 0;
        }
    }
    else if(y->ld == 0){
        y->li->ld = 0;
    }
    else{
        y->ld->li = y->li;
        y->li->ld = y->ld;
    }
    free(y);
}
//BORRAR DATO IMPAR
int counterUnpair(doble *list){
    doble *p;
    p = list;
    int counter = 0;
    while(p != NULL){
        if(p->data % 2 != 0){
            counter++;
        }
        p=p->ld;
    }
    return counter;
}
//BUSCAR IMPAR
doble *findunpair(doble *list){
    if(list == 0){
        return 0;
    }
    doble *y;
    y = list;
    while((y != 0) && y->data % 2 == 0){
        y = y->ld;
    }
    return y;
}