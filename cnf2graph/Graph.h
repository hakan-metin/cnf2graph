
// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_GRAPH_H_
#define INCLUDE_CNF2GRAPH_GRAPH_H_

#include <vector>

#include "cnf2graph/Literal.h"

namespace cnf2graph {

// Representations of the graph node:
//    [0   ,  n]  - positive literals
//    [n+1 , 2n]  - negative literals
//    [2n+1, XX]  - clauses
static inline
unsigned int literal2Node(const Literal& literal, unsigned int n) {
    unsigned int v = literal.variable().value();
    if (literal.isPositive())
        return v;
    else
        return n + v;
}

static inline LiteralIndex node2Literal(unsigned int node, unsigned int n) {
    if (node < n)
        return Literal(node).index();
    else if (node < 2*n)
        return Literal(-(n - node)).index();
    else
        return kNoLiteralIndex;
}

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
    virtual ~AdjacencyGraph() {}

    virtual void addNode(unsigned int node);
    void addEdge(unsigned int from, unsigned int to);

    const std::vector< std::vector<unsigned int> > adjacency() const {
        return _adjacency;
    }

    const std::vector<unsigned int> degree() const {
        return _degree;
    }

 protected:
    std::vector< std::vector<unsigned int> > _adjacency;
    std::vector<unsigned int> _degree;
};

static const unsigned int kLiteralColor = 0;
static const unsigned int kClauseColor = 1;
static const unsigned int kNoNeighBourPositiveColor = 2;
static const unsigned int kNoNeighBourNegativeColor = 3;

class ColoredAdjacencyGraph : public AdjacencyGraph {
 public:

    ColoredAdjacencyGraph() : AdjacencyGraph() {}
    ~ColoredAdjacencyGraph() {}

    void addNode(unsigned int node) override;
    void changeColor(unsigned int node, unsigned int color);

    const std::vector<unsigned int> colors() const { return _colors; };
 private:
    std::vector<unsigned int> _colors;
};

}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_GRAPH_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
