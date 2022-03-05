#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> data(n, vector<int>(3));

  for(auto &vec: data)
    for(auto &x: vec) cin >> x;

  int maxx =-1;

  for(int i =1; i<=3; i++){
    int sum = 0;
    vector<int> simul(4);
    simul[i] = 1;

    for(int j = 0; j <n; ++j){
      swap(simul[data[j][0]],simul[data[j][1]]);
      sum+= simul[data[j][2]];
    }

    maxx = max(maxx, sum);
  }

  cout << maxx << endl;
  return 0;
}