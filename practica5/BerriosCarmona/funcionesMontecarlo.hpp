#ifndef FUNCIONESMONTECARLO_H
#define FUNCIONESMONTECARLO_H

    #include <vector>

    void rellenarMatrices(const int orden, std::vector< std::vector<int> > &A, 
        std::vector< std::vector<int> > &B);
    void productoMatricesCuadradas(const int orden, const std::vector< std::vector<int> > &A,
        const std::vector< std::vector<int> > &B, std::vector< std::vector<int> > &C);
    bool cambiarMatrizDado(const int orden, std::vector <std::vector<int> > &C);
    bool verificarProductoRepeticiones(const int repeticiones, int &intentos, const int orden,
        const std::vector< std::vector<int> > &A, const std::vector< std::vector<int> > &B, 
        const std::vector< std::vector<int> > &C);
    void mostrarSolucionMontecarlo(const bool correcto, const int intentos,
        const long double probabilidad, const long double tiempo_producto, 
        const long double tiempo_verificacion);
    void mostrarSolucionMontecarloFallo(const long int ejecuciones, const long int repeticiones, 
        const long int aciertos, const long double probabilidad, const long double probabilidad_real,
        const long double tiempo_producto, const long double tiempo_verificacion);

#endif