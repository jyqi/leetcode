#include <iostream>
using namespace std;

/**
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/
 //* Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *insertCopy(RandomListNode *head) {
		RandomListNode *cur = head;
		while(cur) {
			RandomListNode *copy = new RandomListNode(cur->label);
			RandomListNode *tmp = cur->next;
			cur->next = copy;
			copy->next = tmp;
			cur = tmp;
		}
		//cout << "insert" << endl;
		return head;
	}
	RandomListNode *addRandom(RandomListNode *head) {
		RandomListNode *cur = head;
		while(cur) {
			if(cur->random) {
				cur->next->random = cur->random->next;
			}
			else {
				cur->next->random = NULL;
			}
			cur = cur->next->next;
		}
		//cout << "add" << endl;
		return head;
	}
	RandomListNode *getRes(RandomListNode *head) {
		RandomListNode *res = head->next;
		RandomListNode *ocur = head;
		while(ocur) {
			RandomListNode *newNode = ocur->next;
			ocur->next = ocur->next->next;
			ocur = ocur->next;
			if(newNode->next) {
				newNode->next = newNode->next->next;
			}
		}
		//cout << "sep" << endl;
		return res;
	}

    RandomListNode *copyRandomList(RandomListNode *head) {
  		if(!head) return NULL;
  		head = insertCopy(head);
  		head = addRandom(head);
  		return getRes(head);
    }
};

RandomListNode *createList(int len) {
	RandomListNode *dummy = new RandomListNode(-1);
	RandomListNode *last = dummy;
	for(int i = 1; i <= len; i++) {
		last->next = new RandomListNode(i);
		RandomListNode *tmp = last->next;
		tmp->random = last;
		last = last->next;
	} 
	return dummy->next;
}

int main() {
	//RandomListNode *l = createList(1);
	RandomListNode *l = new RandomListNode(-1);
	Solution s;
	RandomListNode *res = s.copyRandomList(l);
	while(res) {
		cout << res->label << endl;
		if(res->random) {
			cout << res->random->label << endl;
		}
		//cout << res->label << res->random->label << endl;
		res = res->next;
	}
	return 0;
}