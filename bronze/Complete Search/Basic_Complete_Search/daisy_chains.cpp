#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vector<int> elems(n+1);
  vector<int> acum(n+1);

  for(int i = 1; i<= n; i++) {
    cin >> elems[i];
    acum[i] = elems[i];
  }

  partial_sum(acum.begin(), acum.end(), acum.begin());

  int sol  = 0;

  for(int i =1; i <=n; i++){
    for(int j = i; j<=n; j++){
      for(int k = i; k<=j; k++){
        if( (acum[j]- acum[i-1]) == elems[k]*(j-i+1)){        
          sol++;
          break;
        }
      }
    }
  }

  cout << sol << endl;
  return 0;
}