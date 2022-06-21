struct StackListNode {
    int val;
    int minVal;
    StackListNode* next;
    
    StackListNode (): val(-1), minVal(INT_MAX), next(nullptr) {};
    StackListNode (int _val, int _minVal): val(_val), minVal(_minVal),  next(nullptr) {};
    
};

class MinStack {
private:
    StackListNode* head;
public:
    MinStack() {
        head = new StackListNode();
    }
    
    void push(int val) {
        
        int minVal = min(head->minVal, val);
        StackListNode* newHead = new StackListNode(val, minVal);
        
        newHead->next = head;
        head = newHead;
        
    }
    
    void pop() {
        StackListNode* remove = head;
        head = head->next;
        remove->next = nullptr;
        delete remove;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */