#include <vector>
#include <cstdlib>
#include <iostream>
    
bool verificarProducto(const int orden, const std::vector< std::vector<int> > &A, 
    const std::vector< std::vector<int> > &B, const std::vector< std::vector<int> > &C);
std::vector<int> productoVectorMatriz(const int orden, const std::vector<int> &x,
    const std::vector< std::vector<int> > &A);

void rellenarMatrices(const int orden, std::vector< std::vector<int> > &A, 
std::vector< std::vector<int> > &B){
    for(int i = 0; i < orden; i++)
        for(int j = 0; j < orden; j++){
            A[i][j] = rand()%3 - 1;
            B[i][j] = rand()%3 - 1;
        }
}

void productoMatricesCuadradas(const int orden, const std::vector< std::vector<int> > &A,
const std::vector< std::vector<int> > &B, std::vector< std::vector<int> > &C){
    for(int i = 0; i < orden; i++)
        for(int j = 0; j < orden; j++){
            C[i][j] = 0;
            for(int k = 0; k < orden; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

bool cambiarMatrizDado(const int orden, std::vector <std::vector<int> > &C){
    int dado = (rand()%6) + 1;
    if( dado%2 != 0){
        C[orden/2][orden/2] = C[orden/2][orden/2] + 1;
        std::cout << "[INFO] Se ha realizado C[n/2][n/2] = C[n/2][n/2] + 1" << std::endl;
        return true;
    }
    return false;
}


bool verificarProductoRepeticiones(const int repeticiones, int &intentos, const int orden, 
const std::vector< std::vector<int> > &A, const std::vector< std::vector<int> > &B, 
const std::vector< std::vector<int> > &C){
    for (int i = 0; i < repeticiones; i++){
        intentos++;
        if (!verificarProducto(orden, A, B, C))
            return false;
    }

    return true;
}

void mostrarSolucionMontecarlo(const bool correcto, const int intentos, const long double probabilidad, 
const long double tiempo_producto, const long double tiempo_verificacion){
    std::cout << std::endl;
    if(correcto){
        std::cout << "CORRECTO. La matriz C es el producto de AB" << std::endl;
        std::cout << "Intentos: " << intentos << std::endl;
        std::cout << "Probabilidad: " << probabilidad << std::endl;
        std::cout << "Tiempo del producto: " << tiempo_producto/1000.0 << "ms" << std::endl;
        std::cout << "Tiempo de la verificación: " << tiempo_verificacion/1000.0 << "ms" << std::endl;
    } else {
        std::cout << "FALSO. La matriz C no es el producto de AB" << std::endl;
        std::cout << "Intentos: " << intentos << std::endl;
        std::cout << "Tiempo del producto: " << tiempo_producto/1000.0 << "ms" << std::endl;
        std::cout << "Tiempo de la verificación: " << tiempo_verificacion/1000.0 << "ms" << std::endl;          
    }
    std::cout << std::endl;
}

void mostrarSolucionMontecarloFallo(const long int ejecuciones, const long int repeticiones, 
const long int aciertos, const long double probabilidad, const long double probabilidad_real,
const long double tiempo_producto, const long double tiempo_verificacion){
    std::cout << std::endl;
    std::cout << "FALLO FORZADO (matriz cambiada)" << std::endl;
    std::cout << "Ejecuciones: " << ejecuciones << std::endl;
    std::cout << "Aciertos: " << aciertos << std::endl;
    std::cout << "Repeticiones: " << repeticiones << std::endl;
    std::cout << "Probabilidad teórica: " << probabilidad << std::endl;
    std::cout << "Probabilidad real: " << probabilidad_real << std::endl;
    std::cout << "Tiempo del producto: " << tiempo_producto/1000.0 << "ms" << std::endl;
    std::cout << "Tiempo de la verificación: " << tiempo_verificacion/1000.0 << "ms" << std::endl;
    std::cout << std::endl;
}

bool verificarProducto(const int orden, const std::vector< std::vector<int> > &A, 
const std::vector< std::vector<int> > &B, const std::vector< std::vector<int> > &C){
    std::vector<int> x (orden);
    for (int i = 0; i < orden; i++)
        x[i] = rand()%2;

    if ((productoVectorMatriz(orden, productoVectorMatriz(orden, x, A), B)) ==
    productoVectorMatriz(orden, x, C))
        return true;
    else 
        return false;
    
}

std::vector<int> productoVectorMatriz(const int orden, const std::vector<int> &x,
const std::vector< std::vector<int> > &A){
    std::vector<int> solucion (orden, 0);
    for (int i = 0; i < orden; i++)
        for (int j = 0; j < orden; j++)
            solucion[i] += x[j] * A[j][i];
    
    return solucion;
}