struct Node {
    int start;
    int end;
    
    Node *left, *right;
    
    Node(int _start, int _end): start(_start), end(_end), left(nullptr), right(nullptr) {};
    
};



class MyCalendar {
private:
    Node *head;
public:
    MyCalendar(): head(nullptr) {};
    
    bool book(int start, int end) {
        Node* curr = head, *prev = nullptr;
        
        if (!curr) {
            head = new Node(start, end);
            return true;
        }
        
        while (curr) {
            prev = curr;
            if (curr->start >= end)
                curr = curr->left;
            else if (curr->end <= start) {
                curr = curr->right;
            }
            else if (curr->start < end && curr->end > start) {
                return false;
            }
        }
        Node* newNode = new Node(start, end);
        
        if (end <= prev->start) 
            prev->left = newNode;
        else
            prev->right = newNode;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */