// we require a dll and a hashmap for this 
class Node{
    // the node should store a key, value, prev pointer and next pointer
public: 
    int key, val; 
    Node* prev; 
    Node* next; 

    Node(){
        key = -1; 
        val = -1; 
        prev= nullptr; 
        next = nullptr; 
    }
    Node(int key, int val){
        this->key = key; 
        this->val = val; 
        prev = nullptr; 
        next = nullptr; 
    }
}; 
class LRUCache {
private: 
    //dummy head and tail nodes
    Node* head; 
    Node* tail; 
    //hashmap 
    unordered_map<int, Node*> mpp; 
    int cap; 

    //function to delete given node 
    void deleteNode(Node* node){
        Node* prevNode = node->prev; 
        Node* nextNode = node->next; 
        prevNode->next = nextNode; 
        nextNode-> prev = prevNode; 
    }
    //function to insert node at the start 
    void insertAfterHead(Node *node){
        Node* nextNode = head->next; 
        head->next = node; 
        node->next = nextNode; 
        node->prev=head; 
        nextNode->prev=node; 
    }
public:
    LRUCache(int capacity) {
        cap = capacity; 
        mpp.clear(); 
        //initial configuration 
        head = new Node(); 
        tail = new Node(); 
        head->next = tail; 
        tail->prev = head; 
    }
    
    int get(int key) {
        // two options --> either key exists in cache or it doesnt
        //key isnt present 
        if(mpp.find(key)==mpp.end()){
            return -1; 
        }
        //key is present
        //get node from map 
        Node* node = mpp[key]; 
        //since it was used in this process delete it and put it in the front 
        deleteNode(node); 
        insertAfterHead(node); 
        return node->val; 
    }
    
    void put(int key, int value) {
        // if key already exits just update value 
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key]; 
            node->val = value; 
            deleteNode(node); 
            insertAfterHead(node); 
            return; 
        }
        else{
            //key doesnt exists
            //check capacity first
            if(mpp.size()==cap){
                Node* node = tail->prev; 
                mpp.erase(node->key); 
                deleteNode(node); 
            }
            //insert into map and dll 
            Node* newNode = new Node(key, value); 
            mpp[key]=newNode; 
            insertAfterHead(newNode); 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */