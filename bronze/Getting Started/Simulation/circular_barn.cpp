#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  int n;
  cin>> n;

  vector<int> r(n);
  for(auto& x: r) cin >> x;

  int mmin = mod;
  for(int i =0; i< n; i++){
    int candidate = 0;
    
    for(int j = 0; j< i; ++j) candidate += (n-i + j)*r[j];
    for(int j = i+1; j < n; ++j) candidate+= (j-i)*r[j];  
    
    mmin = min(mmin, candidate);
  }

  cout << mmin << endl;
  return 0;
}