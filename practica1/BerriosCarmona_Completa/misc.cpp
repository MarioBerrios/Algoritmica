#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <fstream>
#include <iostream>
#include "misc.hpp"

double calcularVarianza(const std::vector<double> &n);
double calcularMedia(const std::vector<double> &n);

void introducirValoresMatriz(std::vector< std::vector<double> > &matriz, int n,
std::string intr_valor_manual){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            double valor = 0;
            if (!intr_valor_manual.compare("s")){
                std::cout << "Introduzca la posición [" << i << "][" << j <<"]" << std::endl;
                std::cin >> valor;
            } else {
                valor = 0.95 + ((std::rand()%100) * 0.1/100);
            }
            matriz[i][j] = valor;
        }
    }
    
}

void calcularMatrices(const std::vector<double> &x, const std::vector<double> &y, int n,
std::vector< std::vector<double> > &A, std::vector< std::vector<double> > &B){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = sumatorio(x, y, i+j, 0);
        }
        B[i][0] = sumatorio(x, y, i, 1);
    }
}
    
double sumatorio(const std::vector<double> &n, const std::vector<double> &t,
int expN, int expT){
    double suma = 0;
    for (size_t i = 0; i < n.size(); i++){
        suma += pow(n[i], expN) * pow(t[i], expT);
    }
    return suma;
}

double calcularCoeficienteDeterminacion(const std::vector<double> &tiemposReales,
const std::vector<double> &tiemposEstimados){
    double varTR = calcularVarianza(tiemposReales);
    double varTE = calcularVarianza(tiemposEstimados);

    return varTE/varTR;
}

double calcularVarianza(const std::vector<double> &n){
    double media = calcularMedia(n);
    double var = 0;
    for (size_t i = 0; i < n.size(); i++){
        var += pow(n[i] - media, 2);
    }
    var /= (double) n.size();
    return var;
}

double calcularMedia(const std::vector<double> &n){
    return std::accumulate(n.begin(), n.end(), 0) / (double) n.size();
}

void guardarDatosFichero(const std::vector<double> &numeroElementos,
const std::vector<double> &tiemposReales, std::vector<double> &tiemposEstimados,
std::string nombreFichero){
    std::ofstream file;
    file.open(nombreFichero);
    for (size_t i = 0; i < numeroElementos.size(); i++){
        file << numeroElementos[i] << "\t" << tiemposReales[i] 
            << "\t" << tiemposEstimados[i] << std::endl;
    }
    file.close();
}

void mostrarGrafica(std::string script){
    std::string orden = "./" + script;
    system(orden.c_str());
}

int numeroAleatorio(int min, int max){
    return (std::rand()%(max - min + 1)) + min;
}

double factorial (double num){
    double factorial = 1;
    for (int i = 1; i <= num; i++){
        factorial *= i;
    }
    return factorial;
}

void conversionMicroseg(double microseg){
    double seg = microseg / 1000000;
    long int min = seg / 60;
    double decimales = seg - (long int) seg;
    long int seg_int = ((long int) seg) % 60;

    seg = seg_int + decimales;

    long int hrs = min/60;
    min %= 60;

    long int dias = hrs/24;
    hrs %= 24;

    long int years = dias/365;
    dias %= 365;
    
    std::cout << "Años: " << years << std::endl;
    std::cout << "Días: " << dias << std::endl;
    std::cout << "Minutos: " << min << std::endl;
    std::cout << "Segundos: " << seg << std::endl;
}