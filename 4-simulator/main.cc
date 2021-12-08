#include <iostream>
#include <iomanip>
#include <vector>
// Kommentar: Det är helt ok att ha flera klasser i samma h-fil, förutsatt
// att de har en tydlig koppling till varandra. Här vore det t.ex. ok att
// lägga alla komponenter i samma fil.
#include "Component.h"
#include "Connection.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

void validate(int argc, char * argv [])
{
    // Komplettering kvarstår: Gör rimlighetskontroll av värdena.
	if(argc != 5)
	{
		cout << "Wrong number of arguments!" << endl;
		exit(1);
	}
	
	try
	{
		stoi(argv[1]);
	}
        // Kommentar: catch-all bör överlag undvikas. Fånga hellre specifika fel. Kastas
        // något fel man inte förväntar sig vill man oftasta att programmet avslutas,
        // men en catch-all riskerar att fånga felet istället.
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

	if (argv[1] <= 0)
	{
		cout << "Sim iterations must be a positive number!" << endl;
		exit(1);
	}

	if (argv[2] <= 0)
	{
		cout << "Print iterations must be a positive number!" << endl;
		exit(1);
	}

	if (argv[3] <= 0)
	{
		cout << "Time must be a positive number!" << endl;
		exit(1);
	}

	if (argv[4] <= 0)
	{
		cout << "Voltage must be a positive number!" << endl;
		exit(1);
	}
}

void simulate(vector<Component*> & net, int const& sim_iterations, int const& print_iterations, const double & time)
{
	cout << setw(11);

	for (Component* c : net)
	{
		cout << c->get_name() << setw(12);
	}
	cout << endl << setw(5);

	for (string::size_type i = 0; i < net.size(); ++i)
	{
		cout << "Volt" << setw(6) << "Curr" << setw(6);
	}

	for (int i = 0; i < sim_iterations; ++i)
	{
		for (Component* c : net)
		{
			c->compute(time);
		}

		if ((i + 1) % (sim_iterations / print_iterations) == 0)
		{
			cout << endl << setw(5);
			for (Component* c : net)
			{
				cout << setprecision(2) << fixed
				 	 << c->get_voltage() << setw(6)
					 << c->get_current() << setw(6);
			}

		}
	}
	cout << endl;

        // Kommentar: Den här vore rimligare att ha i en egen funktion. Är det säkert
        // att man alltid vill ta bort komponenterna direkt efter simulering? I vilket
        // fall borde vektorn även tömmas, eftersom den annars är full av ogiltiga
        // pekare.
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

int main (int argc, char * argv [])
{
	validate(argc, argv);

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
