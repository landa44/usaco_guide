#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  int n ;
  cin >> n;

  vector<string> road(n);
  vector<int> inf(n);
  vector<int> sup(n);

  int mmax = 0;
  int mmin = 1000;

  for(int i = 0; i<n; i++){
    cin >> road[i] >> inf[i] >> sup[i];

    if(road[i] ==  "none"){
      mmin = min(mmin, sup[i]);
      mmax = max(mmax, inf[i]);
    }
    if(road[i]== "on"){
      mmin+= sup[i];
      mmax+= inf[i];
    }  
    if(road[i]== "off"){
      mmin-= inf[i];
      mmax-= sup[i];
      mmax = max(mmax, 0);
    }  
  }

  int mmin1 = 1000;
  int mmax1 = 0;

  for(int i = n-1; i>=0; i--){
    if(road[i] ==  "none"){
      mmin1 = min(mmin1, sup[i]);
      mmax1 = max(mmax1, inf[i]);
    }
    if(road[i]== "on"){
      mmin1-= inf[i];
      mmax1-= sup[i];
      mmax1 = max(mmax1, 0);

    }  
    if(road[i]== "off"){
      mmin1+= sup[i];
      mmax1+= inf[i];
    }  
  }

  cout << mmax1 << " " << mmin1 << endl;
  cout << mmax << " " << mmin << endl;
  return 0;
}