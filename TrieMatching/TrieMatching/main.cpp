//
//  main.cpp
//  TrieMatching
//
//  Created by Vaibhav Chakki on 9/8/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

/*
 Expected Input/output
 
 Test 1:
 Input: AAA
        1
        AA
 Output:
        0 1
 Explanation:
 The pattern AA appears at positions 0 and 1. Note that these two occurrences of the pattern overlap.
 
 Test 2:
 Input:
        AA
        1
        T
 
 Output:
 
 Explanation:
 There are no occurrences of the pattern in the text.
 
 Test 3:
 Input:
        AATCGGGTTCAATCGGGGT
        2
        ATCG
        GGGT
 
 Output:
        1 4 11 15
 
 Explanation:
 The pattern ATCG appears at positions 1 and 11, the pattern GGGT appears at positions 4 and 15.
 */


#include <iostream>
using namespace std;

#define NUM_CHARS 26
#define INDEX(C) (C - 'A')

struct Trie {
    int isLeaf;
    Trie* children[NUM_CHARS];
    
    Trie() {
        isLeaf = false;
        for (int i = 0; i < NUM_CHARS; i++) {
            children[i] = NULL;
        }
    }
};

void insert(Trie** root, string str) {
    Trie *node = *root;
    
    if (node) {
        for(int i = 0; i < str.length(); i++) {
            Trie* child = node->children[INDEX(str[i])];
            if (!child) {
                node->children[INDEX(str[i])] = new Trie();
                node->isLeaf = true;
            }
            node = node->children[INDEX(str[i])];
        }
    }
}



void matchTrie(Trie* root, string s) {
    
    for (int i = 0; i < s.length(); i++) {
        int j = i;
        Trie *node = root;
        
        while (node) {
            if (j < s.length()) {
                char ch = s[j];
                Trie* child = node->children[INDEX(ch)];
                if (!child) {
                    break;
                }
                else {
                    if (!child->isLeaf) {
                        cout << i << " ";
                        break;
                    }
                    else {
                        node = child;
                        j++;
                    }
                }
            }
            else {
                break;
            }
        }
        
    }
    cout << endl;
}


int main(int argc, char** argv) {
    Trie* root = new Trie();
    string str;
    cin >> str;
    
    // construct a Trie first
    //
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(&root, s);
    }
    
    matchTrie(root, str);
    
    return 0;
}


