/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, ll> umapii;
typedef unordered_map<ll, bool> umapib;
typedef unordered_map<string, ll> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, ll> mapsi;
typedef map<pair<ll, ll>, ll> mappiii;
typedef map<ll, ll> mapii;
typedef pair<ll, ll> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<ll> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


// ax+by = gcd(a,b)
ll exgcd(ll a, ll b, ll &x, ll &y){
    if (a==0)
    {
        x = 0;
        y = 1;
        
        return b;
    }

    ll x1, y1;
    ll ans = exgcd(b%a, a, x1, y1);

    x = y1-(ll)(b/a)*x1;
    y = x1;

    return ans;
}

ll inv(ll a){
    ll x,y;
    exgcd(a,MOD,x,y);
    return (x+MOD)%MOD;
}

ll comb(ll n, ll k)  
{  
    ll res = 1;  
  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (ll i = 0; i < k; ++i)  
    {  
        res = (res%MOD)*((n - i)%MOD);
        res = res%MOD ;
        // cout<<"i+1: "<<i+1<<" INV: "<<inv(i+1)<<endl;
        res = res * (inv((i + 1)%MOD)%MOD);  
        res = res%MOD ;

    }  
  
    return res%MOD;  
}


ll powerMod(ll x, ll n){
    if(n == 0) return 1;
    else if(n == 1) return x%MOD;
    
    ll y;
    if(n%2 == 0){
        y = powerMod(x, n/2);
        return (y*y)%MOD;
    }
    else{
        y = powerMod(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

ll getLeft(ll n){
    ll height = log2(n);
    ll maxLast = powerMod(2, height);
    ll currLast = n-(maxLast-1);

    if (currLast<=maxLast/2)
    {
        return (powerMod(2,height)-1-(maxLast/2 - currLast));
    }else{
        return powerMod(2,height)-1;
    }
}


int Solution::solve(int n) {
    if (n==0 || n==1)
    {
        return 1;
    }

    ll l = getLeft(n);
    ll ans = 0;
    ans+=comb(n-1, l)%MOD;
    ans = ((ans%MOD)*((solve(l))%MOD))%MOD;
    ans = ((ans%MOD)*((solve(n-1-l))%MOD))%MOD;

    return (int)(ans%MOD);
}
