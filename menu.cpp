//REALIZADO POR: GeffryS

#include <iostream>
using namespace std;

struct nodo
{
    int data;
    nodo *next;
};

nodo *cabecera = NULL;

//prototipos de subprogramas
void menu(void);
void insertaralfinal(void);
void insertaralinicio(void);
void insertarordenado(void);
void borrardato(void);
void borrardatorepetidamente();
void liberarlista(nodo *&);
void mostrarlista(nodo *);
void mostrarlistacondetalles(nodo *);
void buscardato(void);
void ordenamientoascendente(nodo *);
void ordenamientodescendente(nodo *);
//programa principal
int main()
{
    menu();
}

//menu de opciones
void menu()
{
    int option;
    do
    {
        cout << "\n\t\t---------- MENU ----------\n\n";
        cout << "\t1. Insertar siempre al final.\n";
        cout << "\t2. Insertar siempre al principio.\n";
        cout << "\t3. Insertar ordenadamente.\n";
        cout << "\t4. Borrar dato.\n";
        cout << "\t5. Borrar dato repetidamente.\n";
        cout << "\t6. Liberar lista.\n";
        cout << "\t7. Mostrar lista.\n";
        cout << "\t8. Mostrar lista con detalles.\n";
        cout << "\t9. Buscar dato.\n";
        cout << "\t10. Ordenar lista ascendentemente.\n";
        cout << "\t11. Ordenar lista descendentemente.\n";
        cout << "\t0. Salir del menu y finalizar.\n";
        cout << "\n\tEscribe tu opcion: ";
        cin >> option;
        switch (option)
        {
        case 0:
            exit(0);
            break;
        case 1:
            insertaralfinal();
            break;
        case 2:
            insertaralinicio();
            break;
        case 3:
            insertarordenado();
            break;
        case 4:
            borrardato();
            break;
        case 5:
            borrardatorepetidamente();
            break;
        case 6:
            liberarlista(cabecera);
            break;
        case 7:
            mostrarlista(cabecera);
            break;
        case 8:
            mostrarlistacondetalles(cabecera);
            break;
        case 9:
            buscardato();
            break;
        case 10:
            ordenamientoascendente(cabecera);
            break;
        case 11:
            ordenamientodescendente(cabecera);
            break;
        }
    } while (option);
}

//---------------INSERTAR SIEMPRE AL FINAL---------------

//llamado de subprogramas necesarios
nodo *crearnodoalfinal(nodo *, int);

//funcion principal de insertar al final
void insertaralfinal()
{
    int n;
    cout << "escriba el numero de elementos a insertar: ";
    cin >> n;
    int dato;
    for (int i = 0; i < n; i++)
    {
        cout << "escriba dato a insertar: ";
        cin >> dato;
        cabecera = crearnodoalfinal(cabecera, dato);
    }
}

nodo *crearnodoalfinal(nodo *cabecera, int data)
{
    nodo *p = NULL, *ultimo = NULL;
    p = cabecera;
    //creamos un espacio en memoria para almacenar el dato y su liga a nulo
    ultimo = (nodo *)malloc(sizeof(nodo));
    ultimo->data = data;
    ultimo->next = NULL;
    //cuando la lista esta vacia simplemente se agrega espacio en memoria
    if (cabecera == 0)
    {
        cabecera = ultimo;
    }
    else
    {
        //hacemos recorrer la lista con la condicion de que la liga sea diferente de cero
        //con el objetivo de que cuando llegue al elemento que esta ligado a cero
        //lo ligaremos a el espacio en memoria ultimo.
        while (p->next != 0)
        {
            p = p->next;
        }
        //la lista recorrida hasta el elemento que tiene liga a 0, entonces la liga de este la hacemos igual a ultimo.
        p->next = ultimo;
    }
    return cabecera;
}

//--------------- INSERTAR AL SIEMPRE PRINCIPIO ---------------

//llamado de subprogramas necesarios
nodo *crearnodoalinicio(nodo *, int);
//subprograma principal de la operacion
void insertaralinicio()
{
    int n;
    cout << "escriba el numero de elementos a insertar: ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "escriba dato a insertar: ";
        cin >> data;
        cabecera = crearnodoalinicio(cabecera, data);
    }
}
nodo *crearnodoalinicio(nodo *cabecera, int data)
{
    nodo *p = NULL;
    p = (nodo *)malloc(sizeof(nodo)); //reservamos espacio en memoria.
    p->data = data;
    p->next = cabecera; //se liga p.next a cabecera que es el primer dato
    cabecera = p;    //posiblemente esto sobre   //cabecera se hace igual al espacio reservado en memoria p
    return p;
}

//--------------- INSERTAR ORDENADAMENTE ---------------

