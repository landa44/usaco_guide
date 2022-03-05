#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> s(n);
  vector<int> t(n);
  vector<int> b(n);
  for(int i = 0; i< n; ++i) cin >> s[i] >> t[i] >> b[i];

  int sol =0;

  for(int j =0; j<=1000; ++j){
    int curr=0;
    for(int i =0; i<n; ++i)
      if(s[i]<=j and t[i]>= j) curr+= b[i];
    
    sol = max(sol, curr);
  }

  cout << sol << endl;
  return 0;
}