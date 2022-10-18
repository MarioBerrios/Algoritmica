#include <vector>
#include <limits>
#include <iostream>
#include "funciones.hpp"
#include "serietemporal.hpp"

int calcularMinimo (std::vector<long double> errores);

void iniciarDominantesErrores(SerieTemporal &serie, std::vector<long double> &dominantes,
std::vector<long double> &errores, int error_type){
    int aux;

    errores.push_back(std::numeric_limits<float>::infinity());
    dominantes.push_back(0);

    for (int i = 1; i < serie.numeroPuntosSerieTemporal() - 1; i++){
        dominantes.push_back(i);
        if (error_type == 1)
            errores.push_back(serie.calcularEmaxEntreDosPuntos(i-1, i+1, aux));
        else
            errores.push_back(serie.calcularIseEntreDosPuntos(i-1, i+1));
    }

    errores.push_back(std::numeric_limits<float>::infinity());
    dominantes.push_back(serie.numeroPuntosSerieTemporal() - 1);
}

void calcularSegmentacionISE(SerieTemporal &serie, std::vector<long double> &dominantes,
std::vector<long double> &errores, int puntos){
    for (int i = 0; i < serie.numeroPuntosSerieTemporal() - puntos; i++){
        int pos_minimo_errores = calcularMinimo(errores);
        dominantes.erase(dominantes.begin() + pos_minimo_errores);
        errores.erase(errores.begin() + pos_minimo_errores);

        if (dominantes[pos_minimo_errores - 1] != 0 
        && errores[pos_minimo_errores - 1] != std::numeric_limits<float>::infinity())
            errores[pos_minimo_errores - 1] = serie.calcularIseEntreDosPuntos(
                dominantes[pos_minimo_errores - 2], dominantes[pos_minimo_errores]);
        
        if (dominantes[pos_minimo_errores] != serie.numeroPuntosSerieTemporal() - 1
        && errores[pos_minimo_errores] != std::numeric_limits<float>::infinity()) 
            errores[pos_minimo_errores] = serie.calcularIseEntreDosPuntos(
                dominantes[pos_minimo_errores - 1], dominantes[pos_minimo_errores + 1]);
    }
}

void calcularSegmentacionEMax(SerieTemporal &serie, std::vector<long double> &dominantes,
std::vector<long double> &errores, int puntos){
    int aux;
    for (int i = 0; i < serie.numeroPuntosSerieTemporal() - puntos; i++){
        int pos_minimo_errores = calcularMinimo(errores);
        dominantes.erase(dominantes.begin() + pos_minimo_errores);
        errores.erase(errores.begin() + pos_minimo_errores);

        if (dominantes[pos_minimo_errores - 1] != 0 
        && errores[pos_minimo_errores - 1] != std::numeric_limits<float>::infinity())
            errores[pos_minimo_errores - 1] = serie.calcularEmaxEntreDosPuntos(
                dominantes[pos_minimo_errores - 2], dominantes[pos_minimo_errores], aux);
        
        if (dominantes[pos_minimo_errores] != serie.numeroPuntosSerieTemporal() - 1
        && errores[pos_minimo_errores] != std::numeric_limits<float>::infinity()) 
            errores[pos_minimo_errores] = serie.calcularEmaxEntreDosPuntos(
                dominantes[pos_minimo_errores - 1], dominantes[pos_minimo_errores + 1], aux);
    }
}

void adjudicarDominantes(SerieTemporal &serie, std::vector<long double> &dominantes){
    for (auto it = dominantes.begin(); it != dominantes.end(); it++)
        serie.dominantePunto(*it, true);
}

int calcularMinimo (std::vector<long double> errores){
    long double minimo = errores[0];
    int cont = 0, pos = 0;
    for (auto it = errores.begin(); it != errores.end(); it++){
        if (*it < minimo){
            minimo = *it;
            pos = cont;
        }
        cont++;
    }
    return pos;
}