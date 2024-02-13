---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/binary_indexed_tree_2d.hpp
    title: lib/data_structure/binary_indexed_tree_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/dsl/dsl_5_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/binary_indexed_tree_2d.hpp\"\
    \n\n/* \n    BinaryIndexedTree2D<T>(h, w) : BIT2D\u3092\u30B5\u30A4\u30BAh*w\u3067\
    \u69CB\u7BC9\n    add(x, y, v) : (x, y) \u306B v \u3092\u52A0\u7B97\u3057\u307E\
    \u3059\u3002 O(log(H) * log(W))\n    imos(x1, y1, x2, y2, v) : \u3044\u3082\u3059\
    \u6CD5\u306B\u304A\u3044\u3066\u3001[(x1, y1), (x2, y2)] \u306B v \u3092\u52A0\
    \u7B97\u3057\u307E\u3059\u3002O(log(H) * log(W))\n    sum(x1, y1, x2, y2) : [(x1,\
    \ y1), (x2, y2)] \u306E\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002O(log(H)\
    \ * log(W))\n*/\n\ntemplate <typename T>\nstruct BinaryIndexedTree2D{\n    int\
    \ H, W;\n    vector<vector<T>> BIT;\n    BinaryIndexedTree2D(const int &_H, const\
    \ int &_W) : H(_H + 1), W(_W + 1){\n        BIT.resize(H + 3, vector<T>(W + 3,\
    \ 0));\n    }\n\n    void add(const int x, const int y, const T v){\n        assert(0\
    \ <= x && x < H && 0 <= y && y < W);\n        for(int a = x + 1; a <= H; a +=\
    \ a & -a){\n            for(int b = y + 1; b <= W; b += b & -b){\n           \
    \     BIT[a][b] += v;\n            }\n        }\n    }\n\n    void imos(const\
    \ int x1, const int y1, const int x2, const int y2, const T v){\n        add(x1,\
    \ y1, v);\n        add(x1, y2 + 1, -v);\n        add(x2 + 1, y1, -v);\n      \
    \  add(x2 + 1, y2 + 1, v);\n    }\n\n    T sum(const int x, const int y){\n  \
    \      assert(x < H && y < W);\n        if(x < 0 || y < 0) return 0;\n       \
    \ T res = 0;\n        for(int a = x + 1; a > 0; a -= a & -a){\n            for(int\
    \ b = y + 1; b > 0; b -= b & -b){\n                res += BIT[a][b];\n       \
    \     }\n        }\n        return res;\n    }\n\n    T sum(const int x1, const\
    \ int y1, const int x2, const int y2){\n        if(x1 > x2 || y1 > y2) return\
    \ T(0);\n        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1\
    \ - 1, y1 - 1);\n    }\n};\n#line 6 \"test/aoj/dsl/dsl_5_b.test.cpp\"\n\nint main(){\n\
    \    int n; cin >> n;\n    BinaryIndexedTree2D<long long> BIT(1002, 1002);\n \
    \   for(int i = 0; i < n; i++){\n        int x1, y1, x2, y2; cin >> x1 >> y1 >>\
    \ x2 >> y2;\n        BIT.imos(x1, y1, x2 - 1, y2 - 1, 1);\n    }\n    long long\
    \ ans = 0;\n    for(int i = 0; i <= 1000; i++){\n        for(int j = 0; j <= 1000;\
    \ j++){\n            ans = max(ans, BIT.sum(0, 0, i, j));\n        }\n    }\n\
    \    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/binary_indexed_tree_2d.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    BinaryIndexedTree2D<long long> BIT(1002,\
    \ 1002);\n    for(int i = 0; i < n; i++){\n        int x1, y1, x2, y2; cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        BIT.imos(x1, y1, x2 - 1, y2 - 1, 1);\n    }\n\
    \    long long ans = 0;\n    for(int i = 0; i <= 1000; i++){\n        for(int\
    \ j = 0; j <= 1000; j++){\n            ans = max(ans, BIT.sum(0, 0, i, j));\n\
    \        }\n    }\n    cout << ans << \"\\n\";\n}"
  dependsOn:
  - lib/data_structure/binary_indexed_tree_2d.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_5_b.test.cpp
  requiredBy: []
  timestamp: '2024-01-29 20:46:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_5_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_5_b.test.cpp
- /verify/test/aoj/dsl/dsl_5_b.test.cpp.html
title: test/aoj/dsl/dsl_5_b.test.cpp
---