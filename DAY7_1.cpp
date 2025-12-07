typedef long long ll;

#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>

using namespace std;


/*
Let's moose it
*/

void print(vector<ll>& vec){
    for(auto val: vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

void print(vector<string>& vec){
    for(auto val: vec){
        cout<<val<<endl;
    }
    cout<<endl;
}

void print(vector<vector<ll>>& vec){
    for(auto val: vec){
        for(auto v: val){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print(pair<ll,ll>& p){
    cout<<"("<<p.first<<","<<p.second<<") "<<endl;
}

void print(map<ll,ll>& hmap){
    for(auto val: hmap){
        cout<<"("<<val.first<<","<<val.second<<") ";
    }
    cout<<endl;
}

void print(vector<pair<ll,ll>>& vec){
    for(auto val: vec){
        cout<<"("<<val.first<<","<<val.second<<") ";
    }
    cout<<endl;
}

const int N=1e6+5;     
const int MOD=1e9+7;   

ll fact[N], inv_fact[N];

ll mod_pow(ll a, ll b, ll mod) {
    ll res =1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute_factorials(int n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % mod;

    // Fermat's little theorem: a^(-1) ≡ a^(mod-2) % mod
    inv_fact[n] = mod_pow(fact[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

ll nCr(int n, int r, int mod) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

ll floor_log2(ll x){
    return  (64-__builtin_clzll(x)-1);
}

vector<string> split(string& str,char c=' '){
    vector<string> vec;
    string temp;
    for(ll i=0;i<str.size();i++){
        if(str[i]==c){
            vec.push_back(temp);
            temp="";
            continue;
        }
        temp.push_back(str[i]);
    }
    if(temp.size()) vec.push_back(temp);
    return vec;
}

ll getAns(vector<ll>& vec,ll n){
    ll ans=0;
    return ans;
}

ll dfs(ll r,ll c,vector<string>& vec,vector<vector<ll>>& vis){
    if(r==vec.size() || r<0 || c<0 || c==vec[0].size() || vis[r][c]) return 0;

    vis[r][c]=1;

    ll ans=0;
    if(vec[r][c]=='.' || vec[r][c]=='S') ans+=dfs(r+1,c,vec,vis);
    else{
        ans+=dfs(r+1,c-1,vec,vis);
        ans+=dfs(r+1,c+1,vec,vis);
        ans++;
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(false); // Fast IO
    cin.tie(NULL);
    
    string str;
    vector<string> vec;
    while(cin>>str){
       vec.push_back(str); 
    }
    ll n=vec.size();
    ll m=vec[0].size();
    vector<vector<ll>> vis(n,vector<ll>(m,0));
    
    ll r=0,c=-1;
    for(ll j=0;j<m;j++) {if(vec[0][j]=='S'){c=j; break;} }

    ll ans=dfs(r,c,vec,vis);

    cout<<ans<<endl;
    
    return 0;
}

        