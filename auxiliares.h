#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool encuestaVacia(eph_i & ti, eph_h & th);
bool esCasa( hogar h );
int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones);
int maximaCantidadDeHabitacionesEnRegion (eph_h th, int region);
int distanciaEuclidiana (pair <int , int > centro , int latitud, int longitud);
bool hogarEnAnillo(int distDesde, int distHasta, pair <int, int> centro, hogar h);
int cantHogaresEnAnillo(int distDesde, int distHasta, pair <int, int> centro, eph_h th);
bool cumpleCondicion(vector<pair<int, dato>>  busqueda, individuo i);

#endif //SOLUCION_AUXILIARES_H
