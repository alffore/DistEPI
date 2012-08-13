/* 
 * File:   definiciones.h
 * Author: Alfonso
 *
 * Created on 9 de agosto de 2012, 06:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#ifndef DEFINICIONES_H
#define	DEFINICIONES_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DELIM " ,|"    
    
/*#define RT 6378390.00;*/
    
    /**
     *
     */
    typedef struct Punto{
        
        double lat;
        double lon;
        
        int id;
        int anno;
        
        struct Punto* pp;
        
    } Punto;

    typedef Punto* PPunto;
    
   

#ifdef	__cplusplus
}
#endif

#endif	/* DEFINICIONES_H */

