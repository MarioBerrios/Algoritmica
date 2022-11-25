#include <vector>
#include <iostream>
#include <cmath>
#include "ClaseTiempo.hpp"
#include "funcionesBT.hpp"
#include "funcionesVegas.hpp"
#include "funcionesMontecarlo.hpp"

void nReinasTodasBT(){
    int reinas;
    std::cout << std::endl;
    std::cout << "Introduzca el número de reinas" << std::endl;
    std::cin >> reinas;

    std::vector< std::vector<int> > soluciones;
    Clock time;

    time.start();
    calcularSolucionesBT(soluciones, reinas);
    time.stop();

    mostrarSoluciones(soluciones, time);
}

void nReinasUnaBT(){
    int reinas;
    std::cout << std::endl;
    std::cout << "Introduzca el número de reinas" << std::endl;
    std::cin >> reinas;

    std::vector<int> solucion;
    Clock time;

    time.start();
    solucion = calcularSolucionBT(reinas);
    time.stop();

    mostrarSolucion(solucion, time);
}

void nReinasVegas(){
    int reinas;
    long int intentos = 1;
    long int no_existos = 1;
    std::cout << std::endl;
    std::cout << "Introduzca el número de reinas" << std::endl;
    std::cin >> reinas;

    std::vector<int> solucion (reinas, -1);
    Clock time;
    bool exito = false;

    time.start();
    while (!exito && no_existos < 100000){
        exito = calcularSolucionVegas(solucion, reinas, intentos);
        no_existos++;
    }
    time.stop();

    mostrarSolucion(solucion, time, intentos, no_existos);
}

void nReinasPodaBT(){
    int reinas;
    long double peso = 0;
    std::cout << std::endl;
    std::cout << "Introduzca el número de reinas" << std::endl;
    std::cin >> reinas;

    std::vector<int> solucion;
    Clock time;

    time.start();
    calcularSolucionPodaBT(solucion, reinas, peso);
    time.stop();

    mostrarSolucionPoda(solucion, time, peso);
}

void verificarProductoMatrices(){
    int orden, repeticiones = 1;
    long double tiempo_producto, tiempo_verificacion, probabilidad = 0;
    std::cout << std::endl;
    std::cout << "Introduzca el orden de las matrices" << std::endl;
    std::cin >> orden; 
    std::cout << "Introduzca número de repeticiones" << std::endl;
    std::cin >> repeticiones;

    Clock time;
    std::vector< std::vector<int> > A (orden, std::vector<int>(orden));
    std::vector< std::vector<int> > B (orden, std::vector<int>(orden));
    std::vector< std::vector<int> > C (orden, std::vector<int>(orden));
    
    rellenarMatrices(orden, A, B);
    time.start();
    productoMatricesCuadradas(orden, A, B, C);
    time.stop();
    tiempo_producto = time.elapsed();
    cambiarMatrizDado(orden, C);

    time.start();
    bool correcto = verificarProductoRepeticiones(repeticiones, orden, A, B, C);
    time.stop();
    tiempo_verificacion = time.elapsed();

    if (correcto)
        probabilidad = 1.0 - std::pow((long double) 1/2, (long double) repeticiones);

    mostrarSolucionMontecarlo(correcto, probabilidad, tiempo_producto, tiempo_verificacion);
}
    
void verificarFallar(){
    long int orden, repeticiones = 1, ejecuciones = 1, aciertos = 0;
    long double probabilidad, probabilidad_real,
        tiempo_producto, tiempo_verificacion;
    std::cout << std::endl;
    std::cout << "Introduzca el orden de las matrices" << std::endl;
    std::cin >> orden; 
    std::cout << "Introduzca número de repeticiones" << std::endl;
    std::cin >> repeticiones;
    std::cout << "Introduzca número de ejecuciones" << std::endl;
    std::cin >> ejecuciones;
    Clock time;
    std::vector< std::vector<int> > A (orden, std::vector<int>(orden));
    std::vector< std::vector<int> > B (orden, std::vector<int>(orden));
    std::vector< std::vector<int> > C (orden, std::vector<int>(orden));
    
    rellenarMatrices(orden, A, B);
    time.start();
    productoMatricesCuadradas(orden, A, B, C);
    time.stop();
    tiempo_producto = time.elapsed();
    bool cambio = false;
    while(!cambio)
        cambio = cambiarMatrizDado(orden, C);

    time.start();

    for (int i = 0; i < ejecuciones; i++){
        if(!verificarProductoRepeticiones(repeticiones, orden, A, B, C)){
            aciertos++;
        }
    }

    time.stop();
    tiempo_verificacion = time.elapsed();

    probabilidad = 1.0 - std::pow((long double) 1/2, (long double) repeticiones);
    probabilidad_real = (long double) aciertos/ (long double) ejecuciones;
    mostrarSolucionMontecarloFallo(ejecuciones, repeticiones, aciertos, probabilidad, 
        probabilidad_real, tiempo_producto, tiempo_verificacion);
}