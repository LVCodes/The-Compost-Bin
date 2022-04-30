#ifndef __GRAPH_H_
#define __GRAPH_H_
#include "GraphBase.hpp"
#include <map>


class Graph : GraphBase{
    public:

        //Creates and adds a vertex to the graph with label. No two vertices should have the same label.
        void addVertex(std::string label){
            adjList.insert({label, std::map<std::string, unsigned long>()});
        };


        //Removes the vertex with label from the graph. Also removes the edges between that
        //vertex and the other vertices of the graph.
        void removeVertex(std::string label){
            adjList.erase(label);
        }


        //Adds an edge of value weight to the graph between the vertex with label1 and the vertex
        //with label2. A vertex with label1 and a vertex with label2 must both exist, there must
        //not already be an edge between those vertices, and a vertex cannot have an edge to itself.
        void addEdge(std::string label1, std::string label2, unsigned long weight){
            adjList[label1][label2] = weight;
            adjList[label2][label1] = weight;
        };


        //Removes the edge from the graph between the vertex with label1 and the vertex with label2.
        //A vertex with label1 and a vertex with label2 must both exist and there must be an edge
        //between those vertices
        void removeEdge(std::string label1, std::string label2){
            adjList[label1].erase(label2);
            adjList[label2].erase(label1);
        };


        //Calculates the shortest path between the vertex with startLabel and the vertex with
        //endLabel using Dijkstra's Algorithm. A vector is passed into the method that stores the
        //shortest path between the vertices. The return value is the sum of the edges between the
        //start and end vertices on the shortest path.
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

    private:
        //map of vertex names and their associated edges stored as a list
        //where the edges are a pair of strings and unsigned longs
        std::map<std::string, std::map<std::string, unsigned long>> adjList;
};



#endif // __GRAPH_H_
