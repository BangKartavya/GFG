class SpecialQueue {
  private:
    queue<int> q;
    multiset<int> s;
  public:

    void enqueue(int x) {
        q.push(x);
        s.insert(x);
    }

    void dequeue() {
        
        int val = q.front();
        q.pop();
        s.erase(s.find(val));
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return *(begin(s));
    }

    int getMax() {
        return *(--end(s));
    }
};