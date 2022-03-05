#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

void solve(){
  int W, H;
  cin >> W >> H;

  int x1, y1, x2, y2, w, h;
  cin >> x1 >> y1 >> x2 >> y2 >> w >> h;

  int mmax = -mod;

  if(h + (y2-y1) <= H){
    mmax = max(mmax, y1 - h);
    mmax = max(mmax, H - y2 - h);
  }
  if(w + (x2-x1) <= W){
    mmax = max(mmax, x1 - w);
    mmax = max(mmax, W - x2 - w);
  }

  if(mmax == -mod){
    cout << -1 << '\n';
    return;
  } 
  if(mmax >= 0){
    cout << 0.0 << '\n';
    return;
  } 
  cout << double(-mmax) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(9);

  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}