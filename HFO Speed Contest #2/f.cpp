#include <bits/stdc++.h>

using namespace std;

int cmp(pair<int,int>a,pair<int,int>b)
{
  if(a.first != b.first)return a.first > b.first;
  else return a.second < b.second;
}

void f(long long &n,int &k)
{
  vector<int>dig;
  vector<int>cis;
  while(n > 0)
  {
	 cis.push_back(n%10);
	 n /= 10;
  }
  reverse(cis.begin(),cis.end());
  for(int i = 0; i < (int)cis.size(); i++)
  {
	 dig.push_back(cis[i]);
  }
  sort(dig.begin(),dig.end());
  reverse(dig.begin(),dig.end());
  for(int j = 0; j < (int)dig.size(); j++)
  {
   for(int i = 0; i < (int)dig.size(); i++)
   {
	  int ps = 0;
	  for(int z = j + 1; z < (int)dig.size(); z++)
	  {
	   if(cis[z] == dig[i]){ps = z; break;}
    }
	  if(dig[i] > cis[j] && j < ps	&& ps - j <= k)
	  {
		 int p = ps;
		 while(p > j)
		 {
		  swap(cis[p],cis[p - 1]);
		  k--;
		  p--;
	   }
	   break;
	  }
   }
  }
  for(int i = 0; i < (int)cis.size(); i++)cout<<cis[i];
  cout<<endl;
}


int main(){
ios_base::sync_with_stdio(0);
int T;
T = 1;
while(T--)
{
  long long n;
  int k;
  cin >> n >> k;
  f(n,k);
}







return 0;
}
