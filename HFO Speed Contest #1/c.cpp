#include <bits/stdc++.h>


using namespace std;

int T;

pair<int,int>f(long long x)
{
  int minn=10;
  int maxx=0;
  while(x > 0)
  {
	int q=x%10;
	if(q > maxx)maxx = q;
	if(q < minn)minn = q;
	x/=10;
  }
  return {minn,maxx};
}

int main(){
ios_base::sync_with_stdio(0);
cin>>T;
while(T--)
{
  long long a,b;
  cin >> a >> b;
  for(int i = 1; i < b; i++)
  {
	  pair<int,int>el = f(a);
    if(el.first == 0)break;
    a = a + el.first * el.second;
  }
  cout << a << endl;
}

return 0;
}
