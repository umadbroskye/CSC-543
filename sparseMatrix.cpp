#include <iostream>

int main()
{

    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    
    int sparseSize = 0;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(sparseMatrix[i][j] != 0){
                sparseSize++;
            }
        }
    }
    
    int condensedMatrix[3][sparseSize];
    
    int n = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(sparseMatrix[i][j]!=0){
                condensedMatrix[0][n] = i;
                condensedMatrix[1][n] = j;
                condensedMatrix[2][n] = sparseMatrix[i][j];
                n++;
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < sparseSize; j++){
            printf("%d ", condensedMatrix[i][j]);
        }
        printf("\n");
    }
}
