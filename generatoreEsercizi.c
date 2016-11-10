#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <struttureDati.h>
#define MIN_MCD 1
#define MAX_MCD 2000
#define MIN_EQUAZIONE 1
#define MAX_EQUAZIONE 200
#define MIN_MODULO 2
#define MAX_MODULO 50
#define MIN_CONGRUENZA 1
#define MAX_CONGRUENZA 50
#define MIN_INVERSO 2
#define MAX_INVERSO 30
#define MIN_BASE 5
#define MAX_BASE 50000
#define MIN_ESPONENTE 5
#define MAX_ESPONENTE 30
#define NOME_FILE 31

// la creazione del seed fa effettuata una sola volta nel main


NumeriMcd generatoreMCD() {
    NumeriMcd numeriMcd;

    numeriMcd.primoNumero = MIN_MCD + rand() % (MAX_MCD - MIN_MCD + 1);
    numeriMcd.secondoNumero = MIN_MCD + rand() % (MAX_MCD - MIN_MCD + 1);

    return numeriMcd;
}

Equazione generatoreEquazioneDiofantea() {
    Equazione equazione;

    equazione.a = MIN_EQUAZIONE + rand() % (MAX_EQUAZIONE - MIN_EQUAZIONE + 1);
    equazione.b = MIN_EQUAZIONE + rand() % (MAX_EQUAZIONE - MIN_EQUAZIONE + 1);
    equazione.c = MIN_EQUAZIONE + rand() % (MAX_EQUAZIONE - MIN_EQUAZIONE + 1);

    return equazione;
}


// solo per ora void
Equazione generatoreEquazioneCongruenziale() {
    Equazione equazione;
    equazione.a = MIN_CONGRUENZA + rand() % (MAX_CONGRUENZA - MIN_CONGRUENZA + 1);
    equazione.b = MIN_CONGRUENZA + rand() % (MAX_CONGRUENZA - MIN_CONGRUENZA + 1);
    equazione.modulo = MIN_MODULO + rand() % (MAX_MODULO - MIN_MODULO + 1);

    return equazione;
}

Equazione generatoreInverso() {
    Equazione equazione;
    equazione.a = MIN_INVERSO + rand() % (MAX_INVERSO - MIN_INVERSO + 1);
    equazione.modulo = MIN_MODULO + rand() % (MAX_MODULO - MIN_MODULO + 1);

    return equazione;
}

Potenza generatorePotenza() {
    Potenza potenza;
    potenza.base = MIN_BASE + rand() % (MAX_BASE - MIN_BASE + 1);
    potenza.esponente = MIN_ESPONENTE + rand() % (MAX_ESPONENTE - MIN_ESPONENTE + 1);
    potenza.modulo = MIN_MODULO + rand() % (MAX_MODULO - MIN_MODULO + 1);

    return potenza;
}


void creazioneEserciziario(char nomeFile[NOME_FILE]) {
    int i;
    // creazione della struttura FILE
    FILE *fileEsercizi;

    // struttura che conterrà tutti gli esercizi generati per stamparli su file
    Equazione equazioneGenerata;
    NumeriMcd numeriMcd;
    Potenza potenzaGenerata;

    // creazione del file
    fileEsercizi = fopen(strcat(nomeFile, ".txt"), "w+");

    // file viene creato, ora bisogna stamparci sopra gli esercizi
    fprintf(fileEsercizi, "Esercitazione di Matematica Discreta\n\n");
    fprintf(fileEsercizi, "Calcola il Massimo Comun Divisore delle seguenti coppie di numeri:\n");

    for(i = 0; i < 20; i++) {
        numeriMcd = generatoreMCD();
        fprintf(fileEsercizi, "MCD(%d, %d) =\n", numeriMcd.primoNumero, numeriMcd.secondoNumero);
    }

    fprintf(fileEsercizi, "\nRisolvi le seguenti equazioni diofantee:\n");

    for(i = 0; i < 20; i++) {
        equazioneGenerata = generatoreEquazioneDiofantea();
        fprintf(fileEsercizi, "%dm + %dn = %d\n", equazioneGenerata.a, equazioneGenerata.b, equazioneGenerata.c);
    }

    fprintf(fileEsercizi, "\nRisolvi le seguenti equazioni congruenziali:\n");

    for(i = 0; i < 20; i++) {
        equazioneGenerata = generatoreEquazioneCongruenziale();
        fprintf(fileEsercizi, "%dx = %d mod %d\n", equazioneGenerata.a, equazioneGenerata.b, equazioneGenerata.modulo);
    }

    fprintf(fileEsercizi, "\nInverso moltiplicativo:\n");

    for(i = 0; i < 20; i++) {
        equazioneGenerata = generatoreInverso();
        fprintf(fileEsercizi, "Calcola l'inverso di [%d] mod %d in Z mod %d.\n", equazioneGenerata.a, equazioneGenerata.modulo, equazioneGenerata.modulo);
    }

    fprintf(fileEsercizi, "\nPotenze grandi:\n");

    for(i = 0; i < 20; i++) {
        potenzaGenerata = generatorePotenza();
        fprintf(fileEsercizi, "Calcola il resto della divisione tra %d^%d e %d.\n", potenzaGenerata.base, potenzaGenerata.esponente, potenzaGenerata.modulo);
    }

    fclose(fileEsercizi);

    printf("File creato correttamente!\n");
}


