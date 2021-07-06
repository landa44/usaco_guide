#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

struct point{
  int x;
  int y;
};

struct rectangle{
  point p1;
  point p2;

  int area(){
    if( p2.x- p1.x < 0 or p2.y - p1.y < 0) return 0;
    return (p2.x- p1.x)*(p2.y - p1.y);
  }

  bool contain( point p){
    return (p1.x <= p.x and p.x <= p2.x and p1.y <= p.y and p.y <= p2.y);
  }

  bool contain(rectangle r){
    return contain(r.p1) and contain(r.p2);
  }

  rectangle intersection(rectangle r){
    rectangle inter;
    inter.p1.x = max(p1.x, r.p1.x);
    inter.p1.y = max(p1.y, r.p1.y);
    inter.p2.x = min(p2.x, r.p2.x);
    inter.p2.y = min(p2.y, r.p2.y);
    return inter;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);

  vector<rectangle> recs(2);

  for(auto &r : recs) cin >> r.p1.x >> r.p1.y >> r.p2.x >> r.p2.y;

  rectangle join;
  join.p1.x = min(recs[0].p1.x, recs[1].p1.x);
  join.p1.y = min(recs[0].p1.y, recs[1].p1.y);
  join.p2.x = max(recs[0].p2.x, recs[1].p2.x);
  join.p2.y = max(recs[0].p2.y, recs[1].p2.y);
  
  int a = max(join.p2.x - join.p1.x, join.p2.y - join.p1.y);
  cout << a*a << endl;
  return 0;
}