#include <bits/stdc++.h>

using namespace std;

string stroka;

int main(){
ios_base::sync_with_stdio(0);
cin>>stroka;

int n = (int)stroka.size();

for(int i = 0; i < n; i++)
{
  if((stroka[i]-'0') % 8 == 0)
  {
	 cout << "YES" << endl;
	 cout << stroka[i] <<endl;
	 return 0;
  }
}

for(int i = 0; i < n; i++)
{
  for(int j = i + 1; j < n; j++)
  {
	 int x = (stroka[i]-'0') * 10 + (stroka[j]-'0');
	 if(x % 8 == 0)
	 {
	  cout << "YES" << endl;
	  cout << x << endl;
	  return 0;
   }
  }
}

for(int i = 0; i < n; i++)
{
  for(int j = i + 1; j < n; j++)
  {
	 for(int k = j + 1; k < n; k++)
	 {
	  int x = (stroka[i]-'0') * 100 + (stroka[j]-'0') * 10 + (stroka[k]-'0');
	  if(x % 8 == 0)
	  {
	    cout << "YES" << endl;
	    cout << x << endl;
	    return 0;
    }
   }
  }
}

cout << "NO" <<endl;


return 0;
}
