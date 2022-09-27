#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {

        int N = 2e4 + 5;
        // int nums[N];
        // fill(nums, nums + N, 1);
        int tot = ratings.size();
        int pre = N;
        ratings.emplace_back(-1);
        int len = tot;
        int nex;
        for(int i = 0; i < len; i++) {
            nex = ratings[i + 1];
            if(i > pre || i > nex) ++tot;
            pre = ratings[i];
        }
        return tot;
    }
};

int main() {

}
