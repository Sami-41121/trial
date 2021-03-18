#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define endl "\n"
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;

bool sortbysecc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

const int MX = 2e5+5;
int d1[MX], d2[MX];

int manacher(string s){
    int ans=0;
    for(int i=0,l=0,r=-1; i<s.size(); i++){
        int k = (i>r) ? 1 : min(d1[l+r-i], r-i+1);
        while(0<=i-k && i+k<s.size() && s[i-k]==s[i+k])
            k++;
        d1[i]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
        ans+=d1[i];
    }
    for(int i=0,l=0,r=-1; i<s.size(); i++){
        int k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(0<=i-k-1 && i+k<s.size() && s[i-k-1]==s[i+k])
            k++;
        d2[i]=k--;
        if(i+k>r){
            l=i-k-1;
            r=i+k;
        }
        ans+=d2[i];
    }
    return ans;
}

int main()
{
    fastio;
    ll tc=1,k, i, j, f, caseno=1;
    // cin>>tc;
    string t, s="";
    while(tc--){
        cin>>k>>t;
        for(char c: t){
            if(c == '-') s.pop_back();
            else s+=c;
            // memset(p, 0, sizeof p);
            cout<<manacher(s)<<" ";
        }
    } 
}
