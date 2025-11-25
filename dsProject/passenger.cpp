#include "passenger.h"
#include<iostream>
#include<string>

Passenger::Passenger(std::string passengerName) {
	passengerID++;
	this->passengerName = passengerName;
	passengerStatus = false;
	//fasle -- not dropped off
}
void Passenger::addPickUP(std::string location) {
	pickUP = location;
}
void Passenger::addDropOFF(std::string location) {
	dropOFF = location;
}
std::string Passenger::getPickUP() {
	return pickUP;
}
std::string Passenger::getDropOFF() {
	return dropOFF;
}
bool Passenger::checkStatus() {
	return passengerStatus;
}
void Passenger::changeStatus(bool status) {
	passengerStatus = status;
}
