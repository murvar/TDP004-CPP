#include <string>

#include "Connection.h"

Connection::Connection() : 
c{0} 
{}

void Connection::setCharge(float const& c)
{
	c = c;
}

float Connection::getCharge() const
{
	return _charge;
}