#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const double EPS = 1e-8;




int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    
    string in;
    string out;
    while ( cin >> n >> in >> out ) {
        stack<char> trains;
        vector<string> ans;
        int j = 0;
        for ( int i = 0; i < n; i++ ) {
            trains.push(in[i]);
            ans.push_back("in");
            while ( !trains.empty() && trains.top() == out[j] ) {
                trains.pop();
                ans.push_back("out");
                j++;
            }
        }
        if ( trains.empty() ) {
            cout << "Yes.\n";
            for ( int i = 0; i < ans.size(); i++ ) {
                cout << ans[i] << "\n";
            }
        } else {
            cout << "No.\n";
        }
        cout << "FINISH\n";
    }


    return 0;
}
