// Copyright 2017 Hakan Metin - LIP6

# include "cnf2graph/Clause.h"

namespace cnf2graph {

// static
Clause* Clause::create(const std::vector<Literal>& literals) {

    Clause *clause = reinterpret_cast<Clause*>(
        ::operator new(sizeof(Clause) + literals.size() * sizeof(Literal)));

    clause->_size  = literals.size();
    for (unsigned int i = 0; i < literals.size(); i++) {
        clause->_literals[i] = literals[i];
    }

    return clause;
}

}  // namespace cnf2graph
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
