#ifndef DIFENSIVA_H_INCLUDED
#define DIFENSIVA_H_INCLUDED

/**
*@file Difensiva.h
*
*@brief Questo file include delle funzioni utili per la programmazione difensiva
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/

#include "header.h"

/**
* valida_nome_file prende in input il nome del file inserito dall'utente
*/

bool valida_nome_file(const char *);

/**
 * valida_estensione_file prende in input il nome del file inserito dall' utente\n e verifica che l'estensione del file sia .txt
 */
bool valida_estensione_file(const char *);

/**
 * validatore_file prende in input il nome del file inserito dall'utente\n e verificano la validazione del file
 */
bool validatore_file(const char *);

/**
* rimuoviNewline prende in input la stringa sostituisce "\\n" con "\\n"
*/
void rimuoviNewline(char* );

/**
* controlloStringa prende in input la stringa ed esegue un controllo sulla correttezza
*/

char* controlloStringa(char* stringa);

/**
* pulisciFile è una procedura che rimuove le righe del file
*/

void pulisciFile (const char* );

#endif  DIFENSIVA_H_INCLUDED
