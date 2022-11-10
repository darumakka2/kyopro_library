---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/string/calc-next.hpp\"\n\n// \u6587\u5B57\u5217 s \u306B\
    \u304A\u3044\u3066\u3001\u3042\u308B\u5730\u70B9\u304B\u3089\u3042\u308B\u6587\
    \u5B57\u304C\u6B21\u306B\u3069\u306E\u5730\u70B9\u306B\u51FA\u3066\u304F\u308B\
    \u304B\u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(|S|)\nvector<vector<int>>\
    \ calc_next(const string &s) {\n    int n = (int) s.size();\n\n    vector<vector<int>>\
    \ res(n + 1, vector<int>(26, n));\n\n    for(int i = n - 1; i >= 0; i--){\n  \
    \      res[i] = res[i + 1];\n        res[i][s[i] - 'a'] = i;\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n// \u6587\u5B57\u5217 s \u306B\u304A\u3044\u3066\u3001\u3042\
    \u308B\u5730\u70B9\u304B\u3089\u3042\u308B\u6587\u5B57\u304C\u6B21\u306B\u3069\
    \u306E\u5730\u70B9\u306B\u51FA\u3066\u304F\u308B\u304B\u3092\u8A08\u7B97\u3057\
    \u307E\u3059\u3002: O(|S|)\nvector<vector<int>> calc_next(const string &s) {\n\
    \    int n = (int) s.size();\n\n    vector<vector<int>> res(n + 1, vector<int>(26,\
    \ n));\n\n    for(int i = n - 1; i >= 0; i--){\n        res[i] = res[i + 1];\n\
    \        res[i][s[i] - 'a'] = i;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/calc-next.hpp
  requiredBy: []
  timestamp: '2022-11-10 08:53:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/calc-next.hpp
layout: document
redirect_from:
- /library/lib/string/calc-next.hpp
- /library/lib/string/calc-next.hpp.html
title: lib/string/calc-next.hpp
---