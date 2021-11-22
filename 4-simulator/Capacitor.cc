#include "Capacitor.h"

Capacitor::Capacitor(string const& name, double const& c, Connection & p, Connection & n) : 
		Component{name, p, n}, 
		capacitance{c}, 
		charge{0} 
		{}

void Capacitor::compute(double const& time)
{
	double new_charge { capacitance * (get_voltage() - charge) * time };

	charge += new_charge;

	double positive { p->get_charge() };
	double negative { n->get_charge() };
	
	if ( positive > negative )
	{
		p->set_charge( positive - new_charge );
		n->set_charge( negative + new_charge );
	}
	else
	{
		n->set_charge( negative - new_charge );
		p->set_charge( positive + new_charge );
	}
}

double Capacitor::get_current()
{
	return abs( capacitance * (get_voltage() - charge));
}

