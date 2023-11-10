#include <iostream>


#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 120

class Tank 
{
	const int VOLUME;
	double fuel;
public:
	const int get_VOLUME()const 
	{
		return VOLUME;
	}
	double get_fuel()const 
	{
		return fuel;
	}
	void fill(double fuel) 
	{
		if (fuel < 0)return;
		if (this->fuel + fuel < VOLUME)this->fuel += fuel;
		else this->fuel = VOLUME;
	}
	Tank(const int volume) : VOLUME
	(
		volume < MIN_TANK_VOLUME ? MIN_TANK_VOLUME :
		volume >MAX_TANK_VOLUME?MAX_TANK_VOLUME:
		volume
	)
	{
		this->fuel = 0;
		std::cout << "Tank is ready\t" << this << std::endl;
	}
	~Tank()
	{
		std::cout << "Tank is over\t" << this << std::endl;
	}
	void info()const 
	{
		std::cout << "Volume:		 " << VOLUME << " liters.\n";
		std::cout << "Fuel lvl: " << fuel << " liters.\n";
	}
};
#define MIN_ENGINE_CONSUMPTION 3
#define MAX_ENGINE_CONSUMPTION 30
class Engine 
{
	const double CONSUMPTION;
	double consumption_per_second;
	bool is_started;
public:
	double get_CONSUMPTION()const 
	{
		return CONSUMPTION;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	void start() 
	{
		is_started = true;
	}
	void stop() 
	{
		is_started = false;
	}
	bool started()const 
	{
		return is_started;
	}

	Engine(double consumption) :CONSUMPTION
	(
		consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
		consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
		consumption
	)
	{
		consumption_per_second = CONSUMPTION * 3e-5;
		is_started = false;
		std::cout << "Engine ready" << this << std::endl;
	}
	~Engine() 
	{
		std::cout << "Engine is over" << this << std::endl;
	}
	void info()const 
	{
		std::cout << "Consumption: " << get_CONSUMPTION() << " liters.\n";
		std::cout << "Consumption/sec: " << get_consumption_per_second() << "liters.\n";
	}
};

void main() 
{
	setlocale(LC_ALL, "");

	Engine engine(20);
	engine.info();
}