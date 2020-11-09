/* ------------------------------------------------------------------|
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：376 ms, 在所有 C++ 提交中击败了68.84%的用户
*	内存消耗：42.6 MB, 在所有 C++ 提交中击败了53.32%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    if (K >= points.size()) {
        return points;
    }
    //优先队列，自动排序，最大值在队顶
    priority_queue<pair<int, int> > q;
    for (int i = 0; i < K; i++) {
        q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
    }
    
    for (int i = K; i < points.size(); i++) {
        int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (dis < q.top().first) {
            q.pop();
            q.emplace(dis, i);
        }
    }
    vector<vector<int> > res;
    while (!q.empty()) {
        res.emplace_back(points[q.top().second]);
        q.pop();
    }
    return res;
}

int main() {

}