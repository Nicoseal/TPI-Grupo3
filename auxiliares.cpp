#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 1
bool esMatriz(vector<vector<int>> &th)
{
    for(int i = 0; i < th.size()-1; i++)
        if (th[i].size() != th[i+1].size())
            return false;
    return true;
}

bool columnasCorrectas(eph_i &ti, eph_h &th)
{
    for(const hogar &hog : th)
        if(hog.size() != FILAS_HOGAR)
            return false;
    for(const individuo &ind : ti)
        if(ind.size() != FILAS_INDIVIDUO)
            return false;
    return true;
}

bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th)
{
    if (ti.empty()  || th.empty())
        return true;
    else
        return false;
}

bool tieneHogar(individuo i, eph_h &th)
{
    for(hogar hog : th)
        if(hog[HOGCODUSU] == i[INDCODUSU])
            return true;
    return false;
}

bool individuosConHogares(eph_i &ti, eph_h &th)
{
    bool ans = true;
    for(individuo &ind : ti)
        ans = ans && tieneHogar(ind, th);
    return ans;
}

bool tieneIndividuo(hogar h, eph_i &ti)
{
    for(individuo ind : ti)
        if(ind[INDCODUSU] == h[HOGCODUSU])
            return true;
    return false;
}

bool hogaresConIndividuos(eph_i ti, eph_h &th)
{
    bool ans = true;
    for(hogar &hog : th)
        ans = ans && tieneIndividuo(hog, ti);
    return ans;
}

bool anioYTrimestreIgualEnTodos(eph_h &th, eph_i &ti)
{
    dato anioRel = th[0][HOGANIO];
    dato trimRel = th[0][HOGTRIMESTRE];
    for(hogar hog : th)
        if((hog[HOGANIO] != anioRel) || (hog[HOGTRIMESTRE] != trimRel))
            return false;
    for(individuo ind : ti)
        if((ind[INDANIO] != anioRel) || (ind[INDTRIMESTRE] != trimRel))
            return false;
    return true;
}

bool genteViviendoMayorA20(dato hogcod, eph_i &ti)
{
    int genteViviendoEnEsteHogcod = 0;
    for (individuo ind : ti)
        if (ind[0] == hogcod)
            genteViviendoEnEsteHogcod++;
    if(genteViviendoEnEsteHogcod > 20)
        return true;
    else
        return false;
}

bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti)
{
    for (hogar hog : th)
        if(genteViviendoMayorA20(hog[0], ti))
            return false;
    return true;
}

bool IV2MayorAII2 (eph_i &th)
{
    for (hogar hog : th)
        if(hog[IV2] < hog[II2])
            return false;
    return true;
}

bool atribsCatsOkDeTi(eph_i ti)
{
    for(individuo &ind : ti)
    {
        if((ind[INDCODUSU] > 0) &&
           (ind[COMPONENTE] > 0) &&
           (ind[INDTRIMESTRE] > 0 && ind[INDTRIMESTRE] < 4) &&
           (ind[CH4] == 1 || ind[CH4] == 2) &&
           (ind[CH6] > 0) &&
           (ind[NIVEL_ED] == 0 || ind[NIVEL_ED] == 1) &&
           (ind[ESTADO] == 0 || ind[ESTADO] == 1 || ind[ESTADO] == -1) &&
           (ind[CAT_OCUP] >= 0 && ind[CAT_OCUP] <= 4) &&
           (ind[p47T] >= -1) &&
           (ind[PP04G] >= 0 && ind[PP04G] <= 10))
        {
            return true;
        }
    }
    return false;

}

bool atribsCatsOkDeTh(eph_h th)
{
    for(hogar &hog : th)
    {
        if((hog[HOGCODUSU] > 0) &&
           (hog[HOGTRIMESTRE] > 0 && hog[HOGTRIMESTRE] <= 4) &&
           (0 < hog[II7] && hog[II7] <= 3) &&
           (hog[REGION] == 1 || (40 <= hog[REGION] && hog[REGION] <= 44)) &&
           (hog[MAS_500] == 1 || hog[MAS_500] == 0) &&
           (hog[IV2] > 0) &&
           (0 < hog[IV1] && hog[IV1] <= 5) &&
           (hog[II2] > 0) &&
           (hog[II3] == 1 || hog[II3] == 2))
        {
            return true;
        }
    }
    return false;
}

bool hayRepetidosH(vector<vector<dato>> &th)
{
    for(int i=0;i<th.size()-1;i++)
        for(int j=i+1;j<th.size();j++)
            if(th[i][HOGCODUSU] == th[j][HOGCODUSU])
                return true;
    return false;
}

bool hayRepetidosI(vector<vector<dato>> &ti)
{
    for(int i=0;i<ti.size()-1;i++)
        for(int j=i+1;j<ti.size();j++)
            if(ti[i][INDCODUSU] == ti[j][INDCODUSU])
                if(ti[i][COMPONENTE] == ti[j][COMPONENTE])
                    return true;
    return false;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 1

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 2
bool esCasa(hogar h){
    bool res = false;
    if(h[IV1] == 1){
        res = true;
    }
    return res;
}

int maximaCantidadDeHabitacionesEnRegion (eph_h th, int region){
    int max = 0;

    for (int i = 0; i < th.size(); ++i)
    {
        if(esCasa(th[i]) && th[i][REGION] == region && th[i][IV2] > max)
        {
            max = th[i][IV2];
        }
    }
    return max;
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
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 2

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 3
float cantHogaresValidos(eph_h &th, int region)
{
    float ans = 0;
    for(hogar hog : th)
        if(hog[REGION] == region && hog[MAS_500] == 0)
            ans++;
    return ans;
}

int cantHabitantes(hogar h, eph_i &ti)
{
    int ans = 0;
    for(individuo habitante : ti)
        if(habitante[INDCODUSU] == h[HOGCODUSU])
            ans++;
    return ans;
}

float cantHogaresValidosConHC(eph_h &th, eph_i &ti, int region)
{
    float ans = 0;
    for(hogar hog : th)
        if(hog[REGION] == region && hog[MAS_500] == 0 && (cantHabitantes(hog, ti) > 3 * hog[II2]))
            ans++;
    return ans;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 3

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 5
int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti)
{
    int genteViviendoEnEsteHogcod1 = 0;
    for(individuo ind : ti)
        if (ind[INDCODUSU] == hogcod)
            genteViviendoEnEsteHogcod1++;
    return genteViviendoEnEsteHogcod1;
}

bool necesitaSubsidioMejora (int genteViviendo, hogar &hog)
{
    if ((hog[IV2]) < (genteViviendo - 2))
        return true;
    else
        return false;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 5

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 10
bool cumpleCondicion(vector<pair<int, dato>>  busqueda, individuo i)
{
    bool ans = true;
    for(pair<int, dato> condicion : busqueda)
        ans = ans && (i[condicion.first] == condicion.second);
    return ans;
}

bool quedanIndividuos(eph_i &ti, dato codigo)
{
    for(individuo ind : ti)
        if(ind[INDCODUSU] == codigo)
            return true;
    return false;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 10

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 11
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
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 11