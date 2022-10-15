#ifndef FUNCNLOGN_H
#define FUNCNLOGN_H

    #include <vector>

    void tiemposOrdenacionQuickSort(int nMin, int nMax, int inc, int rep,
        std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
    void ajusteNlogN(const std::vector <double> &numeroElementos, 
        const std::vector <double> &tiemposReales, std::vector <double> &a);
    void calcularTiemposEstimadosNlogN(const std::vector<double> &numeroElementos,
        const std::vector<double> &a, std::vector<double> &tiemposEstimados);
    double calcularTiempoEstimadoNlogN(const double &n, std::vector<double> &a);
    int numeroAleatorioNlogN();

#endif