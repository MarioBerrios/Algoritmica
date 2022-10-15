#ifndef FUNCDETIT_HPP
#define FUNCDETIT_HPP

    #include <vector>
    
    void tiemposDeterminanteIterativo(int ordenMin, int ordenMax, int inc, 
    std::vector<double> &numeroOrden, std::vector<double> &tiemposReales);
    void ajustePolinomico(const std::vector<double> &n, 
        const std::vector <double> &tiemposReales, std::vector <double> &a);
    void calcularTiemposEstimadosPolinomico(const std::vector<double> &n,
        const std::vector<double> &a, std::vector<double> &tiemposEstimados);
    double calcularTiempoEstimadoPolinomico(const double &n, const std::vector<double> &a);
    
#endif