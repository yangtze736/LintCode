/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

分析
  可参考merge_two_sorted_lists混合插入有序链表。这道题是合并k个有序链表
  容易想到的一种思路是取出两条，用merge2Lists的方法合并为一条，再将这条
  和下一条用merge2Lists来合并为一条，以此类推。假设每条链表平均有n个元素，
  此种时间复杂度是O(2n+3n+…+kn), 为O(nk²),因此若用此法会超时。

1.使用分治法将合并k个链表划分为合并两个k／2个链表的任务，再不停的往下划分，
  直到划分成只有一个或两个链表的任务，开始合并。举个例子来说比如合并6个链
  表，那么按照分治法，我们首先分别合并1和4,2和5,3和6。这样下一次只需合并3
  个链表，我们再合并1和3，最后和2合并就可以了。

2.利用最小堆这种数据结构，我们首先把k个链表的首元素都加入最小堆中，它们会
  自动排好序。然后我们每次取出最小的那个元素加入我们最终结果的链表中，然后
  把取出元素的那个List中下一个元素再加入堆中，下次仍从堆中取出最小的元素做
  相同的操作，以此类推，直到堆中没有元素，此时k个链表也合并为了一个链表，
  返回首节点。
 */

#include<vector>
#include<queue>
#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

/* solution 1 */
/*
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
		}
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};
*/

/* solution 2 */
struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
 
class Solution {  
public:  
    ListNode *mergeKLists(vector<ListNode *> &lists) {  
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }  
};  




void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

int main(int argc, char**argv)
{
    int a[] = {1,3,5,6,7,10};
    int b[] = {0,4,6,8,9,11,20,30,40};
    int c[] = {9,10,11,21,31,41,51,61};
    ListNode *p1 = createList(a, sizeof(a)/sizeof(int));
    ListNode *p2 = createList(b, sizeof(b)/sizeof(int));
    ListNode *p3 = createList(c, sizeof(c)/sizeof(int));

    vector<ListNode*> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);		

    Solution solu;
    printList( solu.mergeKLists(v) );
    return 0;
}




