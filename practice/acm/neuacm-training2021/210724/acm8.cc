#include<bits/stdc++.h>
using namespace std;


typedef map<int, string> mapis;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    string str = "123456freaver";
    string sub = "fraever";

    mapis map;

    map[1] = "freaver1";
    map[2] = "freaver2";
    map[3] = "freaver3";

    mapis::iterator it;

    mapis::iterator itend;
    it = map.begin();
    itend = map.end();

    while (it != itend)
    {
        /* code */
        cout << it->first << " " << it->second << endl;
        it++;
    }
    
    
    return 0;
}

