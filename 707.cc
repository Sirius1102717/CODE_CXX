class MyLinkedList {
private:
    int val;
    MyLinkedList* next;
    MyLinkedList* prev;

public:
    MyLinkedList() : next(nullptr), prev(nullptr), val(-1) {}

    int get(int index) {
        if(index < 0) return -1;
        MyLinkedList* tmp = this;
        while(index > 0)
            tmp = tmp->next;
        return tmp->val;
    }

    void addAtHead(int val) {
        this->prev->val = val;
    }

    void addAtTail(int val) {
        MyLinkedList* tmp = this;
        while(tmp->next)
            tmp = tmp->next;
        tmp->val = val;
    }

    void addAtIndex(int index, int val) {
        if(index < 0) return;
        MyLinkedList* tmp = this;
        while(index > 0) 
            tmp = tmp->next;
        tmp->val = val;
    }

    void deleteAtIndex(int index) {
        if (index < 0) return;
        MyLinkedList *tmp = this;
        while (index > 0) 
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
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
