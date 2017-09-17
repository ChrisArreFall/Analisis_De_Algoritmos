cmake_minimum_required(VERSION 3.8)
project(Analisis_De_Algoritmos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp estructurasDeDatos/BubbleSort.h estructurasDeDatos/SelectionSort.h estructurasDeDatos/MergeSort.h estructurasDeDatos/QuickSort.h estructurasDeDatos/LinkedList.cpp estructurasDeDatos/LinkedList.h estructurasDeDatos/InsertionSort.h estructurasDeDatos/BinarySearchTree.h estructurasDeDatos/Grapher.h estructurasDeDatos/PrintArray.h estructurasDeDatos/swap.h)
add_executable(Analisis_De_Algoritmos ${SOURCE_FILES})