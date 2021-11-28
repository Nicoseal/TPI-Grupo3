#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(quitarIndividuosTEST, SacaUnIndividuoHogaresSinModificacion) {
    eph_h th = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2},
            {20101,2020,3,315773,625696,1,41,0,1,2,2,2},
    };

    eph_i ti = {
            {22010,2020,1,0,3,1,65,1,2,15000,8}, // este se borra
            {22010,2020,7,0,3,2,22,0,0,10000,10},
            {22010,2020,9,0,3,1,9,0,0,0,10},
            {22010,2020,10,0,3,2,9,0,0,0,10},
            {22010,2020,11,0,3,2,2,0,0,0,10},
            {22010,2020,12,0,3,2,17,0,0,0,10},
            {20101,2020,1,0,3,2,46,1,3,3900,0},  // este no se borra, que tiene el mismo nro de componente
            {20101,2020,2,0,3,1,24,0,3,6000,10},
    };

    EXPECT_TRUE(esEncuestaValida(th, ti));

    vector<pair<int, dato>> busqueda = {
            {PP04G, 8},
            {COMPONENTE, 1}
    };

    eph_h th0 = eph_h(th);
    eph_i ti0 = eph_i(ti);

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    eph_h th_res = {{22010,2020,3,319938,629513,1,41,0,1,4,3,2}};
    eph_i ti_res = {{22010,2020,1,0,3,1,65,1,2,15000,8}};
    //verificacion de salida
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(ti_res, res.second);

    // verificacion de encuesta resultante
    EXPECT_TRUE(esEncuestaValida(th,ti));
    ti0.erase(ti0.begin()); // borro el primer elemento que era el que cumplia el criterio
    // ordeno para que no importe el orden
    sort(th.begin(),th.end());
    sort(ti.begin(),ti.end());

    sort(th0.begin(),th0.end());
    sort(ti0.begin(),ti0.end());

    EXPECT_EQ(th, th0);
    EXPECT_EQ(ti, ti0);

}

TEST(quitarIndividuosTEST, SacaTodosIndividuosYHogarVacio) {
    eph_h th = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2},
            {20101,2020,3,315773,625696,1,41,0,1,2,2,2},
    };

    eph_i ti = {
            {22010,2020,1,0,3,1,65,1,2,15000,8},
            {22010,2020,7,0,3,2,22,0,0,10000,10},
            {22010,2020,9,0,3,1,9,0,0,0,10},
            {22010,2020,10,0,3,2,9,0,0,0,10},
            {22010,2020,11,0,3,2,2,0,0,0,10},
            {22010,2020,12,0,3,2,17,0,0,0,10},
            {20101,2020,1,0,3,2,46,1,3,3900,0},
            {20101,2020,2,0,3,1,24,0,3,6000,10},
    };

    vector<pair<int, dato>> busqueda = {
            {INDCODUSU, 22010}
    };


    eph_h th_res = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2}
    };

    eph_i ti_res = {
            {22010,2020,1,0,3,1,65,1,2,15000,8},
            {22010,2020,7,0,3,2,22,0,0,10000,10},
            {22010,2020,9,0,3,1,9,0,0,0,10},
            {22010,2020,10,0,3,2,9,0,0,0,10},
            {22010,2020,11,0,3,2,2,0,0,0,10},
            {22010,2020,12,0,3,2,17,0,0,0,10}
    };

    eph_h th_out = {
            {20101,2020,3,315773,625696,1,41,0,1,2,2,2}
    };

    eph_i ti_out = {
            {20101,2020,2,0,3,1,24,0,3,6000,10},
            {20101,2020,1,0,3,2,46,1,3,3900,0},
    };

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    // verificacion de encuesta resultante
    EXPECT_TRUE(esEncuestaValida(th,ti));
    //verificacion de salida de hogares (un solo elemento)
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(th_out, th);

    // verificacion de salida de individuos (varios elementos)
    // ordeno para que no importe el orden
    sort(ti_out.begin(),ti_out.end());

    EXPECT_EQ(ti, ti_out);
}

TEST(customTEST, quitarIndividuosYNoHogar) {
    eph_h th = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2}
    };

    eph_i ti = {
            {22010,2020,1,0,3,1,65,1,2,15000,8},
            {22010,2020,7,0,3,2,22,0,0,10000,10},
            {22010,2020,9,0,3,1,9,0,0,0,10},
            {22010,2020,10,0,3,2,9,0,0,0,10},
            {22010,2020,11,0,3,2,2,0,0,0,10},
            {22010,2020,12,0,3,2,17,0,0,0,10}
    };

    vector<pair<int, dato>> busqueda = {
            {CH6, 9}
    };


    eph_h th_res = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2}
    };

    eph_i ti_res = {
            {22010,2020,9,0,3,1,9,0,0,0,10},
            {22010,2020,10,0,3,2,9,0,0,0,10}
    };

    eph_h th_out = {
            {22010,2020,3,319938,629513,1,41,0,1,4,3,2}
    };

    eph_i ti_out = {
            {22010,2020,1,0,3,1,65,1,2,15000,8},
            {22010,2020,7,0,3,2,22,0,0,10000,10},
            {22010,2020,11,0,3,2,2,0,0,0,10},
            {22010,2020,12,0,3,2,17,0,0,0,10}
    };

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    EXPECT_TRUE(esEncuestaValida(th,ti));
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(ti_res, res.second);
    EXPECT_EQ(th_out, th);

    sort(ti_out.begin(),ti_out.end());
    EXPECT_EQ(ti, ti_out);
}

TEST(customTEST, quitarIndividuosYNoHogarLargo) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    vector<pair<int, dato>> busqueda = {
            {CAT_OCUP, 3}
    };


    eph_h th_res = {{31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                    {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2}
    };

    eph_i ti_res = {{31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                    {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                    {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                    {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                    {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                    {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
    };

    eph_h th_out = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                    {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                    {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}
    };

    eph_i ti_out = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                    {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                    {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                    {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                    {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                    {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                    {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                    {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}
    };

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    EXPECT_TRUE(esEncuestaValida(th,ti));
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(ti_res, res.second);
    EXPECT_EQ(th_out, th);
}
