#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVecrtices, false);

    distances[source] = UNDEFINED;
    priority_queue<pair<int,int>> minHeap;

    minHeap.push({source,0});

    while(!minHeap.empty()){
        int u = minHeap.top().first;

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            // int weight = edge.weight;
            int weight = edge.second;
            
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                minHeap.push({distance[v], v});
            }
        }
    }
    return distance;
}


vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    if (path.empty()) {
        cout << "No path found." << endl;
        return;
    }
    cout << "Shortest path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal distance: " << total << endl;
}