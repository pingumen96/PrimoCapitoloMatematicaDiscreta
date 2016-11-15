#ifndef GENERATOREESERCIZI_H_INCLUDED
#define GENERATOREESERCIZI_H_INCLUDED
#include <struttureDati.h>


NumeriMcd generatoreMCD();
void sceltaEsercizio();
void creazioneEserciziario(char nomeFile[31]);
Equazione generatoreEquazioneCongruenziale();
Equazione generatoreEquazioneDiofantea();
Equazione generatoreInverso();
Potenza generatorePotenza();
Rsa generatoreRsa();

#endif // GENERATOREESERCIZI_H_INCLUDED
