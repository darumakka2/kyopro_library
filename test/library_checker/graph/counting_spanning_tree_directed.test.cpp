#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/graph/counting_spanning_tree.hpp"

using mint = ModInt<998244353>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r; cin >> n >> m >> r;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    cout << countingSpanningTree<mint>(G, r) << '\n';
}
