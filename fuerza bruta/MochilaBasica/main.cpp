#include <iostream>
#include <cmath>
#define N 5

using namespace std;

void cambioBase(int i,int base,int n,int combinacion[N])
{
    int j;
    /*Esto es para limpiar el arreglo de combinacion*/
    for (j=0; j<n; j++)
    {
        combinacion[j] = 0;
    }
    /*Hago el cambio de base*/
    j = 0;
    while (i>0)
    {
        combinacion[j++] = i % base;
        i = i / base;
    }
}



int main()
{
    int pesos[N] = {1,2,4,12,1};
    int n = 5; /*Cantidad de Productos*/
    int pesoMochila = 10;
    int combinacion[N]; /*Aqui voy a guardar la combinacion obtenida por el cambio de base*/
    int base = 2; /*Esto se debe a que tiene estados 0-Fuera, 1-Dentro*/
    int combinaciones = pow(base,n);
    int pesoMayor = 0;
    int solucion;


    /*Para obtener todas las posibles combinaciones*/
    for (int i=1; i<combinaciones; i++)
    {
        cambioBase(i,base,n,combinacion);
        int pesoCombinacion = 0;
        for (int j=0; j<n; j++)
        {
            if (combinacion[j]==1)
            {
                pesoCombinacion = pesoCombinacion + pesos[j];
            }
        }
        if (pesoCombinacion<=pesoMochila)
        {
            if (pesoMayor<pesoCombinacion)
            {
                pesoMayor = pesoCombinacion;
                solucion = i;
            }
        }
    }
    cout << "El mayor peso a cargar es: " << pesoMayor << endl;
    cambioBase(solucion,base,n,combinacion);
    /*Voy a recorrer la combinacion solucion*/
    for (int j=0; j<n; j++)
    {
        if (combinacion[j]==1)
        {
            char letra = 'A' + j;
            cout << "Producto: " << letra << " - peso: " << pesos[j] << endl;
        }
    }
    return 0;
}
