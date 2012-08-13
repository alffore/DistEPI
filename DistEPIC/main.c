/* 
 * File:   main.c
 * Author: AAFR
 *
 * Created on 9 de agosto de 2012, 06:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "definiciones.h"

/*
 * 
 */
int main(int argc, char** argv) {

    PPunto p = NULL;


    p = recuperaDatos(*(argv + 1));
    calculaMinD(p, atoi(*(argv + 2)), atoi(*(argv + 3)));
    liberaMemoria(p);
    
    
    return 0;
}

