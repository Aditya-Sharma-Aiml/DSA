#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        int value = node->val;

        deleteNode(node);
        addNode(node);

        mpp[key] = head->next; // update position

        return value;
    }

    void put(int key, int value) {

        // Case 1: already exists
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            deleteNode(node);
            mpp.erase(key);
            delete node; // memory free
        }

        // Case 2: capacity full → remove LRU
        if (mpp.size() == cap) {
            Node* lru = tail->prev;
            mpp.erase(lru->key);
            deleteNode(lru);
            delete lru; // memory free
        }

        // Case 3: insert new node
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

int main(){

    LRUCache* cache = new LRUCache(4); // capacity 4

    cache->put(2, 6);
    cache->put(4, 7);
    cache->put(8, 11);
    cache->put(7, 10);

    cout << cache->get(2) << endl; // returns 6
    cout << cache->get(4) << endl; // returns 7
    cout << cache->get(8) << endl; // returns 11
    cout << cache->get(7) << endl; // returns 10

    cache->put(5, 6);// evicts key 2 (LRU)
    cout << cache->get(2) << endl; // returns -1 (not found)

    cache->put(5, 7); // updates key 5's value to 7
    cout << cache->get(5) << endl; // returns 7

}