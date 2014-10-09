#ifdef __linux__
#define LIMPIAR "CLEAR"
#endif

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif

#ifdef __MINGW64__
#define LIMPIAR "CLS"
#endif

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    struct Nodo* anterior;
    struct Nodo* sgte;
};

struct ListaDoble{
    struct Nodo* Inicio;
    struct Nodo* Fin;
    int tamLista;
};

typedef struct Nodo* punteroNodo;
struct ListaDoble listaDoble;
struct ListaDoble* punteroListaDoble = &listaDoble;

int buscarElemento(ListaDoble* listaDoble, int elemento);
void eliminarInicio(ListaDoble* listaDoble);
void eliminarFinal(ListaDoble* listaDoble);
int eliminarPos(ListaDoble* listaDoble, int pos);
void eliminarListaDoble(ListaDoble* listaDoble);
void insertarInicio(ListaDoble* listaDoble, int num);
void insertarFinal(ListaDoble* listaDoble, int num);
int insertarPos(ListaDoble* listaDoble, int num, int pos);
bool isVacia(ListaDoble* listaDoble);
void menu();
void mostrarListaDoble(ListaDoble* listaDoble);
void resetear(ListaDoble* listaDoble);

int main(){
    menu();
    return 0;
}

void menu()
{
    system(LIMPIAR);
    int op=0, num=0, pos=0;
    do{
    cout << "\t+-------------------------------------+" << endl;
    cout << "\t|      Lista Enlazada Doble           |" << endl;
    cout << "\t+-------------------------------------+" << endl;
    cout << "\t| 1. Inicializar Lista.               |" << endl;
    cout << "\t| 2. Insertar al inicio.              |" << endl;
    cout << "\t| 3. Insertar al final.               |" << endl;
    cout << "\t| 4. Insertar en posicion.            |" << endl;
    cout << "\t| 5. Eliminar primer elemento.        |" << endl;
    cout << "\t| 6. Eliminar ultimo elemento.        |" << endl;
    cout << "\t| 7. Eliminar posicion.               |" << endl;
    cout << "\t| 8. Eliminar lista.                  |" << endl;
    cout << "\t| 9. Mostrar lista.                   |" << endl;
    cout << "\t| 10. Buscar elemento.                |" << endl;
    cout << "\t| 11. Salir.                          |" << endl;
    cout << "\t+-------------------------------------+" << endl;
    cout << "\t  Ingrese Opcion: ";
    cin  >> op;

    switch(op){
        case 1: resetear(punteroListaDoble);
                cout << "\tLista doble creada..." << endl;
                cout << "\tPresione una tecla para continuar";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;

        case 2: cout << "\tnumero a insertar: ";
                cin >> num;
                insertarInicio(punteroListaDoble,num);
                system(LIMPIAR);
                break;

        case 3: cout << "\tnumero a insertar: ";
                cin  >> num;
                insertarFinal(punteroListaDoble,num);
                system(LIMPIAR);
                break;

        case 4: cout << "\tNumero a insertar: ";
                cin  >> num;
                cout << "\tPosicion: ";
                cin  >> pos;
                insertarPos(punteroListaDoble,num, pos);
                system(LIMPIAR);
                break;

        case 5: eliminarInicio(punteroListaDoble);
                system(LIMPIAR);
                break;

        case 6: eliminarFinal(punteroListaDoble);
                system(LIMPIAR);
                break;

        case 7: cout << "\tPosicion a eliminar: ";
                cin  >> pos;
                eliminarPos(punteroListaDoble,pos);
                system(LIMPIAR);
                break;

        case 8: eliminarListaDoble(punteroListaDoble);
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;

        case 9: mostrarListaDoble(punteroListaDoble);
                cout<<"\tPresione una tecla para continuar";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;

        case 10: cout << "\tElemento a buscar: ";
                 cin  >> num;
                 buscarElemento(punteroListaDoble,num);
                 cout << "\tPresione una tecla para continuar";
                 cin.sync();
                 cin.get();
                 system(LIMPIAR);
                 break;

        case 11:
                cout << "\tGood Bye";
                break;

        default :
                cout << "\t[msgError]: Opcion no valida.";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;
    }
  }while(op!=11);
}

void resetear(ListaDoble* listaDoble)
{
    listaDoble->Inicio = NULL;
    listaDoble->Fin = NULL;
    listaDoble->tamLista = 0;
}

void insertarInicio(ListaDoble* listaDoble, int num)
{
    punteroNodo nuevo = new Nodo;
    nuevo->dato = num;
    nuevo->anterior = NULL;

    if(isVacia(listaDoble))
    {
        listaDoble->Inicio = nuevo;
        listaDoble->Fin = nuevo;
        nuevo->sgte = NULL;
    }
    else
    {
        nuevo->sgte = listaDoble->Inicio;
        listaDoble->Inicio->anterior = nuevo;
        listaDoble->Inicio = nuevo;
    }

    listaDoble->tamLista++;
}

