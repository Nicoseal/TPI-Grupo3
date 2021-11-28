#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

/// Integrantes del grupo 3:
/// Agustin Canteros
/// Juan Carlos Aguirre
/// Mirko Cuchan
/// Nicolas Ventieri

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
    for(int i=0;i<th.size();i++)
        if(th[i].size() != FILAS_HOGAR)
            return false;
    for(int i=0;i<ti.size();i++)
        if(ti[i].size() != FILAS_INDIVIDUO)
            return false;
    return true;
}

bool algunaEncuestaVacia (const eph_i &ti, const eph_h &th)
{
    return (ti.empty() || th.empty());
}

bool tieneHogar(individuo i, eph_h &th)
{
    for(int j=0;j<th.size();j++)
        if(th[j][HOGCODUSU] == i[INDCODUSU])
            return true;
    return false;
}

bool individuosConHogares(eph_i &ti, eph_h &th)
{
    bool ans = true;
    for(int i=0;i<ti.size();i++)
        ans = ans && tieneHogar(ti[i], th);
    return ans;
}

bool tieneIndividuo(hogar h, eph_i &ti)
{
    for(int i=0;i<ti.size();i++)
        if(ti[i][INDCODUSU] == h[HOGCODUSU])
            return true;
    return false;
}

bool hogaresConIndividuos(eph_i ti, eph_h &th)
{
    bool ans = true;
    for(int i=0;i<th.size();i++)
        ans = ans && tieneIndividuo(th[i], ti);
    return ans;
}

bool anioYTrimestreIgualEnTodos(eph_h &th, eph_i &ti)
{
    dato anioRel = th[0][HOGANIO];
    dato trimRel = th[0][HOGTRIMESTRE];
    for(int i=0;i<th.size();i++)
        if((th[i][HOGANIO] != anioRel) || (th[i][HOGTRIMESTRE] != trimRel))
            return false;
    for(int i=0;i<ti.size();i++)
        if((ti[i][INDANIO] != anioRel) || (ti[i][INDTRIMESTRE] != trimRel))
            return false;
    return true;
}

bool genteViviendoMayorA20(dato hogcod, eph_i &ti)
{
    int genteViviendoEnEsteHogcod = 0;
    for(int i=0;i<ti.size();i++)
        if (ti[i][INDCODUSU] == hogcod)
            genteViviendoEnEsteHogcod++;
    return genteViviendoEnEsteHogcod > 20;
}

bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti)
{
    for(int i=0;i<th.size();i++)
        if(genteViviendoMayorA20(th[i][HOGCODUSU], ti))
            return false;
    return true;
}

bool IV2MayorAII2 (eph_i &th)
{
    for(int i=0;i<th.size();i++)
        if(th[i][IV2] < th[i][II2])
            return false;
    return true;
}

bool atribsCatsOkDeTi(eph_i ti)
{
    for(int i=0;i<ti.size();i++)
        if((ti[i][INDCODUSU] > 0) &&
           (ti[i][COMPONENTE] > 0) &&
           (ti[i][INDTRIMESTRE] > 0 && ti[i][INDTRIMESTRE] < 4) &&
           (ti[i][CH4] == 1 || ti[i][CH4] == 2) &&
           (ti[i][CH6] >= 0) &&
           (ti[i][NIVEL_ED] == 0 || ti[i][NIVEL_ED] == 1) &&
           (ti[i][ESTADO] == 0 || ti[i][ESTADO] == 1 || ti[i][ESTADO] == -1) &&
           (ti[i][CAT_OCUP] >= 0 && ti[i][CAT_OCUP] <= 4) &&
           (ti[i][p47T] >= -1) &&
           (ti[i][PP04G] >= 0 && ti[i][PP04G] <= 10))
        {
            return true;
        }
    return false;
}

