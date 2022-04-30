#include "Graph.hpp"
#include <set>
#include <iostream>

unsigned long Graph :: shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path){
    std::set<std::string> visited = {startLabel};
    std::map<std::string, std::pair<std::string, unsigned long>> weight;
    //default initializing each edge weight to max value
    for(auto v : adjList){
        if(v.first != startLabel)
            weight.insert({v.first, {"", (unsigned long)-1}});
    }
    //set weight of the edge of start label to itself to zero
    weight.insert({startLabel, {startLabel, 0}});

    //while there are still unvisited vertices
    while(visited.size() < adjList.size()){
        std::string startVertex = *visited.begin();
        for(auto v : visited){
            for(auto k_v : adjList[v]){
                if(weight[v].second + k_v.second <= weight[k_v.first].second){
                    if(visited.count(k_v.first) == 0)
                        visited.insert(k_v.first);
                    weight[k_v.first] = {v, weight[v].second + k_v.second};
                }
            }
        }
    }
    //back tracking
    std::vector<std::string> revV;
    for(std::string v = endLabel; v != startLabel; v = weight[v].first)
        revV.push_back(v);

    revV.push_back(startLabel);
    path = std::vector<std::string>(revV.rbegin(), revV.rend());

    return weight[endLabel].second;
}