//llamado a subprogramas y funciones necesarias
nodo *buscardonde(nodo *, int);
nodo *insertar(nodo *, nodo *, int);
//subprograma principal de la operacion
void insertarordenado()
{
    int n;
    cout << "escriba cuantos elementos va a insertar: ";
    cin >> n;
    int data;
    nodo *y = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "escriba dato a ingresar: ";
        cin >> data;
        y = buscardonde(cabecera, data);
        cabecera = insertar(cabecera, y, data);
    }
}
nodo *buscardonde(nodo *cabecera, int data)
{
    nodo *p, *y;
    p = cabecera;
    y = NULL;
    //recorre la lista hasta que p.data sea mayor o igual que dato y ahi para la iteracion
    while ((p != 0) && (p->data < data))
    {
        y = p; //y conserve la posicion anterior debido a que es el ultimo caso donde p.dato es menor que dato
        //por lo tanto el dato se debe insertar entre y and p
        p = p->next;
    }
    //retornamos la posicion y que es donde necesitamos insertar
    return y;
}
nodo *insertar(nodo *cabecera, nodo *y, int data)
{
    //reservamos un espacio en memoria de tipo nodo y en este almacenamos el dato.
    nodo *x;
    x = (nodo *)malloc(sizeof(nodo));
    x->data = data;
    //cuando y es igual a 0 es porque la lista estaba vacia entonces ligamos a cabecera
    //y cabecera la hacemos igual a el espacio que reservamos
    if (y == 0)
    {
        x->next = cabecera; //agregamos el elemento que faltaba agregarle al nodo, antes habiamos puesto el dato pero faltaba la liga.
        cabecera = x;       //hacemos el nodo cabecera = al nodo x que contiene liga y dato agregados anteriormente.
    }
    else
    {
        x->next = y->next; //hacemos la liga de x el elemento que estaba despues de y que era el elemento mayor al dato
        y->next = x;       //ligamos y al dato que vamos a agregar.
    }
    return cabecera;
}

//--------------- BORRAR DATO ---------------

//llamado a subprogramas y funciones
void borrar(nodo *&, int);
//subprograma principal de la operacion
void borrardato(void)
{
    int data;
    cout << "escriba dato a eliminar: ";
    cin >> data;
    borrar(cabecera, data);
}
void borrar(nodo *&cabecera, int data)
{
    nodo *x, *y;
    x = cabecera;
    y = NULL;
    while ((x != 0) && (x->data != data))
    {
        y = x;       //y lo hace al dato anterior para que dado el caso de que se incumpla la entrada al ciclo mantiene el valor anterior al que se va a borrar
        x = x->next; //x llega hasta el valor a borrar
    }
    //cuando x llego al final, significa que en ningun tramo del recorrido de la lista se topo con el dato
    if (x == 0)
    {
        cout << "\nel dato no existe en la lista";
    }
    //significa que el elemento a borrar esta en la primera posicion debido a que ni alcanzo a entrar en el while que recorre,
    //por esto en la linea 180 igualamos y a 0.
    else if (y == 0)
    {
        cabecera = cabecera->next;
    }
    else
    {
        y->next = x->next;
    }
    free(x);
}

//--------------- BORRAR DATO REPETIDAMENTE ---------------

//llamado de subprogramas para la operacion
int contador(nodo *, int);
//subprograma principal de la operacion
void borrardatorepetidamente()
{
    int data;
    cout << "escriba el dato a eliminar: ";
    cin >> data;
    int counter = contador(cabecera, data);
    if (counter > 0)
    {
        for (int i = 0; i < counter; i++)
        {
            borrar(cabecera, data);
        }
    }
}
int contador(nodo *cabecera, int data)
{
    nodo *p;
    p = cabecera;
    int counter = 0;
    while (p != 0)
    {
        if (p->data == data)
        {
            counter += 1;
        }
        p = p->next;
    }
    return counter;
}

//--------------- LIBERAR LISTA ---------------

void liberarlista(nodo *&cabecera)
{
    nodo *aux;
    aux = NULL;
    while (cabecera != 0)
    {
        aux = cabecera;
        cabecera = aux->next;
        delete aux;
    }
}

//--------------- MOSTRAR LISTA ---------------

void mostrarlista(nodo *cabecera)
{
    cout << endl;
    if (cabecera != 0)
    {
        nodo *p;
        p = cabecera;
        while (p != 0)
        {
            cout << p->data << "\t->\t";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "la lista esta vacia.\n";
    }
}

//--------------- MOSTRAR LISTA CON DETALLES ---------------

void mostrarlistacondetalles(nodo *cabecera)
{
    cout << endl;
    if (cabecera != 0)
    {
        nodo *p;
        p = cabecera;
        while (p != 0)
        {
            cout << "dato: " << p->data << " dir: " << p << " apunta a: " << p->next << "\t->\t";
            p = p->next;
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "la lista esta vacia.\n";
    }
}

//--------------- BUSCAR DATO ---------------

//llamado a subprogramas necesarios
void buscar(nodo *, int);
//programa principal de la operacion
void buscardato()
{
    int data;
    cout << "escriba elemento a buscar: ";
    cin >> data;
    buscar(cabecera, data);
}
void buscar(nodo *cabecera, int data)
{
    nodo *p;
    p = cabecera;
    int counter = 0;
    while (p != 0)
    {
        if (p->data == data)
        {
            counter += 1;
        }
        p = p->next;
    }
    if (counter > 0)
    {
        cout << "\n\nel dato esta en la lista " << counter << " veces.\n\n";
    }
    else
    {
        cout << "\n\nel dato no esta en la lista.\n\n";
    }
}

//--------------- ORDENAR LISTA ASCENDENTEMENTE ---------------

void ordenamientoascendente(nodo *cabecera)
{
    if (cabecera != 0)
    {
        nodo *p, *q;
        int aux;
        p = cabecera;
        while (p != 0)
        {
            q = p->next;
            while (q != 0)
            {
                if (p->data > q->data)
                {
                    aux = p->data;
                    p->data = q->data;
                    q->data = aux;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
}

//--------------- ORDENAR LISTA DESCENDENTEMENTE ---------------

void ordenamientodescendente(nodo *cabecera)
{
    if (cabecera != 0)
    {
        nodo *p, *q;
        int aux;
        p = cabecera;
        while (p != 0)
        {
            q = p->next;
            while (q != 0)
            {
                if (p->data < q->data)
                {
                    aux = p->data;
                    p->data = q->data;
                    q->data = aux;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
}