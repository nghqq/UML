#include <iostream>
#include <conio.h>

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
		std::cout << "Engine is over\t"  << this << std::endl;
	}
	void info()const 
	{
		std::cout << "Consumption: " << get_CONSUMPTION() << " liters.\n";
		std::cout << "Consumption/sec: " << get_consumption_per_second() << "liters.\n";
	}
};

#define MAX_SPEED_LOW_LVL 50
#define MAX_SPEED_HIGH_LVL 450

class Car 
{
	Engine engine;
	Tank tank;
	const int MAX_SPEED;
	int speed;
	bool driver_inside;
public:
	int get_MAX_SPEED()const 
	{
		return MAX_SPEED;
	}
	int get_speed()const 
	{
		return speed;
	}
	Car(int max_speed, double consumption = 10, int volume = 40) :MAX_SPEED
	(
		max_speed < MAX_SPEED_LOW_LVL ? MAX_SPEED_LOW_LVL :
		max_speed > MAX_SPEED_HIGH_LVL ? MAX_SPEED_HIGH_LVL :
		max_speed
	),engine(consumption),tank(volume)
	{
		this->speed = 0;
		std::cout << "Car is ready, Press Enter to get in" << this << std::endl;
	}
	~Car() 
	{
		std::cout << "Your car destroyed:\t" << this << std::endl;
	}
	void fill(double fuel) 
	{
		tank.fill(fuel);
	}
	void get_in() 
	{
		driver_inside = true;
		panel();
	}
	void get_out() 
	{
		driver_inside = false;
		std::cout << "You are out " << std::endl;

	}
	void control()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case 'F':
			case  'f':
			{
				if(driver_inside)
				{
					std::cout << "First of all get out your car" << std::endl;
					break;
				}
				double fuel;
				std::cout << "¬ведите уровень топлива: "; std::cin >> fuel;
				fill(fuel);
			}
				break;
			case 13:
				if (driver_inside)get_out();
				else get_in();
			}
		} while (key!=27);
	}
	void panel()const 
	{
		while (driver_inside)
		{
			system("CLS");
			std::cout << "Fuel Level: " << tank.get_fuel() << "liters.\n";
			std::cout << "Engine is " << (engine.started() ? "started" : "stopped") << std::endl;
		}
	}
	void info()const 
	{
		engine.info();
		tank.info();
	}

};

void main() 
{
	setlocale(LC_ALL, "");

	//Engine engine(20);
	//engine.info();

	Car car(250);
	//car.info();
	car.control();

}