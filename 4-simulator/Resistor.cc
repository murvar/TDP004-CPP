#include "Resistor.h"

using namespace std;

Resistor::Resistor(string const& name, double const& r, Connection & p, Connection & n) : 
	Component{name, p, n}, 
	resistance{r}
	{}

void Resistor::compute(double const& time)
{
	double charge {get_voltage() / resistance * time};
	double positive {p->get_charge()};
	double negative {n->get_charge()};
	
	if (positive > negative)
	{
		p->set_charge(positive - charge);
		n->set_charge(negative + charge);
	}
	else
	{
		n->set_charge(negative - charge);
		p->set_charge(positive + charge);
	}
}

double Resistor::get_current()
{
	return (get_voltage() / resistance);
}

