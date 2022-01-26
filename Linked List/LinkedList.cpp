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
class LinkedList{
    private:
        Node<T>* headPtr;
    public:
        LinkedList() {
            headPtr = nullptr;
        }

        void insert(T item) {
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
        }

        void deleteNode(T item) {
            Node<T>* dummyHeadPtr = headPtr;
            //case if head node is the target node
            if(dummyHeadPtr != nullptr) {
                if(dummyHeadPtr->getItem() == item) {
                    headPtr = dummyHeadPtr->getNext();

                    delete dummyHeadPtr;
                    dummyHeadPtr = nullptr;

                    return;
                }
            }
            else {
                //search for the node to be deleted
                Node<T>* prevPtr;
                while(dummyHeadPtr != nullptr) {
                    if(dummyHeadPtr->getItem() == item) {
                        break;
                    }
                    prevPtr = dummyHeadPtr;
                    dummyHeadPtr = dummyHeadPtr->getNext();
                }
                //if item not in the list
                if(dummyHeadPtr == nullptr) {
                    return;
                }

                //actual "deletion"
                prevPtr->setNext(dummyHeadPtr->getNext());
                delete dummyHeadPtr;
                dummyHeadPtr = nullptr;
            }
        }

        void reverse() {
            Node<T>* prevNodePtr = nullptr;
            Node<T>* currNodePtr = headPtr;

            while(currNodePtr != nullptr) {
                Node<T>* nextNodePtr = currNodePtr->getNext();

                currNodePtr->setNext(prevNodePtr);
                prevNodePtr = currNodePtr;
                currNodePtr = nextNodePtr;
            }
            headPtr = prevNodePtr;
        }

        void print() {
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
    LinkedList<int> ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);

    ll.print();
    
    ll.reverse();
    
    ll.print();
    
}