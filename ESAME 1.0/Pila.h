#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

/**
 * @file Pila.h
 *
 * @brief Questo file include tutti i prototipi di gestione della pila
 *
 * @version 1.0.0
 * @date 06/07/2023
 * @authors Calabrese lorenzo
 * @authors Cappelluti Claudia Antonia
 * @authors Conforti Francesco
/**

* SIZE_PILA definisce la dimensione del dato char della struct
*/
#define SIZE_PILA 100

/**
* typedef struct Pila definisce una struttura di tipo Stack
*/
typedef struct Pila {
    char dato[SIZE_PILA];
    struct Pila* nextPtr;
} Pila;

/**
* push inserisce un nuova stringa al top della pila
*/

void push(Pila**, const char[]);

/**
* stampaPila e' una procedura in grado di stampare la pila ricevuta come parametro
*/
void stampaPila(Pila*);

/**
* invertiPila inverte la pila ricevuta come parametro
*/
void invertiPila(Pila**);

/**
* svuotaPila elimina gli elementi di una pila
*/
void svuotaPila(Pila**);

#endif  PILA_H_INCLUDED
