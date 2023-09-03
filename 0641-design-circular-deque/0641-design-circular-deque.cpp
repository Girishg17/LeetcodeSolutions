class MyCircularDeque
{

    public:
        struct node
        {
            int val;
            node * next;
            node * prev;
            node(int x)
            {
                val = x;
                next = NULL;
                prev = NULL;
            }
        };
    int max_size;
    int cur_size = 0;
    node *front = NULL;
    node *last = NULL;
    MyCircularDeque(int k)
    {
        max_size = k;
    }

    bool insertFront(int value)
    {
        if (cur_size < max_size)
        {
            node *newnode = new node(value);
            if (front == NULL)
            {
                front = newnode;
                last = newnode;
            }
            else
            {
                node *temp = front;
                front = newnode;
                front->next = temp;
                temp->prev = front;
                if (last == NULL)
                {
                    last = newnode;
                }
            }
            cur_size++;
            return true;
        }
        return false;
    }

    bool insertLast(int value)
    {
        if (cur_size < max_size)
        {
            node *newnode = new node(value);
            if (last == NULL)
            {
                front = newnode;
                last = newnode;
            }
            else
            {
                last->next = newnode;
                newnode->prev = last;
                last = last->next;
                if (front == NULL)
                {
                    front = last;
                }
            }
            cur_size++;
            return true;
        }
        return false;
    }

    bool deleteFront()
    {
        if (cur_size > 0)
        {
            node *temp = front;
            front = front->next;
              if (front) {
                front->prev = nullptr;
            } else {
                last = nullptr;
            }
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            cur_size--;
            return true;
        }
        return false;
    }

    bool deleteLast()
    {
        if (cur_size > 0)
        {
            node *temp = last;
            last = last->prev;
            if (last)
            {
                last->next = nullptr;
            }
         else 
            {
                front = nullptr;
            }
            temp->prev = nullptr;
            temp->next = nullptr;
            delete temp;
            cur_size--;
            return true;
        }
        return false;
    }

    int getFront()
    {
        if (cur_size > 0) return front->val;
        return -1;
    }

    int getRear()
    {
        if (cur_size > 0) return last->val;
        return -1;
    }

    bool isEmpty()
    {
        if (cur_size == 0) return true;
        return false;
    }

    bool isFull()
    {
        if (cur_size == max_size) return true;
        return false;
    }
};

/**
 *Your MyCircularDeque object will be instantiated and called as such:
 *MyCircularDeque* obj = new MyCircularDeque(k);
 *bool param_1 = obj->insertFront(value);
 *bool param_2 = obj->insertLast(value);
 *bool param_3 = obj->deleteFront();
 *bool param_4 = obj->deleteLast();
 *int param_5 = obj->getFront();
 *int param_6 = obj->getRear();
 *bool param_7 = obj->isEmpty();
 *bool param_8 = obj->isFull();
 */