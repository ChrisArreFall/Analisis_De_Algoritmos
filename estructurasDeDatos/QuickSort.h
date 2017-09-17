//
// Created by Chris on 9/15/17.
//

#ifndef ANALISIS_DE_ALGORITMOS_QUICKSORT_H
#define ANALISIS_DE_ALGORITMOS_QUICKSORT_H


#include <cstdio>
#include <iostream>
#include "Grapher.h"



int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



void pruebaQuickSort(){
    //Inicia Prueba------------------------------------------------------------------------------
    double valoresPruebasX[6]= {25,50,100,200,400,800};
    double valoresPruebasY[6];
    int prueba25[25];
    int prueba50[50];
    int prueba100[100];
    int prueba200[200];
    int prueba400[400];
    int prueba800[800];


    int n25 = sizeof(prueba25)/sizeof(prueba25[0]);
    int n50 = sizeof(prueba50)/sizeof(prueba50[0]);
    int n100 = sizeof(prueba100)/sizeof(prueba100[0]);
    int n200 = sizeof(prueba200)/sizeof(prueba200[0]);
    int n400 = sizeof(prueba400)/sizeof(prueba400[0]);
    int n800 = sizeof(prueba800)/sizeof(prueba800[0]);


    for (int i = 0; i < 25; ++i) {
        prueba25[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < 50; ++i) {
        prueba50[50] = rand() % 10 + 1;
    }
    for (int i = 0; i < 100; ++i) {
        prueba100[100] = rand() % 10 + 1;
    }
    for (int i = 0; i < 200; ++i) {
        prueba200[200] = rand() % 10 + 1;
    }
    for (int i = 0; i < 400; ++i) {
        prueba400[400] = rand() % 10 + 1;
    }
    for (int i = 0; i < 800; ++i) {
        prueba800[800] = rand() % 10 + 1;
    }

    //------------------------------------------------------------------
    auto start25 = std::chrono::high_resolution_clock::now();
    quickSort(prueba25,0,n25-1);
    auto end25 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff25 = end25 - start25;

    std::cout << diff25.count()*1000 << std::endl;

    valoresPruebasY[0] = diff25.count()*1000;
    //------------------------------------------------------------------
    auto start50 = std::chrono::high_resolution_clock::now();
    quickSort(prueba50,0,n50-1);
    auto end50 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff50 = end50 - start50;

    std::cout << diff50.count()*1000 << std::endl;

    valoresPruebasY[1] = diff50.count()*1000;
    //------------------------------------------------------------------
    auto start100 = std::chrono::high_resolution_clock::now();
    quickSort(prueba100,0,n100-1);
    auto end100 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff100 = end100 - start100;

    std::cout << diff100.count()*1000 << std::endl;

    valoresPruebasY[2] = diff100.count()*1000;
    //------------------------------------------------------------------
    auto start200 = std::chrono::high_resolution_clock::now();
    quickSort(prueba200,0,n200-1);
    auto end200 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff200 = end200 - start200;

    std::cout << diff200.count()*1000 << std::endl;

    valoresPruebasY[3] = diff200.count()*1000;
    //------------------------------------------------------------------
    auto start400 = std::chrono::high_resolution_clock::now();
    quickSort(prueba400,0,n400-1);
    auto end400 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff400 = end400 - start400;

    std::cout << diff400.count()*1000 << std::endl;

    valoresPruebasY[4] = diff400.count()*1000;
    //------------------------------------------------------------------
    auto start800 = std::chrono::high_resolution_clock::now();
    quickSort(prueba800,0,n800-1);
    auto end800 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff800 = end800 - start800;

    std::cout << diff800.count()*1000 << std::endl;

    valoresPruebasY[5] = diff800.count()*1000;




    Grapher(valoresPruebasX,valoresPruebasY,"quicksort.txt","plot 'quicksort.txt' using 1:2:(sprintf(\"(%d, %d)\", $1, $2)) with labels point pt 7 offset char 1,1 font ',14' notitle,\ 'quicksort.txt' w linespoint , '' with labels ");

    //Termina Prueba------------------------------------------------------------------------------
}


#endif //ANALISIS_DE_ALGORITMOS_QUICKSORT_H
