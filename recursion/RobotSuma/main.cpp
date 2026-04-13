#include <iostream>
#define N 10
#define M 10

using namespace std;

int obtenerMayorPuntaje(int matriz[N][M],int x,int y,int xFin,int yFin)
{
    int derecha=-999999, abajo=-999999;
    if (x==xFin && y==yFin)
    {
        return matriz[x][y];
    }
    if (y+1<=yFin)
    {
        derecha = obtenerMayorPuntaje(matriz,x,y+1,yFin,yFin);
    }
    if (x+1<=xFin)
    {
        abajo = obtenerMayorPuntaje(matriz,x+1,y,yFin,yFin);
    }
    if (derecha > abajo)
    {
        return matriz[x][y] + derecha;
    }
    else
    {
        return matriz[x][y] + abajo;
    }
}

int main()
{
    int matriz[N][M] = {
        {3,-2,4},
        {1,-2,3}
    };
    int n=2, m=3;
    cout << "Mayor Puntaje: " << obtenerMayorPuntaje(matriz,0,0,n-1,m-1);
    return 0;
}