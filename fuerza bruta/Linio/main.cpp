#include <iostream>
#include <cmath>
#define N 20
#define M 4
#define T 4
#define H 24

using namespace  std;

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
    int datos[N][M] = {
        {100,4,8,2},
        {101,2,10,2},
        {102,3,12,2},
        {103,1,13,2},
        {104,3,15,1},
        {105,1,10,2},
        {106,4,16,1},
        {107,2,8,2},
        {108,3,14,1},
        {109,2,18,2},
        {110,1,18,2},
        {111,4,14,2}
    };
    int combinacion[N];
    int n=12; /*Cantidad de productos*/
    int base = 2; /*Porque tenemos 2 estados*/
    int combinaciones = pow(base,n);
    int tiposProductos[T];
    int tipoProducto, horaInicio, cantHoras;
    int horario[H];
    bool hayCruce;
    int solucion = 0;

    for (int i=1; i<combinaciones; i++)
    {
        cambioBase(i,base,n,combinacion);
        /*Inicializamos el arreglo que cuenta los tipo de producto*/
        for (int j=0; j<T; j++)
        {
            tiposProductos[j] = 0;
        }
        /*Inicializamos el arreglo del horario*/
        for (int j=0; j<H; j++)
        {
            horario[j] = 0;
        }
        hayCruce = false;
        /*Analizamos la combinacion*/
        for (int j=0; j<n; j++)
        {
            if (combinacion[j]==1)
            {
                tipoProducto = datos[j][1];
                horaInicio = datos[j][2];
                cantHoras = datos[j][3];
                tiposProductos[tipoProducto-1]++;
                for (int k=horaInicio; k<horaInicio+cantHoras; k++)
                {
                    if (horario[k]==0)
                    {
                        horario[k] = 1;
                    }
                    else
                    {
                        hayCruce = true;
                        break;
                    }
                }
            }
            if (hayCruce)
            {
                break;
            }
        }
        if (!hayCruce)
        {
            if (tiposProductos[0]>=2 && tiposProductos[1]>=2 && tiposProductos[2]>=1 && tiposProductos[3]>=1)
            {
                solucion = i;
            }
        }
    }
    if (solucion>0)
    {
        /*Esto es para imprimir la solucion*/
        cambioBase(solucion,base,n,combinacion);
        for (int j=0; j<n; j++)
        {
            if (combinacion[j]==1)
            {
                cout << datos[j][0] << " " << datos[j][1] <<  endl;
            }
        }
    }
    else
    {
        cout << "No se puede armar la lista";
    }
    return 0;
}