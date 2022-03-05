#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> shuffle(n);
  for(auto &x: shuffle) cin >> x;

  vector<int> actual(n);
  for(auto &x: actual) cin >>x;


  for(int j =0; j<3; ++j){
    vector<int> before(n);
    for(int i = 0; i < n; ++ i){
      before[i] = actual[shuffle[i]-1];
    }
    actual = before;
  }

  for(auto x : actual) cout << x << "\n";

  return 0;
}