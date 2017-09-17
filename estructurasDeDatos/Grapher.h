//
// Created by Chris on 9/16/17.
//

#ifndef ANALISIS_DE_ALGORITMOS_GRAPHER_H
#define ANALISIS_DE_ALGORITMOS_GRAPHER_H
#define NUM_POINTS 6
#define NUM_COMMANDS 3
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;


void Grapher(double xvals[NUM_POINTS],double yvals[NUM_POINTS],char *location,char *command){
    char * commandsForGnuplot[] = {"set title \"Benchmark\"", command,"set ylabel \"Tiempo (uS)\""};
    FILE * temp = fopen(location, "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     *
    */

    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < NUM_POINTS; i++)
    {
        fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
    }

    for (i=0; i < NUM_COMMANDS; i++)
    {
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
}

#endif //ANALISIS_DE_ALGORITMOS_GRAPHER_H
