#include<bits/stdc++.h>
using namespace std;
/*#include <atcoder/all>
using namespace atcoder;
*/

// loop
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)

// Type aliases
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//vector<vector<int>> P(3, vector<int>(4));

// x:コンテナ
#define ALL(x) x.begin(),x.end() //sort(ALL(x))　昇順ソート
#define RALL(x) x.rbegin(),x.rend() //sort(RALL(x)) 降順ソート
#define SIZE(x) ll(x.size()) // 要素数

// const
const int MOD = 1000000007;
#define yes "Yes"
#define no "No"

//library
// int 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
priority_queue<int, vector<int>, greater<int>> Q1;
priority_queue<int, vector<int>, less<int>> Q2;
template <typename T>
bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <typename T> 
bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }

const int dy[4] = { 0, 1, -1, 0 };
const int dx[4] = { 1, 0, 0, -1 };

// pow関数(返り値整数値ver)
ll pow_ll(ll n, ll cnt){
	ll ans=1;
	while(cnt){
		ans*=n;
		--cnt;
	}
	return ans;
}

// pow関数(返り値整数値verMOD)
ll pow_mod(ll n, ll cnt, ll mod){
	ll ans=1;
	while(cnt>0){
		if(cnt&1) ans=ans*n%mod;
		n=n*n%mod;
		cnt>>=1;
	}
	return ans;
}

ll fact[200009];
// n!の除算(mod)
ll Division(ll a,ll b, ll m){
	return (a*pow_mod(b,m-2,m))%m;
}


ll nCr(ll n, ll r){
	return Division(fact[n], fact[r]*fact[n-r]%MOD,MOD);
}


//エラトステネスの篩
vector<bool> Era(int n){
	vector<bool> isprime(n+1,true);
	isprime[1]=false; // 1は予めふるい落とす
	for(int p=2;p<=n;p++){
		if(!isprime[p]) continue;
		for(int q=p*2;q<=n;q+=p){
			isprime[q]=false;
		}
	}
	return isprime;
}

//約数列挙
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

//素因数分解
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


//座標圧縮(一次元)
vector<int> compress(vector<int> &X){
    vector<int> vals = X;
    vector<int> res(X.size());
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        res[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return res; //圧縮結果を返す
}


//UnionFind
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

vector<vector<ll>> comb(ll n, ll r) {
  vector<vector<ll>> v(n + 1,vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main(){
  //処理を書いていく
}


