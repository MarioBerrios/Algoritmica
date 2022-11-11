#include <iostream>
#include "funcionesMedioNivel.hpp"

int main(){
    int opcion = 0;

    while (opcion != 3){
        std::cout << "Indique que método quiere utilizar" << std::endl;
        std::cout << "[1] Método 1 (Prog. dinámica)" << std::endl;
        std::cout << "[2] Método 2 (A*)" << std::endl;
        std::cout << "[3] Salir" << std::endl;
        std::cin >> opcion;

        if (opcion == 1){
            metodoDinamica();
        } else if (opcion == 2){
            metodoAestrella();
        }
    }

    return 0;
}
