#include <mlx.h>
#include <unistd.h>

// Dichiarazione della funzione da chiamare ogni tot secondi
void funzioneDaRichiamare() {
    // Questa è la funzione che verrà richiamata ogni tot secondi
    // Puoi inserire qui il codice che desideri eseguire periodicamente
    // ad esempio, un aggiornamento grafico o altre operazioni.
}

int main() {
    // Inizializza MiniLibX
    void *mlx_ptr = mlx_init();

    // Crea una finestra (questo è solo un esempio)
    void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "MiniLibX Example");

    int intervalloMicrosecondi = 1000000; // Specifica l'intervallo in microsecondi (1 secondo = 1,000,000 microsecondi)
    int intervalloChiamataFunzione = 5;   // Specifica l'intervallo di chiamata alla funzione in secondi

    while (1) {
        // Chiama la funzione ogni intervalloChiamataFunzione secondi
        static int tempoTrascorso = 0;
        if (tempoTrascorso >= intervalloChiamataFunzione) {
            funzioneDaRichiamare();
            tempoTrascorso = 0;
        }

        // Attendi l'intervallo specificato in microsecondi
        usleep(intervalloMicrosecondi);

        // Esegui mlx_loop una volta per gestire gli eventi grafici
        mlx_loop(mlx_ptr);

        // Aggiorna il tempo trascorso
        tempoTrascorso += intervalloChiamataFunzione;
    }

    return 0;
}
