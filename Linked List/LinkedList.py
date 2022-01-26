class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LinkedList:
    #constructor
    def __init__(self):
        self.head = None 
    #insert
    def insert(self,item):
        #empty list
        newNode = Node(item)
        if self.head == None:
            self.head = newNode
        #not empty
        else:
            dummyHead = self.head
            while dummyHead.next is not None:
                dummyHead = dummyHead.next
            dummyHead.next = newNode
            newNode.next = None
            
    def delete(self,item):
        dummyHead = self.head
        #if head node holds the item
        if dummyHead is not None:
            if dummyHead.data == item:
                self.head = dummyHead.next
                dummyHead = None
                return
        #search for the node to be deleted while keeping track of the previous node
        while dummyHead is not None:
            if dummyHead.data == item:
                break
            prev = dummyHead
            dummyHead = dummyHead.next
            
        #if item to be deleted was not in the list
        if dummyHead == None:
            return
        
        prev.next = dummyHead.next
        dummyHead = None
        
    def reverse(self):
        prev = None
        curr = self.head
        
        while curr is not None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        self.head = prev
            
    #print
    def printList(self):
        temp = self.head
        while temp.next is not None:
            print(str(temp.data) + " -> ", end='')#print in a mannerly fashion
            temp = temp.next
        #print last value
        print(temp.data)
            

ll = LinkedList()
ll.insert(1)
ll.insert(2)
ll.insert(3)



ll.printList()

ll.reverse()

ll.printList()
            
    
    

                
            
            