bool atribsCatsOkDeTh(eph_h th)
{
    for(int i=0;i<th.size();i++)
        if((th[i][HOGCODUSU] > 0) &&
           (th[i][HOGTRIMESTRE] > 0 && th[i][HOGTRIMESTRE] <= 4) &&
           (0 < th[i][II7] && th[i][II7] <= 3) &&
           (th[i][REGION] == 1 || (40 <= th[i][REGION] && th[i][REGION] <= 44)) &&
           (th[i][MAS_500] == 1 || th[i][MAS_500] == 0) &&
           (th[i][IV2] > 0) &&
           (0 < th[i][IV1] && th[i][IV1] <= 5) &&
           (th[i][II2] > 0) &&
           (th[i][II3] == 1 || th[i][II3] == 2))
        {
            return true;
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
int maxHabitacionRegion(eph_h &th, int region)
{
    int max = 0;
    for(int i=0;i<th.size();i++)
        if(th[i][REGION] == region && th[i][IV2] > max)
            max = th[i][IV2];
    return max;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 2

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 3
float cantHogaresValidos(eph_h &th, int region)
{
    float ans = 0;
    for(int i=0;i<th.size();i++)
        if(th[i][REGION] == region && th[i][MAS_500] == 0)
            ans++;
    return ans;
}

int cantHabitantes(hogar h, eph_i &ti)
{
    int ans = 0;
    for(int i=0;i<ti.size();i++)
        if(ti[i][INDCODUSU] == h[HOGCODUSU])
            ans++;
    return ans;
}

float cantHogaresValidosConHC(eph_h &th, eph_i &ti, int region)
{
    float ans = 0;
    for(int i=0;i<th.size();i++)
        if(th[i][REGION] == region && th[i][MAS_500] == 0 && (cantHabitantes(th[i], ti) > 3 * th[i][II2]))
            ans++;
    return ans;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 3

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 4
bool suHogarTieneEspaciosReservadosParaElTrabajo (individuo i, eph_h &th)
{
    for(int j=0;j<th.size();j++)
        if ((th[j][HOGCODUSU] == i[INDCODUSU]) && (th[j][II3] == 1))
            return true;
    return false;
}

bool individuoEnHogarValido(individuo &i, eph_h &th)
{
    for(int j=0;j<th.size();j++)
        if ((th[j][HOGCODUSU] == i[INDCODUSU]) && th[j][MAS_500] == 1 && (th[j][IV1] == 1 || th[j][IV1] == 2))
            return true;
    return false;
}

bool trabajaEnSuVivienda(individuo i, eph_h th)
{
    return ((i[PP04G] == 6) && suHogarTieneEspaciosReservadosParaElTrabajo(i, th));
}

float cantIndividuosQueTrabajan(eph_h &th, eph_i &ti)
{
    float cant = 0;
    for(int i=0;i<ti.size();i++)
        if((ti[i][ESTADO] == 1) && individuoEnHogarValido(ti[i], th))
            cant++;
    return cant;
}

float cantIndividuosTrabajandoEnSuVivienda(eph_h &th, eph_i &ti)
{
    float x = 0;
    for(int i=0;i<ti.size();i++)
        if((ti[i][ESTADO] == 1) && individuoEnHogarValido(ti[i], th) && trabajaEnSuVivienda(ti[i], th))
            x++;
    return x;
}

float proporcionTeleworking(eph_h &th, eph_i &ti)
{
    float cant_trab = cantIndividuosQueTrabajan(th, ti);
    if(cant_trab > 0)
        return cantIndividuosTrabajandoEnSuVivienda(th, ti) / cant_trab;
    else
        return 0;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 4

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 5
int cantidadDeHabitantesEnCasa(dato hogcod, eph_i &ti)
{
    int genteViviendoEnEsteHogcod1 = 0;
    for(int i=0;i<ti.size();i++)
        if (ti[i][INDCODUSU] == hogcod)
            genteViviendoEnEsteHogcod1++;
    return genteViviendoEnEsteHogcod1;
}

bool necesitaSubsidioMejora (int genteViviendo, hogar &hog)
{
    return (hog[II2]) < (genteViviendo - 2);
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 5

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 7
void burbujeo(eph_h &th, int i)
{
    for(int j=th.size()-1; j>i; j--)
    {
        if(th[j][REGION] < th[j-1][REGION])
            swap(th[j] ,th[j-1] );
        if (th[j][REGION] == th[j-1][REGION] && th[j][HOGCODUSU] < th[j-1][HOGCODUSU])
            swap(th[j] ,th[j-1] );
    }
}

eph_h ordenarPorRegionYCodosu(eph_h &th)
{
    for(int i=0; i<th.size(); i++)
        burbujeo(th ,i);
    return th;
}

eph_i ordenarPorIndividuosPorHOGCODOSU(eph_h th, eph_i ti)
{
    eph_i res = {};
    for(int i=0;i<th.size();i++)
        for(int j=0;j<ti.size();j++)
            if (ti[j][INDCODUSU] == th[i][HOGCODUSU])
                res.push_back(ti[j]);
    return res;
}

void seleccionarMinimo(eph_i &ti, int i)
{
    int posMinimo= i;
    for(int j=i; j<ti.size(); j++)
        if((ti[posMinimo][INDCODUSU] == ti[j][INDCODUSU]) && (ti[posMinimo][COMPONENTE] > ti[j][COMPONENTE]))
            posMinimo = j;
    swap(ti[i],ti[posMinimo]);
}

eph_h ordenarPorCOMPONENTE(eph_i &ti)
{
    for(int i=0; i<ti.size(); i++)
        seleccionarMinimo(ti,i);
    return ti;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 7

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 8
int totIngresos(hogar &h, eph_i &ti)
{
    int total = 0;
    for(int i=0;i<ti.size();i++)
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > 0)
            total += ti[i][p47T];
    return total;
}

vector<int> ordenar(eph_h &th, eph_i &ti)
{
    vector<int> ingresos(th.size());
    for(int i=0; i<th.size();i++)
        ingresos[i] = totIngresos(th[i], ti);
    for(int i=0; i<ingresos.size();i++)
        for(int j=i; j<ingresos.size(); j++)
            if(ingresos[i] > ingresos[j])
            {
                swap(th[i], th[j]);
                swap(ingresos[i], ingresos[j]);
            }
    return ingresos;
}

eph_h solucionHomogenea(eph_h &th,vector<int> ingresos)
{
    eph_h vect = {};
    eph_h ans = {};
    for(int i=0;i<ingresos.size()-2;i++)
    {
        for(int x=i+1;x<ingresos.size()-1;x++)
        {
            int dif_inicial = ingresos[x] - ingresos[i];
            if(dif_inicial==0) continue;
            int multiplicador = 2;
            vect.push_back(th[i]);
            vect.push_back(th[x]);
            for(int j=x+1;j<ingresos.size();j++)
            {
                int diferencia = ingresos[j] - ingresos[i];
                if(diferencia == dif_inicial * multiplicador)
                {
                    multiplicador++;
                    vect.push_back(th[j]);
                }
            }
            if(vect.size() < 3 || vect.size() <= ans.size())
                vect.clear();
            else
            {
                ans = vect;
                vect.clear();
            }
        }
    }
    return ans;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 8

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 10
bool cumpleCondicion(vector<pair<int, dato>>  &busqueda, individuo i)
{
    bool ans = true;
    for(int j=0;j<busqueda.size();j++)
        ans = ans && (i[busqueda[j].first] == busqueda[j].second);
    return ans;
}

bool quedanIndividuos(eph_i &ti, dato codigo)
{
    for(int i=0;i<ti.size();i++)
        if(ti[i][INDCODUSU] == codigo)
            return true;
    return false;
}

bool existe(int codigo, vector<dato> &cods)
{
    for(int j=0;j<cods.size();j++)
        if(cods[j] == codigo)
            return true;
    return false;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 10

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 11
int distanciaEuclidiana (pair <int , int > centro , int latitud, int longitud)
{
    int result = sqrt(pow(centro.first - latitud,2) + pow(centro.second - longitud,2));
    return result;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair <int, int> centro, hogar h)
{
    bool result = false;
    int x = distanciaEuclidiana(centro, h[HOGLATITUD], h[HOGLONGITUD]);
    if (distDesde < x && x <= distHasta)
        result = true;
    return result;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair <int, int> centro, eph_h &th)
{
    int contador = 0;
    for(int i=0;i<th.size();i++)
        if(hogarEnAnillo(distDesde, distHasta, centro, th[i]))
            contador ++;
    return contador;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 11
