#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class NODE {
public:
    int DATA;
    NODE* NEXT;
    NODE(int d) {
        DATA = d;
        NEXT = NULL;
    }
};
class LinkList {
    NODE* head;

public:
    LinkList() {
        head = NULL;
    }
        void insertAtBeginning() {
        int data;
        cout<<"\n\nyou choose insertion at beginning...\n\n";
        cout << "\nEnter node data: ";
        cin >> data;
        NODE* newNode = new NODE(data);
        newNode->NEXT = head;
        head = newNode;
        cout << "\nNode inserted at beginning successfully ... \n";
    }
    void insertAtEnd() {
        int data;
        cout<<"\n\nyou choose insertion at end...\n\n";
        cout << "\nEnter node data: ";
        cin >> data;
        NODE* newNode = new NODE(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        NODE* temp = head;
        while (temp->NEXT != NULL) {
            temp = temp->NEXT;
        }
        temp->NEXT = newNode;
        cout << "\nNode inserted at end successfully... \n";
    }
    void traverse() {
        if (head == NULL) {
            cout<<"\n\nyou choose traverse...\n\n";
            cout << "\nLinked List is empty.\n";
            return;
        }
        NODE* temp = head;
        cout<<"\n\nyou choose traversal...\n\n";
        cout << "\nLinked List: ";
        while (temp != NULL) {
            cout << temp->DATA << " -> ";
            temp = temp->NEXT;
        }
        cout << "NULL\n";
    }
    void deleteAtBeginning() {
        if (head == NULL) {
            cout<<"\n\nyou choose deletion at beginning...\n\n";
            cout << "\nList is empty.\n";
            return;
        }
        NODE* temp = head;
        head = head->NEXT;
        delete temp;
        cout << "\nNode deleted from beginning successfully.\n";
    }
    void deleteAtEnd() {
        if (head == NULL) {
            cout<<"\n\nyou choose deletion at end...\n\n";
            cout << "\nLink list is empty.\n";
            return;
        }
        if (head->NEXT == NULL) {
            delete head;
            head = NULL;
            cout << "\nLast node deleted successfully....\n";
            return;
        }
        NODE* temp = head;
        while (temp->NEXT->NEXT != NULL) {
            temp = temp->NEXT;
        }
        delete temp->NEXT;
        temp->NEXT = NULL;
        cout << "\nNode deleted from end successfully...\n";
    }
};

int main() {
    LinkList l;
    char c;
    while (true) {
        system("cls");
        cout << "\n\tLINKLIST PROJECT\n\n";
        cout << "1. Insert at Beginning \t2. Insert at End\n\n";
        cout << "3. Delete at Beginning \t4. Delete at End\n\n";
        cout << "5. Traverse \t\t";
        cout << "\n\nEnter your choice -- \n\n";
        c = getch();

        switch (c) {
            case '1':
                l.insertAtBeginning();
                break;
            case '2':
                l.insertAtEnd();
                break;
            case '3':
                l.deleteAtBeginning();
                break;
            case '4':
                l.deleteAtEnd();
                break;
            case '5':
                l.traverse();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

        cout << "\n\nDo you Want to continue .. press 1 else any key..";
        c = getch();
        if (c != '1') break;
    }
    return 0;
}
