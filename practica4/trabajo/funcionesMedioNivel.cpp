#include <vector>
#include <iostream>
#include "serietemporal.hpp"
#include "funcionesMedioNivel.hpp"
#include "funcionesDinamica.hpp"
#include "funcionesAestrella.hpp"
#include "ClaseTiempo.hpp"

void metodoDinamica(){

    char nombreFichero[100];
    int puntos = 0;

    std::cout << std::endl;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el número de puntos objetivo" << std::endl;
    std::cin >> puntos;

    SerieTemporal serie(nombreFichero);
    Clock time;

    std::vector< std::vector<long int> > father =
        std::vector< std::vector<long int> > (serie.numeroPuntosSerieTemporal(), 
        std::vector<long int> (puntos));
    std::vector< std::vector<long double> > errores =
        std::vector< std::vector<long double> > (serie.numeroPuntosSerieTemporal(), 
        std::vector<long double> (puntos));

    iniciarMatriz(serie, errores);
    time.start();
    calcularErrores(serie, errores, father, puntos);
    time.stop();
    guardarSegmentacion(serie, father, puntos);

    long double errorMax;
    long double ise;
    int posicion;
    serie.erroresSegmentacion(ise, errorMax, posicion);

    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Número de puntos dominantes: " << serie.contarPuntosDominantes() << std::endl;
    std::cout << "ISE = " << ise << std::endl;
    std::cout << "Error máximo = " << errorMax << std::endl;
    std::cout << "Punto de error máximo: " << posicion << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000000.0 << "s" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
    std::cout << std::endl;
}

void metodoAestrella(){

    char nombreFichero[100];
    int puntos = 0;
    long double poda = 0;

    std::cout << std::endl;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el número de puntos objetivo" << std::endl;
    std::cin >> puntos;
    std::cout << "Introduzca el valor de poda" << std::endl;
    std::cin >> poda;

    SerieTemporal serie(nombreFichero);

    //TODO
    Clock time;
    std::vector<Nodo> la;
    std::vector<Nodo> lc;
    
    time.start();
    algoritmoAestrella(serie, la, lc, puntos, poda);
    time.stop();
    crearSegmentacion(serie, lc, puntos);

    long double errorMax;
    long double ise;
    int posicion;
    serie.erroresSegmentacion(ise, errorMax, posicion);

    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Número de puntos dominantes: " << serie.contarPuntosDominantes() << std::endl;
    std::cout << "ISE = " << ise << std::endl;
    std::cout << "Error máximo = " << errorMax << std::endl;
    std::cout << "Punto de error máximo: " << posicion << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000000.0 << "s" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
    std::cout << std::endl;
}