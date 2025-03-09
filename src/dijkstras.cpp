#include "dijkstras.h"
#include <algorithm>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    previous.resize(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.push({0, source});
    distances[source] = 0;

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : G[u]) {
            int v = edge.dst, weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if (distances[destination] == INF){
        return path;
    }
    for (int v = destination; v != -1; v = previous[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total){
    if (path.empty() || total == INF) {
        cout << "No path found." << endl;
        return;
    }

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << "\nTotal cost is " << total << endl;
}
