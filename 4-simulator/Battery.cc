#include "Battery.h"

Battery::Battery(string const& name, double const& v, Connection & p, Connection & n) : 
		Component{name, p, n}, 
		voltage{v} 
		{}

double Battery::get_voltage() 
{
	return voltage;
}
	
double Battery::get_current() 
{
	return 0;
}

void Battery::compute(double const&)
{
	p->set_charge(voltage);
	n->set_charge(0);
}

