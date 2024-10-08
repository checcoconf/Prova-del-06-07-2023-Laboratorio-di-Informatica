#include "Difensiva.h"
#include "Gestione_File.h"

/**
*@file Difensiva.c
*
*@brief Questo file include tutte le implementazioni riguardanti la programmazione difensiva
*
*@version 1.0.0
*@date 06/07/2023
*@authors Calabrese Lorenzo
*@authors Cappelluti Claudia Antonia
*@authors Conforti Francesco
*/

/**
*valida_nome_file
* @param[in] *nomeFile e'un puntatore a carattere,esso rappresenta il nome del file
* @return true se il nome del file rispetta la dimensione e non presenta caratteri non ammessi
* @return false se il nome del file non rispetta la dimensione e/o i caratteri non ammessi
*/
bool valida_nome_file(const char *nomeFile){
    // Verifica la lunghezza del nome del file
    if (strlen(nomeFile) > SIZE_NOME_FILE){
        return false;
    }

    // Verifica la presenza di caratteri non ammessi
    const char *caratteriNonAmmessi = ":*?\"<>|";
    for (int i = 0; i < strlen(caratteriNonAmmessi); i++){
        if (strchr(nomeFile, caratteriNonAmmessi[i]) != NULL){
            return false;
        }
    }
    return true;
}

/**
 * valida_estensione_file
 * @param[in] *nome_file e'un puntatore a carattere,esso rappresenta il nome del file
 * @pre nome_file e'una stringa non nulla
 * @return 1 se il file ha estensione .txt
 * @return 0 se il file non presenta l'estensione
 */
bool valida_estensione_file(const char *nome_file){
    // Verifica che l'estensione del file sia .txt
    const char *estensione = ".txt";
    const char *punto = strrchr(nome_file, '.');

    if (punto == NULL)
        return 0;

    return (strcmp(punto, estensione) == 0);
}

/**
 *validatore_file
 * @param[in] *nomeFile e'un puntatore a carattere,esso rappresenta il nome del file
 * @pre nome_file e' una stringa non nulla
 * @return true se il nome del file presenta un nome corretto,se l'estensione  e  il percorso file sono corretti
 * @return false se il nome del file non presenta un nome corretto, se l' estensione e il percorso file non sono corretti
 */
bool validatore_file(const char *nomeFile){
    bool flagValiditaFile = true;

    /// Verifica nomeFile e che l'estensione del file sia .txt
    if (!valida_nome_file(nomeFile)){
        printf(" Nome del file non valido. Assicurati di inserire un file con un nome corretto.\n");
        flagValiditaFile = false;
    }
    /// Valida Estensione File
    if (!valida_estensione_file(nomeFile)){
        printf(" Estensione del file non valida. Assicurati di inserire un file .txt.\n");
        flagValiditaFile = false;
    }
    /// Se il percorso del file fornito e' corretto, allora verifico la sua esistenza effettiva
    if (flagValiditaFile){
        FILE *file;
        if (apriFile(nomeFile, "r", &file) == 0){
            printf(" Il file da lei specificato e' inesistente. Assicurati di inserire il percorso corretto.\n");
            flagValiditaFile = false;
        }
    }
    return flagValiditaFile;
}
/**
*rimuoviNewline
*@param[in] stringa e' un puntatore a carattere ,essa rappresenta una stringa non formattata dal '-'
*@pre stringa non e' nulla
*/
void rimuoviNewline(char* stringa) {
    unsigned len = strlen(stringa);
    if (len > 0 && stringa[len - 1] == '\n') {
        stringa[len - 1] = '\0';
    }
}


/**
*controlloStringa
*@param[in] stringa e' un puntatore a carattere,essa rappresenta una stringa non formattata dal '-'
*@pre stringa non e' nulla
*@return viene restituita una stringa puntatore a carattere quando la stringa viene inserita correttamente
*/

char* controlloStringa(char* stringa) {
    int scelta = 0, conferma = 0;

    do {
        printf("Sei sicuro di aver inserito la stringa corretta?\n1) per confermare\n"
               "2) per modificare\nScrivi qui --> ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                return stringa;

            case 2:
                printf("Inserisci la nuova stringa: ");
                fflush(stdin);
                scanf("%s", stringa);
                printf("Vuoi confermare la modifica?\n1) per confermare\n"
                       "2) per annullare\nScrivi qui --> ");
                scanf("%d", &conferma);
                break;
            default:
                printf("|ERRORE| - Scelta %d non consentita\n", scelta);
                break;

        }
        if(conferma==2){
            scelta = 0;
        }
    } while (scelta != 1 && scelta != 2);

    return stringa;
}

/**
*pulisciFile
*@param[in] *nomeFile e' un puntatore a carattere ,esso rappresenta il nome del file
*@pre il nome del file non e' nullo
**/
void pulisciFile (const char* nomeFile){
    FILE* file;
    if (validatore_file(nomeFile) == true){
        file = fopen(nomeFile, "w");
        chiudiFile(file);
    }
}
