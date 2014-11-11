class MinStack {
public:
    void push(int x) {
        m_data.push(x);
        if(m_min.empty()){
            m_min.push(x);
        }else{
            if(x <= m_min.top())
                m_min.push(x);
        }
    }

    void pop() {
        int tmp = m_data.top();
        m_data.pop();
        if(tmp <= m_min.top()){
            m_min.pop();
        }
    }

    int top() {
        return m_data.top();
    }

    int getMin() {
        return m_min.top();
    }
private:
    stack<int> m_data;
    stack<int> m_min;
};