// Copyright 2017 Hakan Metin


#ifndef INCLUDE_CNF2GRAPH_CNFMODELSTATS_H_
#define INCLUDE_CNF2GRAPH_CNFMODELSTATS_H_

#include <algorithm>
#include <memory>
#include <unordered_set>
#include <vector>

#include "cnf2graph/Clause.h"
#include "cnf2graph/Literal.h"
#include "cnf2graph/Logging.h"

namespace cnf2graph {

class CNFModel {
 public:
    CNFModel();
    ~CNFModel();

    void addClause(std::vector<Literal>* literals);

    const std::vector<std::unique_ptr<Clause>>& clauses() { return _clauses; }

    int64 numberOfVariables()      const { return _num_variables + 1; }
    int64 numberOfClauses()        const { return _clauses.size();    }
    int64 numberOfClausesReaded()  const { return _num_clauses;       }

    int64 numberOfUnaryClauses()   const { return _num_unary_clauses;   }
    int64 numberOfBinaryClauses()  const { return _num_binary_clauses;  }
    int64 numberOfTernaryClauses() const { return _num_ternary_clauses; }
    int64 numberOfLargeClauses()   const { return _num_large_clauses;   }

    const std::vector<int64>& occurences() const { return _occurences; }

    void summarize() const;
 private:
    int64 _num_variables;
    int64 _num_clauses;

    int64 _num_unary_clauses;
    int64 _num_binary_clauses;
    int64 _num_ternary_clauses;
    int64 _num_large_clauses;

    std::vector<std::unique_ptr<Clause>> _clauses;
    std::unordered_set<size_t> _duplicates;

    std::vector<int64> _positive_occurences;
    std::vector<int64> _negative_occurences;
    std::vector<int64> _occurences;

    void compute_occurences(const std::vector<Literal>& literals);
    void compute_sizes(const std::vector<Literal>& literals);

    DISALLOW_COPY_AND_ASSIGN(CNFModel);
};
}  // namespace cnf2graph

#endif  // INCLUDE_CNF2GRAPH_CNFMODELSTATS_H_

/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
