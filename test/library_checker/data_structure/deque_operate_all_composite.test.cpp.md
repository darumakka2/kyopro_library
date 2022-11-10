---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/deswag.hpp
    title: lib/data_structure/deswag.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/deswag.hpp\"\
    \n\n/* \n    DESWAG<T>(op) : \u4E21\u7AEFSWAG \u3092\u69CB\u7BC9\u3057\u307E\u3059\
    \u3002\n    fold() : \u8981\u7D20\u5168\u3066\u306B op \u3092\u9069\u7528\u3055\
    \u305B\u305F\u5024\u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(1)\n    push_front(x)\
    \ : x \u3092\u5148\u982D\u306B\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n   \
    \ push_back(x) : x \u3092\u672B\u5C3E\u306B\u8FFD\u52A0\u3057\u307E\u3059\u3002\
    : O(1)\n    pop_front() : x \u3092\u5148\u982D\u304B\u3089\u524A\u9664\u3057\u307E\
    \u3059\u3002: \u511F\u5374 O(1)\n    pop_back() : x \u3092\u672B\u5C3E\u304B\u3089\
    \u524A\u9664\u3057\u307E\u3059\u3002: \u511F\u5374 O(1)\n*/\n\ntemplate <typename\
    \ T>\nstruct DESWAG{\n    using Op = function<T(T, T)>;\n\nprivate:\n    struct\
    \ node{\n    public:\n        T val, sum;\n        node(const T &val, const T\
    \ &sum) : val(val), sum(sum) {}\n    };\n\n    Op op;\n    stack<node> front_stack,\
    \ back_stack, temp_stack;\n\npublic:\n    DESWAG(const Op &op = Op()) : op(op),\
    \ front_stack(), back_stack(), temp_stack() {}\n\n    bool empty(){\n        return\
    \ front_stack.empty() && back_stack.empty();\n    }\n\n    size_t size(){\n  \
    \      return front_stack.size() + back_stack.size();\n    }\n\n    T fold(){\n\
    \        if(front_stack.empty()){\n            return back_stack.top().sum;\n\
    \        }else if(back_stack.empty()){\n            return front_stack.top().sum;\n\
    \        }else{\n            return op(front_stack.top().sum, back_stack.top().sum);\n\
    \        }\n    }\n\n    void push_front(const T &x){\n        if(front_stack.empty()){\n\
    \            front_stack.emplace(x, x);\n        }else{\n            T s = op(x,\
    \ front_stack.top().sum);\n            front_stack.emplace(x, s);\n        }\n\
    \    }\n\n    void push_back(const T &x){\n        if(back_stack.empty()){\n \
    \           back_stack.emplace(x, x);\n        }else{\n            T s = op(back_stack.top().sum,\
    \ x);\n            back_stack.emplace(x, s);\n        }\n    }\n\n    void pop_front(){\n\
    \        if(front_stack.empty()){\n            int half = (back_stack.size() +\
    \ 1) / 2;\n            while(!back_stack.empty()){\n                if(back_stack.size()\
    \ == half){\n                    front_stack.emplace(back_stack.top().val, back_stack.top().val);\n\
    \                }else if(back_stack.size() < half){\n                    T s\
    \ = op(back_stack.top().val, front_stack.top().sum);\n                    front_stack.emplace(back_stack.top().val,\
    \ s);\n                }else{\n                    temp_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n                }\n                back_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                back_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(back_stack.top().sum, temp_stack.top().val);\n \
    \                   back_stack.emplace(temp_stack.top().val, s);\n           \
    \         temp_stack.pop();\n                }\n            }\n        }\n   \
    \     front_stack.pop();\n    }\n\n    void pop_back(){\n        if(back_stack.empty()){\n\
    \            int half = (front_stack.size() + 1) / 2;\n            while(!front_stack.empty()){\n\
    \                if(front_stack.size() == half){\n                    back_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }else if(front_stack.size() < half){\n\
    \                    T s = op(back_stack.top().sum, front_stack.top().val);\n\
    \                    back_stack.emplace(front_stack.top().val, s);\n         \
    \       }else{\n                    temp_stack.emplace(front_stack.top().val,\
    \ front_stack.top().val);\n                }\n                front_stack.pop();\n\
    \            }\n            if(!temp_stack.empty()){\n                front_stack.emplace(temp_stack.top().val,\
    \ temp_stack.top().val);\n                temp_stack.pop();\n                while(!temp_stack.empty()){\n\
    \                    T s = op(temp_stack.top().val, front_stack.top().sum);\n\
    \                    front_stack.emplace(temp_stack.top().val, s);\n         \
    \           temp_stack.pop();\n                }\n            }\n        }\n \
    \       back_stack.pop();\n    }\n};\n#line 6 \"test/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \n\nconstexpr long long MOD = 998244353;\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    using T = pair<long long, long long>;\n\
    \    auto op = [](T x1, T x2) -> T { \n        return {x1.first * x2.first % MOD,\
    \ (x2.first * x1.second % MOD + x2.second) % MOD};\n    };\n    DESWAG<T> swag(op);\n\
    \n    int q; cin >> q;\n    while(q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            long long a, b; cin >> a >> b;\n            swag.push_front({a,\
    \ b});\n        }else if(t == 1){\n            long long a, b; cin >> a >> b;\n\
    \            swag.push_back({a, b});\n        }else if(t == 2){\n            swag.pop_front();\n\
    \        }else if(t == 3){\n            swag.pop_back();\n        }else{\n   \
    \         long long x; cin >> x;\n            if(swag.size() == 0){\n        \
    \        cout << x << \"\\n\";\n                continue;\n            }\n   \
    \         T k = swag.fold();\n            long long ans = k.first * x % MOD +\
    \ k.second;\n            ans %= MOD;\n            cout << ans << \"\\n\";\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/deswag.hpp\"\
    \n\nconstexpr long long MOD = 998244353;\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    using T = pair<long long, long long>;\n\
    \    auto op = [](T x1, T x2) -> T { \n        return {x1.first * x2.first % MOD,\
    \ (x2.first * x1.second % MOD + x2.second) % MOD};\n    };\n    DESWAG<T> swag(op);\n\
    \n    int q; cin >> q;\n    while(q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            long long a, b; cin >> a >> b;\n            swag.push_front({a,\
    \ b});\n        }else if(t == 1){\n            long long a, b; cin >> a >> b;\n\
    \            swag.push_back({a, b});\n        }else if(t == 2){\n            swag.pop_front();\n\
    \        }else if(t == 3){\n            swag.pop_back();\n        }else{\n   \
    \         long long x; cin >> x;\n            if(swag.size() == 0){\n        \
    \        cout << x << \"\\n\";\n                continue;\n            }\n   \
    \         T k = swag.fold();\n            long long ans = k.first * x % MOD +\
    \ k.second;\n            ans %= MOD;\n            cout << ans << \"\\n\";\n  \
    \      }\n    }\n}"
  dependsOn:
  - lib/data_structure/deswag.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-11-10 02:54:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/deque_operate_all_composite.test.cpp
- /verify/test/library_checker/data_structure/deque_operate_all_composite.test.cpp.html
title: test/library_checker/data_structure/deque_operate_all_composite.test.cpp
---