#include <vector>
#include <queue>

using namespace std;

int kth_largest(vector<int> values, int k){
    priority_queue<int> max_queue(values.begin(), values.end());
    for (int i = 1; i < k; i++){
        max_queue.pop();
    }
    return max_queue.top();
}