#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int n , k;
  cin >> k >> n;

  vector<vector<int>> sessions(k, vector<int>(n));

  for(auto &s: sessions){
    for(int i =0; i< n; ++i){
      int x;
      cin >> x;
      s[x-1]=i;
    }
  }

  int sol =0;

  for(int i =0; i < n; i++){
    for(int j = i+1; j< n; j++){
      int cowi =0;
      int cowj =0;

      for(int m = 0; m < k; m++){
        if(sessions[m][i] > sessions[m][j]) cowi++;
        if(sessions[m][j] > sessions[m][i]) cowj++;
      }

      if(cowi == k or cowj == k)  sol++;
      
    }
  }


  cout << sol << endl;
  return 0;
}