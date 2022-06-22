struct Node {
    int val;
    Node* next;
    
    Node (): val(-1), next(nullptr) {};
    
    Node (int _val): val(_val), next(nullptr) {};
    
    Node (int _val, Node* _next): val(_val), next(_next) {};
    
};


class MyLinkedList {
private:
    int size;
    Node* head;
public:
    MyLinkedList() {
        head = new Node();
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        
        Node* work = head;
        for (int i = 0; i <= index; ++i) {
            work = work->next;
        }
        
        return work->val;
    }
    
    void addAtHead(int val) {
        Node* curr = new Node(val, head->next);
        head->next = curr;
        ++size;
    }
    
    void addAtTail(int val) {
        Node* work = head;
        
        while (work->next) {
            work = work->next;
        }
        
        work->next = new Node(val);
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        
        if (index == size) {
            addAtTail(val);
            return;
        }
        
        Node* work = head;
        
        for (int i = 0; i < index; ++i) {
            work = work->next;
        }
        
        work->next = new Node(val, work->next);
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        } 
        
        Node* work = head;
        
        for (int i = 0; i < index; ++i) {
            work = work->next;
        }
        
        work->next = work->next->next;
        
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */