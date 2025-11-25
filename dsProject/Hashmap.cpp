#include "Hashmap.h"
#include<iostream>
#include<string>

Hashmap::Hashmap(size_t mapSize) {
	this->numBuckets = mapSize;
	bucket = new std::list<std::pair<std::string, int>>[mapSize];
}
void Hashmap::insert(char* cKey, int value) {
	
}