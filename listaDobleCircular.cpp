#include <iostream>
#include <conio.h>
using namespace std;

struct Estudiante{
    Estudiante *ld;
    Estudiante *li;
    int carnet;
    float nota;
    char gano;
};
//subprogramas
Estudiante *insertarcircular(Estudiante *&list, Estudiante *&last, int id, float nota);
void leerlista(Estudiante *last, Estudiante *list);
void ordenarcircularDescendemente(Estudiante *&last, Estudiante *&list);
//PROGRAMA PRINCIPAL
int main(){
    int n;
    cout<<"how many students want to register: ";
    cin>>n;
    //datos del estudiante
    int id;
    float nota;
    //definimos la lista
    Estudiante *list, *last;
    list = NULL;
    for(int i = 0; i < n; i++){
        cout<<"write ID of student: ";
        cin>>id;
        cout<<"write the grade of student: ";
        cin>>nota;
        list = insertarcircular(list,last,id,nota);
        cout<<endl;
    }
    cout<<"reading list: \n";
    leerlista(last, list);
    cout<<"\npress enter to skip to the next page...";
    getch();
    system("CLS");
    ordenarcircularDescendemente(last, list);
    cout<<"descending order list: \n";
    leerlista(last, list);
    getch();
}

Estudiante *insertarcircular(Estudiante *&list, Estudiante *&last, int id, float nota){
    Estudiante *p;
    p = new Estudiante();
    p->carnet = id;
    p->nota = nota;
    //definimos si gano o perdio
    {
        if(p->nota >= 3.0){
            p->gano = 'S';
        }else{
            p->gano = 'N';
        }
    }
    if(list == NULL){
        p->ld = p;
        p->li = p;
        last = p;
    }else{
        list->li = p;
        last->ld = p;
        p->ld = list;
        p->li = last;
    }
    return p;
}

void leerlista(Estudiante *last, Estudiante *list){
    Estudiante *p;
    p = list;
    do{
        cout<<"Id: "<<p->carnet<<" Nota: "<<p->nota<<" Gano? "<<p->gano<<endl;
        p = p->ld;
    }while(p != last->ld);
}

void ordenarcircularDescendemente(Estudiante *&last, Estudiante *&list){
    Estudiante *p, *q;
    int auxid;
    float auxnot;
    char auxgano;
    p = list;
    do{
        q = p->ld;
        do{
            if(p->carnet > q->carnet){
                auxid = p->carnet;
                auxnot = p->nota;
                auxgano = p->gano;
                p->carnet = q->carnet;
                p->nota = q->nota;
                p->gano = q->gano;
                q->carnet = auxid;
                q->nota = auxnot;
                q->gano = auxgano;
            }
            q = q->ld;
        }while(q != last->ld);
        p = p->ld;
    }while(p != last->ld);
}