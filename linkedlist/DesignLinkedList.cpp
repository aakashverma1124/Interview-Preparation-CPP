#include <iostream>
using namespace std;

class Node {
public :
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class DesignLinkedList {
public:

	Node *head;

	DesignLinkedList() {
		this->head = NULL;
	}

	void insertAtBeginning(int data) {
		Node* node = new Node(data);
		node->next = this->head;
		this->head = node;
	}

	void insertAtEnd_N(int data) {
		Node* node = new Node(data);
		if(this->head == NULL) {
			this->head = node;
		} else {
			Node *temp = this->head;
			while(temp->next != NULL) {
				temp = temp->next;
			}	
			temp->next = node;	
		}
		
	}

	int deleteNode(int data) {
		if(this->head == NULL)
			return -1;
		Node *temp = this->head;
		if(temp->data == data) {
			this->head = temp->next;
			return data;
		}
		Node *prev = temp;
		temp = temp->next;
		while(temp != NULL) {
			if(temp->data == data) {
				prev->next = temp->next;
				return data;
			}
			prev = temp;
			temp = temp->next;
		}
		return -1;
	}

	void printList() {
		Node *temp = this->head;
		while(temp != NULL) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main(int argc, char const *argv[]) {
	DesignLinkedList ll;
	ll.insertAtEnd_N(30);
	ll.insertAtEnd_N(40);
	ll.insertAtEnd_N(50);
	ll.insertAtBeginning(20);
	ll.insertAtBeginning(10);
	ll.insertAtEnd_N(60);
	ll.printList();
	ll.deleteNode(20);
	ll.printList();
	ll.deleteNode(60);
	ll.printList();
	ll.insertAtEnd_N(70);
	ll.printList();
	return 0;
}