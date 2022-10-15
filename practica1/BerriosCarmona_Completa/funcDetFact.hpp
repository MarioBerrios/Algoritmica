#ifndef FUNCDETFACT_H
#define FUNCDETFACT_H

    #include <vector>

    void tiemposDeterminanteFactorial(int ordenMin, int ordenMax, int inc,
        std::vector<double> &numeroOrdenes, std::vector<double> &tiemposReales);
    void ajusteFactorial(const std::vector<double> &n,
        const std::vector<double> &tiemposReales, std::vector <double> &a);
    void calcularTiemposEstimadosFactorial(const std::vector<double> &n, 
        const std::vector<double> &a, std::vector<double> &tiemposEstimados);
    double calcularTiempoEstimadoFactorial(const double &n, const std::vector<double> &a);
    double determFact(std::vector< std::vector<double> > &matriz, int n);

#endif