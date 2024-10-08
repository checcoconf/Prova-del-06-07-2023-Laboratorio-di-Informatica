#include "Header.h"
#include "Pila.h"
#include "InputOutput.h"
#include "Gestione_File.h"
#include "Difensiva.h"
#include "Funzioni.h"

/**
 * @file InputOutput.c
 *
 * @brief Questo file include tutte le funzioni di Input e Output verso l'utente
 *
 * @version 1.0.0
 * @date 06/07/2023
 * @authors Calabrese lorenzo
 * @authors Cappelluti Claudia Antonia
 * @authors Conforti Francesco
*/


/**
 * Visualizza il menu di scelta dell'applicazione.
 *
 * @pre L'output standard (stdout) deve essere disponibile per la stampa del menu.
 * @post Il menu viene visualizzato correttamente sulla console.
 */
void visualizzaMenu(){
    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    puts(" ||                                          B E N V E N U T O !                                                 ||");
    puts(" ||                                                                                                              ||");
    puts(" ||                                     M E N U'   D I     S C E L T A :                                         ||");
    puts(" ||                                                                                                              ||");
    puts(" ||            - Premere il tasto |1| per acquisire i dati da file con visualizzazione                           ||");
    puts(" ||            - Premere il tasto |2| per effettuare una sostituzione all'interno della pila                     ||");
    puts(" ||            - Premere il tasto |3| per effettuare l'ordinamento della pila                                    ||");
    puts(" ||            - Premere il tasto |4| per chiudere l'appilcazione                                                ||");
    puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

/**
 * Visualizza il messaggio di chiusura dell'applicazione, esegue un countdown visivo e registra la chiusura nel file di log.
 *
 * @pre L'output standard (stdout) deve essere disponibile per la stampa del messaggio di chiusura.
 * @post La chiusura dell'applicazione viene registrata nel file di log.
 */
void visualizzaChiusura() {
    printf("Chiusura in corso");
    for(int i = 0; i < 3; i++) {
        sleep(1);
        printf(".");
    }
    printf("\nArrivederci.");
    scrivi_log("Chiusura");
}

/**
 * Gestisce la scelta dell'utente e esegue le operazioni corrispondenti.
 *
 * @param[in] *pila  La pila di dati su cui eseguire le operazioni.
 *
 * @pre La pila deve essere valida e correttamente inizializzata.
 * @post Le operazioni selezionate dall'utente vengono eseguite correttamente sulla pila.
 *       La memoria allocata per le pile dopo l'utilizzo viene rilasciata.
 */
void gestoreScelta(Pila* pila){
    Pila *pilaOrdinata = NULL, *pilaSostituita = NULL;
    char nomeFile[SIZE_NOME_FILE], daSostituire[MIN_SIZE],daInserire[MIN_SIZE];
    int scelta = 0;

    do{
        visualizzaMenu();
        printf("Effettua una scelta --> ");
        scanf("%d",&scelta);

        while (((scelta > 4 || scelta < 2) || pila == NULL) && (pila == NULL && scelta != 1 && scelta != 4)){
            if(scelta > 4 || scelta < 1){
                puts("|ERRORE| - L'opzione %d la scelta non e' corretta.\nRiprova con un valore valido ");
                scrivi_log("Scelta non corretta");
            }
            if (pila == NULL && scelta != 1 && scelta != 4){
                printf("|ERRORE| - La pila e' vuota!\n");
                scrivi_log("Pila vuota");
            }
            printf("Riscrivi qui --> ");
            scanf("%d", &scelta);
        }

        switch (scelta) {
            case 1:
                scrivi_log("Scelta 1");
                svuotaPila(&pila);
                leggiFile(acquisisciNomeFile(nomeFile),&pila);
                scrivi_log("Inizio lettura file Input.txt");
                invertiPila(&pila);
                printf("Stampa pila");
                stampaPila(pila);
                system("pause");
                system("cls");
                scrivi_log("Fine lettura file Input.txt");
                break;

            case 2:
                scrivi_log("Scelta 2");
                pulisciFile("Sostituisci.txt");
                printf("Inserisci l'elemento da sostituire: ");
                acquisisciStringa(daSostituire);
                scrivi_log("Elemento da sostituire inserito");

                printf("Inserisci l'elemento che vuoi inserire: ");
                acquisisciStringa(daInserire);
                scrivi_log("Secondo elemento inserito");

                // Se la pila non è popolata prende quella letta da file, altrimenti la pila aggiornata
                if (pilaSostituita != NULL){
                    pilaSostituita = sostituisci(&pilaSostituita, daSostituire, daInserire);
                }else{
                    pilaSostituita = sostituisci(&pila, daSostituire, daInserire);
                }
                scrivi_log("Operazione di sostituzione effettuata");

                scriviFileFormattato("Sostituisci.txt",pilaSostituita);
                scrivi_log("Operazione di formattazione effettuata");

                printf("\tPila Originale");
                stampaPila(pila);

                printf("\tPila Sostituita");
                stampaPila(pilaSostituita);

                system("pause");
                system("cls");
                scrivi_log("Fine scrittura e modifica del file Sostituisci.txt");
                break;

            case 3:
                do{
                    scrivi_log("Scelta 3");
                    pulisciFile("Ordina.txt");
                    printf("Premi |1| per ordinare in modo crescente\nPremi |2| per ordinare in modo decrescente\nScrivi qui --> ");
                    scanf("%d",&scelta);
                    switch (scelta) {
                        case 1:
                            if (pilaSostituita == NULL){
                                pilaOrdinata = bubbleSortRicorsivo(&pila);
                            } else{
                                pilaOrdinata = bubbleSortRicorsivo(&pilaSostituita);
                            }
                            scrivi_log("Operazione di ordinamento effettuata");
                            scriviFileFormattato("Ordina.txt", pila);
                            scrivi_log("Operazione di formattazione effettuata");
                            printf("Ordina crescente");
                            stampaPila(pilaOrdinata);
                            break;
                        case 2:
                            if (pilaSostituita == NULL){
                                pilaOrdinata = bubbleSortRicorsivo(&pila);
                                invertiPila(&pilaOrdinata);
                            } else{
                                pilaOrdinata = bubbleSortRicorsivo(&pilaSostituita);
                                invertiPila(&pilaOrdinata);
                            }
                            scriviFileFormattato("Ordina.txt", pilaOrdinata);
                            printf("Ordina decrescente");
                            stampaPila(pilaOrdinata);
                            scrivi_log("Fine scrittura e modifica del file Ordina.txt");
                            break;
                        default:
                            printf("|ERRORE| - Scelta %d non ammessa!", scelta);
                            scrivi_log("Scelta non ammessa");
                    }
                }while(scelta!=1 && scelta!=2);
                system("pause");
                system("cls");
                break;
            case 4:
                scrivi_log("Scelta 4");
                visualizzaChiusura();
                exit(0);
            default:
                printf("|ERRORE| - Scelta %d non ammessa!",scelta);
                scrivi_log("Chisura forzata scelta non consentita");
                exit(-1);
        }
    } while (scelta != 4);

    free(pila);
    free(pilaSostituita);
    free(pilaOrdinata);
    scrivi_log("Rilascio della memoria");
}

/**
 * Acquisisce il nome del file di input dall'utente.
 *
 * @param[in] *nomeFile  Il puntatore al buffer in cui memorizzare il nome del file.
 *                  Deve essere inizializzato con una dimensione sufficiente per contenere il nome del file.
 *
 * @pre Il nome del file viene controllato dalla funzione validatore_file.
 * @post Il nome del file di input viene acquisito correttamente dall'utente e restituito come stringa.
 */
char * acquisisciNomeFile(char* nomeFile) {
    do {
        printf("Inserisci il nome del file di input (estensione .txt): ");
        scanf("%49s", nomeFile);
    } while(!validatore_file(nomeFile));

    return nomeFile;
}

/**
 * Acquisisce una stringa dall'utente.
 *
 * @param[in] *str  e' il puntatore al buffer in cui memorizzare la stringa acquisita.
 * @pre La stringa viene controllata dalla funzione controllo stringa.
 * @post La stringa viene acquisita correttamente dall'utente, controllata e restituita come risultato.
 */
char* acquisisciStringa(char* str) {
    scanf("%s",str);
    controlloStringa(str);
    return str;
}
