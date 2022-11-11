#include <vector>
#include <limits>
#include "funcionesDinamica.hpp"
#include "serietemporal.hpp"

void iniciarMatriz(SerieTemporal &serie, std::vector< std::vector<long double> > &errores){
    errores[0][0] = 0;
    for (int i = 1; i < serie.numeroPuntosSerieTemporal(); i++)
        errores[i][0] = numeric_limits<long double>::infinity();
}

void calcularErrores(SerieTemporal &serie, std::vector< std::vector<long double> > &errores,
std::vector< std::vector<long int> > &father, int puntos){
    for(int m = 1; m < puntos; m++){
        for(int n = m; n < serie.numeroPuntosSerieTemporal(); n++){
            errores[n][m] = numeric_limits<long double>::infinity();
            for(int j = m - 1; j < n; j++){
                long double error = errores[j][m-1] + serie.calcularIseEntreDosPuntos(j, n);
                if (error < errores[n][m]){
                    errores[n][m] = error; 
                    father[n][m] = j;
                }
            }
        }
    }
}

void calcularSegmentacion(SerieTemporal &serie, std::vector< std::vector<long int> > &father,
int puntos){
    long int puntoDominante = serie.numeroPuntosSerieTemporal() - 1;
    serie.dominantePunto(puntoDominante, true);
    for (int i = puntos-1; i >= 0; i--){
        puntoDominante = father[puntoDominante][i];
        serie.dominantePunto(puntoDominante, true);
    }
}
