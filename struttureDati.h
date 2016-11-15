#ifndef STRUTTUREDATI_H_INCLUDED
#define STRUTTUREDATI_H_INCLUDED

typedef struct {
    // forma del tipo am + bn = c
    int a;
    int b;
    int c;
    int mcd;
    int m;
    int n;
    int modulo;
} Equazione;


typedef struct {
    int primoNumero;
    int secondoNumero;
} NumeriMcd;


typedef struct {
    unsigned int modulo;
    unsigned int base;
    unsigned int esponente;
} Potenza;


typedef struct {
    unsigned short p;
    unsigned short q;
    unsigned int messaggio;
} Rsa;

#endif // STRUTTUREDATI_H_INCLUDED