void insertarFinal(ListaDoble* listaDoble, int num)
{

    punteroNodo nuevo = new Nodo;
    nuevo->dato = num;
    nuevo->sgte = NULL;

    if(isVacia(listaDoble))
    {
        listaDoble->Inicio = nuevo;
        listaDoble->Fin = nuevo;
        nuevo->sgte = NULL;
    }
    else
    {
        nuevo->anterior = listaDoble->Fin;
        listaDoble->Fin->sgte = nuevo;
        listaDoble->Fin = nuevo;
    }

    listaDoble->tamLista++;
}

int insertarPos(ListaDoble* listaDoble, int num, int pos){

    if(pos>listaDoble->tamLista || pos<1)
    {
        cout<<"\tEsa posicion no existe."<<endl;
        cin.sync();
        cin.get();
        return -1;
    }
    else
    {
        if(pos == 1)
        {
            insertarInicio(listaDoble,num);
            return 0;
        }
        else if(pos == listaDoble->tamLista+1)
        {
            insertarFinal(listaDoble,num);
            return 0;
        }
        else
        {
            punteroNodo nuevo = new Nodo;
            nuevo->dato = num;
            punteroNodo aux = listaDoble->Inicio;

            for(int i=0; i<pos-1; i++)
                aux = aux->sgte;

            nuevo->sgte = aux;
            nuevo->anterior = aux->anterior;
            aux->anterior->sgte = nuevo;
            aux->anterior = nuevo;
            listaDoble->tamLista++;
        }
    }
    return 0;
}

void eliminarInicio(ListaDoble* listaDoble)
{
    if(isVacia(listaDoble))
    {
        cout << "\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
    }
    else
    {
        punteroNodo tmp = listaDoble->Inicio;
        listaDoble->Inicio = listaDoble->Inicio->sgte;
        listaDoble->Inicio->anterior = NULL;
        delete tmp;
        listaDoble->tamLista--;

        if(listaDoble->tamLista == 0)
            resetear(listaDoble);
    }
}

void eliminarFinal(ListaDoble* listaDoble)
{

    if(isVacia(listaDoble))
    {
        cout << "\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
    }
    else
    {
        punteroNodo tmp = listaDoble->Fin;
        listaDoble->Fin = listaDoble->Fin->anterior;
        listaDoble->Fin->sgte = NULL;
        delete tmp;
        listaDoble->tamLista--;

        if(listaDoble->tamLista == 0)
            resetear(listaDoble);
    }
}

int eliminarPos(ListaDoble* listaDoble, int pos)
{
    if(pos > listaDoble->tamLista || pos < 1)
    {
        cout<<"\tEsa posicion no existe."<<endl;
        cin.sync();
        cin.get();
        return -1;
    }
    else{
        if(isVacia(listaDoble))
        {
            cout<<"\tLa lista esta vacia.\n";
            cin.sync();
            cin.get();
            return -1;
        }

        else
        {
            if(pos == listaDoble->tamLista+1)
            {
                eliminarFinal(listaDoble);
                return 0;
            }
            else if(pos == 1)
            {
                eliminarInicio(listaDoble);
                return 0;
            }

            punteroNodo tmp;
            punteroNodo aux = listaDoble->Inicio;

            for(int i=1; i<pos; i++)
                aux = aux->sgte;

            tmp = aux;
            aux->anterior->sgte = aux->sgte;
            aux->sgte->anterior = aux->anterior;
            delete tmp;
            listaDoble->tamLista--;

            if(listaDoble->tamLista == 0)
                resetear(listaDoble);
        }
    }
    return 0;
}

bool isVacia(ListaDoble* listaDoble)
{
    return listaDoble->Inicio == NULL;
}

void mostrarListaDoble(ListaDoble* listaDoble)
{

    if(isVacia(listaDoble))
    {
        cout<<"\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
    }
    else
    {
        punteroNodo aux = listaDoble->Inicio;
        cout<<"\tNULL<--> ";
        while(aux != NULL)
        {
            cout << aux->dato << " <--> ";
            aux = aux->sgte;
        }
        cout<<"NULL\n";
    }
}

void eliminarListaDoble(ListaDoble* listaDoble)
{

    if(isVacia(listaDoble))
    {
        cout<<"\tLa lista ya esta vacia.\n";
        cin.sync();
        cin.get();
    }
    while(listaDoble->Inicio != NULL)
    {
        punteroNodo tmp = listaDoble->Inicio;
        listaDoble->Inicio = listaDoble->Inicio->sgte;
        delete tmp;
    }
    resetear(listaDoble);
}

int buscarElemento(ListaDoble* listaDoble, int elemento)
{

   if(isVacia(listaDoble))
    {
        cout << "\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
        return -1;
    }

   int cont = 1;
   punteroNodo aux = listaDoble->Inicio;

   while(aux != NULL)
    {
       if(aux->dato == elemento)
       {
           cout << "\tElemento encontrado.!" << endl;
           cout << "\tPosicion: " << cont << endl;
           cout << "\tDato: " << aux->dato << endl;
           return 0;
       }
       aux = aux->sgte;
       cont++;
    }
    cout << "\tDato no encontrado." << endl;
    return -1;
}
