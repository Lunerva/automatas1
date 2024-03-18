#include "stack.h"

stack::stack()
{
    void top();
    void pop() {
    if (top != null) {
    Object item = top.data;
    top = top.next;
        return item;
    }
    return null;
    }
    void push(int item) {
        Node t = new Node(item);
        t.next = top;
        top = t;
        }
    }
}
