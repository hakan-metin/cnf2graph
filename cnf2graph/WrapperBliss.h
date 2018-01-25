
// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_WRAPPERBLISS_H_
#define INCLUDE_CNF2GRAPH_WRAPPERBLISS_H_

#include <vector>
#include <memory>

#include "cnf2graph/CNFGraph.h"

#include "bliss/graph.hh"

namespace cnf2graph {

class WrapperBliss {
 public:
    WrapperBliss() {}
    ~WrapperBliss() {}

    void assign(const ColoredAdjacencyGraph& graph);
 private:
};

}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_WRAPPERBLISS_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
