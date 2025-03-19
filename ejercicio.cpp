#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int valor;
    shared_ptr<nodo> siguiente;
//Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};
//hola

struct lista_enlazada{
    shared_ptr<nodo> head;
    shared_ptr<nodo> tail;
    int tamanio;
};

shared_ptr <nodo> create_node(int val){
    return make_shared<nodo>(val);
}

void push_front(lista_enlazada lista, int val){
    shared_ptr<nodo> nuevonodo = create_node(val);
    nuevonodo -> valor = val;
    nuevonodo -> siguiente = lista.head;
    lista.head = nuevonodo;
    lista.tamanio ++;

    if (lista.tail == NULL) lista.tail = nuevonodo;
}

void push_back(lista_enlazada lista, int val){
    shared_ptr<nodo> nuevonodo = create_node(val);
    nuevonodo -> valor = val;
    nuevonodo -> siguiente = NULL;

    if (lista.tail != NULL){
    lista.tail -> siguiente = nuevonodo;
    }
    else{
        lista.head = nuevonodo;
    }
    lista.tail = nuevonodo;

    lista.tamanio ++;
    }

/*
iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa
una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de
agregar el nodo al final de la lista.
v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
el último nodo.
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”.
*/