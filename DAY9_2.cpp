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


bool rectanglePossible(ll x1,ll y1,ll x2,ll y2,ll i,ll j,vector<vector<ll>>& vec){
    if(y1<y2){
        ll topLeft=vec[i][1];
        ll bttmRight=vec[j][3];
        if(topLeft<y2 || bttmRight>y1) return false;
    }
    else{
        ll topRight=vec[j][0];
        ll bttmLeft=vec[i][2];
        if(topRight<y1 || bttmLeft>y2) return false;
    
    }

    return true;
}


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

    sort(vec.begin(),vec.end());

    vector<vector<ll>> rE(n,vector<ll>(4));
    /*
    rE -> relativeExtremum
    rE[i][0] -> topRight
    rE[i][1] -> topLeft
    rE[i][2] -> bttmLeft
    re[i][3] -> bttmRight
    */


    for(ll i=0;i<n;i++){
        rE[i][0]=rE[i][1]=rE[i][2]=rE[i][3]=vec[i].second;
        for(ll j=0;j<n;j++){
            if(vec[j].first<=vec[i].first){
                rE[i][1]=max(rE[i][1],vec[j].second);
                rE[i][2]=min(rE[i][2],vec[j].second);
            }
            if(vec[j].first>=vec[i].first){
                rE[i][0]=max(rE[i][0],vec[j].second);
                rE[i][3]=min(rE[i][3],vec[j].second);
            }
            
        }
    }
    
    // print(vec);
    // cout<<endl;
    // print(rE);

    // pair<ll,ll>& p1=vec[0];
    // pair<ll,ll>& p2=vec[4];
    // print(p1);
    // print(p2);

    // if(rectanglePossible(p1.first,p1.second,p2.first,p2.second,0,4,rE) || (p1.first==p2.first) || (p1.second==p2.second)){
    //     cout<<"possible";
    // }



    ll ans=0;
    for(ll i=0;i<n;i++){
        pair<ll,ll>& p1=vec[i];
        for(ll j=i+1;j<n;j++){
            pair<ll,ll>& p2=vec[j];
            if(rectanglePossible(p1.first,p1.second,p2.first,p2.second,i,j,rE) || (p1.first==p2.first) || (p1.second==p2.second)){
                ll x=abs(p1.first-p2.first)+1;
                ll y=abs(p1.second-p2.second)+1;
                
                ans=max(ans,x*y);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

        