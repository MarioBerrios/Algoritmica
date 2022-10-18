#include <vector>
#include <iostream>
#include "serietemporal.hpp"
#include "funcionesMedioNivel.hpp"
#include "funciones.hpp"

void metodoISE(){

    char nombreFichero[100];
    int puntos = 0;

    std::cout << std::endl;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el número de puntos objetivo" << std::endl;
    std::cin >> puntos;

    SerieTemporal serie(nombreFichero);

    std::vector<long double> errores;
    std::vector<long double> dominantes;
    iniciarDominantesErrores(serie, dominantes, errores, 0);
    calcularSegmentaciónISE(serie, dominantes, errores, puntos);
    adjudicarDominantes(serie, dominantes);

    long double errorMax;
    long double ise;
    int posicion;
    serie.erroresSegmentacion(ise, errorMax, posicion);

    std::cout << std::endl;
    std::cout << "Número de puntos dominantes: " << serie.contarPuntosDominantes() << std::endl;
    std::cout << "ISE = " << ise << std::endl;
    std::cout << "Error máximo = " << errorMax << std::endl;
    std::cout << "Punto de error máximo: " << posicion << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
    std::cout << std::endl;
}