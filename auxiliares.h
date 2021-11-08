#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 1
bool esMatriz(vector<vector<int>> &th);
bool columnasCorrectas(eph_i &ti, eph_h &th);
bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th);
bool individuosConHogares(eph_i &ti, eph_h &th);
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

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 5
int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti);
bool necesitaSubsidioMejora (int genteViviendo, hogar &hog);
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 5

#endif //SOLUCION_AUXILIARES_H


