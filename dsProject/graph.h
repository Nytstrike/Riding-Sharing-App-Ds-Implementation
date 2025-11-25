#pragma once
#include<iostream>
#include "linkedList.h"
//DS implementation #2 (Graph)

class Graph {
	VertixNode* head;
public:
	Graph();
	void addVertix(int id);
	void addEdge(int from, int to, int weight);
	VertixNode* findVertix (int id);
	static Graph* readFromCSV(const std::string fileName);
	bool writeGraphtoFile(const std::string& filename);
	
};