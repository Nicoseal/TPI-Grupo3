#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    if(esMatriz(th) && (esMatriz(ti)) && columnasCorrectas(ti, th) && !algunaEncuestaVacia(ti, th) && columnasIgualEnum(ti, th)
       && individuosConHogares(ti, th) && hogaresConIndividuos(ti, th) && anioYTrimestreIgualEnTodos(ti, th) && miembrosDelHogarMenorA20(ti, th)
       && IV2MayorAII2(ti) && atribsCatsOkDeTi(ti) && atribsCatsOkDeTh(th)){
        return true;
    } else {
        return false;
    }
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector < int > resultado;

    int longitudDeResultado = maximaCantidadDeHabitacionesEnRegion(th, region);

    for (int i = 0; i < longitudDeResultado ; ++i) {

        resultado.push_back(cantHogaresCasaConNHabitaciones(th,region,i+1));

    }
    return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
	// TODO
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp = 0;    // originalmente decia -1

    for (int i = 0; i < th.size(); i++){
        if(th[i][II7] == 1){
            if (necesitaSubsidioMejora(cantidadDeHabitantesEnCasa(th[i][0], ti), (th[i]))){
                resp = resp + monto;
            }}
    }

    return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {

    for (int i = 0; i < th.size(); ++i) {

        if (th[i][REGION] == 1)th[i][REGION] = 43;
    }

    return;
}

// Implementacion Problema 11
vector < int > histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias)
{
    vector<int> resp = {};
    resp.push_back(cantHogaresEnAnillo(0,distancias[0],centro,th));
    for (int i = 1; i < distancias.size() ; ++i)
    {
        resp.push_back(cantHogaresEnAnillo(distancias[i-1],distancias[i],centro,th));
    }
    return resp;
}

// Implementacion Problema 10
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>>&  busqueda)
{
    eph_h rth = {};
    eph_i rti = {};
    for(int i=0;i<ti.size();i++)
        if(cumpleCondicion(busqueda, ti[i]))
        {
            for(int x=0;x<th.size();x++)
                if(th[x][HOGCODUSU] == ti[i][INDCODUSU])
                {
                    rth.push_back(th[x]);
                    th.erase(th.begin() + x);
                    x--;
                }
            rti.push_back(ti[i]);
            ti.erase(ti.begin() + i);
            i--;
        }
    pair<eph_h, eph_i> resp = make_pair(rth, rti);
    return resp;
}
