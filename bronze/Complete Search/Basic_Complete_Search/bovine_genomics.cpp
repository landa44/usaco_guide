#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >>m;

  vector<string> spotty(n);
  vector<string> plain(n);

  for(auto& s: spotty) cin >> s;
  for(auto& s: plain) cin >> s;

  int sol =0;
  for(int i =0; i< m; i++){
    set<char> spot;

    for(int j = 0; j < n; j++)
      spot.insert(spotty[j][i]);

    bool potential= true;
    for(int j =0; j< n; j++)
      if(spot.count(plain[j][i])) potential = false;

    if(potential) sol++;
  }

  cout << sol << endl;
  return 0;
}