class LRUCache {
public:
class Node{
    public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v){
    key = k;
    val = v;
    prev = next = nullptr;
    }
};
unordered_map<int,Node*> m;
int limit;
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);

void Add(Node* newnode){
    Node* oldnext = head->next;
    head->next = newnode;
    newnode->next = oldnext;
    newnode->prev = head;
    oldnext->prev = newnode;


}
void Delete(Node* oldnode){
    Node* newnext = oldnode->next;
    Node* newprev = oldnode->prev;
    newnext->prev = newprev;
    newprev->next = newnext;
    
}

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;

        
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* ansnode = m[key];
        int ans = ansnode->val;

        m.erase(key);
        Delete(ansnode);
        
        Add(ansnode);
        m[key] = ansnode;
        return ans;

        
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldnode = m[key];
            m.erase(key);
            Delete(oldnode);
            
        }
        if(m.size() == limit){
            m.erase(tail->prev->key);
            Delete(tail->prev);
            
        }
        Node* newnode = new Node(key, value);
        Add(newnode);
        m[key] = newnode;
        
    }
};
