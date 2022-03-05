#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n , k;
  cin >> n  >> k;

  vector<int> elems(n);

  for(auto &x: elems) cin >> x;

  sort(elems.begin(),elems.end());

  int sol =0;

  for(int i = 0; i < n; ++i)
    for(int j = i; j< n; ++j)
      if(elems[j]- elems[i] <= k) sol = max(sol, j - i + 1);

  cout << sol << endl;
  return 0;
}