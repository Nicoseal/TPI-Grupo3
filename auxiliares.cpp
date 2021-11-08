#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include "math.h"
#include "utility"

bool encuestaVacia(eph_i & ti, eph_h & th)
{
    return ti.empty() && th.empty();
}

bool esCasa( hogar h ){
    bool res = false;
    if(h[IV1] == 1){
        res = true;
    }
    return res;
}

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones){

    int contador = 0;

    for (int j = 0; j < th.size(); ++j) {

        if(esCasa(th[j]) && th[j][IV2] == habitaciones && th[j][REGION] == region){
            contador ++;
        }
    }
    return contador;
}

int maximaCantidadDeHabitacionesEnRegion (eph_h th, int region){
    int max = 0;

    for (int i = 0; i < th.size(); ++i) {

        if(esCasa(th[i]) && th[i][REGION] == region && th[i][IV2] > max ){

            max = th[i][IV2];
        }
    }
    return max;
}


int distanciaEuclidiana (pair <int , int > centro , int latitud, int longitud){

    int result = sqrt(pow(centro.first - latitud,2) + pow(centro.second - longitud,2));

    return result;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair <int, int> centro, hogar h){
    bool result = false;
    int x = distanciaEuclidiana(centro, h[HOGLATITUD], h[HOGLONGITUD]);
    if (distDesde < x && x <= distHasta){
        result = true;
    }
    return result;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair <int, int> centro, eph_h th){
    int contador = 0;
    for (int i = 0; i < th.size() ; ++i) {
        if(hogarEnAnillo(distDesde,distHasta,centro,th[i])){
            contador ++;
        }
    }
    return contador;
}