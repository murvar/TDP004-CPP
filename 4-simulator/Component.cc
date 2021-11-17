#include "Component.h"

using namespace std;

Component::Component(string const& name, Connection & p, Connection & n) :
	name{name},
     p{&p},
     n(&n) 
     {}

Component::~Component() {}


// double Component::getVoltage()
// {
// 	return fabs( _a->getCharge() - _b->getCharge() );
// }