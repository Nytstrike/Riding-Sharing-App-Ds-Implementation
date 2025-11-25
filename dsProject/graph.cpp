#include<iostream>
#include<list>
#include<vector>
#include<fstream>
#include<sstream>
#include<exception>
#include "graph.h"
#include "linkedList.h"

//constructor
Graph::Graph() {
	head = NULL;
}
//finding specific Node
VertixNode* Graph::findVertix(int id) {
	VertixNode* temp = head;
	while (temp) {
		if (temp->vertixId == id) {
			return temp;
		}
		temp = temp->nextVertix;
	}
	return NULL;
}

// adding vertices . . .
void Graph::addVertix(int id) {
	if (findVertix(id) != NULL) {
		std::cout << "Vertix:" << id << "already exits" << std::endl;
	}
	VertixNode* newNode = new VertixNode(id);
	if (head == NULL) {
		head = newNode;
	}
	else {
		VertixNode* temp = head;
		while (temp->nextVertix != NULL) {
			temp = temp->nextVertix;
		}
		temp->nextVertix = newNode;
	}
}

//adding edges . . . 
void Graph::addEdge(int from, int to, int weight) {
	VertixNode* fromVertix = findVertix(from);
	VertixNode* toVertix = findVertix(to);
	if (!fromVertix) {
		std::cout << "No source vertix of ID: " << from << std::endl;
		addVertix(from);
		fromVertix = findVertix(from);
	}
	if (!toVertix) {
		std::cout << "No destination vertix of ID: " << to << std::endl;
		addVertix(to);
		toVertix = findVertix(to);
	}
	Edge* newNode = new  Edge(to, weight);
	newNode->nextEdge = fromVertix->headVertix;
	fromVertix->headVertix = newNode;
}

bool Graph::writeGraphtoFile(const std::string& fileName) {
	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Could not open file : " << fileName << std::endl;
	}
	file << "source,destination,weight" << std::endl;

	VertixNode* currentVertix = head;
	while (currentVertix != NULL) {
		Edge* currentEdge = currentVertix->headVertix;
		while (currentEdge != NULL) {
			file << currentVertix->vertixId << ","
				<< currentEdge->getDestination() << ","
				<< currentEdge->getWeight() << std::endl;
			currentEdge = currentEdge->nextEdge;
		}
		currentVertix = currentVertix->nextVertix;

	}
	file.close();
	std::cout << "Graph written to file" << std::endl;
	return true;
}

//reading from csv file
Graph* Graph::readFromCSV(const std::string fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Could not open file: " << fileName << std::endl;
	}

	Graph* newGraph = new Graph();
	std::string line;
	int lineNumber = 0;
	while (std::getline(file, line)) {
		lineNumber++;

		if (line.empty() || line.find("source") != std::string::npos) {
			continue;
		}
		std::stringstream ss(line);
		std::string value;
		int from, to, weight;

		try {
			if (!std::getline(ss, value, ',')) {
				continue;
			}
			else {
				from = std::stoi(value);
			}
			if (!std::getline(ss, value, ','))
			{
				continue;
			}
			else {
				to = std::stoi(value);
			}
			if (!std::getline(ss, value, ',')) {
				continue;
			}
			else {
				weight = std::stoi(value);
			}

			newGraph->addEdge(from, to, weight);

		}
		catch (const std::exception& e) {
			std::cerr << "Invalid value at line: " << lineNumber<<" - "<<e.what() << std::endl;
			continue;
		}

	}
	file.close();
	std::cout << "Map data loaded, ready for next action . . ." << std::endl;

	return newGraph;
}

