class Stack:
    def __init__(self):
        self.arr = []
        
    def push(self,item):
        self.arr.append(item)
        
    def pop(self):
        if(not self.empty()):
            del(self.arr[-1])
            
    def empty(self):
        return len(self.arr) == 0
    
    def top(self):
        return self.arr[len(self.arr) - 1]
    
    def display(self):
        print(self.arr)
        
if __name__ == "__main__":
    stk = Stack()
    stk.push(1)
    stk.push(2)
    stk.push(3)
    stk.display()
    stk.pop()
    stk.display()