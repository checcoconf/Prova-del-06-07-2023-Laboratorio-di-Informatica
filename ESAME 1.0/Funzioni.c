#include"header.h"
#include "Funzioni.h"
#include "InputOutput.h."
#include "Pila.h"

/**
*@file Funzioni.c
*
*@brief Questo file include le funzioni di dominio
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/


/**
*sostituisci
*@param[in] *pila e'un puntatore alla struct Pila
*@param[in] *elementoDaSostituire e'un puntatore a carattere
*@param[in] *nuovoElemento e' un puntatore a carattere
*@pre la pila e' nulla
*@return restituisce una nuova pila con le dovute sostituzioni
*/

Pila* sostituisci(Pila** pila, const char* elementoDaSostituire, const char* nuovoElemento) {
    Pila* pilaModificata = NULL;
    Pila* nodoCorrente = *pila;
    Pila* nodoPrecedente = NULL;
    bool trovataOccorrenza = false;

    while (nodoCorrente != NULL) {
        Pila* nuovoNodo = malloc(sizeof(Pila));
        strcpy(nuovoNodo->dato, nodoCorrente->dato);
        nuovoNodo->nextPtr = NULL;

        if (strcmp(nodoCorrente->dato, nuovoElemento) == 0) {
            printf("E' stata trovata un'occorrenza!\nNessuna operazione effettuata\n");
            gestoreScelta(*pila);
            trovataOccorrenza = true;
        } else if (strcmp(nodoCorrente->dato, elementoDaSostituire) == 0) {
            strcpy(nuovoNodo->dato, nuovoElemento);
            trovataOccorrenza = true;
        }

        if (pilaModificata == NULL) {
            pilaModificata = nuovoNodo;
        } else {
            nodoPrecedente->nextPtr = nuovoNodo;
        }

        nodoPrecedente = nuovoNodo;
        nodoCorrente = nodoCorrente->nextPtr;
    }

    if (!trovataOccorrenza) {
        printf("Parola |%s| non trovata!\n",elementoDaSostituire);
        gestoreScelta(*pila);
    }

    return pilaModificata;
}

/**
*contaAlfanumerico
*@param[in] *str e' un puntatore a carattere
*@pre la stringa non deve essere nulla
*@return restituisce il numero di caratteri alfanumerici
*/
int contaAlfanumerico(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]))
            count++;
    }
    return count;
}


/**
*contaNumeri
*@param[in] *str e' un puntatore a carattere
*@pre la stringa non deve essere nulla
*@return restituisce il numero dei numeri presenti nella stringa
*/
int contaNumeri(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]))
            count++;
    }
    return count;
}

/**
*contaVocali
*@param[in] *str e' un puntatore a carattere
*@pre la stringa non deve essere nulla
*@return restituisce il numero di vocali presenti nella stringa
*/
int contaVocali(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}
/**
*swap
*@param[in] *a e' un puntatore alla struttura Pila
*@param[in] *b e' un puntatore alla struttura Pila
*/
void swap(Pila* a, Pila* b) {
    char temp[SIZE_PILA];
    strcpy(temp, a->dato);
    strcpy(a->dato, b->dato);
    strcpy(b->dato, temp);
}
/**
*clonaPila
*@param[in] *pilaOriginale e' un puntatore alla struttura Pila
*@return restituisce una pila clonata a quella passata per riferimento
*/
Pila* clonaPila(const Pila* pilaOriginale) {
    if (pilaOriginale == NULL)
        return NULL;

    Pila* nuovaPila = malloc(sizeof(Pila));
    strcpy(nuovaPila->dato, pilaOriginale->dato);
    nuovaPila->nextPtr = clonaPila(pilaOriginale->nextPtr);

    return nuovaPila;
}

/**
*bubbleSortRicorsivo
*@param[in] *pila e' un puntatore alla struttura Pila
*@pre la pila non deve essere nulla e nemmemeno l'elemento successivo
*@return restituisce una nuova pila ordinata secondo una specifica relazione d'ordine
*/
//Crescente
Pila* bubbleSortRicorsivo(Pila** pila) {
    if (pila == NULL || (*pila)->nextPtr == NULL)
        return clonaPila(*pila); // Clona la pila originale e restituisce una nuova pila

    Pila* pilaOrdinata = clonaPila(*pila); // Clona la pila originale per creare una nuova pila ordinata

    int caratteriAlfabetici = contaAlfanumerico(pilaOrdinata->dato);
    int caratteriNumerici = contaNumeri(pilaOrdinata->dato);
    int caratteriVocali = contaVocali(pilaOrdinata->dato);

    Pila* current = pilaOrdinata;
    Pila* next = pilaOrdinata->nextPtr;

    if (caratteriAlfabetici > contaAlfanumerico(next->dato) || (caratteriAlfabetici == contaAlfanumerico(next->dato) &&
         caratteriNumerici > contaNumeri(next->dato)) ||
         (caratteriAlfabetici == contaAlfanumerico(next->dato) &&
            caratteriNumerici == contaNumeri(next->dato) &&
            caratteriVocali > contaVocali(next->dato))) {
        swap(current, next);
    }

    pilaOrdinata->nextPtr = bubbleSortRicorsivo(&pilaOrdinata->nextPtr);
    return pilaOrdinata;
}



