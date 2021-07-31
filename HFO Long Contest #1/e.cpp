#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int cnt[27];
string stroka;
long long ans = 0;

map<string,long long>words_count;

int main(){
ios_base::sync_with_stdio(0);
//Main idea:
//It is obvious that better to have the smaller substring as possible as it will give as maximum result.
//So better to check the substrings with size of 2 and 1 and take maximum answer.
cin >> stroka;
//Checking substrings with size 1.
for(int i = 0; i < (int)stroka.size(); i++)
{
  cnt[stroka[i] - 'a']++;
  ans = max(ans, cnt[stroka[i] - 'a'] * 1LL); //Checking the result
}

memset(cnt, 0, sizeof(cnt)); //Cleaning the count array of symbols.

//Checking substrings with size 2.
//For each symbol i, we will put the other symbol a which ocurried earlier. We will have substring ai.
//So, for the count of substring ai we add the count of symbols a.
//For storing the count of substring ai we can use map , where we will store it at as "ai" or we can use
//2D array cnt_substrings[i][j] where i is the first letter, j is the second letter.

for(int i = 0; i < (int)stroka.size(); i++)
{
  for(int a = 'a'; a <= 'z'; a++)
  {
    char sim = a;
    string word;
    word += sim;
    word += stroka[i];
    words_count[word] += cnt[a - 'a'];  //for the count of substring ai we add the count of symbols a.
    ans = max(words_count[word],ans); //Checking the result
  }
  cnt[stroka[i] - 'a']++;
}

cout << ans << endl;




return 0;
}
