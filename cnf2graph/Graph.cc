
#include "cnf2graph/Graph.h"

namespace cnf2graph {

void AdjacencyGraph::addNode(unsigned int node) {
    if (_num_nodes > node)
        return;
    _num_nodes = node + 1;
    _adjacency.resize(_num_nodes);
    _degree.resize(_num_nodes);
}

void AdjacencyGraph::addEdge(unsigned int from, unsigned int to) {
    addNode(from > to ? from : to);
    _adjacency[from].push_back(to);
    _adjacency[to].push_back(from);
    _degree[from]++;
    _degree[to]++;
    _num_edges++;
}

void ColoredAdjacencyGraph::addNode(unsigned int node) {
    AdjacencyGraph::addNode(node);
    _colors.resize(_num_nodes, kLiteralColor);
}

void ColoredAdjacencyGraph::changeColor(unsigned int node, unsigned int color) {
    _colors[node] = color;
}


}  // namespace cnf2graph
