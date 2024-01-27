// OpenMP_Sol.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//Librerías empleadas
#include <iostream>
#include <omp.h>
#define N 10 //Cantidad de valores que se disponen en los arreglos
#define chunk 1000 //Tamaño de los tramos o pedazos en los arreglos, carga para cada hilo creado
#define mostrar 10 //Contendrá la cantidad de datos a mostrar

//Función para imprimir los valores del arreglo seleccionado por el puntero, que es el parámetro definido por la función
void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando arreglos en paralelo!\n";
    float a[N], b[N], c[N]; //Areglos
    int i; //Iterador

    //Bucle for para realizar iteraciones mienta i sea menor que N
    for (i = 0; i < N; i++)
    {
        //Definición numérica de los arreglos
        a[i] = i * 8 *30;
        b[i] = (i + 4) * 4.2;
    }
    int tramos = chunk;

    //Definición del procesamiento paralelo
#pragma omp parallel for shared(a,b,c,tramos) private(i) schedule(static, tramos)

    //Bucle que será procesado por medio del paralelismo
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
   
std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
imprimeArreglo(a);
std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
imprimeArreglo(b);
std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
imprimeArreglo(c);
}

//Definición de la función para imprimir los arreglos
void imprimeArreglo(float *d)
{
    //Bucle que muestra los resultados por medio de la variable "mostrar"
    for (int x = 0; x < mostrar; x++)
        //Concatenación de un caracter para separar los valores
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
