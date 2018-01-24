
#include "cnf2graph/WrapperSaucy.h"

namespace cnf2graph {

void WrapperSaucy::assign(const ColoredAdjacencyGraph& graph,
                          unsigned int num_vars) {
    std::vector<int> adj;
    std::vector<int> edj;
    std::vector<int> colors;
    int n;
    int e;

    const std::vector<unsigned int>& d = graph.degree();
    adj.push_back(0);
    unsigned int sum = 0;
    for (unsigned int i = 0; i<d.size(); ++i) {
        sum += d[i];
        adj.push_back(sum);
    }

    for (const std::vector<unsigned int>& neighbour : graph.adjacency())
        for (const unsigned int& x : neighbour)
            edj.push_back(x);

    for (unsigned int color : graph.colors())
        colors.push_back(color);

    //colors.assign(graph.colors().begin(), graph.colors().end());
    // const unsigned int kLiteralColor = 0;
    // const unsigned int kClauseColor = 2;

    // const unsigned int kNoNeighBourPositiveColor = 3;
    // const unsigned int kNoNeighBourNegativeColor = 4;

    // unsigned int color = kLiteralColor;
    // for (unsigned int i=0; i<num_vars; ++i)
    //         colors.push_back(color);

    // for (unsigned int i=num_vars; i<2*num_vars; ++i) {
    //         colors.push_back(color);
    // }

    // color = kClauseColor;
    // for (unsigned int i=2*num_vars; i<graph.numberOfNodes(); ++i)
    //     colors.push_back(color);

    n = graph.numberOfNodes();
    e = graph.numberOfEdges();

    for (auto a : adj)
        std::cout << a << std::endl;
    std::cout  << std::endl;

    for (auto a : edj)
        std::cout << a << std::endl;
    std::cout  << std::endl;

    for (auto a : colors)
        std::cout << a << std::endl;


}


}  // namespace cnf2graph
