
// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_WRAPPERSAUCY_H_
#define INCLUDE_CNF2GRAPH_WRAPPERSAUCY_H_

#include <vector>

#include "cnf2graph/CNFModel.h"

namespace cnf2graph {

class WrapperSaucy {
 public:
    WrapperSaucy();
    ~WrapperSaucy();

    void assign(const CNFModel& cnf);

};

}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_WRAPPERSAUCY_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
