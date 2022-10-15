#include <ctime>
#include <algorithm>
#include <cmath>
#include "funcNlogN.hpp"
#include "misc.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"

void tiemposOrdenacionQuickSort(int nMin, int nMax, int inc, int rep, 
std::vector <double> &tiemposReales, std::vector <double> &numeroElementos){
    std::srand(unsigned(std::time(nullptr)));

    for (int i = nMin; i <= nMax; i += inc) {        
        Clock time;
        double accTiempo = 0;
        double tiempoReal = 0;

        for (int j = 0; j < rep; j++){    
            std::vector<int> valores = std::vector<int>(i);
            std::generate (valores.begin(), valores.end(), numeroAleatorioNlogN);

            time.start();
            std::sort(valores.begin(), valores.end());
            time.stop();

            accTiempo += time.elapsed();
        }

        tiempoReal = accTiempo/rep;
        tiemposReales.push_back(tiempoReal);
        numeroElementos.push_back(i);
    }
}

void ajusteNlogN(const std::vector <double> &n, 
const std::vector <double> &tiemposReales, std::vector <double> &a){
    int ordenM = 2;
    std::vector< std::vector<double> > A, B, X;
    A = std::vector< std::vector<double> >(ordenM, std::vector<double>(ordenM));
    B = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));
    X = std::vector< std::vector<double> >(ordenM, std::vector<double>(1));

    std::vector<double> z;
    for (auto it = n.begin(); it != n.end(); it++){
        z.push_back(*it * log10(*it));
    }

    calcularMatrices(z, tiemposReales, ordenM, A, B);
    resolverSistemaEcuaciones(A, B, ordenM, X);

    for (int i = 0; i < ordenM; i++){
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosNlogN(const std::vector<double> &numeroElementos,
const std::vector<double> &a, std::vector<double> &tiemposEstimados){
    for (size_t i = 0; i < numeroElementos.size(); i++){
        tiemposEstimados.push_back(a[0] + a[1] * numeroElementos[i] * log10(numeroElementos[i]));
    }
}

double calcularTiempoEstimadoNlogN(const double &n, std::vector<double> &a){
    return a[0] + a[1] * n * log10(n);
}

int numeroAleatorioNlogN(){
    return std::rand()%10000000;
}
