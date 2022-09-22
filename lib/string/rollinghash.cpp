#include <bits/stdc++.h>

using namespace std;

/* 
    RollingHash(s, base) : 文字列 s についてのハッシュテーブルを構築します。O(n)
    get(l, r) : [l, r) のハッシュ値を取得します。O(1) 
    connect(h1, h2, h2len) : ハッシュ値 h1 と長さ h2len のハッシュ値 h2 を結合します。
    LCP(b, l1, r1, l2, r2) 区間 [l1, r1) と ハッシュテーブルが b となる区間 [l2, r2) の文字列の最長接頭辞を求めます。 O(logN)
*/
struct RollingHash{
    vector<unsigned long> hashed, power;
    static constexpr unsigned long mod = (1uL << 61) - 1;
	
    unsigned long mul(__int128_t a, __int128_t b) const {
		__int128_t t = a * b;
		t = (t >> 61) + (t & mod);
		
		if(t >= mod) return t - mod;
		return t;
	}

    RollingHash(const string &s, unsigned base = 10007){
        int siz = (int) s.size();
        hashed.assign(siz + 1, 0);
        power.assign(siz + 1, 0);
        power[0] = 1;
        for(int i = 0; i < siz; i++){
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned long get(int l, int r) const {
        unsigned long ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if(ret >= mod) ret -= mod;
        return ret;
    }

    unsigned long connect(unsigned h1, int h2, int h2len) const {
        unsigned long ret = mul(h1, power[h2len]) + h2;
        if(ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash &b, int l1, int r1, int l2, int r2){
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1){
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};

// example(ABC141E)
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    RollingHash rh(s);
    for(int l1 = 0; l1 < n; l1++){
        for(int l2 = l1 + 1; l2 < n; l2++){
            while(l1 + ans < l2 && l2 + ans < n){
                if(rh.get(l1, l1 + ans + 1) == rh.get(l2, l2 + ans + 1)){
                    ans++;
                }else{
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}