#include <vector>
#include <iostream>
#include <string>
#include "funcDetFact.hpp"
#include "misc.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"

void tiemposDeterminanteFactorial(int ordenMin, int ordenMax, int inc,
std::vector<double> &numeroOrdenes, std::vector<double> &tiemposReales){
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
        determFact(matriz, i);
        time.stop();

        tiemposReales.push_back(time.elapsed());
        numeroOrdenes.push_back(i);
    }
}

void ajusteFactorial(const std::vector<double> &n,
const std::vector<double> &tiemposReales, std::vector <double> &a){
    int ordenM = 2;
    std::vector< std::vector<double> > A, B, X;
    A = std::vector< std::vector<double> >(ordenM, std::vector<double>(ordenM));
    B = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));
    X = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));

    std::vector<double> z;
    for (auto it = n.begin(); it != n.end(); it++){
        z.push_back(factorial(*it));
    }

    calcularMatrices(z, tiemposReales, ordenM, A, B);
    resolverSistemaEcuaciones(A, B, ordenM, X);

    for (int i = 0; i < ordenM; i++){
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosFactorial(const std::vector<double> &n, 
const std::vector<double> &a, std::vector<double> &tiemposEstimados){
	for (size_t i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0] + a[1] * factorial(n[i]));
    }
}

double calcularTiempoEstimadoFactorial(const double &n, const std::vector<double> &a){
    return a[0] + a[1] * factorial(n);
}

double determFact(std::vector< std::vector<double> > &matriz, int n){
    double det = 0, h, k;
    std::vector< std::vector<double> > temp =
        std::vector< std::vector<double> > (n, std::vector<double> (n));

    if(n == 1) {
        return matriz[0][0];
    } 
    else if(n == 2) {
        det = (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]);
        return det;
    }
    else if(n == 3) {
        double x = ((matriz[1][1] * matriz[2][2]) - (matriz[2][1] * matriz[1][2]));
        double y = ((matriz[1][0] * matriz[2][2]) - (matriz[2][0] * matriz[1][2]));
        double z = ((matriz[1][0] * matriz[2][1]) - (matriz[2][0] * matriz[1][1]));
	
	    det = ((matriz[0][0] * x) - (matriz[0][1] * y) + (matriz[0][2] * z));
        return det;
    }
    else {
        for(int p = 0; p < n; p++) {
            h = 0;
            k = 0;
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(j == p) {
                        continue;
                    }
                    temp[h][k] = matriz[i][j];
                    k++;
                    if(k == n-1) {
                        h++;
                        k = 0;
                    }
                }
            }
            det = det + matriz[0][p] * pow(-1,p) * determFact(temp, n-1);
        }
        return det;
    }
}
