#include "EdgeWeightedDigraph.h"

EdgeWeightedDigraph::EdgeWeightedDigraph(std::istream&& in) : EdgeWeightedDigraph([&in]() {
    int i;
    return in >> i, i;
}()) {
    int E;
    in >> E;
    for (int i = 0; i < E; ++i) {
        int v, w;
        double weight;
        in >> v >> w >> weight;
        addEdge(DirectedEdge(v, w, weight));
    }
}

void EdgeWeightedDigraph::addEdge(const DirectedEdge& e) {
    adj_[e.from()].push_front(e);
    ++E_;
}

std::forward_list<DirectedEdge> EdgeWeightedDigraph::edges() const {
    std::forward_list<DirectedEdge> bag;
    for (int v = 0; v < V_; ++v) {
        for (const auto& e : adj_[v]) {
            bag.push_front(e);
        }
    }
    return bag;
}
