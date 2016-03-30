
/**
Native and Trivial的想法
就是按照基本思路来进行的

32ms
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        ListNode *fp = head;
        ListNode *ret = head;
        ListNode *tail = head;
        bool first = true;
        while(true){
            int t = k;
            while(fp && --t){
                fp = fp->next;
            }
            if(fp == NULL) break;
            //这儿必须要记录原始的fp->next 否则后面 在subReverse中被更改了
            ListNode *store = fp->next;
            ListNode *tmp = subReverse(head,k);
            if(first){
                ret = tmp;
                first = false;
            }else{
                tail->next = tmp;
            }
            tail = head;
            fp = head = store;
        }
        return ret;
    }
    ListNode* subReverse(ListNode *head,int k){
        if(k <= 1) return head;
        int t = k;
        ListNode *tail = head;
        while(tail && --t){
            tail = tail->next;
        }
        ListNode *tmp = head->next;
        head->next = tail->next;
        if(tmp == tail){
            tail->next = head;
        }else{
            tail->next = subReverse(tmp,k-2);
            //将tmp串接上
            tmp->next = head;
        }
        return tail;
    }
};

/***
https://leetcode.com/discuss/27468/20-line-iterative-c-solution

Discuss中的一种解法  比如 1 2 3 4 -> 2 1 3 4-> 3 2 1 4-> 4 3 2 1  为了达到这样的效果
我们需要：
 pre: 将链表串联起来所必须需要的
 分别三个指针记录当前要移动到pre后面的节点 它的前一个节点和后一个节点
 具体的起名随便了

-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    |
pre  cur  nex  tmp

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    |
pre       cur  nex  tmp

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    |
pre            cur  nex  tmp

24ms
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        int total = 0;
        ListNode* tail = head;
        while(tail){
            total += 1;
            tail = tail->next;
        }
        ListNode *prehead = new ListNode(-1);
        prehead->next = head;
        ListNode *cur = prehead,*nex,*pre;
        while(total >= k){
            pre = cur;
            cur = pre->next;
            nex = cur->next;
            for(int i = 1;i<k;++i){
               ListNode *tmp = nex->next;
               nex->next = pre->next;
               pre->next = nex;
               cur->next = tmp;
               nex = cur->next;
            }
            total -= k;
        }
        ListNode *ret = prehead->next;
        delete(prehead);
        return ret;
    }
};












