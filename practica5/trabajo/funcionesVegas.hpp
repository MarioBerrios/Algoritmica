#ifndef FUNCIONESVEGAS_H
#define FUNCIONESVEGAS_H
    
    #include <vector>
    #include "ClaseTiempo.hpp"

    bool calcularSolucionVegas(std::vector<int> &solucion, const int reinas, long int &intentos);
    void mostrarSolucion(const std::vector<int> &solucion, const Clock &time, 
        const long int intentos, const long int no_exitos);

#endif