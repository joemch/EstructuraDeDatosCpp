#ifdef __linux__
#define LIMPIAR "CLEAR"
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__

#ifdef __MINGW64__
#define LIMPIAR "CLS"
#endif // __MINGW64__


#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    struct Nodo* sgte;
};

struct Lista{
    struct Nodo* Primero;
    struct Nodo* Ultimo;
    int tamLista;
};

typedef struct Nodo* punteroNodo;

struct Lista lista;
struct Lista* punteroLista = &lista;

void menu();
void resetear(Lista* lista);
void insertarInicio(Lista* lista, int valor);
void insertarFinal(Lista* lista, int valor);
void mostrarLista(Lista* lista);
int insertarPos(Lista* lista, int pos, int num);
bool isVacia(Lista* lista);
void eliminarInicio(Lista* lista);
void eliminarFinal(Lista* lista);
int eliminarPos(Lista* lista, int pos);
void eliminarLista(Lista* lista);
int buscarElemento(Lista* lista, int elemento);

int main(void){
    menu();
    return 0;
}

void menu(){
    int op=0, num=0, pos=0;
    do{
    cout << "\t+-------------------------------------+" << endl;
    cout << "\t|      Lista Simple Enlazada          |" << endl;
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
    cin >>op;
    switch(op){
        case 1: resetear(punteroLista);
                cout << "\tLista creada..." << endl;
                cout << "\tPresione una tecla para continuar";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;

        case 2: cout<<"\tNumero a insertar: ";
                cin>>num;
                insertarInicio(punteroLista,num);
                system(LIMPIAR);
                break;

        case 3: cout << "\tNumero a insertar: ";
                cin  >> num;
                insertarFinal(punteroLista,num);
                system(LIMPIAR);
                break;

        case 4: cout << "\tNumero a insertar: ";
                cin  >> num;
                cout << "\tPosicion: ";
                cin  >> pos;
                insertarPos(punteroLista, pos, num);
                system(LIMPIAR);
                break;

        case 5: eliminarInicio(punteroLista);
                system(LIMPIAR);
                break;

        case 6: eliminarFinal(punteroLista);
                system(LIMPIAR);
                break;

        case 7: cout << "\tPosicion a eliminar: ";
                cin  >> pos;
                eliminarPos(punteroLista, pos);
                system(LIMPIAR);
                break;

        case 8: eliminarLista(punteroLista);
                system(LIMPIAR);
                break;

        case 9: mostrarLista(punteroLista);
                cout << "\tPresione una tecla para continuar";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;

        case 10: cout << "\tElemento a buscar: ";
                 cin  >> num;
                 buscarElemento(punteroLista,num);
                 cout << "\tPresione una tecla para continuar";
                 cin.sync();
                 cin.get();
                 system(LIMPIAR);
                 break;

        case 11: cout << "\tGood Bye";
                 break;

        default :
                cout<<"\t[msgError]: Opcion no valida.";
                cin.sync();
                cin.get();
                system(LIMPIAR);
                break;
    }
  }while(op != 11);//Fin de do
}

void resetear(Lista* lista){
    lista->Primero = NULL;
    lista->Ultimo = NULL;
    lista->tamLista = 0;
}

void insertarInicio(Lista* lista, int valor){
    punteroNodo nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->sgte = NULL;
    if(isVacia(lista)){
        lista->Primero = nuevo;
        lista->Ultimo = nuevo;
    }
    else{
        nuevo->sgte = lista->Primero;
        lista->Primero = nuevo;
    }

    lista->tamLista++;
}

void insertarFinal(Lista* lista, int valor){
    punteroNodo nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->sgte = NULL;

    if(isVacia(lista)){
        lista->Primero = nuevo;
        lista->Ultimo = nuevo;
    }
    else{
        lista->Ultimo->sgte = nuevo;
        lista->Ultimo = nuevo;
    }
    lista->tamLista++;
}

