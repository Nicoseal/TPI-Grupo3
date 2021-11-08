#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool encuestaVacia(eph_i & ti, eph_h & th);

#endif //SOLUCION_AUXILIARES_H
// auxiliares ejercicio 1

bool esMatriz(vector<vector<int>> &th);
bool columnasCorrectas(eph_i &ti, eph_h &th);
bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th);
bool columnasIgualEnum(eph_i &ti, eph_h &th);
bool individuoConHogar(individuo ind, eph_h th);
bool hogarConIndividuo(hogar hog, eph_i ti);
bool individuosConHogares(eph_h th, eph_i ti);
bool hogaresConIndividuos(eph_h th, eph_i ti);
bool anioYTrimestreIgualEnTodos(eph_h &th, eph_i &ti);
bool genteViviendoMayorA20(dato hogcod, eph_i &ti);
bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti);
bool IV2MayorAII2 (eph_i ti);
bool atribsCatsOkDeTi(eph_i ti);
bool atribsCatsOkDeTh(eph_h th);

// auxiliares ejercicio 5

int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti);
bool necesitaSubsidioMejora (int genteViviendo, hogar &hog);