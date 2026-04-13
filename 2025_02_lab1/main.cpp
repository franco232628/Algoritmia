#include <iostream>
#include <iomanip>
#include <cmath>
#define Elementos 8
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
    int ArrCostos[Elementos]={35000,24000,30000,27000,10000,7000,6000,40000};
    int ArrBeneficios[Elementos]={80,60,70,48,20,35,10,40};
    int ArrFalsosNegativos[Elementos]={1,3,2,1,1,2,1,3};
    int cromosoma[Elementos]{};
    int estados = 2;
    int cantidad_soluciones = (int)pow(estados,Elementos);
    int P,B,F;
    //creo un arr aux para guardar los elementos que vaya a usar
    int aux[Elementos]{};
    int k=0,soluciones=0;
    //mensaje generico para solicitar valores
    cout<<"Ingrese los valores de P,B y F";
    cin>>P>>B>>F;
    for(int i=0;i<cantidad_soluciones;i++) {
        int costototal=0,beneficio=0,negativos=0;
        InicializarCromosoma(cromosoma,i,estados); // el i es el numero de iteraccion
        for(int j=0;j<Elementos;j++) {
            if (cromosoma[j]==1) {
                beneficio+=ArrBeneficios[j];
                costototal+=ArrCostos[j];
                negativos+=ArrFalsosNegativos[j];
            }
        }
        if (costototal<=P && beneficio>=B && negativos<=F) {
            soluciones++;
            cout<<"RECURSOS: { ";
            for(int x=0;x<Elementos;x++) {
                if (cromosoma[x]==1) {
                    cout<<x+1<<", ";
                }
            }
            cout<<"Costo total: "<<costototal<<", Beneficio: "<<beneficio<<", Falsos negativos: "<<negativos<<endl;
        }


    }
    return 0;
}