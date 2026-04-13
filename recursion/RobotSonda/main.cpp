#include <iostream>
#define N 10
#define M 10

using namespace std;

int contarMinas(int arreglo[N][M],int x,int y,int dx,int dy,int n,int m)
{
    if (x<0 || x>=n || y<0 || y>=m)
    {
        if (dx==0)
        {
            return cuentaHorizontal(arreglo,x,0,m);
        }
        else
        {
            return cuentaVertical(arreglo,y,0,n);
        }
    }
    int cantMinas;
    if (dx==0)
    {
        cantMinas = cuentaVertical(arreglo,y,0,n);
    }
    else
    {
        cantMinas = cuentaHorizontal(arreglo,x,0,m);
    }
    return cantMinas + contarMinas(arreglo,x+dx,y+dy,dx,dy,n,m);
}

int main()
{
    int arreglo[N][M] = {
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0}
    };
    int n=6, m=6;
    int x=3, y=2;
    int dx=0, dy=1; //Derecha
    cout << "Minas: " << contarMinas(arreglo,x,y,dx,dy,n,m);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}