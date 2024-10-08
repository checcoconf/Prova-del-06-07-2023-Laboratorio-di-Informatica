#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

/**
*@file Funzioni.h
*
*@brief Questo file include i prototipi delle funzioni di dominio
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/

#include "header.h"
#include "Pila.h"

/**
* sostituisci restituisce la pila con gli elementi sostituiti
*/
Pila *sostituisci(Pila**, const char*, const char*);

/**
* bubbleSortRicorsivo restituisce la pila ordinata
*/
Pila* bubbleSortRicorsivo(Pila **);

/**
* swap esegue lo scambio tra i top delle due pile ricevute come parametro
*/
void swap(Pila* , Pila* );

/**
* contaVocali conta le vocali della stringa ricevuta come parametro
*/
int contaVocali(const char*);


/**
* contaNumeri conta i numeri della stringa ricevuta come parametro
*/
int contaNumeri (const char* );

/**
* contaAlfanumerico conta gli elementi della stringa ricevuta come parametro che sono delle lettere :
*/
int contaAlfanumerico (const char*);

/**
* clonaPila crea una copia di una pila passata  per riferimento
*/
Pila* clonaPila(const Pila*);

#endif  FUNZIONI_H_INCLUDED
