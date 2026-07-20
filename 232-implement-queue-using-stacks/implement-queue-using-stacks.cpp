class MyQueue {
    stack<int> in, out;

    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    void push(int x) {
        in.push(x);
    }

    int pop() {
        transfer();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        transfer();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};