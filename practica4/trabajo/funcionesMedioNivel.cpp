#include <vector>
#include <iostream>
#include "serietemporal.hpp"
#include "funcionesMedioNivel.hpp"
#include "funcionesDinamica.hpp"
#include "funcionesAestrella.hpp"

void metodoDinamica(){

    char nombreFichero[100];
    int puntos = 0;

    std::cout << std::endl;
    std::cout << "Introduzca el nombre del fichero que contiene la serie" << std::endl;
    std::cin >> nombreFichero;
    std::cout << "Introduzca el número de puntos objetivo" << std::endl;
    std::cin >> puntos;

    SerieTemporal serie(nombreFichero);

    std::vector< std::vector<long int> > father =
        std::vector< std::vector<long int> > (serie.numeroPuntosSerieTemporal(), 
        std::vector<long int> (puntos));
    std::vector< std::vector<long double> > errores =
        std::vector< std::vector<long double> > (serie.numeroPuntosSerieTemporal(), 
        std::vector<long double> (puntos));

    iniciarMatriz(serie, errores);
    calcularErrores(serie, errores, father, puntos);
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
    std::vector<Nodo> la;
    std::vector<Nodo> lc;

    algoritmoAestrella(serie, la, lc, puntos, poda);
    /*
    for (Nodo nodo: lc){
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "nodo encontrado " << nodo.punto << " | error: " << nodo.error
             << " | rango: " << nodo.rango << " | padre: " << nodo.padre << std::endl;
        std::cout << "---------------------------------------------" << std::endl;       
    }
    
    for (Nodo nodo: la)    
        if (nodo.punto == 5 && nodo.rango == 1)
            std::cout << "nodo encontrado " << nodo.punto << " | error: " << nodo.error
                << " | rango: " << nodo.rango << " | padre: " << nodo.padre << std::endl;
    */
    crearSegmentacion(serie, lc, puntos);
    /*
    std::cout << serie.calcularIseEntreDosPuntos(0, 5) << std::endl;
    std::cout << serie.calcularIseEntreDosPuntos(5, 9) << std::endl;
    std::cout << serie.calcularIseEntreDosPuntos(9, 10) << std::endl;
    std::cout << serie.calcularIseEntreDosPuntos(10, 49) << std::endl;
    */
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
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    char guardarFichero[50];
    std::cout << "Introduzca el nombre del fichero para guardar la segmentación" << std::endl;
    std::cin >> guardarFichero;
    serie.guardarSegmentacion(guardarFichero);
    std::cout << std::endl;
}