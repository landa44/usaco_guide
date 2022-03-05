#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
  int n =100;

  vector<int> capacity(3);
  vector<int> amount(3);

  for(int i= 0; i< 3; ++i) cin >> capacity[i] >> amount[i];

  int i = 0;
  while(n--){
    int aux = min(amount[(i+1)%4]+ amount[i], capacity[(i+1)%3]);
    amount[i]-= (aux - amount[(i+1)%3]);
    amount[(i+1)%3] = aux;

    i = (i+1)%3;
  }

  for(auto x: amount) cout << x << endl;
  return 0;
}