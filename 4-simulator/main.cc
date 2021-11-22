#include <iostream>
#include <iomanip>
#include <vector>
#include "Component.h"
#include "Connection.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

void validate(char * argv [])
{
	try
	{
		stoi(argv[1]);
	}
	catch(...)
	{
		cout << "Sim iterations must be of type int!" << endl;
		exit(1);
	}
		
	try
	{
		stoi(argv[2]);
	}
	catch(...)
	{
		cout << "Print iterations must be of type int!!" << endl;
		exit(1);
	}
		
	try
	{
		stod(argv[3]);

	}
	catch(...)
	{
		cout << "Time must be of type double!" << endl;
		exit(1);
	}
		
	try
	{
		stod(argv[4]);
	}
	catch(...)
	{
		cout << "Voltage must be of type double!" << endl;
		exit(1);
	}
}

void simulate(vector<Component*> & net, int const& sim_iterations, int const& print_iterations, const double & time)
{
	for (Component* c : net)
	{
		cout << setw(12) << c->get_name() << "    ";
	}
	cout << endl << " ";

	for (string::size_type i = 0; i < net.size(); ++i)
	{
		cout << "Volt" << "\t" << "Curr" << "\t";
	}
	cout << endl;

	for (int i = 0; i < sim_iterations; ++i)
	{
		for (Component* c : net)
		{
			c->compute(time);
		}

		if ((i + 1) % (sim_iterations / print_iterations) == 0)
		{
			for (Component* c : net)
			{
				cout << setprecision(2) << fixed;
				cout << c->get_voltage() << "\t";
				cout << c->get_current() << "\t";
			}
			cout << endl;
		}
	}

	for (Component* c : net)
	{
		delete c;
	}
}

void example1(double voltage, int sim_iterations, int print_iterations, double time)
{
	Connection p, n, R124, R23;
	vector<Component*> net;
	net.push_back(new Battery("Bat", voltage, p, n));
	net.push_back(new Resistor("R1",  6.0, p, R124));
	net.push_back(new Resistor("R2",  4.0, R124, R23));
	net.push_back(new Resistor("R3",  8.0, R23, n));
	net.push_back(new Resistor("R4", 12.0, R124, n));
	simulate(net, sim_iterations, print_iterations, time);
}

void example2(double voltage, int sim_iterations, int print_iterations, double time)
{
	Connection p, l, n, r;
	vector<Component*> net;
	net.push_back(new Battery("Bat", voltage, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2",  50.0, p, r));
	net.push_back(new Resistor("R3",  100.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Resistor("R5",  250.0, r, n));
	simulate(net, sim_iterations, print_iterations, time);
}

void example3(double voltage, int sim_iterations, int print_iterations, double time)
{
	Connection p, n, l, r;
	vector<Component*> net;
	net.push_back(new Battery("Bat", voltage, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2",  50.0, p, r));
	net.push_back(new Capacitor("C3",  1.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Capacitor("C5",  0.75, r, n));
	simulate(net, sim_iterations, print_iterations, time);
}

int main (int, char * argv [])
{
	validate(argv);

	int sim_iterations {stoi(argv[1])};
	int print_iterations {stoi(argv[2])};
	double time {stod(argv[3])};
	double voltage {stod(argv[4])};

	example1(voltage, sim_iterations, print_iterations, time);

	cout << endl << endl;

	example2(voltage, sim_iterations, print_iterations, time);

	cout << endl << endl;

	example3(voltage, sim_iterations, print_iterations, time);

	return 0;
}
