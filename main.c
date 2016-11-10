#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <generatoreEsercizi.h>
#include <struttureDati.h>
#include <risolutoreEsercizi.h>

/*
Da inserire:
[X] algoritmo di Euclide
[X] identità di Bézout
[X] risoluzione equazioni diofantee
[X] calcolo minimo comune multiplo
[X] generatore esercizi
[] risoluzione potenze grandi
*/

int main() {
    char scelta;
    unsigned short esci = 0; // determina la fine o meno del programma

    // creazione del seed, dev'esserci solo questo in tutto il programma
    srand(time(NULL));

    // menù principale dell'applicazione
    while(!esci) {
        printf("1. risolvi un esercizio\n2. genera un esercizio\ne. uscita\n");
        scanf("%c", &scelta);

        switch(scelta) {
        case '1':
            sceltaRisolutore();
            //getchar();
            break;
        case '2':
            sceltaEsercizio();
            //getchar();

            break;
        case 'e':
            esci = 1;
            break;
        }
    }

    return 0;
}
