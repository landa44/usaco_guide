#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  int n, m;

  cin >> n >> m;

  vector<int> road(n);
  vector<int> limit(n);

  for(int i =0; i< n; ++i)
    cin >> road[i] >> limit[i];

  vector<int> roadb(m);
  vector<int> limitb(m);
  for(int i =0; i< m; ++i)
    cin >> roadb[i] >> limitb[i];

  int police = 0;
  int pol_count = 0;
  int bessie =0;
  int bessie_count = 0;
  int sol =0;

  for(int i = 0; i< 100; i++, pol_count++, bessie_count++){
    if(pol_count == road[police]){
      police++;
      pol_count =0;
    }

    if(bessie_count == roadb[bessie]){
      bessie++;
      bessie_count =0;
    }

    sol = max(sol, limitb[bessie]-limit[police]);
  }

  cout << sol << endl;
  return 0;
}