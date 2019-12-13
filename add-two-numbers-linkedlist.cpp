/*

https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 */

#include<iostream>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1 = l1, *n2 = l2;
        ListNode *output = NULL, *n;
        int carry = 0;
        while (!(n1 == NULL && n2 == NULL)) {
            int sum = carry;
            if (n1 != NULL) sum += n1->val;
            if (n2 != NULL) sum += n2->val;
            carry = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            if (output == NULL) {
                output = node;
                n = output;
            } else {
                n->next = node;
                n = n->next;
            }
            if (n1 != NULL) n1 = n1->next;
            if (n2 != NULL) n2 = n2->next;
        }
        
        if (carry == 1) {
            ListNode *node = new ListNode(1);
            n->next = node;
        }
        return (output);
    }  
};

// auxiliary code ...

void trimLeftTrailingSpaces(string &input) {
    //input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;

/*
    getline(cin, line);
    cout << "line: " << line << endl;

    trimLeftTrailingSpaces(line);
    cout << "line: " << line << endl;
    cout << "Enter line: ";
    getline(cin, line);
    ListNode* l1 = stringToListNode(line);
    string out = listNodeToString(l1);
    cout << out << endl;
*/
    
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}


