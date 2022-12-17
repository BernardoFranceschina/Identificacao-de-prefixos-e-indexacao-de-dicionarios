#include <iostream>
#include <fstream>
#include <cstring>
#include "./trie.h"

using namespace std;

int main() {
    struct TrieNode *trie = getNode();
    string filename;
    string Uinput;
    string line;

    cin >> filename;

    ifstream dataset;
    dataset.open(filename);
    if (dataset.is_open()) {
        int step = -1;
        while (getline(dataset, line)) {
            step++;
            string word = line.substr(1, line.find("]") - 1);
            insert(trie, word, step, line.length());
            step += line.length();
        }
        dataset.close();
    }
    while (1) {
        cin >> Uinput;
        if (Uinput.compare("0") == 0) break;
        search(trie, Uinput);
    }

    return 0;
}
