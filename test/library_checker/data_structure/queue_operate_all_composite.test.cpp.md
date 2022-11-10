---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/swag.hpp
    title: lib/data_structure/swag.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: lib/math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/data_structure/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/modint.hpp\"\
    \n\ntemplate <long long Modulus>\nstruct ModInt{\n    long long val;\n    constexpr\
    \ ModInt(const long long &_val = 0) noexcept : val(_val) {\n        normalize();\n\
    \    }\n    void normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n\
    \    }\n    inline ModInt& operator+=(const ModInt& rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n\
    \    inline ModInt& operator-=(const ModInt& rhs) noexcept {\n        if(val -=\
    \ rhs.val, val < 0) val += Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt& operator*=(const ModInt& rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt& operator/=(const\
    \ ModInt& rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus;\n \
    \       return *this;\n    }\n    inline ModInt& operator++() noexcept {\n   \
    \     if(++val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n        if(++val\
    \ >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline ModInt& operator--()\
    \ noexcept {\n        if(--val < 0) val += Modulus;\n        return *this;\n \
    \   }\n    inline ModInt operator--(int) noexcept {\n        ModInt t = val;\n\
    \        if(--val < 0) val += Modulus;\n        return t;\n    }\n    inline ModInt\
    \ operator-() const noexcept { return (Modulus - val) % Modulus; }\n    inline\
    \ ModInt inv(void) const { return inv(val); }\n    ModInt inv(const long long&\
    \ n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n        while(b){\n\
    \            long long t = a / b;\n            a -= t * b; swap(a, b);\n     \
    \       u -= t * v; swap(u, v);\n        }\n        u %= Modulus;\n        if(u\
    \ < 0) u += Modulus;\n        return u;\n    }\n    friend inline ModInt operator+(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }\n  \
    \  friend inline ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ inline ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return lhs.val == rhs.val; }\n    friend inline\
    \ bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.val\
    \ != rhs.val; }\n    friend inline istream& operator>>(istream& is, ModInt& x)\
    \ noexcept {\n        is >> x.val;\n        x.normalize();\n        return is;\n\
    \    }\n    friend inline ostream& operator<<(ostream& os, const ModInt& x) noexcept\
    \ { return os << x.val; }\n};\n#line 2 \"lib/data_structure/swag.hpp\"\n\n/* \n\
    \    SWAG<T>(op) : SWAG \u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\n    fold()\
    \ : \u8981\u7D20\u5168\u3066\u306B op \u3092\u9069\u7528\u3055\u305B\u305F\u5024\
    \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(1)\n    push(x) : x \u3092\u672B\
    \u5C3E\u306B\u8FFD\u52A0\u3057\u307E\u3059\u3002: O(1)\n    pop() : x \u3092\u5148\
    \u982D\u304B\u3089\u524A\u9664\u3057\u307E\u3059\u3002: \u511F\u5374 O(1)\n*/\n\
    \ntemplate <typename T>\nstruct SWAG{\n    using Op = function<T(T, T)>;\n\nprivate:\n\
    \    struct node{\n    public:\n        T val, sum;\n        node(const T &val,\
    \ const T &sum) : val(val), sum(sum) {}\n    };\n\n    Op op;\n    stack<node>\
    \ front_stack, back_stack;\n\npublic:\n    SWAG(const Op &op = Op()) : op(op),\
    \ front_stack(), back_stack() {}\n\n    bool empty(){\n        return front_stack.empty()\
    \ && back_stack.empty();\n    }\n\n    size_t size(){\n        return front_stack.size()\
    \ + back_stack.size();\n    }\n\n    T fold(){\n        if(front_stack.empty()){\n\
    \            return back_stack.top().sum;\n        }else if(back_stack.empty()){\n\
    \            return front_stack.top().sum;\n        }else{\n            return\
    \ op(front_stack.top().sum, back_stack.top().sum);\n        }\n    }\n\n    void\
    \ push(const T &x){\n        if(back_stack.empty()){\n            back_stack.emplace(x,\
    \ x);\n        }else{\n            T s = op(back_stack.top().sum, x);\n      \
    \      back_stack.emplace(x, s);\n        }\n    }\n\n    void pop(){\n      \
    \  if(front_stack.empty()){\n            front_stack.emplace(back_stack.top().val,\
    \ back_stack.top().val);\n            back_stack.pop();\n            while(!back_stack.empty()){\n\
    \                T s = op(back_stack.top().val, front_stack.top().sum);\n    \
    \            front_stack.emplace(back_stack.top().val, s);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n};\n#line 7 \"test/library_checker/data_structure/queue_operate_all_composite.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    using T = pair<mint, mint>;\n    auto op\
    \ = [](T x1, T x2) -> T { \n        return {x1.first * x2.first, x2.first * x1.second\
    \ + x2.second};\n    };\n    SWAG<T> swag(op);\n\n    int q; cin >> q;\n    while(q--){\n\
    \        int t; cin >> t;\n        if(t == 0){\n            long long a, b; cin\
    \ >> a >> b;\n            swag.push({a, b});\n        }else if(t == 1){\n    \
    \        swag.pop();\n        }else{\n            long long x; cin >> x;\n   \
    \         if(swag.size() == 0){\n                cout << x << \"\\n\";\n     \
    \           continue;\n            }\n            T k = swag.fold();\n       \
    \     mint ans = k.first * x + k.second;\n            cout << ans << \"\\n\";\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/modint.hpp\"\
    \n#include \"../../../lib/data_structure/swag.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n   \
    \ using T = pair<mint, mint>;\n    auto op = [](T x1, T x2) -> T { \n        return\
    \ {x1.first * x2.first, x2.first * x1.second + x2.second};\n    };\n    SWAG<T>\
    \ swag(op);\n\n    int q; cin >> q;\n    while(q--){\n        int t; cin >> t;\n\
    \        if(t == 0){\n            long long a, b; cin >> a >> b;\n           \
    \ swag.push({a, b});\n        }else if(t == 1){\n            swag.pop();\n   \
    \     }else{\n            long long x; cin >> x;\n            if(swag.size() ==\
    \ 0){\n                cout << x << \"\\n\";\n                continue;\n    \
    \        }\n            T k = swag.fold();\n            mint ans = k.first * x\
    \ + k.second;\n            cout << ans << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/math/modint.hpp
  - lib/data_structure/swag.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-11-10 02:54:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/queue_operate_all_composite.test.cpp
- /verify/test/library_checker/data_structure/queue_operate_all_composite.test.cpp.html
title: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
---