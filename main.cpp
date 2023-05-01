#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
#include "Ordenador.h"
using namespace std;

int intAleatorio()
{
    const int BITS_PER_RAND = (int)(log2(RAND_MAX / 2 + 1) + 1.0);
    int ret = 0;
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i += BITS_PER_RAND)
    {
        ret <<= BITS_PER_RAND;
        ret |= rand();
    }
    return ret;
}

int *generarArreglo(int arreglo[], int tam)
{
    srand ( time(NULL) );

    for (int i = 0; i < tam; i++)
    {
        arreglo[i] = intAleatorio();
    }

    return arreglo;
}

int main(int argc, char *argv[])
{

    int _50k = 50000;
    int _100k = 100000;
    int _150k = 150000;
    int _200k = 200000;

    int n = _50k;

    int arreglo[n];

    int *A = generarArreglo(arreglo, n);

    cout << "n = " << n << "\n";

    Ordenador Ordenador;
    //Ordenador.seleccion(A, n);
    //Ordenador.insercion(A, n);
    Ordenador.mergesort(A, n);

    // Prueba
    bool fallo = false;
    for (int i = 1; i < n; i++)
    {
        //if(i<50) cout << "\nPos: " << i << ": " << A[i];
        if (A[i] < A[i - 1])
            fallo = true;
    }

    if(fallo == false)
        cout << "\n=============\nPrueba paso\n=============\n";
    else
        cout << "\n=============\n!!!!Prueba fallo!!!\n=============\n";

    return 0;
}