package com.tuoyu.leetcodescala;

import scala.collection.immutable.Nil;

import java.util.List;

/**
 * Created by tuoyu on 6/24/16.
 */


public class twonumbers {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; };
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p = l1, q = l2;
        ListNode curr = null;
        ListNode head = null;
        int flag = 0;

        while(p != null || q != null) {
            int x = (p == null)? 0 : p.val;
            int y = (q == null)? 0 : q.val;
            int sum = x + y + flag;
            if (sum >= 10)
                flag = 1;
            else
                flag = 0;

            ListNode tmp = new ListNode(sum % 10);
            if (curr == null) {
                curr = tmp;
                head = curr;
            } else {
                curr.next = tmp;
                curr = curr.next;
            }

            if (p != null) p = p.next;
            if (q != null) q = q.next;
        }

        if (flag > 0)
            curr.next = new ListNode(flag);

        return head;
    }
}
