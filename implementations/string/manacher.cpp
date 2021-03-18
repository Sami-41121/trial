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
int p[MX];

string process(string &s){
    string ret = "$#";
    for(auto c: s){
        ret+=c;
        ret+='#';
    }
    ret+='@';
    return ret;
}
void manacher(string s){
    s = process(s);
    int  c=0, r=0;
    for(int i=1; i<s.size()-1; i++) {
        int mirror = c+c-i;
        if(i<r) p[i] = min(p[mirror], r-i);
        while(s[i+1+p[i]]==s[i-1-p[i]])
            p[i]++;
        if(i+p[i]>r){
            c=i;
            r=i+p[i];
        }
    }
}

int main()
{
    fastio;
    ll tc=1,k, i, j, f, caseno=1;
    // cin>>tc;
    string s;
    while(tc--){
        cin>>k>>s;
        manacher(s);
        int ans=0;
        for(i=0;i<2*k+3;i++){
            ans=max(ans,p[i]);
        }
        cout<<ans<<endl;
    } 
}
