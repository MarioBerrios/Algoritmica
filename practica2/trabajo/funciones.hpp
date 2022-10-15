#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <vector>
    #include "serietemporal.hpp"

    void calcularSecuenciaErrorMax(SerieTemporal &serie, std::vector<int> intervalo, 
        long double &errorMax);
    void calcularSecuenciaInter(SerieTemporal &serie, std::vector<int> intervalo, 
        long double &errorMax);

#endif