class Stack {
    constructor() {
        this.arr = [];
        this.itemcount = 0;
    }
    
    push(item) {
        this.arr.push(item);
        this.itemcount++;
    }

    pop() {
        this.arr.splice(-1)
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

let stk = new Stack();
stk.push(1);
stk.push(2);
stk.push(3);

stk.display();

stk.pop();
stk.display();