class Queue {
    constructor() {
        this.arr = [];
        this.itemcount = 0;
    }
    
    enqueue(item) {
        this.arr.push(item);
        this.itemcount++;
    }

    dequeue() {
        this.arr.shift()
    }

    empty() {
        return this.arr.length === 0;
    }

    top() {
        return this.arr[this.arr.length - 1];
    }

    display() {
        var str = ""
        for(var i = 0; i < this.arr.length; i++) {
            str += this.arr[i] + " ";
        }
        console.log(str)
    }
}

let q = new Queue();
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.display()
q.dequeue()
q.display()