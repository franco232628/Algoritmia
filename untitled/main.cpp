#include <iostream>
#include <cmath>
#define N 5

using namespace std;

void cambioBase(int i,int base,int n,int combinacion[N])
{
    //inicializar:
    int j;
    for (j=0; j<n; j++) {
        combinacion[j] = 0;
    }
    j = 0;
    while (i>0) {
        combinacion[j] = i%base;
        i=i/base;
        j++;
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
        cout << "i = " << i << " => Combinacion: ";
        int pesoCombinacion = 0;

        for (int j=0; j<n; j++) {
            cout << combinacion[j] << " ";
            if (combinacion[j] == 1) {
                pesoCombinacion = pesoCombinacion + pesos[j];
                cout << "(+" << pesos[j] << ") ";
            }
        }

        cout << " | Peso total: " << pesoCombinacion;
        cout << " | Productos: ";
        for (int j=0; j<n; j++) {
            if (combinacion[j] == 1) {
                cout << char('A' + j) << " ";
            }
        }
        cout << endl;
        if (pesoCombinacion <= pesoMochila) {
            if (pesoCombinacion > pesoMayor) {
                pesoMayor = pesoCombinacion;
                solucion = i;
            }
        }
    }

    cout << "\nEl mayor peso a cargar es: " << pesoMayor << endl;
    cambioBase(solucion,base,n,combinacion);
    cout << "Mejor combinacion encontrada:" << endl;
    for (int j=0; j<n; j++) {
        if (combinacion[j] == 1) {
            cout << "Producto: "<< char('A' + j) << " - peso: " << pesos[j] << endl;
        }
    }




    return 0;
}
