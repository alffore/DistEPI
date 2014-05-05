/* 
 * File:   cac2.h
 * Author: alfonso
 *
 * Created on November 19, 2012, 1:39 PM
 */

#ifndef CAC2_H
#define	CAC2_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * @brief Estructura que registra un recuro y sus caracteristicas
     */
    typedef struct Recurso {
        char * stipo_infra;
        int id;
        double lon;
        double lat;

        int estado_id;
        int municipio_id;
        int localidad_id;

        struct Recurso* Pnext;

    } Recurso;


    typedef Recurso * PRecurso;

    /**
     */
    typedef struct Localidad {
        int estado_id;
        int municipio_id;
        int localidad_id;

        int poblacion;

        double lat;
        double lon;


        struct Localidad * Pnext;

    } Localidad;

    typedef Localidad * PLocalidad;


    /**
     */
    static char *tipoi[8] = {
        "museo",
        "teatro",
        "auditorio",
        "galeria",
        "libreria",
        "zona_arqueologica",
        "biblioteca",
        "centro_cultural"
    };

#ifdef	__cplusplus
}
#endif

#endif	/* CAC2_H */

