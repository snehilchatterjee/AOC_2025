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
        cout<<val<<" "<<endl;
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

void print(map<string,vector<string>>& hmap){
    for(auto p: hmap){
        cout<<p.first<<": ";
        for(auto v: p.second){
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

ll constructNumber(string str){
    ll num=0;
    for(ll i=1;i<str.size()-1;i++){
        if(str[i]=='#'){
            num|=(1LL<<(i-1));
        }
    }
    return num;
}

ll dfs(string node,map<string,vector<string>>& adj,map<string,ll>& dp){
    if(node.compare("out")==0) return 1;

    if(dp[node]!=-1) return dp[node];

    ll paths=0;
    for(auto nextNode: adj[node]){
        paths+=dfs(nextNode,adj,dp);
    }

    return paths;

}

int main() {
    ios::sync_with_stdio(false); // Fast IO
    cin.tie(NULL);
    
    string str;
    ll ans=0;

    map<string,vector<string>> hmap;
    map<string,ll> dp;
    
    while(getline(cin,str)){
        vector<string> tempVec=split(str,' ');
        string src=string(tempVec[0].begin(),tempVec[0].end()-1);
        dp[src]=-1;
        for(ll i=1;i<tempVec.size();i++){
            hmap[src].push_back(tempVec[i]);
        }
    }

    ans=dfs("you",hmap,dp);
    cout<<ans<<endl;

    return 0;
}

        