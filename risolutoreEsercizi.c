#include <struttureDati.h>
#include <stdlib.h>
#include <stdio.h>


int algoritmoEuclide(int primoNumero, int secondoNumero) {
    int resto;

    // esecuzione dell'algoritmo di Euclide
    while(secondoNumero != 0) {
        resto = primoNumero % secondoNumero;
        primoNumero = secondoNumero;
        secondoNumero = resto;
    }

    return abs(primoNumero);
}


Equazione calcoloIdentitaBezout(int primoNumero, int secondoNumero, int terzoNumero) {
    int massimoComunDivisore, i, j;// appoggio;
    /* temporaneamente utilizzo degli array statici, bisognerebbe creare una lista linkata ma col C è un casino */
    int arrayQuozienti[100], arrayResti[100], arrayX[100], arrayY[100];
    Equazione equazione;

    printf("L'identita' di Bezout verra' stampata nella forma: d = ma + nb\n");

    massimoComunDivisore = algoritmoEuclide(primoNumero, secondoNumero);

    printf("%d = %d m + %d n\n", massimoComunDivisore, primoNumero, secondoNumero);

    arrayQuozienti[0] = primoNumero;
    arrayResti[0] = primoNumero;
    arrayQuozienti[1] = primoNumero;
    arrayResti[1] = secondoNumero;

    // versione leggermente diversa dell'algoritmo di Euclide con utilizzo degli array
    printf("Svolgimento dell'algoritmo di Euclide:\n");
    for(i = 2; (primoNumero % secondoNumero) > 0; i++) {
        //printf("%d\n", i);
        arrayQuozienti[i] = primoNumero / secondoNumero;
        arrayResti[i] = primoNumero % secondoNumero;
        printf("%d\t = %d * %d + %d\n", primoNumero, secondoNumero, arrayQuozienti[i], arrayResti[i]);
        primoNumero = secondoNumero;
        secondoNumero = arrayResti[i];
    }

    arrayX[i] = 0;
    arrayY[i] = 1;

    for(j = i - 1; j > 1; j--) {
        arrayX[j] = 1 * arrayY[j+1];
        arrayY[j] = 1 * (arrayX[j+1] - arrayQuozienti[j] * arrayY[j+1]);
        printf("%d = (%d) * %d + (%d) * %d\n", secondoNumero, arrayX[j], arrayResti[j-2], arrayY[j], arrayResti[j-1]);
    }

    equazione.m = arrayX[j+1];
    equazione.n = arrayY[j+1];
    equazione.a = arrayResti[j-1];
    equazione.b = arrayResti[j];
    equazione.c = terzoNumero;
    equazione.mcd = secondoNumero;

    return equazione;
}

// funzione che dati i punti a, b e c di un'equazione, calcola il risultato dell'equazione diofantea
void calcoloEquazioneDiofantea(int a, int b, int c) {
    int moltiplicatore; // valore per il quale si moltiplicano i valori di n e m se necessario

    // dati i tre punti si crea la struttura Equazione
    Equazione equazione = calcoloIdentitaBezout(a, b, c);

    if(c % equazione.mcd != 0) {
        printf("Non esistono soluzioni per l'equazione diofantea.\n");
    } else if(c % equazione.mcd != 1) {
        moltiplicatore = c / equazione.mcd;
        printf("Una delle soluzioni dell'equazione diofantea e' (%d, %d).\n", equazione.m * moltiplicatore, equazione.n * moltiplicatore);

        printf("Ecco altri risultati:\n");
        for(int i = -5; i <=5; i++) {
            printf("k = %d\t(%d, %d)\n", i, ((equazione.m * moltiplicatore) + (equazione.b / equazione.mcd) * i), ((equazione.n * moltiplicatore) - (equazione.a / equazione.mcd) * i));
        }
    }
}


int minimoComuneMultiplo(int primoNumero, int secondoNumero) {
    int mcd = algoritmoEuclide(primoNumero, secondoNumero);
    return abs((primoNumero * secondoNumero) / mcd);
}



void sceltaRisolutore() {
    char scelta;
    int primoNumero, secondoNumero, terzoNumero;
    short esci = 0;

    getchar();

    while(!esci) {
        // menù del risolutore di esercizi
        printf("1. calcolo del MCD con l'algoritmo di Euclide\n2. ottenimento identita' di Bezout\n3. risoluzione equazione diofantea\n4. calcolo del minimo comune multiplo\n");
        printf("e. torna al menu' precedente\n");
        scanf("%c", &scelta);

        switch(scelta) {
        case '1':
            printf("Inserisci il primo numero: ");
            scanf("%d", &primoNumero);
            printf("Inserisci il secondo numero: ");
            scanf("%d", &secondoNumero);
            getchar();
            printf("MCD(%d, %d) = %d\n", primoNumero, secondoNumero, algoritmoEuclide(primoNumero, secondoNumero));
            break;
        case '2':
            printf("Data l'equazione della forma am + bn = c.\n");
            printf("Inserire a: ");
            scanf("%d", &primoNumero);
            printf("Inserire b: ");
            scanf("%d", &secondoNumero);
            getchar();
            calcoloIdentitaBezout(primoNumero, secondoNumero, 0);
            break;
        case '3':
            printf("Data l'equazione della forma am + bn = c.\n");
            printf("Inserire a: ");
            scanf("%d", &primoNumero);
            printf("Inserire b: ");
            scanf("%d", &secondoNumero);
            printf("Inserire c: ");
            scanf("%d", &terzoNumero);
            calcoloEquazioneDiofantea(primoNumero, secondoNumero, terzoNumero);
            getchar();
            break;
        case '4':
            printf("Inserisci il primo numero: ");
            scanf("%d", &primoNumero);
            printf("Inserisci il secondo numero: ");
            scanf("%d", &secondoNumero);
            printf("Il minimo comune multiplo tra %d e %d e' %d.\n", primoNumero, secondoNumero, minimoComuneMultiplo(primoNumero, secondoNumero));
            getchar();
            break;
        case 'e':
            esci = 1;
            getchar();
            break;
        }
    }


}
