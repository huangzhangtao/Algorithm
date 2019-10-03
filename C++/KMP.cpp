#include <iostream>
#include <vector>
#include <string>
using namespace std;

void kmp(string& p, string& s)
{
    int n = p.size();
    if(n < 2)  return;
    
    vector<int> next(n, 0);

    for(int i = 1, j = 0; i < n; ++i) //求NEXT数列
    {
        while(j && p[j] != p[i]) j = next[j];
        if(p[i] == p[j]) ++j;
        next[i] = j;
    }

    for(int i = n - 1; i > 0; --i)  next[i] = next[i - 1]; //NEXT数列右移一位


    for(int i = 0, j = 0; i < s.size() - 1; ++i)
    {
        while(j && s[i] != p[j]) j = next[j];
        if(s[i] == p[j]) ++j;
        if(j == n - 1)
        {
            cout<< i - j + 1 << endl;
            j = next[j];
        }
    }
}

int main()
{
    string p, s;
    cin >> p >> s;

    kmp(p, s);

    return 0;
}
