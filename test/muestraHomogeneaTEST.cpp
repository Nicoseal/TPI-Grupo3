#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(muestraHomogeneaTEST, unaSolucionDe4) {
    vector <hogar> esperado = {{2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                               {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                               {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                               {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1}};
    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    };

    eph_i ti = {{543,   2018, 1, 1, 1, 1, 36, 1,  3, 1, 1}, // 1
                {334,   2018, 1, 1, 1, 1, 36, 1,  3, 90, 1},
                {340,   2018, 1, 1, 1, 1, 36, 1,  3, 30, 1}, // 35
                {340,   2018, 3, 1, 1, 1, 36, 1,  3, 5, 1},
                {334,   2018, 2, 1, 1, 1, 31, 1,  3, 90, 1},
                {1009,  2018, 1, 1, 1, 2, 36, 1,  3, 26, 1}, // 26
                {210,   2018, 1, 1, 1, 1, 36, 1,  1, 25, 1}, // 27
                {210,   2018, 2, 1, 1, 1, 36, 1,  3, 2, 1},
                {1,     2018, 1, 1, 1, 2, 5,  1,  2, 25, 1},  // 25
                {4377,  2018, 1, 1, 1, 1, 36, 1,  3, 15, 1}, // 30
                {4377,  2018, 3, 1, 1, 1, 7,  1,  3, 15, 1},
                {2354,  2018, 1, 1, 1, 2, 36, 1,  3, 20, 1}, // 20
                {200,   2018, 2, 1, 1, 1, 36, 1,  3, 0, 1}, // 0
                {960,   2018, 3, 1, 1, 2, 51, 1,  4, 0,  1}, // 0
                {960,   2018, 2, 1, 1, 2, 51, 1,  4, 0,  1},
                {960,   2018, 1, 1, 1, 2, 51, 1,  4, 0,  1}
    };
    EXPECT_TRUE(esEncuestaValida(th, ti));

    vector <hogar> res = muestraHomogenea(th,ti);

    // uso sort para independizar el orden
    sort(esperado.begin(),esperado.end());
    sort(res.begin(), res.end());

    EXPECT_EQ(res,esperado);
}


TEST(muestraHomogeneaTEST, dosSolucionesDe3) {
    vector <hogar> res1 = {{1,    2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
                           {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
                           {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2,1,1}};

    vector <hogar> res2 = {{1,    2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
                           {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
                           {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1}};

    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2,1,1},
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2,1,1},
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
            {800,  2018, 1, 1, 2, 1, 1, 1, 1, 2,1,1},
    };

    eph_i ti = {{543,  2018, 1, 1, 1, 1, 36, 1,  3, 1,  1}, // 1
                {334,  2018, 1, 1, 1, 1, 36, 1,  3, 1,  1}, // 3
                {334,  2018, 2, 1, 1, 1, 36, 1,  3, 2,  1},
                {340,  2018, 1, 1, 1, 1, 36, 1,  3, 30,  1},  // 30
                {340,  2018, 3, 1, 1, 1, 36, 1,  3, 0,  1},
                {1009, 2018, 1, 1, 1, 1, 36, 1,  3, 26,  1}, // 26
                {210,  2018, 1, 1, 1, 1, 36, 1,  3, 25,  1}, // 27
                {210,  2018, 2, 1, 1, 1, 36, 1,  3, 2,  1},
                {1,    2018, 1, 1, 1, 1, 36, 1,  3, 24,  1}, // 24
                {4377, 2018, 1, 1, 1, 1, 36, 1,  3, 15,  1}, // 30
                {4377, 2018, 3, 1, 1, 1, 36, 1,  3, 15,  1},
                {2354, 2018, 1, 1, 1, 1, 36, 1,  3, 20,  1}, // 20
                {800,  2018, 2, 1, 1, 1, 36, 1,  3, 0,  1}, // 0
                {200,  2018, 2, 1, 1, 1, 36, 1,  3, 0,  1}, // 0
                {960,  2018, 3, 1, 1, 2, 51, 1,  4, 0,   1}, // 0
                {960,  2018, 2, 1, 1, 2, 51, 1,  4, 0,   1},
                {960,  2018, 1, 1, 1, 2, 51, 1,  4, 0,   1}};
    EXPECT_TRUE(esEncuestaValida(th, ti));

    vector <hogar> propuesto = muestraHomogenea(th,ti);

    // uso del sort para independizar el orden
    sort(propuesto.begin(), propuesto.end());
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());

    bool esperado = res1 == propuesto || res2 == propuesto;
    EXPECT_TRUE(esperado);
}
