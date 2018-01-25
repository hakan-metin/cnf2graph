
#include "cnf2graph/WrapperSaucy.h"


namespace {
std::vector<bool> seen;
static int
on_automorphism(int n, const int *gamma, int k, int *support, void *arg) {
    seen.assign(n, false);

    for (int i=0; i<n; ++i) {
        if (i == gamma[i] || seen[i])
            continue;
        std::cout << "(" << i+1;

        seen[i] = true;

        for (int j = gamma[i]; j != i; j = gamma[j]) {
            seen[j] = true;
            std::cout << " " << j+1;
        }
        std::cout << ")";
    }
    std::cout << std::endl;
}

} // namespace

namespace cnf2graph {


void WrapperSaucy::assign(const ColoredAdjacencyGraph& graph) {
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

    n = graph.numberOfNodes();
    e = graph.numberOfEdges();

    // Initialize saucy structure
    struct saucy *s = (saucy*) saucy_alloc(n);
    struct saucy_graph	*g = (saucy_graph*)malloc(sizeof(struct saucy_graph));

    g->n = n;
    g->e = e;
    g->adj = adj.data();
    g->edg = edj.data();

    struct saucy_stats stats;
    saucy_search(s, g, 0, colors.data(), on_automorphism, g, &stats);
    saucy_free(s);
}


}  // namespace cnf2graph
