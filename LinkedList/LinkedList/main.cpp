//
//  main.cpp
//  LinkedList
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* InsertNth(Node *head, int data, int position)
{
    // Complete this method only
    // Do not write main function.
    Node* curr = head;
    Node* prev = head;
    
    while (position && curr) {
        prev = curr;
        curr = curr->next;
        position--;
    }
    
    Node* n = new Node();
    n->data = data;
    if (prev == curr) {
        n->next = head;
        return n;
    }
    
    prev->next = n;
    n->next = curr;
    return head;
}


Node* InsertAtTail(Node *head,int data)
{
    // Complete this method
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    
    if (head) {
        Node* curr = head;
        Node* prev = head;
        
        while (curr) {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = n;
        return head;
    }
    else {
        return n;
    }
    
    
}


Node* InsertAtHead(Node *head,int data)
{
    // Complete this method
    Node* n = new Node();
    n->data = data;
    
    if (head) {
        n->next = head;
    }
    
    return n;
}

Node* Delete(Node *head, int position)
{
    // Complete this method
    Node* curr = head;
    Node* prev = head;
    
    if (position == 0) {
        if (curr) {
            head = curr->next;
            delete curr;
        }
        return head;
    }
    
    while (position && curr) {
        prev = curr;
        curr = curr->next;
        position--;
    }
    
    prev->next = curr->next;
    delete curr;
    
    return head;
}


void Print(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    while(head) {
        cout << head->data << endl;
        head = head->next;
    }
}

void ReversePrint(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    if (head) {
        ReversePrint(head->next);
        cout << head->data << endl;
    }
    
}

int GetNode(Node *head,int positionFromTail)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    Node *curr = head;
    
    int  index = positionFromTail;
    
    while (curr && index) {
        curr = curr->next;
        index--;
    }
    
    Node *curr2 = head;
    while (curr && curr->next) {
        curr = curr->next;
        curr2 = curr2->next;
    }
    
    if (curr2)
        return curr2->data;
    
    return -1;
}

Node* RemoveDuplicates(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    if (head == NULL) {
        return NULL;
    }
    
    Node* prev = head;
    Node* curr = head->next;
    
    
    while (prev && curr) {
        if (prev->data == curr->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}


bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if (head == NULL) {
        return 0;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (slow && fast && fast->next) {
        if (slow == fast) {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return 0;
}





int main(int argc, const char * argv[]) {

    return 0;
}
