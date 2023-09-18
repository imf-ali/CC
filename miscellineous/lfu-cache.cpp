struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node (int key,int val) {
        this->key = key;
        this->val = val;
    }
};

class LFUCache {
public:
    int capacity = 0;
    map<int,Node*> mp;
    map<int,int> freq;
    map<int,pair<Node*,Node*>> flist;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node *temp = mp[key];
        int val = temp->val;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete(temp);
        if(flist[freq[key]].first->next == flist[freq[key]].second) {
            flist.erase(freq[key]);
        }
        insert(key,val);
        return val;
    }

    void create(int freq){
        Node *head = new Node(-1,-1);
        Node *tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        flist[freq] = { head, tail};
    }

    void insert(int key,int val){
        freq[key]++;
        if(flist.find(freq[key]) == flist.end()){
            create(freq[key]);
        }
        Node *head = flist[freq[key]].first;
        Node *temp = new Node(key,val);
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        mp[key] = temp;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(!capacity){
                int keyx = flist.begin()->first;
                Node *tail = flist.begin()->second.second;
                Node *temp = tail->prev;
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
                mp.erase(temp->key);
                freq.erase(temp->key);
                delete(temp);
                if(flist[keyx].first->next == flist[keyx].second) {
                    flist.erase(keyx);
                }
            }
            insert(key,value);
            if(capacity > 0)
                capacity--;
        } else {
            Node *temp = mp[key];
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete(temp);
            if(flist[freq[key]].first->next == flist[freq[key]].second) {
                flist.erase(freq[key]);
            }
            insert(key,value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
