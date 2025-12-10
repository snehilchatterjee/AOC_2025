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

ll getMin(ll idx,ll val,vector<vector<ll>>& switches,vector<vector<ll>>& dp){
    if(idx==switches.size()){
        if(val==0) return 0;
        else return 1e9;
    }

    if(dp[idx][val]!=-1) return dp[idx][val];

    ll pickVal=val;
    for(ll i=0;i<switches[idx].size();i++){
        pickVal^=(1LL<<switches[idx][i]);
    }

    ll pick=getMin(idx+1,pickVal,switches,dp)+1;
    ll noPick=getMin(idx+1,val,switches,dp);

    return dp[idx][val]=min(pick,noPick);

}

ll sol(vector<vector<ll>>& switches,ll target){
    ll n=switches.size();

    vector<vector<ll>> dp(n,vector<ll>(1024,-1));

    return getMin(0,target,switches,dp);
}


int main() {
    ios::sync_with_stdio(false); // Fast IO
    cin.tie(NULL);
    
    string str;
    ll ans=0;
    
    while(getline(cin,str)){
        vector<string> tempVec=split(str,' ');
        ll target=constructNumber(tempVec[0]);
        
        vector<vector<ll>> switches(tempVec.size()-2);
        for(ll i=1;i<tempVec.size()-1;i++){
            string tempStr=string(tempVec[i].begin()+1,tempVec[i].end()-1);
            vector<string> tempVec2=split(tempStr,',');   
            for(auto s: tempVec2) switches[i-1].push_back(stoll(s));     
        }

        ans+=sol(switches,target);
    }

    cout<<ans<<endl;


    return 0;
}

        