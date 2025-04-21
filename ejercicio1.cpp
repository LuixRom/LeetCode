#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data) : val(data), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
public:
    LinkedList(): head(nullptr){}

    ListNode* get_head() {
        return head;
    }

    void push_front(int val) {
        ListNode* newNode= new ListNode(val);
        if(head==nullptr) {
            head= newNode;
            return;
        }
        newNode->next= head;
        head= newNode;
    }

    void print() {
        ListNode* temp=head;
        while(temp!=nullptr) {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }

};


class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

int main() {
    LinkedList l1;
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    cout<<endl;
    Solution s1;
    s1.reorderList(l1.get_head());

    /*
    ListNode* prev= nullptr;
    ListNode* current= head;
    while(current!=nullptr) {
        ListNode* forward= current->next;
        current->next= prev;
        prev=current;
        current= forward;
    }
    return prev;
    */
}