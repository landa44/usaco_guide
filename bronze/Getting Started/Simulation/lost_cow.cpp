#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  int x, y;
  cin >> x >> y;

  int sol = 0;
  for(int i = 0; i <= 10; i++){
    if(i%2==1){
      if( x-(1<<i) <= y and y<=x) break;
    }
    else if(x<= y and y<= x+(1<<i)) break;
    sol+= 2*(1<<i);
  }

  cout << sol+ abs(x-y) << endl;
  return 0;
}