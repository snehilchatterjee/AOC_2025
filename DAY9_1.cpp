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
        cout<<val<<" ";
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

class DSU{
    public:
    vector<ll> size;
    vector<ll> parent;
    ll components;

    DSU(ll n){
        parent.resize(n);
        size.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        components=n;
    }

    ll findUParent(ll node){
        if(parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }

    ll unify(ll node1,ll node2){
        ll parent1=findUParent(node1);
        ll parent2=findUParent(node2);

        if(parent1==parent2) return 0;

        components--;
        
        if(size[parent1]>size[parent2]){
            parent[parent2]=parent1;
            size[parent1]+=size[parent2];
        }
        else{
            parent[parent1]=parent2;
            size[parent2]+=size[parent1];
        }

        return 1;
    }

};


int main() {
    ios::sync_with_stdio(false); // Fast IO
    cin.tie(NULL);
    
    string str;
    vector<pair<ll,ll>> vec;
    while(cin>>str){
        vector<string> tempVec=split(str,',');
        vec.push_back({stoll(tempVec[0]),stoll(tempVec[1])});
    }
    ll n=vec.size();
    ll ans=0;
    for(ll i=0;i<n;i++){
        pair<ll,ll>& p1=vec[i];
        for(ll j=i+1;j<n;j++){
            pair<ll,ll>& p2=vec[j];

            ll x=abs(p1.first-p2.first+1);
            ll y=abs(p1.second-p2.second+1);
            ans=max(ans,x*y);
        }
    }

    cout<<ans<<endl;

    return 0;
}

        