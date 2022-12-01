#include <iostream>
#include <time.h>
#include "funcionesMedioNivel.hpp"

int main(){
    srand(time(NULL));
    int opcion = 0;

    while (opcion != 7){
        std::cout << "Indique que método quiere utilizar" << std::endl;
        std::cout << "[1] Todas las soluciones de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "[2] Una solución de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "[3] Una solución de las N-Reinas (Las Vegas)" << std::endl;
        std::cout << "[4] Solución de menor coste para N-Reinas (Backtracking con poda)" << std::endl;
        std::cout << "[5] Verificación del producto de matrices (Montecarlo)" << std::endl;
        std::cout << "[6] Verificar probabilidad (Montecarlo)" << std::endl;
        std::cout << "[7] Salir" << std::endl;
        std::cin >> opcion;

        if (opcion == 1){
            nReinasTodasBT();
        } else if (opcion == 2){
            nReinasUnaBT();
        } else if (opcion == 3){
            nReinasVegas();
        } else if (opcion == 4){
            nReinasPodaBT();
        } else if (opcion == 5){
            verificarProductoMatrices();
        } else if (opcion == 6){
            verificarFallar();
        }
    }

    return 0;
}
