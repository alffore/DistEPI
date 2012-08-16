
#include "definiciones.h"

extern double dist(Punto p1, Punto p2);

int calculaMinD(PPunto pr, int anno, int annoa);
double distaAcum(PPunto p, int anno);
int cantidadR(PPunto p, int anno);

/**
 * 
 * @param anno
 * @param annoa
 * @return 
 */
int calculaMinD(PPunto pr, int anno, int annoa) {

    int a, cuenta;

    double dist = 0;


    for (a = anno; a <= annoa; a++) {

        dist = distaAcum(pr, a);
        cuenta = cantidadR(pr, a);

        printf("%i|%11.4lf|%i|%5.4lf\n", a, dist, cuenta, dist / (1000 * cuenta));

    }



    return 1;
}

/**
 * 
 * @param p
 * @param anno
 * @return 
 */
double distaAcum(PPunto p, int anno) {

    double aux = 0;
    PPunto paux = p;


    while (1) {

        if (paux->anno <= anno) {

            aux += dist(*p, *paux);
        }

        paux = paux->pp;

        if (paux == NULL)break;

    }

    return aux;
}

/**
 * 
 * @param p
 * @param anno
 * @return 
 */
int cantidadR(PPunto p, int anno) {
    int aux = 0;
    PPunto paux = p;


    while (1) {

        if (paux->anno <= anno) {

            aux++;
        }

        paux = paux->pp;

        if (paux == NULL)break;

    }

    return aux;
}
