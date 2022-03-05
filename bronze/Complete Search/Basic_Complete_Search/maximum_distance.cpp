#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  
  vector<ll> x(n);
  vector<ll> y(n);

  for(auto &a : x) cin>> a;
  for(auto &a: y) cin >> a;

  ll sol =0;
  for(int i =0; i < n; i++){
    for(int j =i+1; j< n; j++ ){
      sol = max(sol, (x[i]- x[j])*(x[i]- x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    }
  }

  cout << sol << endl;
  return 0;
}