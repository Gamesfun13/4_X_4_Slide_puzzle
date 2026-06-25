#include <stdio.h>
#include <stdlib.h>
int main()
{

    int arr1[4][4] = {
        {1, 4, 15, 7},
        {8, 10, 2, 11},
        {14, 3, 6, 13},
        {12, 9, 5, 0}};

    // Test winning conditon
    // int arr1[4][4] = { 
    //     { 1,  2,  3,  4},
    //     { 5,  6,  7,  8},
    //     { 9, 10, 11, 12},
    //     {13, 14, 0,  15}
    // };
    for (int k = 0; k < 4; k++)
    {
        for (int m = 0; m < 4; m++)
        {
            if (arr1[k][m] == 0){
                printf(" \t");
            }
            else {
                printf("%d\t", arr1[k][m]);
            }
        
        }
        printf("\n");
    }

    char input[10];

    while (1)
    {   
        fgets(input, sizeof(input), stdin);
        printf("\n\n");
        char c = input[0];
        printf("Read: %c\n", c);
        int keyi, keyj, temp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (arr1[i][j] == 0)
                {
                    keyi = i;
                    keyj = j;
                }
            }
        }
        if (c == 'd' && (keyj - 1 >= 0 && keyj - 1 < 4))
        {
            temp = arr1[keyi][keyj - 1];
            arr1[keyi][keyj - 1] = 0;
            arr1[keyi][keyj] = temp;
        }
        else if (c == 's' && (keyi - 1 >= 0 && keyi - 1 < 4))
        {
            temp = arr1[keyi - 1][keyj];
            arr1[keyi - 1][keyj] = 0;
            arr1[keyi][keyj] = temp;
        }
        else if (c == 'w' && (keyi + 1 >= 0 && keyi + 1 < 4))
        {
            temp = arr1[keyi + 1][keyj];
            arr1[keyi + 1][keyj] = 0;
            arr1[keyi][keyj] = temp;
        }
        else if (c == 'a' && (keyj + 1 >= 0 && keyj + 1 < 4))
        {
            temp = arr1[keyi][keyj + 1];
            arr1[keyi][keyj + 1] = 0;
            arr1[keyi][keyj] = temp;
        }

        for (int k = 0; k < 4; k++)
        {
            for (int m = 0; m < 4; m++)
            {
                if (arr1[k][m] != 0)
                {
                    printf("%d\t", arr1[k][m]);
                }
                else
                {
                    printf("\t");
                }
            }
            printf("\n");
        }

        int expected = 1;
        int win = 1;
        for (int i = 0; i < 4 && win; i++) {
            for (int j = 0; j < 4 && win; j++) {
        
                if (i == 3 && j == 3)
                    win = (arr1[i][j] == 0);
                else
                    win = (arr1[i][j] == expected++);
            }
        }
        
        if (win){
            printf("You win!\n");
            break;
        }
    }
    return 0;
}
