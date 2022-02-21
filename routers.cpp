#include "routers.h"

// funciones privadas de routers
routers::routers()
{
    mRuta="";
    mCosto=numeric_limits<int>::max();
}

void routers::setRuta(const string _r, const int _c) //Asignacion de valores
{
    mRuta= _r;
    mCosto= _c;
}

string routers::getRutaminima() // ruta minima del objeto
{
return mRuta;
}

int routers::getCostoMinimo()
{
return mCosto;
}

