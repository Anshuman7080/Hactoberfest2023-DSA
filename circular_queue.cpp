#include <iostream>

using namespace std;

class CircularQueue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull() const;
    bool isEmpty() const;
    void enqueue(int x);
    int dequeue();
    void display() const;
};

CircularQueue::CircularQueue(int size) : size(size), front(0), rear(0) {
    Q = new int[size];
}

CircularQueue::~CircularQueue() {
    delete[] Q;
}

bool CircularQueue::isEmpty() const {
    return front == rear;
}

bool CircularQueue::isFull() const {
    return (rear + 1) % size == front;
}

void CircularQueue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1;
    } else {
        front = (front + 1) % size;
        return Q[front];
    }
}

void CircularQueue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = (front + 1) % size;
    while (i != (rear + 1) % size) {
        cout << Q[i] << (i != rear ? " <- " : "") << flush;
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    CircularQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // Enqueue
    for (int x : A) {
        cq.enqueue(x);
    }

    // Display
    cq.display();

    // Overflow
    cq.enqueue(10);

    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cq.dequeue();
    }

    // Underflow
    cq.dequeue();

    return 0;
}
