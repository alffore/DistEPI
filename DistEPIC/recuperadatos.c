
#include "definiciones.h"


PPunto recuperaDatos(char * snomarch);
PPunto parserLine(char * slinea);
PPunto creaPunto(double lat, double lon, int id, int anno);
void insertaPunto(PPunto pori, PPunto pai);
void liberaMemoria(PPunto p);

int eliminaPunto(PPunto p);



extern int anno_min;
int cantob;





/**
 * 
 * @param snomarch
 * @return 
 */
PPunto recuperaDatos(char * snomarch) {

    FILE*fp;
    char c;

    PPunto proot = NULL;
    PPunto paux = NULL, pact = NULL;

    cantob = 0;


    fp = fopen(snomarch, "r");

    if (fp != NULL) {
        char line [ 128 ];
        while (fgets(line, sizeof line, fp) != NULL) {
            
            paux = parserLine(line);
/*
            printf("%f::%f::%d::%i\n", paux->lat, paux->lon, paux->id, paux->anno);
*/
            
            if (proot != NULL) {               
                if (pact != NULL) {
                    insertaPunto(pact, paux);
                    pact = paux;
                }
                
            } else {
                proot = paux;
                pact = proot;
                
            }

        }
        fclose(fp);
    }



    return proot;
}

/**
 * 
 * @param slinea
 * @return 
 */
PPunto parserLine(char * slinea) {

    int campo = 0;
    double latlon_m[4];

    char* token = strtok(slinea, DELIM);
    while (token) {
        latlon_m[campo] = atof(token);
        token = strtok(NULL, DELIM);
        campo++;
    }

    return creaPunto(latlon_m[0], latlon_m[1], (int) latlon_m[2], (int) latlon_m[3]);
}

/**
 * 
 * @param lat
 * @param lon
 * @param anno
 * @param id
 * @return 
 */
PPunto creaPunto(double lat, double lon, int anno, int id) {

    PPunto p = (PPunto) malloc(sizeof (Punto));

    p->anno = anno;
    p->id = id;
    p->lat = lat * M_PI / 180.0;
    p->lon = lon * M_PI / 180.0;

    p->pp = NULL;
    cantob++;
    return p;
}

/**
 * 
 * @param pori
 * @param pai
 */
void insertaPunto(PPunto pori, PPunto pai) {

    pori->pp = pai;

}

/**
 * 
 * @param p
 */
void liberaMemoria(PPunto p) {
    PPunto paux1, paux2;

    paux1 = p;
    while (1) {

        paux2 = paux1->pp;
        eliminaPunto(paux1);
        paux1 = paux2;

        if (paux1 == NULL)break;

    }


}

/**
 * 
 * @param p
 * @return 
 */
int eliminaPunto(PPunto p) {
    if (p != NULL) {
        free(p);
        return 0;
    }

    return 1;
}