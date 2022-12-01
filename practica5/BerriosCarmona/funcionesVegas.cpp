#include <vector>
#include <cstdlib>
#include "comunes.hpp"
#include "ClaseTiempo.hpp"

bool calcularSolucionVegas(std::vector<int> &solucion, const int reinas, long int &intentos){
    std::vector<int> ok (reinas);
    for(int i = 0; i < reinas; i++){
        int index = -1;
        for(int j = 0; j < reinas; j++){   
            solucion[i] = j;
            if (lugar(solucion, i)){
                index++;
                ok[index] = j;
            }
        }
        if (index == -1){
            intentos++;
            return false;
        }
        if (index != 0)
            solucion[i] = ok[rand()%index];
        else
            solucion[i] = ok[0];
    }
    return (ok.size() != 0);
}

void mostrarSolucion(const std::vector<int> &solucion, const Clock &time, 
const long int intentos, const long int no_exitos){
    std::cout << std::endl;
    if (no_exitos == 100000){
        std::cout << "No se ha encontrado solución" << std::endl;
    } else {
        std::cout << "[";
        for(auto valor: solucion)
            std::cout << " " << valor;
        std::cout << " ]" << std::endl;
    }
    std::cout << "Intentos: " << intentos << std::endl;
    std::cout << "Tiempo tardado: " << time.elapsed()/1000.0 << "ms" << std::endl;
    std::cout << std::endl;
}