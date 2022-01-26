#include <iostream>

template <typename Type>
class Stack {
    private:
        static const int SIZE = 10; //feel free to edit this
        int itemcount;
        Type *arr;
        int top;
    public:
        Stack() {
            arr = new Type[SIZE];
            top = -1;
            itemcount = 0;
        }

        ~Stack() {
            delete [] arr;
            arr = nullptr;
        }

        void push(const Type& item) {
            if(full()) {
                exit(EXIT_FAILURE);
            }
            else {
                arr[++top] = item;
                itemcount++;
            }
        }

        void pop() {
            if(empty()) {
                exit(EXIT_FAILURE);
            }
            else {
                Type popped = arr[top--];
                itemcount--;
            }
        }

        Type topElem() {
            if(!empty()) {
                return arr[top];
            }
        }

        void display() {
            for(int i = 0; i < itemcount - 1; i++) {
                std::cout << arr[i] << ", ";
            }
            std::cout << arr[itemcount-1] << std::endl;
        }

        bool empty() {
            return top == -1;
        }

        bool full() {
            return top == SIZE - 1;
        }
};

int main() {
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.display();
    stk.pop();
    stk.display();

}