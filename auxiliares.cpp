#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Ejercicio 1

bool esMatriz(vector<vector<int>> &th){
    for(int i = 0; i < th.size() - 1; i++){
        if (th[i].size() != th[i+1].size()){
            return false;
        }
    } return true;
}

bool columnasCorrectas(eph_i &ti, eph_h &th){
    for (int i = 0; i < th.size(); i++){
        if(th[i].size() != 12){
            return false;
        }
    }
    for (int j =0; j < ti.size(); j++){
        if(ti[j].size() != 12){
            return false;
        }
    } return true;}

bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th){
    if (ti.empty()  || th.empty()){
        return true;
    } else {
        return false;
    }
}

bool columnasIgualEnum(eph_i &ti, eph_h &th){
    if(ti[0].size() == 12 && th[0].size() == 12){
        return true;
    } else {
        return false;
    }
}



bool individuoConHogar(individuo ind, eph_h th) {
    for (int i = 0; i < th.size(); i++){
        if (th[i][HOGCODUSU] == ind[INDCODUSU]){
            return true;
        }
    } return false;
}


bool individuosConHogares(eph_i ti, eph_h th){
    for(int j = 0; j < th.size(); j++){
        if(!individuoConHogar(ti[j], th)){
            return false;
        }
    } return true;
}



bool hogarConIndividuo(hogar hog, eph_i ti) {
    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDCODUSU] == hog[HOGCODUSU]){
            return true;
        }
    } return false;
}


bool hogaresConIndividuos(eph_i ti, eph_h th){
    for(int i = 0; i < th.size(); i++){
        if(!hogarConIndividuo(th[i], ti)){
            return false;
        }
    } return true;
}



// hasta ahora, falta repetidos

bool anioYTrimestreIgualEnTodos(eph_h &th, eph_i &ti){
    dato anioRel = th[0][1];
    dato trimRel = th[0][2] ;
    for(int j = 0; j < th.size(); j++){
        if((th[j][1] != anioRel) || (th[j][2] != trimRel)){
            return false;
        }
    }
    for (int i = 0; i < ti.size(); i++){
        if((ti[i][1] != anioRel) || (ti[i][4] != trimRel) ){
            return false;
        }
    } return true;
}

//void todosLosIndcodusu(eph_i &ti, vector<dato> &indcod){
//   for (int i = 0; i < ti.size(); i++){
//      indcod.push_back(ti[i][0]);
//  }
//}

bool genteViviendoMayorA20(dato hogcod, eph_i &ti){
    int genteViviendoEnEsteHogcod;
    for (int i = 0; i < ti.size(); i++){
        if (ti[i][0] == hogcod){
            genteViviendoEnEsteHogcod = genteViviendoEnEsteHogcod + 1;
        }
    } if (genteViviendoEnEsteHogcod > 20){
        return true;
    } else {
        return false;
    }
}


bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti){
    for (int i = 0; i < th.size(); i++){
        if(genteViviendoMayorA20(th[i][0], ti)){
            return false;
        }
    } return true;
}

bool IV2MayorAII2 (eph_i ti){
    for (int i = 0; i < ti.size(); i++){
        if(ti[i][9] > ti[i][10]){
            return false;
        }
    } return true;
}

// atribs categoricos OK

bool atribsCatsOkDeTi(eph_i ti){
    for(int i = 0; i < ti.size(); i++){
        if((ti[i][INDCODUSU] > 0) && (ti[i][COMPONENTE] > 0) && (ti[i][INDANIO] > 0) &&
           (ti[i][INDTRIMESTRE] > 0 && ti[i][INDTRIMESTRE] < 4) && (ti[i][CH4] == 1 || ti[i][CH4] == 2) && (ti[i][CH6] > 0)
           && (ti[i][NIVEL_ED] == 0 || ti[i][NIVEL_ED] == 1) && (ti[i][ESTADO] == 0 || ti[i][ESTADO] == 1 || ti[i][ESTADO]
                                                                                                             == -1) && (ti[i][CAT_OCUP] >= 0 && ti[i][CAT_OCUP] <= 4) && (ti[i][p47T] >= -1) && (ti[i][PP04G] >= 0 &&
                                                                                                                                                                                                 ti[i][PP04G] <= 10)){
            return true;
        }}
    return false;

}

bool atribsCatsOkDeTh(eph_h th){
    for(int i = 0; i < th.size(); i++){
        if((th[i][HOGCODUSU] > 0) && (th[i][HOGANIO] > 0) &&
           (th[i][HOGTRIMESTRE] > 0 && th[i][HOGTRIMESTRE] < 4) && (th[i][II7] == 1 || th[i][II7] == 2 || th[i][II7] == 3)
           && (th[i][REGION] == 1 || th[i][REGION] == 40 || th[i][REGION] == 41 ||
               th[i][REGION] == 42 || th[i][REGION] == 43 || th[i][REGION] == 44) && (th[i][MAS_500] == 1 || th[i][MAS_500] == 0)
           && (th[i][IV2] > 0) && (th[i][IV1] > 0 || th[i][ESTADO] <= 5) && (th[i][II2] > 0) && (th[i][II3] == 1 ||
                                                                                                 th[i][II3] == 0)) {
            return true;
        }}
    return false;

}











// Ejercicio 5

int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti){
    int genteViviendoEnEsteHogcod1;
    for (int i = 0; i < ti.size(); i++){
        if (ti[i][0] == hogcod){
            genteViviendoEnEsteHogcod1 = genteViviendoEnEsteHogcod1 + 1;
        }
    } return genteViviendoEnEsteHogcod1;
}

bool necesitaSubsidioMejora (int genteViviendo, hogar &hog){
    if ((hog[9]) < (genteViviendo - 2)){
        return true;
    } else{
        return false;
    }
}
