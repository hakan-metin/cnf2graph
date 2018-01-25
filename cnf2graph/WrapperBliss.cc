
#include "cnf2graph/WrapperBliss.h"

#include "bliss/utils.hh"

namespace cnf2graph {


static void
report_aut(void* param, const unsigned int n, const unsigned int* aut)
{
  assert(param);
  bliss::print_permutation((FILE*)param, n, aut, 1);
  fprintf((FILE*)param, "\n");
}


void WrapperBliss::assign(const ColoredAdjacencyGraph& graph) {
    unsigned int n = graph.numberOfNodes();

    std::unique_ptr<bliss::Graph> g(new bliss::Graph(n));
    bliss::Stats stats;

    unsigned int i = 0;
    for (unsigned int color : graph.colors())
        g->change_color(i++, color);

    i = 0;
    for (const std::vector<unsigned int>& neighbour : graph.adjacency()) {
        for (const unsigned int& x : neighbour)
            g->add_edge(i, x);
        i++;
    }

    g->find_automorphisms(stats, &report_aut, stdout);

}

}  // namespace cnf2graph
