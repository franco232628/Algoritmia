#include <iostream>
#define N 4
#define M 10
#define Z 4
using namespace  std;

int main()
{
    char tablero[N][M] = {
        {'H','C','H','B','Y','S','O','O','S','H'},
        {'S','C','S','S','Y','Q','O','S','Z','K'},
        {'O','P','N','Y','O','K','F','H','C','K'},
        {'O','B','N','I','Y','S','P','O','O','K'},
    };
    int movimientos[8][2] = {
          {-1,-1},
          {-1,0},
          {-1,1},
          {0,-1},
          {0,1},
          {1,-1},
          {1,0},
          {1,1}
    };
    char palabra[Z] = {'H','S','O'};
    int size = 3, x, y;
    bool sihay;

    /*Vamos a recorrer todas las letras del tablero ubicando las que son iguales a la primera letra de la palabra*/
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (tablero[i][j]==palabra[0])
            {
                /*Ahora debo ir por todos lo posibles movimientos desde esa posicion*/
                for (int k=0; k<8; k++)
                {
                    x = i + movimientos[k][0];
                    y = j + movimientos[k][1];
                    if (x>=0 && x<N && y>=0 && y<M)
                    {
                        if (tablero[x][y]==palabra[1])
                        {
                            /*Ya tengo la direccion, entonces busquemos las demas letras de la palabra en esa direccion*/
                            sihay = true;
                            for (int l=2; l<size; l++)
                            {
                                x = x + movimientos[k][0];
                                y = y + movimientos[k][1];
                                if (x>=0 && x<N && y>=0 && y<M){
                                    if (tablero[x][y]!=palabra[l])
                                    {
                                        sihay = false;
                                        break;
                                    }
                                }
                                else
                                {
                                    sihay = false;
                                    break;
                                }
                            }
                            if (sihay)
                            {
                                cout << "(" << i << "," << j << ")" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}