#include <iostream>
#include <string>
#include "funcionesMedioNivel.hpp"

int main(){
    int opcion = 0;

    while (opcion != 3){
        std::cout << "Indique que método quiere utilizar" << std::endl;
        std::cout << "[1] Método 1 (ISE)" << std::endl;
        std::cout << "[2] Método 2 (Error máximo)" << std::endl;
        std::cout << "[3] Salir" << std::endl;
        std::cin >> opcion;

        if (opcion == 1){
            metodoISE();
        } else if (opcion == 2){
            //metodoEMax();
        }
    }

    return 0;
}