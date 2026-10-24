#include <stdlib.h>
#include <stdio.h>

#define HASH_SIZE 10007 // A prime number for better hash distribution

// Node for the Doubly Linked List
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// Hash Table Node for Chaining
typedef struct HashNode {
    int key;
    Node* cache_node;
    struct HashNode* next;
} HashNode;

// LRUCache structure
typedef struct {
    int capacity;
    int size;
    Node* head; // Dummy head
    Node* tail; // Dummy tail
    HashNode* table[HASH_SIZE];
} LRUCache;

// Hash function
unsigned int hash(int key) {
    return (unsigned int)(key) % HASH_SIZE;
}

// Add a node right after the dummy head (Most Recently Used)
void add_to_head(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// Remove a node from the doubly linked list
void remove_node(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Move an existing node to the head
void move_to_head(LRUCache* obj, Node* node) {
    remove_node(node);
    add_to_head(obj, node);
}

// Pop the least recently used node (just before dummy tail)
Node* pop_tail(LRUCache* obj) {
    Node* lru = obj->tail->prev;
    if (lru == obj->head) return NULL; // Empty list
    remove_node(lru);
    return lru;
}

// Hash table helper: find a hash node by key
Node* hash_find(LRUCache* obj, int key) {
    unsigned int h = hash(key);
    HashNode* curr = obj->table[h];
    while (curr) {
        if (curr->key == key) {
            return curr->cache_node;
        }
        curr = curr->next;
    }
    return NULL;
}

// Hash table helper: insert key and cache_node mapping
void hash_insert(LRUCache* obj, int key, Node* cache_node) {
    unsigned int h = hash(key);
    HashNode* new_hn = (HashNode*)malloc(sizeof(HashNode));
    new_hn->key = key;
    new_hn->cache_node = cache_node;
    new_hn->next = obj->table[h];
    obj->table[h] = new_hn;
}

// Hash table helper: remove a key mapping
void hash_remove(LRUCache* obj, int key) {
    unsigned int h = hash(key);
    HashNode* curr = obj->table[h];
    HashNode* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                obj->table[h] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Initialize the LRU cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    
    // Initialize hash table buckets to NULL
    for (int i = 0; i < HASH_SIZE; i++) {
        obj->table[i] = NULL;
    }
    
    // Create dummy head and tail nodes
    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));
    obj->head->key = -1; obj->head->value = -1;
    obj->tail->key = -1; obj->tail->value = -1;
    
    obj->head->next = obj->tail;
    obj->head->prev = NULL;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    
    return obj;
}

// Get the value of the key if it exists, otherwise return -1
int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = hash_find(obj, key);
    if (!node) {
        return -1;
    }
    // Key exists, move it to the head (most recently used)
    move_to_head(obj, node);
    return node->value;
}

// Update or insert a key-value pair
void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = hash_find(obj, key);
    
    if (node) {
        // Update value and move to head
        node->value = value;
        move_to_head(obj, node);
    } else {
        // If capacity is reached, evict the least recently used node
        if (obj->size == obj->capacity) {
            Node* lru = pop_tail(obj);
            if (lru) {
                hash_remove(obj, lru->key);
                free(lru);
                obj->size--;
            }
        }
        
        // Create new node
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->key = key;
        new_node->value = value;
        
        // Add to doubly linked list and hash table
        add_to_head(obj, new_node);
        hash_insert(obj, key, new_node);
        obj->size++;
    }
}

// Free allocated memory
void lRUCacheFree(LRUCache* obj) {
    // Free hash table nodes
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = obj->table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    
    // Free doubly linked list nodes
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    free(obj);
}