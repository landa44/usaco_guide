#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n; 
  cin >> n;

  vector<int> buckets(1004);

  while(n--){
    int s,t,b;
    cin >> s >> t >> b;
    buckets[s]+=b;
    buckets[t+1]+=-b;
  }

  partial_sum(buckets.begin(), buckets.end(), buckets.begin());
  int mmax = 0;
  for(auto x: buckets) mmax = max(mmax, x);

  cout << mmax << endl;
  return 0;
}