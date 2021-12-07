#pragma once

#include <string>
#include "Connection.h"

//x Komplettering: Använd aldrig using i en h-fil! Den som inkluderar filen vill
// kanske inte vill få in hela std i sitt namespace.

class Component
{
public:
	Component(std::string const& name, Connection & p, Connection & n );

	virtual ~Component() = default;

	virtual void compute(double const& time) =0;

	virtual double get_current() =0;

	virtual double get_voltage();

	std::string get_name() const;

private:
	const std::string name;

	Component(const Component&);

    void operator=(const Component&);

protected:
	Connection* p;
	
	Connection* n;
};
