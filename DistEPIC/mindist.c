
#include "definiciones.h"

extern int calculaMinD(PPunto pr,int anno, int annoa);

double distaAcum(PPunto p,int anno);
double cantidadR(PPunto p, int anno);

/**
 * 
 * @param anno
 * @param annoa
 * @return 
 */
int calculaMinD(PPunto pr,int anno, int annoa){
    
    int a,i;
    PPunto paux;
    
    for(a=anno;a<=annoa;a++){
        
        paux=pr;
        while(1){
            
            
            if(paux->pp==NULL)break;
            paux=paux->pp;
        }
        
        
        
        
    }
    
    
    
    return 1;
}


double distaAcum(PPunto p,int anno){
    
    double aux=0;
    PPunto paux=p;
    int id=p->id;
    
    
    
   return aux; 
}

double cantidadR(PPunto p, int anno){
    
}
