#include <bits/stdc++.h>

using namespace std;

void f(int &n,vector<string>&words,string &stroka)
{
  int ind = 0, p = 0;
  for(int i = 0; i < (int)stroka.size(); i++)
  {
	 if(stroka[i] == words[ind][p])
	 {
	  p++;
	  if(p == (int)words[ind].size())
	  {
		 ind++;
		 p = 0;
	  }
	  if(ind == n)break;
   }
  }
  if(ind == n)
  {
 	 cout<<"yes"<<endl;
  }
  else cout<<"no"<<endl;
  return ;
}

int main(){
ios_base::sync_with_stdio(0);
int T;
T = 1;
while(T--)
{
  int n;
  cin >> n;
  vector<string>words;
  string stroka;

  for(int i = 0; i < n; i++)
  {
	 cin >> stroka;
	 reverse(stroka.begin(),stroka.end());
	 if(i == 0)stroka += "3<";
	 reverse(stroka.begin(),stroka.end());
	 stroka += "<3";
	 words.push_back(stroka);
  }
  cin >> stroka;
  f(n,words,stroka);
}

return 0;
}
