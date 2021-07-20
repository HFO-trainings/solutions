#include <bits/stdc++.h>

using namespace std;

void f(int &n,string &stroka)
{
  string a="",b="";
  int sig = 0;
  int sg = 0;
  for(int i = 0; i < (int)stroka.size(); i++)
  {
	int x = stroka[i];
	if(x == '0')
	{
      a += '0'; b += '0';
    }
    else if(x == '1')
    {
	  if(sig & 1){a += '1'; b += '0';}
	  else {a += '0'; b += '1';}
	  if(!sg)sig = 1 - sig;
	  sg = 1;
	}
	else if(x == '2')
	{
	  char z,j;
	  if(sg){z = '2'; j = '0';}
	  else {z = '1'; j = '1';}

	  if(z == j){a += z; b += z;}
	  else {
		if(sig & 1){a += z; b += j;}
	    else {a += j; b += z;}
	  }
    }
  }
  cout << a << endl;
  cout << b << endl;
}

int main(){
ios_base::sync_with_stdio(0);
int T;
cin >> T;
while(T--)
{
  int n;
  string stroka;
  cin>>n;
  cin>>stroka;
  f(n,stroka);
}

return 0;
}
