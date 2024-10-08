#ifndef INPUTOUTPUT_H_INCLUDED
#define INPUTOUTPUT_H_INCLUDED

/**
 * @file InputOutput.h
 *
 * @brief Questo file include tutte i prototipi di Input e Output verso l'utente
 *
 * @version 1.0.0
 * @date 06/07/2023
 * @authors Calabrese lorenzo
 * @authors Cappelluti Claudia Antonia
 * @authors Conforti Francesco
*/

#include "Header.h"
#include "Pila.h"

/**
* acquisiscinomefile acquisisce in input il nome del file
*/
char* acquisisciNomeFile(char*);

/**
* acquisisciStringa acquisisce una stringa dalla tastiera
*/
char* acquisisciStringa(char*);

/**
* visualizzaMenu e' una funzione che permette di visualizzare il menu di scelta
*/
void visualizzaMenu();

/**
* gestoreScelta è una procedura che gestisce la scelta dell'utente
*/
void gestoreScelta(Pila *);

/**
* visualizzaChiusura e' un'animazione di chiusura del gestionale
*/
void visualizzaChiusura();


#endif INPUTOUTPUT_H_INCLUDED
