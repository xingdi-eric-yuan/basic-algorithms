#include "linked_list.h"
using namespace std;


void printLinkedList(ListNode *head){
    ListNode *p = head;
    while(p){
        cout<<p -> val<<" -> ";
        p = p -> next;
    }
    cout<<"NULL"<<endl;
}

ListNode* reverseLinkedList(ListNode *head){
    if(!head || !(head -> next)) return head;
    ListNode *res;
    ListNode *last = NULL;
    ListNode *current = head;
    ListNode *nxt;
    while(1){
        if(!current) break;
        if(!(current -> next)){
            current -> next = last;
            res = current;
            break;
        }
        nxt = current -> next;
        current -> next = last;
        last = current;
        current = nxt;
    }
    return res;
}














