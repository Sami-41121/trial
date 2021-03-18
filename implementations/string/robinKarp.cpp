/*    Mohammed Sami Khan
      মোহাম্মদ সামী খান
*/
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

set<pair<ll, ll>> generateHash(ll m, string s) {
	ll p1 = 27, p2 = 31;
	ll m1 = 1e9 + 7, m2 = 1e9 + 9;
	ll hash1=0, hash2=0, pow1=1, pow2=1, i;
	for(i=m-1; i>=0; i--){
		hash1 = (hash1 + ((s[i]-'a'+1)*pow1)%m1)%m1;
		hash2 = (hash2 + ((s[i]-'a'+1)*pow2)%m2)%m2;
		if(i){
			pow1 = (pow1*p1)%m1;
			pow2 = (pow2*p2)%m2;
		}
	}
	set<pair<ll, ll>> ans;
	ans.insert(mp(hash1, hash2));
	for(i=m; i<s.size(); i++) {
		hash1 = (hash1 - (pow1*(s[i-m]-'a'+1))%m1)%m1;
		hash1 = (hash1 + m1)%m1;
		hash1 = (hash1 * p1)%m1;
		hash1 = (hash1 + (s[i]-'a'+1))%m1;
		hash2 = (hash2 - (pow2*(s[i-m]-'a'+1))%m2)%m2;
		hash2 = (hash2 + m2)%m2;
		hash2 = (hash2 * p2)%m2;
		hash2 = (hash2 + (s[i]-'a'+1))%m2;
		ans.insert(mp(hash1, hash2));
	}
	return ans;
}


bool check(ll m, vector<string>& s){
	ll k=s.size(), i;
	bool ans=true;
	vector<set<pair<ll,ll>>> subs(k);
	for(i=0;i<k;i++){
		subs[i] = generateHash(m, s[i]);
		// cout<<m<<" "<<subs[i].size()<<endl;
	}
	for(auto p : subs[0]){
		ans=true;
		for(i=0;i<k;i++){
			if(!subs[i].count(p)){
				ans=false;
				break;
			}
		}
		if(ans) return ans;
	}
	return ans;
}

int main()
{
	fastio;
	ll tc, n, k, m, i, j, f, caseno=1;
	string t;
	cin>>tc;
	while(tc--){
		ll lo=1, hi=1e4+5, mid, ans=0;
		cin>>k;
		vector<string> s(k);
		for(i=0;i<k;i++){
			cin>>t;
			hi=min(hi, (ll)t.size());
			s[i]=t;
		}

		while(lo<=hi){
			mid=(lo+hi)/2;
			if(check(mid, s)){
				ans=mid;
				lo=mid+1;
			}
			else hi=mid-1;
		}
		cout<<ans<<endl;
	}
}
