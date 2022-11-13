#ifndef FUNCIONESAESTRELLA_H
#define FUNCIONESAESTRELLA_H

    #include <vector>
    #include "serietemporal.hpp"

    typedef struct nodo{
        int punto;
        long double error;
        int rango;
        int padre;
    } Nodo;
    
    void algoritmoAestrella(SerieTemporal &serie, std::vector<Nodo> &la, std::vector<Nodo> &lc,
        const int puntos, const long double poda);
    void crearSegmentacion(SerieTemporal &serie, std::vector<Nodo> &lc, const int puntos);

#endif