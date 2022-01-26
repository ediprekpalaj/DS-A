class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }
    insert(data) {
        let newNode = new Node(data);
        //empty list
        if(this.head === null) {
            this.head = newNode;
        }
        else {
            let currNode = this.head;
            while(currNode.next != null) {
                currNode = currNode.next;
            }
            currNode.next = newNode;
            newNode.next = null
        }
    }

    delete(item) {
        let dummyHead = this.head;
        let prev;
        //case when headnode is to be deleted
        if(dummyHead != null) {
            if(dummyHead.data == item) {
                this.head = dummyHead.next;
                dummyHead = null;
                return;
            }
        }
        //search for the node to be deleted
        while(dummyHead != null) {
            if(dummyHead.data === item){
                break;
            }
            prev = dummyHead
            dummyHead = dummyHead.next
        }
        if(dummyHead === null) {
            return;
        }
        prev.next = dummyHead.next;
        dummyHead = null;
    }

    reverse() {
        let prev = null;
        let curr = this.head;
        while(curr != null) {
            let nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        this.head = prev;
    }

    print() {
        let temp = this.head;
        while(temp.next != null) {
            console.log(temp.data);
            console.log("|");
            console.log("V");
            temp = temp.next;
        }
        console.log(temp.data);
    
    }
}

let ll = new LinkedList();
ll.insert(1);
ll.insert(2);
ll.insert(3);

ll.print();

ll.reverse();
ll.print();