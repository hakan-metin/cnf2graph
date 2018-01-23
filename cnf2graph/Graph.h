
// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_GRAPH_H_
#define INCLUDE_CNF2GRAPH_GRAPH_H_

#include <vector>

namespace cnf2graph {

class Graph {
 public:
    Graph() :
        _num_nodes(0),
        _num_edges(0) {}
    virtual ~Graph() {}

    unsigned int numberOfNodes() const { return _num_nodes; }
    unsigned int numberOfEdges() const { return _num_edges; }
 protected:
    unsigned int _num_nodes;
    unsigned int _num_edges;
};


class AdjacencyGraph : public Graph {
 public:
    AdjacencyGraph() : Graph() {}
    ~AdjacencyGraph() {}

    void addNode(unsigned int node);
    void addEdge(unsigned int from, unsigned int to);

    const std::vector< std::vector<unsigned int> > adjacency() const {
        return _adjacency;
    }
 private:
    std::vector< std::vector<unsigned int> > _adjacency;


};

}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_GRAPH_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
