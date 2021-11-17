#include "Battery.h"

Battery::Battery(const string & name, float const& u, Connection & p, Connection & n) : 
		Component(name, p, n), 
        u(u) 
        {}

void Battery::move(const float &)
{
	p->setCharge(u);
	n->setCharge(0);
}
