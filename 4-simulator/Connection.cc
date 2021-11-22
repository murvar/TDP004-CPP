#include "Connection.h"

Connection::Connection() : 
	charge{0} 
	{}

void Connection::set_charge(double const& c)
{
	charge = c;
}

double Connection::get_charge() const
{
	return charge;
}
