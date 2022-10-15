#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "funcDetIt.hpp"
#include "ClaseTiempo.hpp"
#include "misc.hpp"
#include "sistemaEcuaciones.hpp"

void tiemposDeterminanteIterativo(int ordenMin, int ordenMax, int inc, 
std::vector<double> &numeroOrden, std::vector<double> &tiemposReales){
    std::string intr_valor_manual;
    std::cout << "¿Desea introducir los valores a mano? [s/n]" << std::endl;
    std::cin >> intr_valor_manual;

    for (int i = ordenMin; i <= ordenMax; i += inc){
        Clock time;

        std::vector< std::vector<double> > matriz = 
            std::vector< std::vector<double> >(i, std::vector<double>(i));
        introducirValoresMatriz(matriz, i, intr_valor_manual);

        std::vector< std::vector<double> > inversa = 
            std::vector< std::vector<double> >(i, std::vector<double>(i));
	
        time.start();
        inicializarInversa(inversa);
        trianguloInferior(matriz, inversa);
        productoDiagonal(matriz);
        time.stop();

        tiemposReales.push_back(time.elapsed());

        numeroOrden.push_back(i);
    }
}

void ajustePolinomico(const std::vector<double> &n, 
const std::vector <double> &tiemposReales, std::vector <double> &a){
	int ordenM = 4;
    std::vector< std::vector<double> > A, B, X;
    A = std::vector< std::vector<double> >(ordenM, std::vector<double>(ordenM));
    B = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));
    X = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));

    calcularMatrices(n, tiemposReales, ordenM, A, B);
    resolverSistemaEcuaciones(A, B, ordenM, X);

    for (int i = 0; i < ordenM; i++){
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosPolinomico(const std::vector<double> &n, 
const std::vector<double> &a, std::vector<double> &tiemposEstimados){
	for (size_t i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0] + a[1] * n[i] + a[2] * n[i]*n[i] + a[3] * n[i]*n[i]*n[i]);
    }
}

double calcularTiempoEstimadoPolinomico(const double &n, const std::vector<double> &a){
	return a[0] + a[1] * n + a[2] * n * n + a[3] * n * n * n;
}