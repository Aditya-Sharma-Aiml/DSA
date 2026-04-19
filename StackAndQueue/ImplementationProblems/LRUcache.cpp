#include <bits/stdc++.h>
using namespace std;

// LRU Cache: Least Recently Used Cache implementation
// Uses a doubly-linked list + hash map for O(1) operations
class LRUCache {
public:
    // Node class for doubly linked list
    class Node {
    public:
        int key, val;      // Key-value pair
        Node* next;        // Pointer to next node (more recent)
        Node* prev;        // Pointer to previous node (less recent)

        // Constructor to initialize a node
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    int cap;                          // Capacity of the cache
    unordered_map<int, Node*> mpp;    // Hash map to store key -> Node mapping
    Node* head;                       // Dummy head node (most recent side)
    Node* tail;                       // Dummy tail node (least recent side)

    // Constructor: Initialize cache with given capacity
    LRUCache(int capacity) {
        cap = capacity;
        // Create dummy head and tail nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head (mark as most recently used)
    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    // Remove node from doubly linked list
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Get value for a key: O(1) operation
    // If key exists, mark it as most recently used by moving to front
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;  // Key not found

        Node* node = mpp[key];
        int value = node->val;

        // Move node to front (mark as recently used)
        deleteNode(node);
        addNode(node);

        mpp[key] = head->next; // Update position after moving

        return value;
    }

    // Put key-value pair: O(1) operation
    void put(int key, int value) {

        // Case 1: Key already exists - update its value
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            deleteNode(node);
            mpp.erase(key);
            delete node; // Free memory
        }

        // Case 2: Cache is at capacity - remove least recently used (node before tail)
        if (mpp.size() == cap) {
            Node* lru = tail->prev;
            mpp.erase(lru->key);
            deleteNode(lru);
            delete lru; // Free memory
        }

        // Case 3: Insert new key-value pair at the front (most recent)
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

int main(){
    // Create LRU cache with capacity 4
    LRUCache* cache = new LRUCache(4);

    // Add 4 key-value pairs
    cache->put(2, 6);
    cache->put(4, 7);
    cache->put(8, 11);
    cache->put(7, 10);

    // Retrieve values (marks them as recently used)
    cout << cache->get(2) << endl; // returns 6
    cout << cache->get(4) << endl; // returns 7
    cout << cache->get(8) << endl; // returns 11
    cout << cache->get(7) << endl; // returns 10

    // Add new key-value pair - evicts key 2 (least recently used)
    cache->put(5, 6);
    cout << cache->get(2) << endl; // returns -1 (evicted from cache)

    // Update existing key 5's value to 7
    cache->put(5, 7);
    cout << cache->get(5) << endl; // returns 7

    return 0;
}