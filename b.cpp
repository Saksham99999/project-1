#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Graph from your diagram
unordered_map<char, vector<pair<char, int>>> graph = {
    {'A', {{'D',5}, {'B',8}, {'C',3}}},
    {'B', {{'A',8}, {'H',2}, {'L',7}}},
    {'C', {{'A',3}, {'J',6}, {'I',7}}},
    {'D', {{'A',5}, {'F',2}, {'K',7}}},
    {'F', {{'D',2}, {'H',5}, {'J',6}}},
    {'H', {{'F',5}, {'B',2}, {'J',8}, {'I',4}}},
    {'I', {{'C',7}, {'K',4}, {'H',4}}},
    {'J', {{'C',6}, {'L',5}, {'H',8}, {'F',6}}},
    {'K', {{'D',7}, {'I',4}, {'L',9}}},
    {'L', {{'B',7}, {'J',5}, {'K',9}}}
};

// Prim’s Algorithm
int prim(char start) {
    unordered_map<char, bool> visited;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;

    pq.push({0, start});
    int totalCost = 0;

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        totalCost += cost;

        for (auto &neighbor : graph[node]) {
            if (!visited[neighbor.first]) {
                pq.push({neighbor.second, neighbor.first});
            }
        }
    }

    return totalCost;
}

int main() {
    int mstCost = prim('A');

    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;

    return 0;
}
