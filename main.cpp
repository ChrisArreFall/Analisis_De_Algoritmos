#include <iostream>
#include <zconf.h>
#include "estructurasDeDatos/BubbleSort.h"
#include "estructurasDeDatos/InsertionSort.h"
#include "estructurasDeDatos/MergeSort.h"
#include "estructurasDeDatos/QuickSort.h"
#include "estructurasDeDatos/SelectionSort.h"


using namespace std;
int main() {
    pruebaBubbleSort();
    pruebaInsertionSort();
    pruebaMergeSort();
    pruebaQuickSort();
    pruebaSelectionSort();
}
