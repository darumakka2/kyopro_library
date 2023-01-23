## Bellman-Ford Algorithm (ベルマン-フォード法)

#### 概要

単一始点最短経路問題を解くことができるアルゴリズムです。

重みが負であった場合でも負の閉路を検出することができます。

#### 使い方

- `bellman_ford(E, n, x)`: 頂点数が $n$ である辺集合 $E$ における $x$ を始点とするそれぞれの頂点への最短距離を求めます。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(EV)$