// Copyright 2017 Hakan Metin

#ifndef INCLUDE_CNF2GRAPH_CNFMODELEXPORT_H_
#define INCLUDE_CNF2GRAPH_CNFMODELEXPORT_H_

#include <string>
#include <vector>

#include "cnf2graph/CNFModel.h"
#include "cnf2graph/Clause.h"
#include "cnf2graph/Literal.h"

namespace cnf2graph {

class CNFModelExport {
 public:
    CNFModelExport() {}
    ~CNFModelExport() {}

    void print(const CNFModel& model);
 private:
    std::string headerString(unsigned int num_vars, unsigned int num_clauses);
    std::string clauseString(const std::unique_ptr<Clause>& clause);
};


} // namespace cnf2graph
#endif // INCLUDE_CNF2GRAPH_CNFMODELEXPORT_H_
