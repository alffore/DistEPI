
#include "definiciones.h"



/**
 * 
 * @param p1
 * @param p2
 * @return 
 */
extern double dist(Punto p1, Punto p2);

double RT = 6378390.00;

double dist(Punto p1, Punto p2){
    double daux=0.0;
    
    
    daux=sin(p1.lat)*sin(p2.lat);
    
    daux+=cos(p1.lat)*cos(p1.lon)*cos(p2.lat)*cos(p2.lon);
    
    daux+=cos(p1.lat)*sin(p1.lon)*cos(p2.lat)*sin(p2.lon);
    
    
    daux=RT*acos(daux);
    
    return daux;
}
