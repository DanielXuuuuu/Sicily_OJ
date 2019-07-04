//字典树 前缀树

#include <iostream>
#include <string>
using namespace std;

struct trie_node {
	bool occupyed;
	trie_node* branch[10];
	trie_node() {
		occupyed = false;
		for (int i = 0; i < 10; i++)
			branch[i] = NULL;
	}
};

class Trie {
public:
	Trie() {
		root = new trie_node;
	}

	bool insert(string phone) {
		int flag = 0;
		trie_node* temp = root;
		int i = 0;
		int nextPosition;
		for (i = 0; i < phone.length(); i++) {
			nextPosition = phone[i]-'0';
			if (temp->branch[nextPosition] == NULL) {
				temp->branch[nextPosition] = new trie_node;
				flag = 1;
			}
			temp = temp->branch[nextPosition];
			if (temp->occupyed == true)
				return false;
		}
		
		temp->occupyed = true;
		if(flag)
			return true;
		return false;
	}

private:
	trie_node* root;
};

int main() {
	int caseNum, phoneNum;
	string phone;
	cin >> caseNum;
	while (caseNum--) {
		int flag = 1;
		Trie temp;
		cin >> phoneNum;
		while (phoneNum--) {
			cin >> phone;
			if (!temp.insert(phone))
				flag = 0;
		}
		if (flag == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}