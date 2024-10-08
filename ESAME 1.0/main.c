#include "InputOutput.h"
#include "Pila.h"
#include "Gestione_File.h"

/**
 * Punto di start dell'applicazione.
 *
 * @pre Nessun requisito preesistente.
 * @post L'applicazione viene avviata correttamente.
 */

int main(){
    scrivi_log("Avvio applicazione");
    Pila *P = NULL;
    gestoreScelta(P);
}
