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

#define MAX 100000
int failure[MAX];

void build_failure_function(string pattern) {
  failure[0] = failure[1] = 0; //base case
  
  for(int i = 2; i <= pattern.size(); i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) { 
        failure[i] = j + 1; 
        break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { 
          failure[i] = 0; 
          break; 
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }   
}

int kmp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  int ans=0;
  build_failure_function(pattern); 

  int i = 0; // the initial state of the automaton is
         // the empty string

  int j = 0; // the first character of the text
  
  while(true) {
    if(j == n) {
        break; //reached the end of the text
    }

    // character matched
    if(text[j] == pattern[i]) {
        i++; // change the state of the automaton
        j++; // get the next character from the text
        if(i == m) {
            ans++;
            i=failure[i];
        }
    } else {
        if (i == 0) {
            // if we reached the empty string and failed to
            // "expand" even it; we go to the next 
            // character from the text, the state of the
            // automaton remains zero
            j++;
        }
        else {
             //we try to "expand" the next best (largest) match
            i = failure[i];
        }
    }
  }
  return ans;
}

int main()
{
    fastio;
    ll tc=1,k, i, j, f, caseno=1;
    cin>>tc;
    while(tc--){
        string a, b;
        cin>>a>>b;
        cout<<"Case "<<caseno++<<": "<<kmp(a, b)<<endl;
    } 
}
