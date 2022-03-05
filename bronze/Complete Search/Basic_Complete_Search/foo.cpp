#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> arr = {1,2,3,4,5,6,7,8};
  auto foo =  lower_bound(arr.begin(), arr.end(), 1);

  cout << (foo == arr.end()) << endl;
  return 0;
}