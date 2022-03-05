#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  int n ;
  cin >> n;

  vector<int> x(n);
  vector<int> y(n);

  map<int, vector<int>> mapx;
  map<int, vector<int>> mapy;

  for(int i =0; i< n; i++){
    cin >> x[i] >> y[i];

    mapx[x[i]].push_back(y[i]);
    mapy[y[i]].push_back(x[i]);
  }

  int sol =0;

  for(int i =0; i < n; i++)
    for(auto y1: mapx[x[i]])
      for(auto x1: mapy[y1])
        sol = max(sol, abs(x[i]-x1)* abs(y[i]-y1));

  cout << sol << endl;
  return 0;
}