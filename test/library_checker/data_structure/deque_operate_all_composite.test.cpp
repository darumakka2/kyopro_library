#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/deswag.hpp"

constexpr long long MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    using T = pair<long long, long long>;
    auto op = [](T x1, T x2) -> T { 
        return {x1.first * x2.first % MOD, (x2.first * x1.second % MOD + x2.second) % MOD};
    };
    DESWAG<T> swag(op);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 0){
            long long a, b; cin >> a >> b;
            swag.push_front({a, b});
        }else if(t == 1){
            long long a, b; cin >> a >> b;
            swag.push_back({a, b});
        }else if(t == 2){
            swag.pop_front();
        }else if(t == 3){
            swag.pop_back();
        }else{
            long long x; cin >> x;
            if(swag.size() == 0){
                cout << x << "\n";
                continue;
            }
            T k = swag.fold();
            long long ans = k.first * x % MOD + k.second;
            ans %= MOD;
            cout << ans << "\n";
        }
    }
}