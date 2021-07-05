#include<bits/stdc++.h>

using namespace std;

int main(){
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if((a<= c and b>= c) or (c<=a and d>= a))
    cout << (max({a, b, c, d}) - min({a, b, c, d})) << '\n';
  else
    cout << b-a + d -c << '\n';
  return 0;
}