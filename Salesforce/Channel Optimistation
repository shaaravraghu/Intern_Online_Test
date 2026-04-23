#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n+1), rank_(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};

long getMaxRemovedChannelCost(int org_nodes, vector<int> org_from,
                               vector<int> org_to, vector<int> org_weight) {
    int m = org_from.size();
    // Sort edges by weight ascending (keep cheapest = min spanning tree)
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return org_weight[a] < org_weight[b];
    });

    DSU dsu(org_nodes);
    long totalSum = 0, keptSum = 0;

    for (int i = 0; i < m; i++) totalSum += org_weight[i];

    for (int i : idx) {
        if (dsu.unite(org_from[i] - 1, org_to[i] - 1)) {
            keptSum += org_weight[i];
        }
    }

    return totalSum - keptSum;
}
