#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H


#include "SP.h"
#include "IndexMinPQ.h"

class DijkstraSP : public SP {
private:
    IndexMinPQ<double> pq;

    void onRelaxationSuccess(const EdgeWeightedDigraph &G, int v, const DirectedEdge &e, int w) override;

public:
    DijkstraSP(const EdgeWeightedDigraph &G, int s);
};


#endif //DIJKSTRASP_H
