// OpenMP_V2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>
#include <omp.h>
#define N 24
#define chunk 100
int mostrar;

void imprimeArreglo(float* d);

int main()
{
    //Cambiamos el color de la consola
    system("color f1");

    std::cout << "----------------------------Sumando arreglos en paralelo----------------------------\n";
    std::cout << "-----Ingrese la cantidad de elementos que desea mostrar: ";
    std::cin >> mostrar;

    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = round(i * rand());
        b[i] = round((i + rand()) * rand())
            ;
    }
    int tramos = chunk;
    std::cout << "--------------Ingrese la cantidad de pedazos o tramos: ";
    std::cin >> tramos;

#pragma omp parallel for shared(a,b,c,tramos) private(i) schedule(static, tramos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " / ";
    std::cout << std::endl;
}
