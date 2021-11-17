#include "Capacitor.h"

Capacitor::Capacitor(string const& name, float const& c, Connection & p, Connection & n) : 
		Component(name, p, n), 
        c(c), _charge(0) 
        {}

void Capacitor::move(const float & timeunits)
{
	// How much to move
	double chargeToMove { c * (getVoltage() - _charge) * timeunits };

	// Add to capacitor charge
	_charge += chargeToMove;

	float aSide { _a->getCharge() };
	float bSide { _b->getCharge() };
	
	if ( aSide > bSide )
	{
		_a->setCharge( aSide - chargeToMove );
		_b->setCharge( bSide + chargeToMove );
	}
	else
	{
		_b->setCharge( bSide - chargeToMove );
		_a->setCharge( aSide + chargeToMove );
	}
}

float Capacitor::getCurrent()
{
	return abs(c * (getVoltage() - _charge));
}