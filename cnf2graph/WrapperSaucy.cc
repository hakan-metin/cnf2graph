
#include "cnf2graph/WrapperSaucy.h"

namespace cnf2graph {

namespace {

}  // namespace

void WrapperSaucy::assign(const CNFModel& cnf) {

    unsigned int num_vars = cnf.numberOfVariables();
    unsigned int num_clauses = 2 * num_vars + 1;

    unsigned int first, second;
    bool opt_optimized = true;

    for (const std::unique_ptr<Clause>& clause : cnf.clauses()) {
        if (opt_optimized && clause->size() == 2) {
            first = 0; // clause->literals()[0];
            second = 1; //clause->literals()[1];
            //addEdge(first, second);
        } else {
            for (const Literal& literal : *clause) {
                //                addEdge(num_clauses, literal);
            }
            num_clauses++;
        }
    }

}


}  // namespace cnf2graph
