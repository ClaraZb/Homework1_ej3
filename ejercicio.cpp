#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int valor;
    shared_ptr<nodo> siguiente;
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
    if (lista.tamanio == 0){
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

    if (lista.tamanio == 0){
        lista.head = nuevonodo;
    }
    else lista.tail -> siguiente = nuevonodo;

    lista.tail = nuevonodo;
    lista.tamanio ++;
    }

void insert(lista_enlazada& lista, int val, int indice){
    if (lista.tamanio == 0){ //la lista esta vacia
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
    while (curr != NULL){
        cout << to_string(curr -> valor) + " -> ";
        curr = curr -> siguiente;
    }
}

/*
v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
el último nodo.
*/