/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        else if (l2 == null) return l1;

        int sum  = l1.val + l2.val;
        int q = 0;
        if (sum >= 10) { sum -= 10; q = 1; }
        ListNode lsum = new ListNode(sum);
        ListNode l;
        l1 = l1.next; l2 = l2.next;
        for (l = lsum; l1 != null && l2 != null; l1 = l1.next, l2 = l2.next) {
            int s = l1.val + l2.val + q;
            if (s >= 10) { s -= 10; q = 1; }
            else q = 0;
            l.next = new ListNode(s);
            l = l.next;
        }

        while (l1 != null) {
            int s = l1.val + q;
            if (s >= 10) { s -= 10; q = 1; }
            else q = 0;
            l.next = new ListNode(s);
            l1 = l1.next;
            l = l.next;
        }
        while (l2 != null) {
            int s = l2.val + q;
            if (s >= 10) { s -= 10; q = 1; }
            else q = 0;
            l.next = new ListNode(s);
            l2 = l2.next;
            l = l.next;
        }
        if (q == 1) {
            l.next = new ListNode(1);
        }
        return lsum;
    }
}
