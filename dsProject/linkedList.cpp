#include<iostream>
#include<utility>
#include "linkedList.h"

Edge::Edge(int destination, int weight) {
	edge = std::make_pair(destination, weight);
	nextEdge = NULL;
}
VertixNode::VertixNode(int vertixId) {
	this->vertixId = vertixId;
	headVertix = NULL;
	nextVertix = NULL;
}
