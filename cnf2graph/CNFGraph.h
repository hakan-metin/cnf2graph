
// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_CNFGRAPH_H_
#define INCLUDE_CNF2GRAPH_CNFGRAPH_H_

#include <vector>

#include "cnf2graph/CNFModel.h"
#include "cnf2graph/Graph.h"

#include "cnf2graph/WrapperSaucy.h"

namespace cnf2graph {

class CNFGraph {
 public:
    CNFGraph();
    ~CNFGraph();

    void assign(const CNFModel& model);

    const ColoredAdjacencyGraph& graph() const { return _graph; }
 private:
    ColoredAdjacencyGraph _graph;
};



}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_CNFGRAPH_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
