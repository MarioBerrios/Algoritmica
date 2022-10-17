#include <iostream>
#include <string>
#include "funcionesMedioNivel.hpp"
#include "serietemporal.hpp"

int main(){
    int opcion = 0;

    while (opcion != 3){
        std::cout << "Indique que método quiere utilizar" << std::endl;
        std::cout << "[1] Método 1" << std::endl;
        std::cout << "[2] Método 2" << std::endl;
        std::cout << "[3] Salir" << std::endl;
        std::cin >> opcion;

        if (opcion == 1){
            metodo1();
        } else if (opcion == 2){
            metodo2();
        }
    }

    return 0;
}