#include <iostream>
#include <iomanip>
#include <cmath>
#define N 12
#define MAX_PRED 3

using namespace std;

void leerDatos(int costo[], int ganancia[], int cantPreecesores[],
               int predecesores[][MAX_PRED], int &n, int &p) {
    cout << "N: ";
    cin >> n;
    cout << "P: ";
    cin >> p;
    for (int i = 0; i < n; i++) {
        cout << "Proyecto " << i + 1 << endl;
        cout << "  - Costo = ";
        cin >> costo[i];
        cout << "  - Ganancia = ";
        cin >> ganancia[i];
        cout << "  - Precocesores = ";
        cin >> cantPreecesores[i];
        for (int j = 0; j < cantPreecesores[i]; j++) {
            cout << "Predecesor " << j + 1 << ": ";
            cin >> predecesores[i][j];
            predecesores[i][j] = predecesores[i][j] - 1;
        }
    }
}

// void cambiarBase(int i, int base, int n, int )


void cambiarBase(int i, int base, int n, int *combinacion) {
    int j;
    for (j = 0; j < n; j++) {
        combinacion[j] = 0;
    }
    j = 0;
    while (i > 0) {
        combinacion[j] = i % base;
        j++;
        i = i / base;
    }
}
int main() {
    int costo[N];
    int ganancia[N];
    int cantPreecesores[N];
    int predecesores[N][MAX_PRED];


    int n, p;

    leerDatos(costo, ganancia, cantPreecesores, predecesores, n, p);

    int combinacion[N];
    int base = 2;
    int combinaciones = pow(base, n);
    int mejorGanancia = 0, mejorSolucion = 0;
    for (int i = 1; i < combinaciones; i++) {
        cambiarBase(i, base, n, combinacion);

        int costoTotal = 0;
        for (int j = 0; j < n; j++) {
            if (combinacion[j] == 1) {
                costoTotal += costo[j];
            }
        }
        if (costoTotal > p)
            continue; //saltar, supera el presupuesto

        bool predOk = true;

        for (int j = 0; j < n && predOk; j++) {
            if (combinacion[j] == 1) {
                for (int k = 0; k < cantPreecesores[j] && predOk; k++) {
                    int idPred = predecesores[j][k]; //el predecesor que llegamos a caer lo guardamos
                    if (combinacion[idPred] == 0) {
                        predOk = false;
                    }
                }
            }
        }
        if (!predOk)
            continue;
        // --- Calcular ganancia ---
        int gananciaTotal = 0;
        for (int j = 0; j < n; j++)
            if (combinacion[j] == 1)
                gananciaTotal += ganancia[j];

        // --- Guardar si es mejor ---
        if (gananciaTotal > mejorGanancia) {
            mejorGanancia = gananciaTotal;
            mejorSolucion = i;
        }
    }
    if (mejorSolucion > 0) {
        cambiarBase(mejorSolucion, base, n, combinacion);

        //para ordenar incia aqui

        int seleccionados[N] ;
        int cantSelecionados = 0;
        for (int j = 0; j < n; j++) {
            if (combinacion[j] == 1) {
                seleccionados[cantSelecionados++] = j;
            }
        }

        // Ordenar por ganancia descendente (burbuja)
        for (int j = 0; j < cantSelecionados - 1; j++) {
            for (int k = 0; k < cantSelecionados - 1 - j; k++) {
                if (ganancia[seleccionados[k]] < ganancia[seleccionados[k+1]]) {
                    int temp = seleccionados[k];
                    seleccionados[k] = seleccionados[k+1];
                    seleccionados[k+1] = temp;
                }
            }
        }

        // Imprimir ordenado
        cout << "Ganancia maxima: " << mejorGanancia << endl;
        cout << "Proyectos seleccionados:" << endl;
        for (int j = 0; j < cantSelecionados; j++)
            cout << "Proyecto " << seleccionados[j] + 1
                 << " - ganancia: " << ganancia[seleccionados[j]] << endl;



        //termina aqui
        /*cout << "Ganancia maxima: " << mejorGanancia << endl;
        cout << "Proyectos seleccionados:" << endl;
        for (int j = 0; j < n; j++)
            if (combinacion[j] == 1)
                cout << "Proyecto " << j+1
                     << " - ganancia: " << ganancia[j] << endl;*/
    } else {
        cout << "No hay solucion posible" << endl;
    }


    return 0;
}