#include "Component.h"
#include <cmath>

using namespace std;

Component::Component(string const& name, Connection & p, Connection & n) :
	name{name}, 
	p{&p}, 
	n{&n}
	{}

//x Kommentar: Du kan skriva = default efter deklarationen i h-filen för att slippa
// en tom implementation.

string Component::get_name() const
{
	return name;
}

double Component::get_voltage()
{
	return fabs( p->get_charge() - n->get_charge() );
}
