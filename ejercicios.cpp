#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;

/// Integrantes del grupo 3:
/// Agustin Canteros
/// Juan Carlos Aguirre
/// Mirko Cuchan
/// Nicolas Ventieri

/// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti )
{
    if(!algunaEncuestaVacia(ti, th) &&
    esMatriz(th) && (esMatriz(ti)) &&
    columnasCorrectas(ti, th) &&
    individuosConHogares(ti, th) && hogaresConIndividuos(ti, th) &&
    anioYTrimestreIgualEnTodos(th, ti) &&
    miembrosDelHogarMenorA20(th, ti) &&
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
vector<pair<int, float>> laCasaEstaQuedandoChica(eph_h th, eph_i ti)
{
    vector<int> regiones = {1, 40, 41, 42, 43, 44};
    vector<pair<int,float>> ans = {};
    for(int i=0;i<regiones.size();i++)
    {
        float hogares_validos = cantHogaresValidos(th, regiones[i]);
        if(hogares_validos > 0)
            ans.emplace_back(regiones[i], cantHogaresValidosConHC(th, ti, regiones[i]) / hogares_validos);
        else
            ans.emplace_back(regiones[i], 0);
    }
    return ans;
}

/// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i)
{
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}

/// Implementacion Problema 5
int costoSubsidioMejora(eph_h th, eph_i ti, int monto)
{
    int resp = 0;
    for(int i=0;i<th.size();i++)
        if(th[i][II7] == 1)
            if (necesitaSubsidioMejora(cantidadDeHabitantesEnCasa(th[i][HOGCODUSU], ti), (th[i])))
                resp += monto;
    return resp;
}

/// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi ans = {};
    for(int i=0;i<ti.size();i++)
        for(int j=0;j<th.size();j++)
            if(ti[i][INDCODUSU] == th[j][HOGCODUSU])
                ans.emplace_back(th[j],ti[i]);
    return ans;
}

/// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti)
{
    ordenarPorRegionYCodosu(th);
    ti = ordenarPorIndividuosPorHOGCODOSU(th,ti);
    ordenarPorCOMPONENTE(ti);
}

/// Implementacion Problema 8
vector <hogar> muestraHomogenea(eph_h &th, eph_i &ti)
{
    vector<pair<int, int>> ordenador;
    for(int i = 0; i < th.size(); i++)
        ordenador.emplace_back(th[i][HOGCODUSU], ingresos(th[i], ti));
    ordenar(th, ordenador);
    vector<int> sol = solucionHomogenea(ordenador, 0, 0);
    return respuestaHomogenea(th, sol);
}

/// Implementacion Problema 9
void corregirRegion(eph_h &th, eph_i &ti)
{
    for(int i=0;i<th.size();i++)
        if (th[i][REGION] == 1) th[i][REGION] = 43;
}

/// Implementacion Problema 10
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>>&  busqueda)
{
    eph_h rth = {};
    eph_i rti = {};
    vector<dato> cods = {};
    for(int i=0;i<ti.size();i++)
        if(cumpleCondicion(busqueda, ti[i]))
        {
            rti.push_back(ti[i]);
            ti.erase(ti.begin() + i);
            i--;
        }
    for(int i=0;i<rti.size();i++)
        if(!existe(rti[i][INDCODUSU], cods))
            cods.push_back(rti[i][INDCODUSU]);
    for(int i=0;i<cods.size();i++)
        for(int x=0;x<th.size();x++)
            if(th[x][HOGCODUSU] == cods[i])
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

/// Implementacion Problema 11
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias)
{
    vector<int> resp = {};
    resp.push_back(cantHogaresEnAnillo(0,distancias[0],centro,th));
    for (int i = 1; i < distancias.size() ; ++i)
        resp.push_back(cantHogaresEnAnillo(distancias[i-1],distancias[i],centro,th));
    return resp;
}
