#include <bits/stdc++.h>

using namespace std;

void f(int &n,vector<int>&massiv,vector<int>&points)
{
  for(int i = 0; i < n; i++)
  {
	 for(int j = 0; j < n - 1; j++)
	 {
	  if(massiv[j] > massiv[j + 1])
	  {
		 if(binary_search(points.begin(),points.end(),j + 1))
		 {
		  swap(massiv[j],massiv[j + 1]);
	   }
	   else
	   {
		  cout << "NO" << endl;
		  return ;
	   }
	  }
   }
  }
  cout << "YES" <<endl;
  return ;
}

int main(){
ios_base::sync_with_stdio(0);
int T;
cin >> T;
while(T--)
{
  int n, k;
  cin >> n >> k;
  vector<int>massiv,points;
  for(int i = 1; i <= n; i++)
  {
	 int x;
	 cin >> x;
	 massiv.push_back(x);
  }
  for(int i = 1; i <= k; i++)
  {
	 int x;
	 cin >> x;
	 points.push_back(x);
  }
  sort(points.begin(),points.end());
  f(n,massiv,points);
}

return 0;
}
