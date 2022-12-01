#ifndef FUNCIONESBT_H
#define FUNCIONESBT_H

    #include <vector>
    #include "ClaseTiempo.hpp"

    void calcularSolucionesBT(std::vector< std::vector<int>> &soluciones, const int reinas);
    std::vector<int> calcularSolucionBT(const int reinas);
    void calcularSolucionPodaBT(std::vector<int> &solucion_optima, int reinas, 
        long double &peso_optimo);
    void mostrarSoluciones(const std::vector< std::vector<int> > &soluciones, const Clock &time);
    void mostrarSolucion(const std::vector<int> &solucion, const Clock &time);
    void mostrarSolucionPoda(std::vector<int> &solucion, Clock &time, long double peso);

#endif