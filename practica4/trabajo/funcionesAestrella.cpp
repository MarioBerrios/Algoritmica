#include <vector>
#include <limits>
#include "serietemporal.hpp"
#include "funcionesAestrella.hpp"

Nodo iniciarNodo(int punto, long double error, int rango, int padre);
Nodo minimoNodo(const std::vector<Nodo> &la);
void borrarNodo(Nodo &nodo, std::vector<Nodo> &lista);
void rellenarListaAbierta(SerieTemporal &serie, const Nodo &nodo_padre, std::vector<Nodo> &la, 
    std::vector<Nodo> &lc, const int puntos, const long double poda);
Nodo buscarNodo(const int punto, const int rango, std::vector<Nodo> &lista);
bool contieneNodo(Nodo &nodo, std::vector<Nodo> &lista);

void algoritmoAestrella(SerieTemporal &serie, std::vector<Nodo> &la, 
std::vector<Nodo> &lc, const int puntos, const long double poda){
    Nodo nodo_minimo = iniciarNodo(0, 0, 0, -1);

    while (nodo_minimo.punto != serie.numeroPuntosSerieTemporal()-1){
        lc.push_back(nodo_minimo);
        rellenarListaAbierta(serie, nodo_minimo, la, lc, puntos, poda);
        nodo_minimo = minimoNodo(la);
        borrarNodo(nodo_minimo, la);
    }
    lc.push_back(nodo_minimo);
}

void crearSegmentacion(SerieTemporal &serie, std::vector<Nodo> &lc, const int puntos){
    Nodo nodo = buscarNodo(serie.numeroPuntosSerieTemporal() - 1, puntos - 1, lc);
    serie.dominantePunto(nodo.punto, true);
    while(nodo.padre != -1){
        int punto_padre = nodo.padre;
        int rango_padre = nodo.rango - 1;
        nodo = buscarNodo(punto_padre, rango_padre, lc);
        serie.dominantePunto(nodo.punto, true);
    }
}

Nodo iniciarNodo(int punto, long double error, int rango, int padre){
    Nodo nodo;
    nodo.punto = punto;
    nodo.error = error;
    nodo.rango = rango;
    nodo.padre = padre;
    return nodo;
}

Nodo minimoNodo(const std::vector<Nodo> &la){
    Nodo minimo = la[0];
    for (auto it = la.begin(); it != la.end(); it++){
        if ((*it).error < minimo.error)
            minimo = *it;
    }
    return minimo;
}

void borrarNodo(Nodo &nodo, std::vector<Nodo> &lista){
    for (auto it = lista.begin(); it != lista.end(); it++){
        if ((*it).punto == nodo.punto && (*it).error == nodo.error 
        && (*it).rango == nodo.rango && (*it).padre == nodo.padre){
            lista.erase(it);
            break;
        }
    }
}

void rellenarListaAbierta(SerieTemporal &serie, const Nodo &nodo_padre, std::vector<Nodo> &la, 
std::vector<Nodo> &lc, const int puntos, const long double poda){
    int rango = nodo_padre.rango + 1;
    for(int i = nodo_padre.punto + 1; i < serie.numeroPuntosSerieTemporal(); i++){
        if (i > (serie.numeroPuntosSerieTemporal() - puntos + rango))
            continue;
        else if (i != serie.numeroPuntosSerieTemporal() - 1 && rango == puntos - 1)
            continue;
        else if (rango < puntos){
            long double error = serie.calcularIseEntreDosPuntos(nodo_padre.punto, i) + nodo_padre.error;
            if (error < poda){
                bool incluir = true;
                for(Nodo &nodo: la){
                    if(nodo.punto == i && nodo.rango == rango){
                        if (nodo.error > error){
                            nodo.error = error;
                            nodo.padre = nodo_padre.punto;
                        }
                        incluir = false;
                    }
                }
                if(incluir){
                    Nodo nodo_hijo = iniciarNodo(i, error, rango, nodo_padre.punto);
                    if(!contieneNodo(nodo_hijo, lc))
                        la.push_back(nodo_hijo);
                }
            }
        }
    }
}

Nodo buscarNodo(const int punto, const int rango, std::vector<Nodo> &lista){
    long double error = numeric_limits<long double>::infinity();
    Nodo nodo;
    for (Nodo &item: lista){
        if (item.punto == punto && item.rango == rango && item.error < error){
            error = item.error;
            nodo = item;
        }
    }
    return nodo;
}

bool contieneNodo(Nodo &nodo, std::vector<Nodo> &lista){
    for (Nodo &item: lista){
        if (item.punto == nodo.punto && item.rango == nodo.rango){
            return true;
        }
    }
    return false;
}