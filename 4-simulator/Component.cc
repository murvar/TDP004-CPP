#include "Component.h"
#include <cmath>

Component::Component(string const& name, Connection & p, Connection & n) :
	name{name}, 
	p{&p}, 
	n{&n}
	{}

Component::~Component() {}

string Component::get_name() const
{
	return name;
}

double Component::get_voltage()
{
	return fabs( p->get_charge() - n->get_charge() );
}