void sceltaEsercizio() {
    NumeriMcd numeriMcdGenerati;
    Equazione equazioneGenerata;
    Potenza potenzaGenerata;
    char scelta, nomeFile[NOME_FILE];
    int numeroGenerazioni, i, esci = 0;

    getchar();

    while(!esci) {
        printf("Scegli l'esercizio che vuoi generare:\n1. calcolo del Massimo Comun Divisore\n2. risoluzione di equazione diofantea\n3. risoluzione di equazione congruenziale\n");
        printf("4. calcolo dell'inverso\n5. calcolo della congruenza di una potenza grande\n6. genera eserciziario\n");
        scanf("%c", &scelta);

        switch(scelta) {
        case '1':
            numeriMcdGenerati = generatoreMCD();
            printf("Calcola il MCD tra %d e %d.\n", numeriMcdGenerati.primoNumero, numeriMcdGenerati.secondoNumero);
            break;
        case '2':
            printf("Quante equazioni si vogliono generare?\n");
            scanf("%d", &numeroGenerazioni);
            for(i = 0; i < numeroGenerazioni; i++) {
                equazioneGenerata = generatoreEquazioneDiofantea();
                printf("%dm + %dn = %d\n", equazioneGenerata.a, equazioneGenerata.b, equazioneGenerata.c);
            }

            break;
        case '3':
            // generazione equazione congruenziale
            printf("Quante equazioni si vogliono generare?\n");
            scanf("%d", &numeroGenerazioni);

            for(i = 0; i < numeroGenerazioni; i++) {
                equazioneGenerata = generatoreEquazioneCongruenziale();
                printf("%dx = %d mod %d\n", equazioneGenerata.a, equazioneGenerata.b, equazioneGenerata.modulo);
            }

            break;
        case '4':
            // calcolo degli inversi
            printf("Quanti inversi si vogliono calcolare?\n");
            scanf("%d", &numeroGenerazioni);

            for(i = 0; i < numeroGenerazioni; i++) {
                equazioneGenerata = generatoreInverso();
                printf("Calcola l'inverso di [%d] mod %d in Z mod %d.\n", equazioneGenerata.a, equazioneGenerata.modulo, equazioneGenerata.modulo);
            }

            break;
        case '5':
            // calcolo potenze grandi
            printf("Quante potenze si vogliono calcolare?\n");
            scanf("%d", &numeroGenerazioni);

            for(i = 0; i < numeroGenerazioni; i++) {
                potenzaGenerata = generatorePotenza();
                printf("Calcola il resto della divisione tra %d^%d e %d.\n", potenzaGenerata.base, potenzaGenerata.esponente, potenzaGenerata.modulo);
            }

            break;
        case '6':
            // creazione file di testo con esercizi di diverso tipo
            printf("Che nome si vuole dare al file?\n");
            scanf("%30s", nomeFile);
            creazioneEserciziario(nomeFile);

            break;
        case 'e':
            esci = 1;
            break;
        }

        getchar();
    }


}
