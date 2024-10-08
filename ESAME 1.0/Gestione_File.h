#ifndef GESTIONE_FILE_H_INCLUDED
#define GESTIONE_FILE_H_INCLUDED

/**
*@file  Gestione_File.h
*
*@brief Questo file include tutti i prototipi per la gestione del file
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/

#include "Header.h"
#include "Pila.h"

/**
* apriFile e' una funzione che si occupa dell'apertura del file
*/
int apriFile(const char*, const char*, FILE**);

/**
* leggiFile e' una procedura che si occupa della lettura del file
*/
void leggiFile(const char*,Pila**);

/**
* chiudiFile e' una funzione che si occupa della chiusura del file
*/
int chiudiFile(FILE*);

/**
* scriviFile e' una procedura che permette la scrittura su file
*/
void scriviFile(const char *,const char*, const char*);

/**
*scriviFileFormattato e' una procedura che permette la scrittura su file mantenendo il formato acquisito
*/
void scriviFileFormattato(const char *,Pila *);

/**
*scrivi_log è una procedura che tiene traccia delle operazioni svolte nel programma
*/
void scrivi_log(const char*);

#endif  GESTIONE_FILE_H_INCLUDED
