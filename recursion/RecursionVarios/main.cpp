#include <iostream>
#define N 10
using namespace std;

void imprimeBinario(int n)
{
    if (n == 0)
    {
        return;
    }
    int digito = n % 2;
    imprimeBinario(n/2);
    cout << digito;
}

void imprimeRango(int i,int n)
{
    if (i>n)
    {
        cout << endl;
        return;
    }
    cout << i << " ";
    imprimeRango(i+1,n);
    cout << i << " ";
}

int buscarElemento(int numBuscado,int n,int arreglo[N],int i)
{
    if (arreglo[i]==numBuscado)
    {
        return i;
    }
    if (i>=n)
    {
        return -1;
    }
    return buscarElemento(numBuscado,n,arreglo,i+1);
}

int main()
{
    int n = 10;
    int arreglo[N] = {8,7,6,12,9,15,3,2,89,65};
    imprimeRango(1,n);
    cout << endl << " El número " << n << " en binario es: ";
    imprimeBinario(n); cout << endl;
    cout << "Posición: " << buscarElemento(12,n,arreglo,0);
    return 0;
}