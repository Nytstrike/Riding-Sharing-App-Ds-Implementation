#pragma once
#include<iostream>
#include<string>

class Passenger
{
	static int passengerID;
	std::string passengerName;
	std::string pickUP;
	std::string dropOFF;
	bool passengerStatus = false;
public:
	Passenger(std::string name);
	void addPickUP(std::string location);
	void addDropOFF(std::string location);
	std::string getPickUP();
	std::string getDropOFF();
	bool checkStatus();
	void changeStatus(bool s);
};

