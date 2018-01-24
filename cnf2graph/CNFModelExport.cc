

#include "cnf2graph/CNFModelExport.h"

namespace cnf2graph {

std::string
CNFModelExport::headerString(unsigned int num_vars, unsigned int num_clauses) {
    return "p cnf " + std::to_string(num_vars) + " " +
        std::to_string(num_clauses);
}

std::string
CNFModelExport::clauseString(const std::unique_ptr<Clause>& clause) {
    std::string c;
    for (const Literal& literal : *clause)
        c += std::to_string(literal.signedValue()) + " ";
    c += "0";
    return c;
}

void CNFModelExport::print(const CNFModel& model) {
    unsigned int num_vars = model.numberOfVariables();
    unsigned int num_clauses = model.numberOfClauses();

    std::cout << headerString(num_vars, num_clauses) << std::endl;
    for (const std::unique_ptr<Clause>& clause : model.clauses())
        std::cout << clauseString(clause) << std::endl;
}

}  // namespace cnf2graph
