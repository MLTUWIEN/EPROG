#ifndef _DYNAMICMATRIX_
#define _DYNAMICMATRIX_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

double* mallocmatrix(int m, int n);
//Allokieren von Speicher fur eine spaltenweise gespeicherte ¨ m × n- Matrix.

double* freematrix(double* matrix);
//Freigeben des allokierten Speichers einer Matrix.

//Reallokieren des Speichers der Matrix, gegebenenfalls Beibehalten von vorhandenen Eintraegen und
//Initialisieren von neuen Eintraegen mit 0.
double* reallocmatrix(double* matrix, int m, int n, int mNew, int nNew);

//Gibt eine spaltenweise gespeicherte m × n-Matrix als Matrix am Bildschirm aus. Die 2 × 3-Matrix

//soll wie folgt ausgegeben werden:
//1 3 5
//2 4 6
void printmatrix(double* matrix, int m, int n);

//Allokiert Speicher fur eine Matrix und liest die Koeffizienten der Matrix von der Tastatur ein. ¨
double* scanmatrix(int m, int n);

//Schneidet die j-te Zeile aus einer m × n-Matrix heraus.
double* cutOffRowJ(double* matrix, int m, int n, int j);

//Schneidet die k-te Spalte aus einer m × n-Matrix heraus.
double* cutOffColK(double* matrix, int m, int n, int k);

#endif
