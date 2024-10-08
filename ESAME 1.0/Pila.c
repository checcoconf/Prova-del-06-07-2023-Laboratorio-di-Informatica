#include "Header.h"
#include "Pila.h"

/**
 * @file Pila.c
 *
 * @brief Questo file include tutte le funzioni di gestione della pila
 *
 * @version 1.0.0
 * @date 06/07/2023
 * @authors Calabrese lorenzo
 * @authors Cappelluti Claudia Antonia
 * @authors Conforti Francesco
/**

/**
*Push
* @param[in] *pilaPassata e' un puntatore al puntatore della Pila
* @param[in] *dato e' una stringa
* @pre Il puntatore alla pila non deve essere NULL
*/
void push(Pila** pilaPassata, const char* dato) {
    Pila* P = malloc(sizeof(Pila));
    if (P == NULL) {
        printf("|ERRORE| - L'elemento non e' stato inserito!\nNon c'è memoria.\n");
        return;
    }

    strncpy(P->dato, dato, SIZE_PILA - 1);
    P->dato[SIZE_PILA - 1] = '\0'; //aggiunge lo \0 a fine carattere
    P->nextPtr = *pilaPassata;
    *pilaPassata = P;
}

/**
* stampaPila
* @param[in] *pilaCorrente e' un puntatore che punta alla pila
* @pre Il puntatore alla pila non deve essere NULL
*/
void stampaPila(Pila* pilaCorrente){
    if (pilaCorrente == NULL){
        printf("La Pila e' vuota.\n");
    }else{
        puts(" ");
        while (pilaCorrente != NULL){
            printf("%s --> ",pilaCorrente->dato);
            pilaCorrente = pilaCorrente->nextPtr;
        }
        printf("NULL\n");
    }
}

/**
* invertiPila
* @param[in] *pilaPassata e' un puntatore al puntatore della Pila
* @pre Il puntatore alla pila non deve essere NULL
*/
void invertiPila(Pila** pilaPassata) {
    Pila* pilaInvertita = NULL;
    while (*pilaPassata != NULL) {
        Pila* nodoCorrente = *pilaPassata;
        *pilaPassata = nodoCorrente->nextPtr;

        nodoCorrente->nextPtr = pilaInvertita;
        pilaInvertita = nodoCorrente;
    }
    *pilaPassata = pilaInvertita;
}

/**
* svuotaPila
* @param[in] *pilaPassata e' un puntatore al puntatore della Pila
* @pre Il puntatore alla pila non deve essere NULL
*/
void svuotaPila(Pila** pila) {
    Pila* nodoCorrente = *pila;

    while (nodoCorrente != NULL) {
        Pila* nodoSuccessivo = nodoCorrente->nextPtr;
        free(nodoCorrente);
        nodoCorrente = nodoSuccessivo;
    }

    *pila = NULL; // Imposta il puntatore alla pila come NULL per indicare una pila vuota
}
