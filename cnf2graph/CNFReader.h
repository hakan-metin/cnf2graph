// Copyright 2017 Hakan Metin - LIP6

#ifndef INCLUDE_CNF2GRAPH_CNFREADER_H_
#define INCLUDE_CNF2GRAPH_CNFREADER_H_

#include <vector>
#include <string>

#include "cnf2graph/CNFModel.h"
#include "cnf2graph/Literal.h"
#include "cnf2graph/StreamBuffer.h"
#include "cnf2graph/Logging.h"

namespace cnf2graph {

class CNFReader {
 public:
    CNFReader();
    ~CNFReader();

    bool load(const std::string &filename, CNFModel *model_stats);

 private:
    DISALLOW_COPY_AND_ASSIGN(CNFReader);
};
}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_CNFREADER_H_

/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
