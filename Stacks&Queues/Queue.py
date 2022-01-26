class Queue:
    def __init__(self):
        self.arr = []
        self.extra = []
        
    def enqueue(self,item):
        self.arr.append(item)
        
    def dequeue(self):
        if(not self.empty()):
            while not self.empty():
                temp = self.arr.pop()
                self.extra.append(temp)
            self.extra.pop()
            self.arr = self.extra[::-1]
                
    def empty(self):
        return len(self.arr) == 0
    
    def top(self):
        return self.arr[len(self.arr) - 1]
    
    def display(self):
        print(self.arr)
        
        
if __name__ == "__main__":
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.display()
    q.dequeue()
    q.display()
    