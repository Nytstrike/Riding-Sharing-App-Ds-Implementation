#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<utility>
// DS implentation #3
//no rehashing function as the graph for the city is pregenerated and the load will always be same

class Hashmap
{
	std::list<std::pair<std::string, int>>* bucket;
	size_t numBuckets;
	size_t hashFuction(const char* cKey) {
		return std::hash<std::string> {} (cKey) % numBuckets;
	}
public:
	Hashmap(int m);
	void insertLocation(char *cKey,int value);
	int getNode(const char *cKey);
};

