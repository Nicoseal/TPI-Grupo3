#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;

// Implementacion Problema 1
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

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector < int > resultado;

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
int costoSubsidioMejora( eph_h th, eph_i ti, int monto )
{
    int resp = 0; // originalmente decia -1
    for(hogar hog : th)
        if(hog[II7] == 1)
            if (necesitaSubsidioMejora(cantidadDeHabitantesEnCasa(hog[HOGCODUSU], ti), (hog)))
                resp += monto;
    return resp;
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

    return resp;
}

// Implementacion Problema 10
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>>&  busqueda)
{
    eph_h rth = {};
    eph_i rti = {};

    pair<eph_h, eph_i> resp = make_pair(rth, rti);
    return resp;
}
