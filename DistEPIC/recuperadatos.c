
#include "definiciones.h"


extern PPunto recuperaDatos(char * snomarch);


PPunto parserLine(char * slinea);

PPunto creaPunto(double lat, double lon, int id, int anno);

void insertaPunto(PPunto pori, PPunto pai);

int eliminaPunto(PPunto p);

extern int anno_min;
extern int cantob;

PPunto recuperaDatos(char * snomarch) {

    FILE*fp;
    char c;

    PPunto proot = NULL;
    PPunto paux=NULL,pact=NULL;


    fp = fopen(snomarch, "r");

    if (fp != NULL) {
        char line [ 128 ]; 
        while (fgets(line, sizeof line, fp) != NULL)  {
            if(proot!=NULL){
                
                
                paux=parserLine(line);
                if(pact!=NULL){
                    
                }
                printf("%f::%f::%d::%i\n",paux->lat,paux->lon,paux->id,paux->anno);
            }else{
                proot=parserLine(line);
                pact=proot;
                printf("%f::%f::%d::%i\n",proot->lat,proot->lon,proot->id,proot->anno);
            }
             
        }
        fclose(fp);
    }



    return proot;
}

PPunto parserLine(char * slinea) {
    
    int  campo=0;
    double latlon_m[4];
    
    char* token = strtok(slinea, DELIM);
    while (token) {
        latlon_m[campo]=atof(token);
        token = strtok(NULL, DELIM);
        campo++;
    }
    
    return creaPunto(latlon_m[0],latlon_m[1],(int)latlon_m[2],(int)latlon_m[3]);
}

PPunto creaPunto(double lat, double lon, int anno, int id) {

    PPunto p = (PPunto) malloc(sizeof (Punto));

    p->anno = anno;
    p->id = id;
    p->lat = lat * M_PI / 180.0;
    p->lon = lon * M_PI / 180.0;

    p->pp = NULL;

    return p;
}

void insertaPunto(PPunto pori, PPunto pai) {

    pori->pp = pai;

}

int eliminaPunto(PPunto p) {
    if (p != NULL) {
        free(p);
        return 0;
    }

    return 1;
}