#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int MAX = 500;
    double A[MAX][MAX];
    double x[MAX], y[MAX]= {0};
    /* Initialize A and x, assign y = 0 */
    for (int j = 0; j < MAX; j++){
        for (int i = 0; i < MAX; i++){
            A[j][i] = 0;
        }
        x[j] = 1;
    }
    unsigned i1, f1, i2, f2;
    /* First pair of loops */
    i1 = clock();
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j]*x[j];
    f1 = clock();
    /* Assign y = 0 */
    for(int m = 0; m < MAX; m++)
        y[m] = 0;
    /* Second pair of loops */
    i2 = clock();
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j]*x[j];
    f2 = clock();
    double time1 = (double(f1-i1)/CLOCKS_PER_SEC);
    printf("Bucle 1: %f segundos\n", time1);
    double time2 = (double(f2-i2)/CLOCKS_PER_SEC);
    printf("Bucle 2: %f segundos\n", time2);
    return 0;
}