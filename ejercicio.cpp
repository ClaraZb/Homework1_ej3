#include <iostream>
#include <memory>
using namespace std;

/*
Utilizo shared pointers. Defino dos structs, uno para el nodo y otro
para la lista enlazada. Me baso en mi codigo del tp de la materia algoritmos.  
Dentro de las funciones manejo los casos problematicos (si la lista esta vacia,
si solo tiene un elemento, etc...)
*/

struct nodo{
    int valor;
    shared_ptr<nodo> siguiente;

    nodo(int val) : valor(val), siguiente(nullptr) {} //constructor
};

struct lista_enlazada{
    shared_ptr<nodo> head;
    shared_ptr<nodo> tail;
    int tamanio;
};

shared_ptr <nodo> create_node(int val){
    return make_shared<nodo>(val);
}

void push_front(lista_enlazada& lista, int val){
    shared_ptr<nodo> nuevonodo = create_node(val);
    nuevonodo -> valor = val;
    if (lista.tamanio == 0){ //lista vacia
        nuevonodo -> siguiente = NULL;
        lista.tail = nuevonodo;
    }
    else nuevonodo -> siguiente = lista.head;
    lista.head = nuevonodo;
    lista.tamanio ++;
}

void push_back(lista_enlazada& lista, int val){
    shared_ptr<nodo> nuevonodo = create_node(val);
    nuevonodo -> valor = val;
    nuevonodo -> siguiente = NULL;

    if (lista.tamanio == 0){ //lista vacia
        lista.head = nuevonodo;
    }
    else lista.tail -> siguiente = nuevonodo;

    lista.tail = nuevonodo;
    lista.tamanio ++;
    }

void insert(lista_enlazada& lista, int val, int indice){
    if (lista.tamanio == 0){ //lista vacia
        push_front(lista, val);
        return;
    }
    if (indice > lista.tamanio){ //indice invalido
        cout << "indice invalido" << endl;
        push_back(lista, val);
        return;
    }
    if (indice == 0) {
        push_front(lista, val); //insertamos al inicio
        return;
    }
    if (indice == lista.tamanio) {
        push_back(lista, val); //insertamos al final
        return;
    }

    //insertamos al medio
    shared_ptr<nodo> curr = lista.head;
    int contador = 0;
    while (contador < indice - 1){
        curr = curr -> siguiente;
        contador++;
    } //nos paramos en el nodo anterior a la insercion

    shared_ptr<nodo> nuevonodo = create_node(val);
    nuevonodo -> valor = val;
    shared_ptr<nodo> temp = curr -> siguiente;
    curr -> siguiente = nuevonodo;
    nuevonodo -> siguiente = temp;
    lista.tamanio++;
}

void print_list(lista_enlazada lista){
    shared_ptr<nodo> curr = lista.head;
    if (curr != NULL) cout << curr -> valor;
    while (curr -> siguiente != NULL){
        curr = curr -> siguiente;
        cout << " -> " + to_string(curr -> valor);
    }
    cout << endl;
}

void erase(lista_enlazada& lista, int indice){
    if (lista.tamanio == 0) return; // lista vacia
    if (indice >= lista.tamanio) indice = lista.tamanio - 1; //indice invalido

    shared_ptr<nodo> curr = lista.head;
    if (indice == 0){ // borramos el primer nodo
        if (lista.tamanio == 1) {
            lista.tail = NULL;
            lista.head = NULL;
        } // si era el unico nodo
        lista.head = curr -> siguiente;
        curr -> siguiente = NULL;
        lista.tamanio--;
        return;
    }

    int contador = 0;
    while (contador < indice - 1){
        curr = curr -> siguiente;
        contador++;
    } // nos paramos en el nodo anterior al nodo a borrar

    shared_ptr<nodo> temp = curr -> siguiente;
    curr -> siguiente = temp -> siguiente;
    temp -> siguiente = NULL;
    if (indice == lista.tamanio - 1) lista.tail = curr; //borramos el ultimo nodo    
    lista.tamanio--;
    return;
}

int main() {
    lista_enlazada lista;
    lista.head = NULL;
    lista.tail = NULL;
    lista.tamanio = 0;

    //test push_front
    push_front(lista, 10);
    push_front(lista, 20);
    cout << "Estado post push_front: ";
    print_list(lista);

    //test push_back
    push_back(lista, 40);
    push_back(lista, 50);
    cout << "Estado post push back: ";
    print_list(lista);

    //test insert
    cout << "Estado post inserciones segun el indice: \n";
    insert(lista, 25, 2);
    print_list(lista);
    insert(lista, 5, 0);
    print_list(lista);
    insert(lista, 60, lista.tamanio);
    print_list(lista);
    insert(lista, 4, lista.tamanio + 2);
    print_list(lista);

    //test erase
    erase(lista, 0);
    erase(lista, 2); 
    erase(lista, lista.tamanio - 1); 
    cout << "Estado post eliminaciones: ";
    print_list(lista);

    return 0;
}