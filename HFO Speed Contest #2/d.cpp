#include <bits/stdc++.h>

using namespace std;

int check(int a,int b,int c)
{
  if(a + b <= c)return 0;
  if(a + c <= b)return 0;
  if(b + c <= a)return 0;
  return 1;
}

void f(int &n)
{
  int cnt = 0;
  for(int i = 1; i <= n; i++)
  {
	 for(int j = i; j <= n; j++)
	 {
	  int k = (i ^ j);
	  if(check(i,j,k) && i <= j && j <= k && i <= k && k <= n)
	  {
		cnt++;
	  }
   }
  }
  cout << cnt << endl;
}

int main(){
ios_base::sync_with_stdio(0);
int T;
T = 1;
while(T--)
{
  int n;
  cin>>n;
  f(n);
}

return 0;
}
