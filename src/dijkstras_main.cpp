#include "dijkstras.h"

int main() {
    string filename = "src/small.txt";
    Graph G;
    
    file_to_graph(filename, G);

    int source = 0;
    int destination = G.numVertices - 1;

    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    vector<int> test_destinations = {0, 1, 2, 3};
    for (int destination : test_destinations) {
        vector<int> path = extract_shortest_path(distances, previous, destination);
        print_path(path, distances[destination]);
    }

    return 0;
}
