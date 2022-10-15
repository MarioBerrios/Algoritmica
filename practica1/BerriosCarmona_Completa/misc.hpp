#ifndef MISC_HPP
#define MISC_HPP

    #include <vector>
    #include <string>

    void introducirValoresMatriz(std::vector< std::vector<double> > &matriz, int n, 
        std::string intr_valor_manual);
    void calcularMatrices(const std::vector<double> &x, const std::vector<double> &y, int n,
        std::vector< std::vector<double> > &A, std::vector< std::vector<double> > &B);
    double sumatorio(const std::vector<double> &n, const std::vector<double> &t, 
        int expN, int expT);
    double calcularCoeficienteDeterminacion(const std::vector<double> &tiemposReales,
        const std::vector<double> &tiemposEstimados);
    void guardarDatosFichero(const std::vector<double> &numeroElementos,
        const std::vector<double> &tiemposReales, std::vector<double> &tiemposEstimados,
        std::string nombreFichero);
    void mostrarGrafica(std::string script);
    void introducirValoresMatriz(std::vector< std::vector<double> > &matriz, int n);
    int numeroAleatorio(int min, int max);
    double factorial(double num);
    void conversionMicroseg(double microseg);
        
#endif