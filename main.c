#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int main()
{
    double array[MAX_SIZE][MAX_SIZE];
    FILE *in_file = fopen("input.txt", "r");
    int  width, height;
    fscanf(in_file, "%d", &width);
    fscanf(in_file, "%d", &height);
    if (width > MAX_SIZE || height > MAX_SIZE)
    {
        printf("Error: width or height more than max size");
        return 1;
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(feof(in_file))
            {
                printf("\nERROR: not enough elements in file"); // если элементов меньше чем (8 + " ")
                return 1;
            }
            fscanf(in_file, "%lf", &array[i][j]);
        }
    }
    if(feof(in_file))
    {
        printf("\nERROR: not enough elements in file");
        return 1;
    } // если элементов меньше чем 9 + " "
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }
    fclose(in_file);
    return 0;
}