void mostrarLista(Lista* lista){

    if(isVacia(lista)){
        cout<<"\tLa lista esta vacia.\n";
    }
    else{
        punteroNodo tmp = lista->Primero;
        cout<<"\t";
        while(tmp!=NULL){
            cout << tmp->dato <<"-->";
            tmp = tmp->sgte;
        }
        cout<<"NULL\n";
    }
}

int insertarPos(Lista* lista, int pos, int num){
    if(pos>lista->tamLista || pos<1){
        cout<<"\tEsa posicion no existe."<<endl;
        cin.sync();
        cin.get();
        return 1;
    }
    else{
        if(pos==1){
            insertarInicio(lista, num);
            return 0;
        } //Fin de if

        else if(pos==lista->tamLista+1){
            insertarFinal(lista, num);
            return 0;
        } //Fin de else if

        punteroNodo nuevo = new Nodo;
        nuevo->dato = num;
        punteroNodo aux = lista->Primero;
        for(int i=1; i<pos-1;i++){
            aux = aux->sgte;
        }

        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
        lista->tamLista++;
    }
    return 0;
}

bool isVacia(Lista* lista){
    return lista->Primero==NULL;
}

void eliminarInicio(Lista* lista){
    if(isVacia(lista)){
        cout<<"\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
    }
    else{
        punteroNodo tmp = lista->Primero;
        lista->Primero = lista->Primero->sgte;
        delete tmp;
        lista->tamLista--;

        if(isVacia(lista)){
            resetear(lista);
        }
    }
}

void eliminarFinal(Lista* lista){

    if(isVacia(lista)){
        cout<<"\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
    }
    //En caso haya 1 elemento
    else if(lista->Primero==lista->Ultimo){
        eliminarInicio(lista);
    }
    else{
        punteroNodo tmp;
        punteroNodo aux = lista->Primero;
        while(aux->sgte!=lista->Ultimo){
            aux = aux->sgte;
        }
        tmp = aux->sgte;
        lista->Ultimo = aux;
        aux->sgte = NULL;
        delete tmp;
        lista->tamLista--;

        if(lista->tamLista==0)
            resetear(lista);
    }

}

int eliminarPos(Lista* lista, int pos){

    if(pos > lista->tamLista || pos < 1)
    {
        cout << "\tEsa posicion no existe." << endl;
        cin.sync();
        cin.get();
        return -1;
    }
    else
    {
        if(isVacia(lista))
        {
            cout << "\tLa lista esta vacia.\n";
            cin.sync();
            cin.get();
            return -1;
        }
        else
        {
            if(pos == lista->tamLista)
            {
                eliminarFinal(lista);
                return 0;
            }
            else if(pos == 1)
            {
                eliminarInicio(lista);
                return 0;
            }

            punteroNodo tmp;
            punteroNodo aux = lista->Primero;

            for(int i=1 ; i<pos-1; i++)
                aux = aux->sgte;

            tmp = aux->sgte;
            aux->sgte = tmp->sgte;
            delete tmp;
            lista->tamLista--;

            if(isVacia(lista))
                resetear(lista);
        }
    }
    return 0;
}

void eliminarLista(Lista* lista){
    if(isVacia(lista)){
        cout<<"\tLa lista ya esta vacia.\n";
        cin.sync();
        cin.get();
    }
    else
    {
        while(!isVacia(lista))
        {
            punteroNodo tmp = lista->Primero;
            lista->Primero = lista->Primero->sgte;
            delete tmp;
        }
        resetear(lista);
    }
}

int buscarElemento(Lista* lista, int elemento){

   if(isVacia(lista))
    {
        cout << "\tLa lista esta vacia.\n";
        cin.sync();
        cin.get();
       return -1;
    }
   else
    {
       int cont = 1;
       punteroNodo tmp = lista->Primero;
       while(tmp != NULL){
           if(tmp->dato == elemento)
            {
               cout << "\tElemento encontrado.!" << endl;
               cout << "\tPosicion: " << cont << endl;
               cout << "\tdato: " << tmp->dato << endl;
               return 0;
            }
           tmp = tmp->sgte;
           cont++;
       }
       cout << "\tDato no encontrado." << endl;
    }
   return 0;
}
