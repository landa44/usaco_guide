#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

struct point{
  int x, y;

  point(){}

  point(int& a, int& b){
    x=a;
    y=b;
  }
};

struct rectangle{
  point p1, p2;

  ll area(){
    if( p2.x- p1.x < 0 or p2.y - p1.y < 0) return 0;
    return 1LL*(p2.x- p1.x)*(p2.y - p1.y);
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

  vector<rectangle> rect(3);
  for(auto &r: rect) cin >> r.p1.x >> r.p1.y >> r.p2.x >> r.p2.y;

  rectangle inter1 = rect[0].intersection(rect[1]);
  rectangle inter2 = rect[0].intersection(rect[2]);

  if(rect[0].area() - (inter1.area() + inter2.area() - inter1.intersection(inter2).area()))
    cout << "YES\n";
  else cout << "NO\n";
  return 0;
}