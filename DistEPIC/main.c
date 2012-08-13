/* 
 * File:   main.c
 * Author: AAFR
 *
 * Created on 9 de agosto de 2012, 06:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*
 * 
 */
int main(int argc, char** argv) {


    
    recuperaDatos(*(argv+1));
    calculaMinD();
    
    return 0;
}

