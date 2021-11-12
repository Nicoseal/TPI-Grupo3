#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

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
    return (ti.empty()  || th.empty());
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
        if (ind[INDCODUSU] == hogcod)
            genteViviendoEnEsteHogcod++;
    return genteViviendoEnEsteHogcod > 20;
}

bool miembrosDelHogarMenorA20(eph_h &th, eph_i &ti)
{
    for (hogar hog : th)
        if(genteViviendoMayorA20(hog[HOGCODUSU], ti))
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
    return false;
}

bool atribsCatsOkDeTh(eph_h th)
{
    for(hogar &hog : th)
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
bool esCasa(hogar h)
{
    bool res = false;
    if(h[IV1] == 1)
        res = true;
    return res;
}

int maximaCantidadDeHabitacionesEnRegion (eph_h th, int region)
{
    int max = 0;
    for(hogar &hog : th)
        if(hog[REGION] == region && hog[IV2] > max)
            max = hog[IV2];
    return max;
}

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones)
{
    int contador = 0;
    for(hogar &hog : th)
        if(esCasa(hog) && hog[IV2] == habitaciones && hog[REGION] == region)
            contador ++;
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

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 4
bool suHogarTieneEspaciosReservadosParaElTrabajo (individuo i, eph_h &th)
{
    for(hogar &hog : th)
        if ((hog[HOGCODUSU] == i[INDCODUSU]) && (hog[II3] == 1))
            return true;
    return false;
}

bool individuoEnHogarValido(individuo &i, eph_h &th)
{
    for(hogar &hog : th)
        if ((hog[HOGCODUSU] == i[INDCODUSU]) && hog[MAS_500] == 1 && (hog[IV1] == 1 || hog[IV1] == 2))
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
    for(individuo &ind : ti)
        if((ind[ESTADO] == 1) && individuoEnHogarValido(ind, th))
            cant++;
    return cant;
}

float cantIndividuosTrabajandoEnSuVivienda(eph_h &th, eph_i &ti)
{
    float x = 0;
    for(individuo &ind : ti)
        if((ind[ESTADO] == 1) && individuoEnHogarValido(ind, th) && trabajaEnSuVivienda(ind, th))
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
    for(individuo ind : ti)
        if (ind[INDCODUSU] == hogcod)
            genteViviendoEnEsteHogcod1++;
    return genteViviendoEnEsteHogcod1;
}

bool necesitaSubsidioMejora (int genteViviendo, hogar &hog)
{
    return (hog[IV2]) < (genteViviendo - 2);
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
    for(hogar &hog : th)
        for(individuo &ind : ti)
            if (ind[INDCODUSU] == hog[HOGCODUSU])
                res.push_back(ind);
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
void ordenar(eph_h &th, vector<pair<int, int>> &ordenador)
{
    for (int i=0; i<ordenador.size();i++)
        for(int j=i; j<ordenador.size(); j++)
            if(ordenador[i].second > ordenador[j].second)
            {
                swap(ordenador[i], ordenador[j]);
                swap(th[i], th[j]);
            }
}

int ingresos(hogar &h, eph_i &ti)
{
    int total = 0;
    for(individuo &ind : ti)
        if (ind[INDCODUSU] == h[HOGCODUSU] && ind[p47T] > 0)
            total += ind[p47T];
    return total;
}

int busqBinaria(vector<pair<int, int>> &vect, int l, int r, int buscar, int restador)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        int dif = vect[mid].second - restador;
        if (dif == buscar)
            return mid;
        if (dif > buscar)
            return busqBinaria(vect, l, mid - 1, buscar, restador);
        return busqBinaria(vect, mid + 1, r, buscar, restador);
    }
    return -1;
}

vector<int> solucionHomogenea(vector<pair<int, int>> &ordenador, int indice, int diferencia)
{
    vector<int> vect = {};
    vector<int> ans = {};
    for(int i=indice;i<ordenador.size()-1;i++)
    {
        for(int j=i+1;j<ordenador.size();j++)
        {
            if(diferencia == 0)
            {
                int dif = ordenador[j].second - ordenador[i].second;

                if(dif==0) continue;
                vect.push_back(ordenador[i].first);
                vector<int> rta = solucionHomogenea(ordenador, j, dif);
                vect.insert(vect.begin(), rta.begin(), rta.end());
                if(vect.size() < 3 || vect.size() <= ans.size())
                    vect.clear();
                else
                {
                    ans = vect;
                    vect.clear();
                }
            }
            else
            {
                int bb = busqBinaria(ordenador, i+1, ordenador.size()-1, diferencia, ordenador[i].second);
                if(bb != -1)
                {
                    vect.push_back(ordenador[i].first);
                    vector<int> rta = solucionHomogenea(ordenador, bb, diferencia);
                    vect.insert(vect.begin(), rta.begin(), rta.end());
                    if(vect.size()>=2) return vect;
                }
            }
        }
        if(diferencia != 0) return {ordenador[i].first};
    }
    return ans;
}

vector <hogar> respuestaHomogenea(eph_h &th, vector<int> &solucion)
{
    eph_h ans = {};
    for(dato codigo : solucion)
        for(hogar hog : th)
            if(codigo == hog[HOGCODUSU])
                ans.push_back(hog);
    return ans;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 8

/////////////////////////////////////////////////////////// INICIO AUXILIARES EJ 10
bool cumpleCondicion(vector<pair<int, dato>>  &busqueda, individuo i)
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
    for (hogar &hog : th)
        if(hogarEnAnillo(distDesde, distHasta, centro, hog))
            contador ++;
    return contador;
}
/////////////////////////////////////////////////////////// FIN AUXILIARES EJ 11