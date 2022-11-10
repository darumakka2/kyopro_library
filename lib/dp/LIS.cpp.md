---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/dp/LIS.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n// \u914D\u5217 a \u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\
    \u9577\u3055\u3092\u6C42\u3081\u307E\u3059 : O(NlogN)\n\n// dp[i] : = \u9577\u3055\
    \u304C i \u306E\u5897\u52A0\u90E8\u5206\u5217\u3068\u3057\u3066\u6700\u5F8C\u5C3E\
    \u306E\u8981\u7D20\u306E\u3068\u308A\u3046\u308B\u6700\u5C0F\u5024\n// is_strong\
    \ = false \u306E\u3068\u304D\u3001\u540C\u3058\u5024\u304C\u9023\u7D9A\u3059\u308B\
    \u3053\u3068\u3092\u8A31\u3059\n\ntemplate <typename T>\nint LIS(vector<T> a,\
    \  bool is_strong = true){\n    const long long INF = 0x1fffffffffffffff;\n  \
    \  int n = (int) a.size();\n    vector<long long> dp(n, INF);\n    for(int i =\
    \ 0; i < n; ++i){\n        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i])\
    \ = a[i];\n        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];\n   \
    \ }\n    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}\n\n//\
    \ \u914D\u5217 a \u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u3092\u69CB\u7BC9\
    \u3057\u307E\u3059\u3002 : O(NlogN)\ntemplate <typename T>\nvector<int> getLIS(vector<T>\
    \ a,  bool is_strong = true){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    int n = (int) a.size();\n    vector<long long> dp(n, INF);\n    vector<vector<int>>\
    \ idx(n);\n    for(int i = 0; i < n; ++i){\n        if(is_strong){\n         \
    \    auto iter = lower_bound(dp.begin(), dp.end(), a[i]);\n            *iter =\
    \ a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n       \
    \ }else{\n            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);\n \
    \           *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }\n    }\n    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    \    vector<int> res;\n    int now = n;\n    for(int i = k - 1; i >= 0; --i){\n\
    \        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);\n       \
    \ iter--;\n        now = *iter;\n        res.push_back(now);\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\n// example\nint main(){\n    int n; cin >>\
    \ n;\n    vector<long long> a(n);\n    for(int i = 0; i < n; i++){\n        cin\
    \ >> a[i];\n    }\n    cout << LIS(a) << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u914D\u5217 a \u306E\
    \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\u3092\u6C42\u3081\
    \u307E\u3059 : O(NlogN)\n\n// dp[i] : = \u9577\u3055\u304C i \u306E\u5897\u52A0\
    \u90E8\u5206\u5217\u3068\u3057\u3066\u6700\u5F8C\u5C3E\u306E\u8981\u7D20\u306E\
    \u3068\u308A\u3046\u308B\u6700\u5C0F\u5024\n// is_strong = false \u306E\u3068\u304D\
    \u3001\u540C\u3058\u5024\u304C\u9023\u7D9A\u3059\u308B\u3053\u3068\u3092\u8A31\
    \u3059\n\ntemplate <typename T>\nint LIS(vector<T> a,  bool is_strong = true){\n\
    \    const long long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n\
    \    vector<long long> dp(n, INF);\n    for(int i = 0; i < n; ++i){\n        if\
    \ (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];\n        else *upper_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];\n    }\n    return lower_bound(dp.begin(), dp.end(),\
    \ INF) - dp.begin();\n}\n\n// \u914D\u5217 a \u306E\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002 : O(NlogN)\ntemplate <typename\
    \ T>\nvector<int> getLIS(vector<T> a,  bool is_strong = true){\n    const long\
    \ long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n    vector<long\
    \ long> dp(n, INF);\n    vector<vector<int>> idx(n);\n    for(int i = 0; i < n;\
    \ ++i){\n        if(is_strong){\n             auto iter = lower_bound(dp.begin(),\
    \ dp.end(), a[i]);\n            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }else{\n            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);\n\
    \            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }\n    }\n    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    \    vector<int> res;\n    int now = n;\n    for(int i = k - 1; i >= 0; --i){\n\
    \        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);\n       \
    \ iter--;\n        now = *iter;\n        res.push_back(now);\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\n// example\nint main(){\n    int n; cin >>\
    \ n;\n    vector<long long> a(n);\n    for(int i = 0; i < n; i++){\n        cin\
    \ >> a[i];\n    }\n    cout << LIS(a) << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/LIS.cpp
  requiredBy: []
  timestamp: '2022-11-08 22:18:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/LIS.cpp
layout: document
redirect_from:
- /library/lib/dp/LIS.cpp
- /library/lib/dp/LIS.cpp.html
title: lib/dp/LIS.cpp
---