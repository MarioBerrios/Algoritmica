#include <vector>
#include "funciones.hpp"
#include "serietemporal.hpp"

void calcularSecuenciaErrorMax(SerieTemporal &serie, std::vector<int> intervalo,
long double &errorMax){
    int pos;
    long double errorMaxInt = serie.calcularEmaxEntreDosPuntos(intervalo[0], intervalo[1], pos);

    if (errorMaxInt > errorMax){
        serie.dominantePunto(pos, true);
        std::vector<int> intInf {intervalo[0], pos};
        std::vector<int> intSup {pos, intervalo[1]};
        calcularSecuenciaErrorMax(serie, intInf, errorMax);
        calcularSecuenciaErrorMax(serie, intSup, errorMax);
    }

}

void calcularSecuenciaInter(SerieTemporal &serie, std::vector<int> intervalo,
long double &errorMax){
    int pos;
    long double errorMaxInt = serie.calcularEmaxEntreDosPuntos(intervalo[0], intervalo[1], pos);

    if (errorMaxInt > errorMax){
        serie.dominantePunto((intervalo[0] + intervalo[1])/2, true);
        std::vector<int> intInf {intervalo[0], (intervalo[0] + intervalo[1])/2};
        std::vector<int> intSup {(intervalo[0] + intervalo[1])/2, intervalo[1]};
        calcularSecuenciaInter(serie, intInf, errorMax);
        calcularSecuenciaInter(serie, intSup, errorMax);
    }
}