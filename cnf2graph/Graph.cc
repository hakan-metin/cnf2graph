
#include "cnf2graph/Graph.h"

namespace cnf2graph {

void AdjacencyGraph::addNode(unsigned int node) {
    if (_num_nodes > node)
        return;
    _num_nodes++;
    _adjacency.resize(_num_nodes);
}

void AdjacencyGraph::addEdge(unsigned int from, unsigned int to) {
    addNode(from > to ? from : to);
    _adjacency[from].push_back(to);
    _adjacency[to].push_back(from);
    _num_edges++;
}

}  // namespace cnf2graph
