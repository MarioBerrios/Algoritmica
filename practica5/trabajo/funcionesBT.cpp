#include <vector>
#include <iostream>
#include <limits>
#include "comunes.hpp"
#include "ClaseTiempo.hpp"

void calcularSolucionesBT(std::vector< std::vector<int>> &soluciones, const int reinas){
    std::vector<int> solucion (reinas);
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1){
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < reinas && !lugar(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < reinas){
            if (fila == reinas - 1)
                soluciones.push_back(solucion);
            else {
                fila = fila + 1;
                solucion[fila] = -1;
            }
        } else
            fila = fila - 1; 
    }
}

std::vector<int> calcularSolucionBT(const int reinas){
    std::vector<int> solucion(reinas);
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1){
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < reinas && !lugar(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < reinas){
            if (fila == reinas - 1)
                return solucion; 
            else {
                fila = fila + 1;
                solucion[fila] = -1;
            }
        }
        else
            fila = fila - 1; 
    }

    solucion.clear();
    return solucion;
}

void calcularSolucionPodaBT(std::vector<int> &solucion_optima, int reinas, 
long double &peso_optimo){
    long double peso = 0;
    peso_optimo = std::numeric_limits<long double>::infinity();
    std::vector<int> solucion (reinas);
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1){
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < reinas && !lugar(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < reinas){
            peso += (solucion[fila]+1)*(fila+1);
            if(peso < peso_optimo){
                if (fila == reinas - 1){
                    peso_optimo = peso;
                    solucion_optima = solucion;
                    peso -= (solucion[fila]+1)*(fila+1);
                } else {
                    fila = fila + 1;
                    solucion[fila] = -1;
                }
            } else {
                peso -= (solucion[fila]+1)*(fila+1);
                fila = fila - 1;
                if (fila >= 0)
                    peso -= (solucion[fila]+1)*(fila+1);
            }
        } else {
            fila = fila - 1;
            if (fila >= 0)
                peso -= (solucion[fila]+1)*(fila+1);
        }
    }
}

void mostrarSoluciones(const std::vector< std::vector<int> > &soluciones, const Clock &time){
    std::cout << std::endl;
    for (auto solucion: soluciones){
        std::cout << "[" ;
        for (auto valor: solucion)
            std::cout << " " << valor;
        std::cout << " ]" << std::endl;
    }
    std::cout << "Número de soluciones: " << soluciones.size() << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000.0 << "ms" << std::endl;
    std::cout << std::endl;
}

void mostrarSolucion(const std::vector<int> &solucion, const Clock &time){
    std::cout << std::endl;
    std::cout << "[";
    for(auto valor: solucion)
        std::cout << " " << valor;
    std::cout << " ]" << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000.0 << "ms" << std::endl;
    std::cout << std::endl;
}

void mostrarSolucionPoda(std::vector<int> &solucion, Clock &time, long double peso){
    std::cout << std::endl;
    std::cout << "[";
    for(auto valor: solucion)
        std::cout << " " << valor;
    std::cout << " ]" << std::endl;
    std::cout << "Peso: " << peso << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000.0 << "ms" << std::endl;
    std::cout << std::endl;
}