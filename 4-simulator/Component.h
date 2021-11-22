#pragma once

#include <string>
#include "Connection.h"

using namespace std;

class Component
{
public:
	Component(string const& name, Connection & p, Connection & n );

	virtual ~Component();

	virtual void compute(double const& time) =0;

	virtual double get_current() =0;

	virtual double get_voltage();

	string get_name() const;

private:
	const string name;

	Component(const Component&);

    void operator=(const Component&);

protected:
	Connection* p;
	
	Connection* n;
};

