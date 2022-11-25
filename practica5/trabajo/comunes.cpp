#include <vector>
#include <cmath>

bool lugar(const std::vector<int> &x, const int fila){
    for (int i = 0; i < fila; i++)
        if(x[i] == x[fila] || std::abs(x[i]-x[fila]) == std::abs(i-fila))
            return false;
    
    if ((fila-2) >= 0){
        if (x[fila-2] == x[fila]-1 || x[fila-2] == x[fila]+1)
            return false;
    }
    if ((fila-1) >= 0){
        if (x[fila-1] == x[fila]-2 || x[fila-1] == x[fila]+2)
             return false;
    }
    
    return true;
}