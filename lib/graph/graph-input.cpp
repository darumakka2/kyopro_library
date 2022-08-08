#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> G;

// グラフ(隣接リスト)の入力
void inputGraph(){
    cin >> n >> m;
    G = vector<vector<int>>(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return;
}

// グラフの入力を簡略化
template<class T, class U>
void inGraph(vector<vector<T>>& G, U n, U m, bool directed = true) {
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        if(!directed) G[b].push_back(a);
    }
}