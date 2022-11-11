#ifndef FUNCIONESDINAMICA_H
#define FUNCIONESDINAMICA_H
    
    #include <vector>
    #include "serietemporal.hpp"

    void iniciarMatriz(SerieTemporal &serie, std::vector< std::vector<long double> > &errores);
    void calcularErrores(SerieTemporal &serie, std::vector< std::vector<long double> > &errores,
        std::vector< std::vector<long int> > &father, int puntos);
    void calcularSegmentacion(SerieTemporal &serie, std::vector< std::vector<long int> > &father,
        int puntos);

#endif