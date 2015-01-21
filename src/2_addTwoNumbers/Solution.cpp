#include <string>
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int q = 0;
        ListNode *p = NULL;
        ListNode *rst = NULL;

        while (l1 != NULL && l2 != NULL) {
            int x = l1->val + l2->val + q;
            if (x >= 10) { x -= 10; q = 1; }
            else q = 0;

            ListNode *next = new ListNode(x);
            if (p) { p->next = next; }
            else { rst = next; }
            p = next;
            l1 = l1->next; l2 = l2->next;
        }

        while (l1 != NULL) {
            int x = q + l1->val;
            if (x >= 10) { x -= 10; q = 1; }
            else q = 0;

            ListNode *next = new ListNode(x);
            if (p) { p->next = next; }
            else { rst = next; }
            p = next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int x = q + l2->val;
            if (x >= 10) { x -= 10; q = 1; }
            else q = 0;

            ListNode *next = new ListNode(x);
            if (p) { p->next = next; }
            else { rst = next; }
            p = next;
            l2 = l2->next;
        }
        if (q == 1)
            p->next = new ListNode(q);

        return rst;
    }
};

int main() {
    int x; 

    ListNode *l1, *l2, *p;
    p = l1 = l2 = NULL;

    while (cin >> x) {
        if (x == -1) break;
        ListNode *node = new ListNode(x);
        if (!l1) { l1 = node; }
        else { p->next = node; }
        p = node;
    }
    p = NULL;
    while (cin >> x) {
        ListNode *node = new ListNode(x);
        if (!l2) { l2 = node; }
        else { p->next = node; }
        p = node;
    }

    Solution s;
    p = s.addTwoNumbers(l1, l2);

    while (p->next) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << p->val << endl;
}
