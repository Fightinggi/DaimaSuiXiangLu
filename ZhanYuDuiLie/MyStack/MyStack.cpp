#include <iostream>
#include <queue>
#include <exception>

template<class T> 
class MyStack {
public:
    void push(const T& num);
    T pop();
    T top();
    void swapQueue();// 交换dataQueue和helpQueue
private:
    std::queue<T> dataQueue;    // 数据队列
    std::queue<T> helpQueue;    // 帮助队列
};

template<typename T>
void MyStack<T>::swapQueue() {
    std::queue<T> tmp = dataQueue;
    dataQueue = helpQueue;
    helpQueue = tmp;
}

template<typename T>
void MyStack<T>::push(const T& num) {   // 不管是上面情况,送入数据都是放到dataQueue里面
    dataQueue.push(num);
}

template<typename T>
T MyStack<T>::pop() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    else {
        while (dataQueue.size() > 1) {  // 当dataQueue
            helpQueue.push(dataQueue.front());
            dataQueue.pop();
        }
        T res = dataQueue.front();    // 这个dataQueue的最后元素也就是stack的栈顶元素
        dataQueue.pop();    // dataQueue已经为空,helpQueue存放n-1个数
        swapQueue();   // 交换二个队列
        return res;
    }
}

template<typename T>
T MyStack<T>::top() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    else {
        while (dataQueue.size() > 1) {  // 当dataQueue
            T data = dataQueue.front();
            dataQueue.pop();
            helpQueue.push(data);
        }
        T res = dataQueue.front();    // 这个dataQueue的最后元素也就是stack的栈顶元素
        dataQueue.pop();    // 此时dataQueue已经为空,helpQueue存放n-1个数
        helpQueue.push(res);    // 获取top元素需要将原来数据返回
        swapQueue();
        return res;
    }
}

int main() {
    MyStack<int> s;
    s.push(4);
    s.push(6);
    s.push(3);
    s.push(1);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    s.push(5);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}

