#ifndef FUNCIONES_H
#define FUNCIONES_H

    #include <vector>
    #include "serietemporal.hpp"

    void iniciarDominantesErrores(SerieTemporal &serie, std::vector<long double> &dominantes,
        std::vector<long double> &errores, int error_type);
    void calcularSegmentacionISE(SerieTemporal &serie, std::vector<long double> &dominantes,
        std::vector<long double> &errores, int puntos);
    void calcularSegmentacionEMax(SerieTemporal &serie, std::vector<long double> &dominantes,
        std::vector<long double> &errores, int puntos);
    void adjudicarDominantes(SerieTemporal &serie, std::vector<long double> &dominantes);

#endif