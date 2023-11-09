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

void main() 
{
	setlocale(LC_ALL, "");

	Tank tank(12);
	double fuel;
	do
	{
		std::cout << "¬ведите уровень топлива: "; std::cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (fuel!=0);
}