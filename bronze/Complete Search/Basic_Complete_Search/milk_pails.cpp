#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;

  cin >> x >> y >> m;

  int n_x = m/x;
  int n_y = m/y;

  int sol = 0;
  for(int i = 0; i<= n_x; i++){
    for(int j  = 0; j <= n_y; j++){
      int candidate = i*x + j*y;
      if(candidate <= m) sol = max( sol, candidate);
    }
  }

  cout << sol << endl;
  return 0;
}