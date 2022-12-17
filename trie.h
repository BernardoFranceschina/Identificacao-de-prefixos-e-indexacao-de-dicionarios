#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	struct TrieNode *children[ALPHABET_SIZE];
    unsigned long step;
    unsigned long length;
};

struct TrieNode *getNode(void) {
	struct TrieNode *pNode = new TrieNode;
	pNode->step = 0;
	pNode->length = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

void insert(struct TrieNode *node, string key, int step, int length) {
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!node->children[index])
			node->children[index] = getNode();
		node = node->children[index];
	}
    node->step = step;
    node->length = length;
}

int prefixCount(struct TrieNode *node) {
    int result = 0;
    if (node->length > 0) result++;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
    	if (node->children[i]) result += prefixCount(node->children[i]);
	}
    return result;  
}

void print(struct TrieNode *node, string key) {
	int count = prefixCount(node);
	if (count > 0) cout << key << " is prefix of " << count << " words" << endl;
	else cout << key << " is not prefix" << endl;
	if (node->length > 0) cout << key << " is at " << "(" << node->step << "," << node->length << ")" << endl;
}

void search(struct TrieNode *node, string key) {
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!node->children[index]) {
			cout << key << " is not prefix" << endl;
			return;
		}
		node = node->children[index];
	}
	print(node, key);
}