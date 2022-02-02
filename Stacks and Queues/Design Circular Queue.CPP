class MyCircularQueue {
public:
    int size, cap, front, *arr;
    MyCircularQueue(int k) {
        cap=k;
        arr = new int[cap];
        front=0;
        size=0;
    }
    
    bool enQueue(int value) {
        if(size==cap) return false;
        int rear = (front+size-1)%cap;
        rear = (rear+1)%cap;
        arr[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front= (front+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[(front+size-1)%cap];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==cap);
    }
};