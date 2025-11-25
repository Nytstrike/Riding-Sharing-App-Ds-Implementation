#pragma once
#include<utility>
#include<iostream>
// DS implementation #1 (2d Linked List)
//the graph is stored as an adjacency list
//The adjacency list is stored as an 2d linked list 

// edge storing for each vertix
struct Edge {
	std::pair<int, int> edge; //first = destination, second = weight;
	Edge* nextEdge;

	Edge(int destination,int weight);
	int getDestination() const { return edge.first; }
	int getWeight() const { return edge.second; }
};

//for each vertix
struct VertixNode {
	int vertixId;
	Edge* headVertix;
	VertixNode* nextVertix;

	VertixNode(int vertixId);

};
