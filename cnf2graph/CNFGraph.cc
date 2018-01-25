
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

    // Graph edges
    for (const std::unique_ptr<Clause>& clause : model.clauses()) {
        if (opt_optimized && clause->size() == 2) {
            x = literal2Node(clause->literals()[0], n);
            y = literal2Node(clause->literals()[1], n);
            _graph.addEdge(x, y);
        } else {
            for (const Literal& literal : *clause) {
                z = literal2Node(literal, n);
                _graph.addEdge(z, num_clauses);
            }
            num_clauses++;
        }
    }

    // Boolean consistency
    for (BooleanVariable var(0); var < n; ++var) {
        x = literal2Node(Literal(var, true), n);
        y = literal2Node(Literal(var, false), n);
        _graph.addEdge(x, y);
    }

    // Colors
    int unused_color = kClauseColor + 1;
    for (BooleanVariable var(0); var < n; ++var) {
        x = literal2Node(Literal(var, true), n);
        y = literal2Node(Literal(var, false), n);
        if (_graph.degree()[x] == 1 && _graph.degree()[y] == 1) {
            _graph.changeColor(x, unused_color++);
            _graph.changeColor(y, unused_color++);
        }
    }
    for (unsigned int i=2*n; i < num_clauses; ++i)
        _graph.changeColor(i, kClauseColor);

    std::cout << "SAUCY GENERATOR" << std::endl;
    WrapperSaucy ws;
    ws.assign(_graph);

    std::cout << "BLISS GENERATOR" << std::endl;

    WrapperBliss wb;
    wb.assign(_graph);

}

}  // namespace cnf2graph
