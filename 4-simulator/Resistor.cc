
#include "Resistor.h"

Resistor::Resistor(string const& name, float const& r, Connection & p, Connection & n) : 
		Component(name, p, n), 
        r(r) 
        {}

void Resistor::move(const float & timeunits)
{
	// How much to move
	double chargeToMove { (getVoltage() / r) * timeunits };

	float aSide { p->getCharge() };
	float bSide { n->getCharge() };
	
	if ( aSide > bSide )
	{
		_a->setCharge( aSide - chargeToMove );
		_b->setCharge( bSide + chargeToMove );
	}
	else
	{
		p->setCharge( bSide - chargeToMove );
		n->setCharge( aSide + chargeToMove );
	}
}

float Resistor::getCurrent()
{
	return getVoltage() /r;
}