#include <bits/stdc++.h>

using namespace std;


void f(int &n,int &k)
{
  multiset<int>ans;
  int prev = n;
  while(n > 0 && k > 0)
  {
   for(int i = 31; i >= 0; i--)
   {
	   if(n == 0 || k == 0)break;
	   if(n - (1 << i ) >= k - 1)
	   {
	     ans.insert((1 << i));
	     n -= (1 << i);
	     k--;
	     break;
     }
   }
   if(n == prev)break;
   prev = n;
  }
  if(k != 0 || n != 0)
  {
    cout << "NO" << endl;
  }
  else
  {
	 cout << "YES" << endl;
	 for(auto i:ans)cout << i << " ";
	 cout << endl;
  }
  return ;
}

int main(){
ios_base::sync_with_stdio(0);
int T;
T = 1;
while(T--)
{
  int n, k;
  cin >> n >> k;
  f(n,k);
}

return 0;
}
