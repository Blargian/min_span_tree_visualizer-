#include "node.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std; 
/**
 * @brief Default Node constructor
 *
 * @param 
 */
Node::Node() {
}

/**
 * @brief Overloaded Node constructor
 *
 * @param nodeName the name of the node 
 *        x the x-coordinate 
 *        y the y-coordinate 
 */
Node::Node(string nodeName, int x, int y) {
	this->setNodeName(nodeName);
	this->setXY(x, y);
}

/**
 * @brief Setter method for the nodename
 *
 * @param nodeName name of the node as a string
 */
void Node::setNodeName(string nodeName) {
	this->nodeName = nodeName; 
}
/**
 * @brief Setter method for the node co-ordinates on 100x100 grid 
 *
 * @param x x-coordinate (0-100), y y-coordinate (0-100)
 */
void Node::setXY(int x, int y) {

	int x_abs = abs(x);
	int y_abs = abs(y);

	if ((x_abs > 100) || (y_abs > 100)) {
		throw std::invalid_argument("Coordinates should be between 0 and 100 inclusive");
	}
	else {
		this->coordinates.first = x;
		this->coordinates.second = y;
	}
}

/**
 * @brief inserts an edge to the edgelist
 *
 * @param edgeToAdd Edge 
 */
void Node::insertEdge(Edge edgeToAdd) {
	Edge e = edgeToAdd; 
	this->edgeList.push_back(e);
}

/**
 * @brief removes an edge from the edgelist
 *
 * @param fromNode Node
 *        toNode   Node
 */
void Node::removeEdge(Node* fromNode, Node* toNode) {
	Edge* edgeToRemove = this->getEdge(fromNode, toNode);
	this->edgeList.remove(*edgeToRemove);
}

/**
 * @brief returns a pointer to an edge
 *
 */
void Node::clearEdgeList() {
	this->edgeList = {};
}

/**
 * @brief returns a pointer to an edge
 * @param fromNode Node (start of the edge)
 *        toNode (end of the edge)
 *
 */
Edge* Node::getEdge(Node* fromNode, Node* toNode) {
	
	Edge* foundNode = nullptr;
	for (auto it = this->edgeList.begin(); it != this->edgeList.end(); ++it) {
		if (*(it->getSourceNode()) == *fromNode && *(it->getDestinationNode()) == *toNode) {
			foundNode = &(*it);
		}
	}
	return foundNode;
}

/**
 * @brief returns the edge list
 */
list<Edge> Node::getEdgeList() {
	return edgeList; 
}

/**
 * @brief returns a nodes coordinates
 */
pair <int, int> Node::getXY() {
	return this->coordinates;
}
