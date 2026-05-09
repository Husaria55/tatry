#include "Graph.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

void Graph::addEdge(const std::string& from, const std::string& to, const int time) {
    adjacencyList[from].push_back({to, time});
}

bool Graph::loadFromJson(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad: Nie udalo sie otworzyc pliku " << filename << "!\n";
        return false;
    }

    json j;
    file >> j;

    for (auto& [from, edges] : j.items())
        {
        for (auto& [to, time] : edges.items())
            {
            if (!time.is_null()) {
                addEdge(from, to, time.get<int>());
            }
        }
    }
    return true;
}

void Graph::printGraph() const {
    for (const auto& pair : adjacencyList) {
        std::cout << "[" << pair.first << "] prowadzi do:\n";
        for (const auto& edge : pair.second) {
            std::cout << "  -> " << edge.destination << " (" << edge.timeMinutes << " min)\n";
        }
    }
}