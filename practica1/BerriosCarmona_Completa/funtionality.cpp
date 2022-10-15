#include <iostream>
#include <vector>
#include "funtionality.hpp"
#include "ClaseTiempo.hpp"
#include "funcNlogN.hpp"
#include "misc.hpp"
#include "funcDetIt.hpp"
#include "funcDetFact.hpp"

void ordenacionQuickSort(){
    int nMin = 1, nMax = 1, inc = 100, rep = 0;
    double valor = -1;
    std::vector<double> tiemposReales, numeroElemntos, a, tiemposEstimados;
  
    std::cout << std::endl;
    std::cout << "Introduzca el tamaño mínimo del vector" << std::endl;
    std::cin >> nMin;
    std::cout << "Introduzca el tamaño máximo del vector" << std::endl;
    std::cin >> nMax;
    std::cout << "Introduzca el incremento de cada vector" << std::endl;
    std::cin >> inc;
    std::cout << "Introduzca las repeticiones por vector" << std::endl;
    std::cin >> rep;

    tiemposOrdenacionQuickSort(nMin, nMax, inc, rep, tiemposReales, numeroElemntos);
    ajusteNlogN(numeroElemntos, tiemposReales, a);
    calcularTiemposEstimadosNlogN(numeroElemntos, a, tiemposEstimados);

    double alpha = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << std::endl;
    std::cout << "El coeficiente de determinación es de " << alpha << std::endl;
    std::cout << "f(n) = " << a[0] << " + " << a[1] << " * n * log10(n)" << std::endl;

    guardarDatosFichero(numeroElemntos, tiemposReales, tiemposEstimados, "datosFinales.txt");
    mostrarGrafica("script_gnuplot.sh");

    while(valor != 0){
        std::cout << std::endl;
        std::cout << "Introduzca el valor que quiera estimar (0 para salir)" << std::endl;
        std::cin >> valor;
        if (valor != 0){
            double microseg = calcularTiempoEstimadoNlogN(valor, a);
            conversionMicroseg(microseg);
        }
    }
}

void determinanteIterativo(){
    int ordenMin = 1, ordenMax = 1, inc = 0;
    double valor = -1;
    std::vector<double> numeroOrdenes, tiemposReales, a, tiemposEstimados;
  
    std::cout << std::endl;
    std::cout << "Introduzca el orden mínimo de la matriz" << std::endl;
    std::cin >> ordenMin;
    std::cout << "Introduzca el orden máximo de la matriz" << std::endl;
    std::cin >> ordenMax;
    std::cout << "Introduzca el incremento del orden de la matriz" << std::endl;
    std::cin >> inc;

    tiemposDeterminanteIterativo(ordenMin, ordenMax, inc, numeroOrdenes, tiemposReales);
    ajustePolinomico(numeroOrdenes, tiemposReales, a);
    calcularTiemposEstimadosPolinomico(numeroOrdenes, a, tiemposEstimados);

    double alpha = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << std::endl;
    std::cout << "El coeficiente de determinación es de " << alpha << std::endl;
    std::cout << "f(n) = " << a[0] << " + " << a[1] << " * n  + " 
        << a[2] << " * n² + " << a[3] << " * n³" << std::endl;

    guardarDatosFichero(numeroOrdenes, tiemposReales, tiemposEstimados, "datosFinales.txt");
    mostrarGrafica("script_gnuplot.sh");

    while(valor != 0){
        std::cout << std::endl;
        std::cout << "Introduzca el valor que quiera estimar (0 para salir)" << std::endl;
        std::cin >> valor;
        if (valor != 0){
            double microseg = calcularTiempoEstimadoPolinomico(valor, a);
            conversionMicroseg(microseg);
        }
    }
}

void determinanteRecursivo(){
    int ordenMin = 1, ordenMax = 1, inc = 0;
    double valor = -1;
    std::vector<double> numeroOrdenes, tiemposReales, a, tiemposEstimados;
  
    std::cout << std::endl;
    std::cout << "Introduzca el orden mínimo de la matriz" << std::endl;
    std::cin >> ordenMin;
    std::cout << "Introduzca el orden máximo de la matriz" << std::endl;
    std::cin >> ordenMax;
    std::cout << "Introduzca el incremento del orden de la matriz" << std::endl;
    std::cin >> inc;

    tiemposDeterminanteFactorial(ordenMin, ordenMax, inc, numeroOrdenes, tiemposReales);
    ajusteFactorial(numeroOrdenes, tiemposReales, a);
    calcularTiemposEstimadosFactorial(numeroOrdenes, a, tiemposEstimados);

    double alpha = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << std::endl;
    std::cout << "El coeficiente de determinación es de " << alpha << std::endl;
    std::cout << "f(n) = " << a[0] << " + " << a[1] << " * n!" << std::endl;

    guardarDatosFichero(numeroOrdenes, tiemposReales, tiemposEstimados, "datosFinales.txt");
    mostrarGrafica("script_gnuplot.sh");

    while(valor != 0){
        std::cout << std::endl;
        std::cout << "Introduzca el valor que quiera estimar (0 para salir)" << std::endl;
        std::cin >> valor;
        if (valor != 0){
            double microseg = calcularTiempoEstimadoFactorial(valor, a);
            conversionMicroseg(microseg);
        }
    }
}