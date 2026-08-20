#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// Graph from your diagram
unordered_map<char, vector<pair<char, int>>> graph = {
    {'a', {{'b', 14}, {'e', 10}, {'g', 17}}},
    {'b', {{'a', 14}, {'e', 3}, {'c', 9}, {'d', 10}}},
    {'c', {{'b', 9}, {'d', 2}}},
    {'d', {{'c', 2}, {'b', 10}, {'f', 7}}},
    {'e', {{'a', 10}, {'b', 3}, {'f', 4}, {'g', 6}}},
    {'f', {{'d', 7}, {'e', 4}, {'g', 1}}},
    {'g', {{'a', 17}, {'e', 6}, {'f', 1}}}
};

// Dijkstra Algorithm
void dijkstra(char start) {
    unordered_map<char, int> dist;

    for (auto &node : graph) {
        dist[node.first] = INT_MAX;
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        for (auto &neighbor : graph[currentNode]) {
            char nextNode = neighbor.first;
            int weight = neighbor.second;

            if (currentDist + weight < dist[nextNode]) {
                dist[nextNode] = currentDist + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << "Minimum cost from node 'a':\n";
    for (auto &d : dist) {
        cout << d.first << " : " << d.second << endl;
    }
}

int main() {
    dijkstra('a');
    return 0;
}
