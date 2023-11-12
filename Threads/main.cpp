#include <iostream>
#include<thread>

using namespace std::chrono_literals;

bool finish = false;

void Plus() 
{
	while (!finish)
	{
		std::cout << "+ ";
		std::this_thread::sleep_for(1s);
	}
}
void Minus()
{
	while (!finish)
	{
		std::cout << "- ";
		std::this_thread::sleep_for(1s);
	}
}


void main() 
{
	//Plus();
	//Minus();
	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);
	std::cin.get(); // Функция cin.get() ожидает нажатия Enter
	finish = true;
	plus_thread.join();
	minus_thread.join();
}