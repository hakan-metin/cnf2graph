
#include "cnf2graph/CNFGraph.h"


namespace cnf2graph {

CNFGraph::CNFGraph() {
}

CNFGraph::~CNFGraph() {
}

void CNFGraph::assign(const CNFModel& model) {

    unsigned int n = model.numberOfVariables();
    unsigned int num_clauses = 2 * n;

    unsigned int x, y, z;
    bool opt_optimized = true;

    // Boolean consistency
    for (BooleanVariable var(0); var < n; ++var) {
        x = literal2Node(Literal(var, true), n);
        y = literal2Node(Literal(var, false), n);
        std::cout << x << " " << y << std::endl;
        _graph.addEdge(x, y);
    }

    for (const std::unique_ptr<Clause>& clause : model.clauses()) {
        if (opt_optimized && clause->size() == 2) {
            x = literal2Node(clause->literals()[0], n);
            y = literal2Node(clause->literals()[1], n);
            std::cout << x << " " << y << std::endl;
            _graph.addEdge(x, y);
        } else {
            for (const Literal& literal : *clause) {
                z = literal2Node(literal, n);
                std::cout << z << " " << num_clauses << std::endl;
                _graph.addEdge(z, num_clauses);
            }
            num_clauses++;
        }
    }

    // Set Colors
    for (BooleanVariable var(0); var < n; ++var) {
        x = literal2Node(Literal(var, true), n);
        y = literal2Node(Literal(var, false), n);
        if (_graph.degree()[x] == 1 && _graph.degree()[y] == 1) {
            _graph.changeColor(x, kNoNeighBourPositiveColor);
            _graph.changeColor(y, kNoNeighBourNegativeColor);
        }
    }
    for (unsigned int i=2*n; i < num_clauses; ++i)
        _graph.changeColor(i, kClauseColor);

    WrapperSaucy ws;
    ws.assign(_graph, n);
}

}  // namespace cnf2graph
