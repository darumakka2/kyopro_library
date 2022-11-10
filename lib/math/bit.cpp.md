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
  bundledCode: "#line 1 \"lib/math/bit.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n// x \u306E\u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\u3057\u307E\u3059\
    \u3002\ntemplate <typename T>\nvector<T> getSubmask(T x){\n    vector<T> submask;\n\
    \    for(T i = x; ; i = (i - 1) & x){ \n        submask.push_back(i);\n      \
    \  if(i == 0) break;\n    }\n    sort(submask.begin(), submask.end());\n    return\
    \ submask;\n}\n\n// \u914D\u5217 a \u306E xor \u57FA\u5E95\u3092\u6C42\u3081\u307E\
    \u3059\u3002\ntemplate <typename T>\npair<vector<T>, vector<T>> getBasis(vector<T>\
    \ a){\n    vector<T> basis, original;\n    for(auto x : a){\n        T y = x;\n\
    \        for(auto z : basis){\n            y = min(y, y ^ z);\n        }\n   \
    \     if(y > 0){\n            basis.push_back(y);\n            original.push_back(x);\n\
    \        }\n    }\n    return {basis, original};\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// x \u306E\u90E8\u5206\
    \u96C6\u5408\u3092\u5217\u6319\u3057\u307E\u3059\u3002\ntemplate <typename T>\n\
    vector<T> getSubmask(T x){\n    vector<T> submask;\n    for(T i = x; ; i = (i\
    \ - 1) & x){ \n        submask.push_back(i);\n        if(i == 0) break;\n    }\n\
    \    sort(submask.begin(), submask.end());\n    return submask;\n}\n\n// \u914D\
    \u5217 a \u306E xor \u57FA\u5E95\u3092\u6C42\u3081\u307E\u3059\u3002\ntemplate\
    \ <typename T>\npair<vector<T>, vector<T>> getBasis(vector<T> a){\n    vector<T>\
    \ basis, original;\n    for(auto x : a){\n        T y = x;\n        for(auto z\
    \ : basis){\n            y = min(y, y ^ z);\n        }\n        if(y > 0){\n \
    \           basis.push_back(y);\n            original.push_back(x);\n        }\n\
    \    }\n    return {basis, original};\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/bit.cpp
  requiredBy: []
  timestamp: '2022-10-19 03:16:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/bit.cpp
layout: document
redirect_from:
- /library/lib/math/bit.cpp
- /library/lib/math/bit.cpp.html
title: lib/math/bit.cpp
---