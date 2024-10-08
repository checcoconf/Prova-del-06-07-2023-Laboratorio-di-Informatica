#include "Header.h"
#include "Pila.h"
#include "Gestione_File.h"
#include "Difensiva.h"

/**
*@file  Gestione_File.c
*
*@brief Questo file include tutte le funzioni per la gestione del file
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/

/**
 * apriFile
 * @param[in] *nome_file e' un puntatore a carattere
 * @param[in] *modo e' un puntatore a carattere
 * @param[in] *file e' un puntatore al file
 * @pre nome_file non e' una stringa non nulla.
 * @pre nodo e' una stringa non nulla.
 * @pre file e' un puntatore al puntatore del file e non deve essere  NULL.
 * @return restituisce 1 se il file e' stato aperto con successo
 * @return restituisce 0 se il file non e' stato aperto con successo
 */
int apriFile(const char* nome_file, const char* modo, FILE** file) {
    *file = fopen(nome_file, modo);
    if (*file == NULL) {
        printf(" Errore: impossibile aprire il file '%s'.\n", nome_file);
        return 0;
    }
    return 1;
}

/**
 *chiudiFile
 * @param[in] *file e' un puntatore al file
 *
 *
 * @post ritorna 0 o 1.
 */
int chiudiFile(FILE* file) {
    if(!fclose(file))
        return 0;
    else
        return 1;
}
/**
 * leggiFile
 *
 * @param[in] *nomeFile  e' un puntatore al nome del file.
 * @param[in] *pilaPassata e' un puntatore al puntatore di una pila in cui memorizzare le stringhe lette.
 * @pre *nome_file una stringa non nulla
 */
void leggiFile(const char* nomeFile, Pila** pilaPassata) {
    FILE* file = fopen(nomeFile, "r");
    if (!validatore_file(nomeFile)) {
        free(pilaPassata);
        exit(0);
    }

    int stringheLette = 0, index;
    char riga[SIZE_PILA];
    char stringa[SIZE_PILA];
    unsigned len;

    while (fgets(riga, SIZE_PILA, file) != NULL) {
        len = strlen(riga);
        index = 0;

        // Rimuove i trattini e memorizza la stringa senza trattini
        for (int i = 0; i < len; i++) {
            if (riga[i] != '-') {
                stringa[index] = riga[i];
                index++;
            }
        }
        stringa[index] = '\0';

        rimuoviNewline(stringa);

        push(pilaPassata, stringa);

        stringheLette++;
    }

    chiudiFile(file);

    if (stringheLette < 4) {
        printf("|ERRORE| - Il file in input contiene solo  %d stringhe per cui non e' possibile procedere con l'elaborazione.",stringheLette);
        exit(0);
    }
}

/**
 * Scrive un messaggio in un file specificato.
 *
 * @param[in] *nomeFile e' il nome del file in cui scrivere il messaggio.
 * @param[in] *msg  e' messaggio da scrivere nel file.
 * @param[in] *modo e' la modalità di apertura del file ("r", "w", "a").
 *
 * @pre Il file specificato deve essere aperto correttamente e accessibile in base alla modalità specificata.
 */
void scriviFile(const char*nomeFile, const char*msg, const char* modo){
    FILE* file = fopen(nomeFile, modo);
    fprintf(file,"%s\n",msg);
    chiudiFile(file);
}

/**
 * Scrive il contenuto di una pila formattata in un file specificato.
 *
 * @param[in] *nomeFile e' il nome del file in cui scrivere il contenuto formattato.
 * @param[in] *pila  e' la pila contenente i dati da scrivere nel file.
 *
 * @pre Il file specificato deve essere aperto correttamente e accessibile in modalità di scrittura.
 * @pre La pila deve essere valida e correttamente inizializzata.
 */
void scriviFileFormattato(const char* nomeFile, Pila* pila) {
    if (!validatore_file(nomeFile)) {
        exit(-1);
    }

    Pila* nodoCorrente = pila;
    int lunghezzaTotale = 0;

    lunghezzaTotale += strlen(nodoCorrente->dato);
    char* caratteri = malloc(sizeof(char) * (lunghezzaTotale + 1));

    nodoCorrente = pila;

    // Copia i caratteri nella variabile caratteri
    while (nodoCorrente != NULL) {

        int index = 0;
        for (int i = 0; nodoCorrente->dato[i] != '\0'; i++) {
            if (nodoCorrente->dato[i] == '\0'){
                caratteri[index] = '\n';
                index++;
            }else{
                caratteri[index] = nodoCorrente->dato[i];
                index++;
                caratteri[index] = '-';
                index++;
            }
        }
        // Rimuovi l'ultimo trattino
        if (index > 0) {
            caratteri[index - 1] = '\0';
        }
        scriviFile(nomeFile,caratteri,"a+");
        nodoCorrente = nodoCorrente->nextPtr;
    }
}

/**
 * Scrive un messaggio di log in un file di log.
 *
 * @param[in] *messaggio  e' il messaggio da scrivere nel file di log.
 *
 * @pre Il file di log "Log.txt" deve essere accessibile e scrivibile.
 */
void scrivi_log(const char* messaggio) {
    FILE* file = fopen("Log.txt", "a");

    if (file != NULL) {
        time_t timestamp = time(NULL);
        struct tm* tempo = localtime(&timestamp);

        // Ottiene la data e l'ora corrente
        char data_ora[20];
        strftime(data_ora, sizeof(data_ora), "%Y-%m-%d %H:%M:%S", tempo);

        // Scrive il messaggio di log nel file
        fprintf(file, "[%s] %s\n", data_ora, messaggio);

        fclose(file);
    } else {
        printf(" Errore nell'apertura del file di log.\n");
    }
}
