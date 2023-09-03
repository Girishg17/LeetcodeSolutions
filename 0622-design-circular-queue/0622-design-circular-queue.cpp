class MyCircularQueue {
public:
    struct node{
        int val;
        node * next;
        node(int x){
            val=x;
            next=NULL;
        }
    };
    node * front=NULL;
    node * rear=NULL;
    int cur_size=0;
    int max_size;
    MyCircularQueue(int k) {
        max_size=k;
        
    }

    
    bool enQueue(int value) {
        if(cur_size<max_size){
            node *newnode=new node(value);
            if(front==NULL){
                front=newnode;
                rear=newnode;
            }
            else{
                rear->next=newnode;
                rear=newnode;
            }
            cur_size++;
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {
        if(cur_size>0){
            node* temp=front;
            front=front->next;
            temp->next=NULL;
            delete temp;
            cur_size--;
            return true;
        }
        return false;

        
    }
    
    int Front() {
        if(cur_size>0)return front->val;
        return -1;
        
    }
    
    int Rear() {
        if(cur_size>0)return rear->val;
        return -1;
        
    }
    
    bool isEmpty() {
        if(cur_size==0)return true;
        return false;
        
    }
    
    bool isFull() {
        if(cur_size==max_size)return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */