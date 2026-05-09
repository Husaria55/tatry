#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Edge {
    std::string destination;
    int timeMinutes;
};

class Graph {
private:
    std::unordered_map<std::string, std::vector<Edge>> adjacencyList;

public:
    void addEdge(const std::string& from, const std::string& to, int time);
    bool loadFromJson(const std::string& filename);
    void printGraph() const;


};