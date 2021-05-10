// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node {
	node* next;
	int val;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		int n, k, q;
		cin >> n >> k >> q;
		node *root = NULL, *cur = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			node *temp = new node();
			temp->next = NULL;
			temp->val = x;

			if (cur == NULL) {
				cur = temp;
				root = temp;
			}
			else {
				cur->next = temp;
				cur = cur->next;
			}
		}
		cur->next = root;

		while (q--) {
			int pos;
			cin >> pos;
			node *cur = root, *prev = NULL;
			if (pos == 0) {
				prev = root;
				while (prev->next != root) {
					prev = prev->next;
				}
			}
			for (int i = 0; i < pos; i++) {
				prev = cur;
				cur = cur->next;
			}
			node *curNext = cur->next, *start = cur, *temp;
			for (int i = 1; i < k; i++) {
				temp = curNext->next;
				curNext->next = cur;
				cur = curNext;
				curNext = temp;
			}
			prev->next = cur;
			start->next = curNext;
		}

		for (int i = 0; i < n; i++) {
			cout << root->val << ' ';
			root = root->next;
		}
		cout << endl;

	}

	return 0;
}