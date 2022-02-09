#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
public:
    void push_back(int val) {
        if (next == nullptr) {
            next = new ListNode(val);
        }
        else {
            next->push_back(val);
        }
    }
    void print() {
        cout << val << " ";
        if (next != nullptr) {
            next->print();
        }
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode head;
    ListNode* l3 = &head;
    int sum = 0;
    while ((l1 != NULL) || (l2 != NULL) || sum > 0) {
        if (l1!=NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2!= NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        l3->next = new ListNode(sum % 10);
        l3 = l3->next;
        sum /= 10; 
    }
    return head.next;
};

int main() {

    ListNode* l1 = new ListNode(2);
    l1->push_back(4);
    l1->push_back(3);
    ListNode* l2 = new ListNode(5);
    l2->push_back(6);
    l2->push_back(4);
    ListNode* l3 = addTwoNumbers(l1, l2);
    l1->print();
    cout << endl;
    l2->print();
    cout << endl;
    l3->print();
    cout << endl << endl;

    ListNode* l4 = new ListNode(0);
    ListNode* l5 = new ListNode(0);
    ListNode* l6 = addTwoNumbers(l4, l5);
    l4->print();
    cout << endl;
    l5->print();
    cout << endl;
    l6->print();
    cout << endl << endl;
}