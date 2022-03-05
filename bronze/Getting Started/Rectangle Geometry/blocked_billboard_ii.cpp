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

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);

  vector<rectangle> recs(2);

  for(auto &r : recs) cin >> r.p1.x >> r.p1.y >> r.p2.x >> r.p2.y;

  rectangle inter = recs[0].intersection(recs[1]);

  if( (inter.p2.x - inter.p1.x == recs[0].p2.x - recs[0].p1.x and (inter.p1.y == recs[0].p1.y or inter.p2.y == recs[0].p2.y)) or
      (inter.p2.y - inter.p1.y == recs[0].p2.y - recs[0].p1.y and (inter.p1.x == recs[0].p1.x or inter.p2.x == recs[0].p2.x)) )
    cout << recs[0].area() - inter.area() << endl;
  else 
    cout << recs[0].area() << endl;

  return 0;
}