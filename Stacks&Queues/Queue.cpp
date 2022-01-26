#include <iostream>

template <typename T>
class Node {
    private:
        T item;
        Node<T>* nextNodePtr;
    public:
        Node() {
            nextNodePtr = nullptr;
        }
        Node(T newItem) {
            item = newItem;
        }

        void setItem(T& data) {
            item = data;
        }
        T getItem() const {
            return item;
        }

        void setNext(Node<T>* newNextNodePtr) {
            nextNodePtr = newNextNodePtr;
        }
        Node<T>* getNext() const {
            return nextNodePtr;
        }
};

template <typename T>
class Queue {
    private:
        Node<T>* headPtr;
        int itemcount;
    public:
        Queue() {
            headPtr = nullptr;
            itemcount = 0;
        }

        void enqueue(T item) {
            Node<T>* newNodePtr = new Node<T>(item);
            
            //case when the list is empty
            if(headPtr == nullptr) {
                headPtr = newNodePtr;
            }
            //not empty
            else {
                Node<T>* dummyHeadPtr = headPtr;
                while(dummyHeadPtr->getNext() != nullptr) {
                    dummyHeadPtr = dummyHeadPtr->getNext();
                }
                dummyHeadPtr->setNext(newNodePtr);
                newNodePtr->setNext(nullptr);
            }
            itemcount++;
        }

        void dequeue() {
            if(!empty()) {
                Node<T>* deletionNodePtr = headPtr;
                if(itemcount == 1) {
                    headPtr = nullptr;
                }
                else { 
                    headPtr = headPtr->getNext();
                }
                deletionNodePtr->setNext(nullptr);
                delete deletionNodePtr;
                deletionNodePtr = nullptr;
                itemcount--;
            }
        }

        T topElem() {
            Node<T>* dummyHead = headPtr;
            while(dummyHead->getNext() != nullptr) {
                dummyHead = dummyHead->getNext();
            }
            return dummyHead->getItem();
        }

        bool empty() {
            return itemcount == 0;
        }

        void display() {
            Node<T>* currPtr = headPtr;
            while(currPtr->getNext() != nullptr) {
                std::cout << currPtr->getItem() << " -> ";
                currPtr = currPtr->getNext();
            }
            //last val
            std::cout << currPtr->getItem() << "\n";
        }

};


int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}