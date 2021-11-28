#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 1
bool esMatriz(vector<vector<int>> &th);
bool columnasCorrectas(eph_i &ti, eph_h &th);
bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th);
bool tieneHogar(individuo i, eph_h &th);
bool individuosConHogares(eph_i &ti, eph_h &th);
bool tieneIndividuo(hogar h, eph_i &ti);
bool hogaresConIndividuos(eph_i ti, eph_h &th);
bool anioYTrimestreIgualEnTodos(eph_h &th, eph_i &ti);
bool genteViviendoMayorA20(dato hogcod, eph_i &ti);
bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti);
bool IV2MayorAII2 (eph_i &th);
bool atribsCatsOkDeTi(eph_i ti);
bool atribsCatsOkDeTh(eph_h th);
bool hayRepetidosH(vector<vector<dato>> &th);
bool hayRepetidosI(vector<vector<dato>> &ti);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 1

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 2
bool esCasa(hogar h);
int maximaCantidadDeHabitacionesEnRegion (eph_h th, int region);
int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 2

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 3
float cantHogaresValidos(eph_h &th, int region);
int cantHabitantes(hogar h, eph_i &ti);
float cantHogaresValidosConHC(eph_h &th, eph_i &ti, int region);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 3

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 4
bool suHogarTieneEspaciosReservadosParaElTrabajo (individuo i, eph_h &th);
bool individuoEnHogarValido(individuo &i, eph_h &th);
bool trabajaEnSuVivienda(individuo i, eph_h th);
float cantIndividuosQueTrabajan(eph_h &th, eph_i &ti);
float cantIndividuosTrabajandoEnSuVivienda(eph_h &th, eph_i &ti);
float proporcionTeleworking(eph_h &th, eph_i &ti);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 4

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 5
int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti);
bool necesitaSubsidioMejora (int genteViviendo, hogar &hog);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 5

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 7
eph_h ordenarPorCOMPONENTE(eph_h &th);
void seleccionarMinimo(eph_h &th, int i);
void burbujeo(eph_h &th, int i);
eph_h ordenarPorRegionYCodosu(eph_h &th);
eph_i ordenarPorIndividuosPorHOGCODOSU(eph_h th, eph_i ti);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 7

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 8
void ordenar(eph_h &th, vector<pair<int, int>> &ordenador);
int ingresos(hogar &h, eph_i &ti);
int busqBinaria(vector<pair<int, int>> &vect, int l, int r, int buscar, int restador);
vector<int> solucionHomogenea(vector<pair<int, int>> &ordenador, int indice, int diferencia);
vector <hogar> respuestaHomogenea(eph_h &th, vector<int> &solucion);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 8

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 10
bool cumpleCondicion(vector<pair<int, dato>>  &busqueda, individuo i);
bool quedanIndividuos(eph_i &ti, dato codigo);
bool existe(int codigo, vector<dato> &cods);
/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 10

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 11
int distanciaEuclidiana (pair <int , int > centro , int latitud, int longitud);
bool hogarEnAnillo(int distDesde, int distHasta, pair <int, int> centro, hogar h);
int cantHogaresEnAnillo(int distDesde, int distHasta, pair <int, int> centro, eph_h &th);
/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 11

#endif //SOLUCION_AUXILIARES_H
