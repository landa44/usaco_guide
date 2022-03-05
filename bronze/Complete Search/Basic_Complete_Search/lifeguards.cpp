#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> l(n);
  vector<int> r(n);
  vector<int> mask(1002);

  for(int i =0; i< n; i++){
    cin >> l[i] >> r[i];
    mask[l[i]] += 1;
    mask[r[i]] -= 1;
  }

  int sol =0;
  for(int i =0; i<n; i++){
    mask[l[i]] -= 1;
    mask[r[i]] += 1;

    int candidate = 0;
    ll sum  = 0;
    for(int j =0; j<= 1000; j++){
      sum+= mask[j];
      if(sum) candidate++;
    }

    sol = max( sol, candidate);

    mask[l[i]] += 1;
    mask[r[i]] -= 1;
  }

  cout  << sol << endl;
  return 0;
}