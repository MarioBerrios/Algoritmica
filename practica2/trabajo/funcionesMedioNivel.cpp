#include <iostream>
#include <vector>
#include <string>
#include "funcionesMedioNivel.hpp"
#include "serietemporal.hpp"
#include "funciones.hpp"

void metodo1(){
    char nombreFichero[100];
    long double errorMax = 0;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el error máximo permitido" << std::endl;
    std::cin >> errorMax;

    SerieTemporal serie(nombreFichero);
    serie.dominantePunto(0, true);
    serie.dominantePunto(serie.numeroPuntosSerieTemporal() - 1, true);

    std::vector<int> intervalo {0, serie.numeroPuntosSerieTemporal() - 1};
    calcularSecuenciaErrorMax(serie, intervalo, errorMax);

    long double ise;
    int posicion;
    serie.erroresSegmentacion(ise, errorMax, posicion);

    std::cout << "Número de puntos dominantes: " << serie.contarPuntosDominantes() << std::endl;
    std::cout << "ISE = " << ise << std::endl;
    std::cout << "Error máximo = " << errorMax << std::endl;
    std::cout << "Punto de error máximo: " << posicion << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
}

void metodo2(){
    char nombreFichero[100];
    long double errorMax = 0;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el error máximo permitido" << std::endl;
    std::cin >> errorMax;

    SerieTemporal serie(nombreFichero);
    serie.dominantePunto(0, true);
    serie.dominantePunto(serie.numeroPuntosSerieTemporal() - 1, true);

    std::vector<int> intervalo {0, serie.numeroPuntosSerieTemporal() - 1};
    calcularSecuenciaInter(serie, intervalo, errorMax);

    long double ise;
    int posicion;
    serie.erroresSegmentacion(ise, errorMax, posicion);

    std::cout << "Número de puntos dominantes: " << serie.contarPuntosDominantes() << std::endl;
    std::cout << "ISE = " << ise << std::endl;
    std::cout << "Error máximo = " << errorMax << std::endl;
    std::cout << "Punto de error máximo: " << posicion << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
}