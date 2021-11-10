#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;

/// Implementacion Problema 1
/// TODO FALTA CREAR LOS TESTS
bool esEncuestaValida ( eph_h th, eph_i ti )
{
    if(!algunaEncuestaVacia(ti, th) &&
    esMatriz(th) && (esMatriz(ti)) &&
    columnasCorrectas(ti, th) &&
    individuosConHogares(ti, th) && hogaresConIndividuos(ti, th) &&
    anioYTrimestreIgualEnTodos(th, ti) &&
    miembrosDelHogarMenorA20(ti, th) &&
    IV2MayorAII2(th) &&
    atribsCatsOkDeTi(ti) && atribsCatsOkDeTh(th) &&
    !hayRepetidosH(th) && !hayRepetidosI(ti))
    {
        return true;
    }
    else
        return false;
}

/// Implementacion Problema 2
/// TODO FALTA CREAR LOS TESTS
vector<int> histHabitacional(eph_h th, eph_i ti, int region)
{
    vector<int> resultado;
    int longitudDeResultado = maximaCantidadDeHabitacionesEnRegion(th, region);
    for (int i=0; i < longitudDeResultado; ++i)
    {
        resultado.push_back(cantHogaresCasaConNHabitaciones(th,region,i+1));
    }
    return resultado;
}

/// Implementacion Problema 3
/// TODO FALTA CREAR LOS TESTS
vector<pair<int, float>> laCasaEstaQuedandoChica(eph_h th, eph_i ti)
{
    vector<int> regiones = {1, 40, 41, 42, 43, 44};
    vector<pair<int,float>> ans = {};
    for(int region : regiones)
    {
        float hogares_validos = cantHogaresValidos(th, region);
        if(hogares_validos > 0)
            ans.emplace_back(region, cantHogaresValidosConHC(th, ti, region) / hogares_validos);
        else
            ans.emplace_back(region, 0);
    }
    return ans;
}

/// Implementacion Problema 4
/// TODO FALTA CREAR LOS TESTS
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i)
{
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}

/// Implementacion Problema 5
/// TODO FALTA CREAR LOS TESTS
int costoSubsidioMejora(eph_h th, eph_i ti, int monto)
{
    int resp = 0;
    for(hogar hog : th)
        if(hog[II7] == 1)
            if (necesitaSubsidioMejora(cantidadDeHabitantesEnCasa(hog[HOGCODUSU], ti), (hog)))
                resp += monto;
    return resp;
}

/// Implementacion Problema 6
/// TODO FALTA CREAR LOS TESTS
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi ans = {};
    for(int i=0;i<ti.size();i++)
        for(int j=0;j<th.size();j++)
            if(ti[i][INDCODUSU] == th[j][HOGCODUSU])
                ans.emplace_back(th[j],ti[i]);
    return ans;
}

/// Implementacion Problema 7
/// TODO FALTA CREAR LOS TESTS
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti)
{
    ordenarPorRegionYCodosu(th);
    ti = ordenarPorIndividuosPorHOGCODOSU(th,ti);
    ordenarPorCOMPONENTE(ti);
}

/// Implementacion Problema 8
/// TODO FALTA HACER EJERCICO
/// TODO FALTA CREAR LOS TESTS
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti )
{
    hogar h = {};
    vector < hogar > resp = {h};
    //
    return  resp;
}

/// Implementacion Problema 9
/// TODO FALTA CREAR LOS TESTS
void corregirRegion(eph_h &th, eph_i &ti)
{
    for (hogar &hog : th)
        if (hog[REGION] == 1)
            hog[REGION] = 43;
}

/// Implementacion Problema 11
/// TODO FALTA CREAR LOS TESTS
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias)
{
    vector<int> resp = {};
    resp.push_back(cantHogaresEnAnillo(0,distancias[0],centro,th));
    for (int i = 1; i < distancias.size() ; ++i)
        resp.push_back(cantHogaresEnAnillo(distancias[i-1],distancias[i],centro,th));
    return resp;
}

/// Implementacion Problema 10
/// TODO FALTA CREAR LOS TESTS
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>>&  busqueda)
{
    eph_h rth = {};
    eph_i rti = {};
    for(int i=0;i<ti.size();i++)
        if(cumpleCondicion(busqueda, ti[i]))
        {
            rti.push_back(ti[i]);
            ti.erase(ti.begin() + i);
            i--;
        }
    for(individuo ind : rti)
        for(int x=0;x<th.size();x++)
            if(th[x][HOGCODUSU] == ind[INDCODUSU])
            {
                if(!quedanIndividuos(ti, th[x][HOGCODUSU]))
                {
                    rth.push_back(th[x]);
                    th.erase(th.begin() + x);
                    x--;
                }
                else
                    rth.push_back(th[x]);
            }
    pair<eph_h, eph_i> resp = make_pair(rth, rti);
    return resp;
}
