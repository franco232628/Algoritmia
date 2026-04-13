#include <iostream>
#include <iomanip>
#include <cmath>
#define Elementos 6
using namespace std;

void InicializarCromosoma(int cromosoma[Elementos],int num,int estados) {

    //inicializo en 0 el arreglo
    for (int i=0;i<Elementos;i++) {
        cromosoma[i] = 0;
    }

    //hago la conversion
    int j=0;
    while (num>0) {
        cromosoma[j++] = num%estados;
        num = num/estados;
    }

}

int main(int argc, char **argv) {
    int ArrVelocidadTablas[Elementos]={150,100,80,50,120,10};
    int estados=3;
    int ArrVelocidadDiscos[estados]={250,200,200};
    int cromosoma[Elementos]{};
    int cantidad_soluciones= (int)pow(estados,Elementos);
    int k=0,soluciones=0;
    int aux_minimo;
    int iteracion_minima= 0;
    int minimo_acumulado = 0;
    for(int i=0;i<cantidad_soluciones;i++) {
        int disc_velocidades[estados]{};
        int tablas_velocidades[estados]{};
        InicializarCromosoma(cromosoma,i,estados);
        for (int j=0;j<Elementos;j++) {
            for (int y=0;y<estados;y++) {
                if (cromosoma[j]==y) {
                    disc_velocidades[y]+=ArrVelocidadTablas[j];
                }
            }

        }
        int paso = 0;
        for (int y=0;y<estados;y++) {
            if (disc_velocidades[y]<=ArrVelocidadDiscos[y]) {
                paso++;
            }
        }
        if (paso==estados) {
            soluciones++;
            int minimo = 0;
            int minimo_interno = 100000;
            cout<<"ITERACION: "<<soluciones<<endl;
            for (int j=0;j<estados;j++) {

                aux_minimo = ArrVelocidadDiscos[j] - disc_velocidades[j];
                if (aux_minimo<minimo_interno) {
                    minimo_interno = aux_minimo;
                }
                cout<<"DISCO "<<j+1<<" {";
                for (int x=0;x<Elementos;x++) {
                    if (cromosoma[x]==j) {
                        cout<<"tabla: "<<x+1<<",";
                        //se me queda una coma mas en la impresion x como lo he mandado a imprimir
                    }

                }
                cout<<"}"<<endl;
            }
            if (minimo_interno>minimo_acumulado) {
                minimo_acumulado = minimo_interno;
                iteracion_minima = soluciones;
            }
        }

    }
    cout<<"MINIMO: "<<minimo_acumulado<<endl;

    return 0;
}
