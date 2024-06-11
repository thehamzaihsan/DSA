#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

void dijkstra(const vector<vector<iPair>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source (" << src << "):" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    vector<vector<iPair>> graph = {
        { {1, 4}, {2, 1} },    
        { {0, 4}, {2, 2}, {3, 5} }, 
        { {0, 1}, {1, 2}, {3, 8}, {4, 10} }, 
        { {1, 5}, {2, 8}, {4, 2} }, 
        { {2, 10}, {3, 2} }  
    };

    int src = 0; 
    dijkstra(graph, src);

    return 0;
}
