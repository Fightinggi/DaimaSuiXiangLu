#include <iostream>
#include <queue>
#include <exception>

template<class T> 
class MyStack {
public:
    void push(const T& num);
    T pop();
    T top();
    void swapQueue();// ����dataQueue��helpQueue
private:
    std::queue<T> dataQueue;    // ���ݶ���
    std::queue<T> helpQueue;    // ��������
};

template<typename T>
void MyStack<T>::swapQueue() {
    std::queue<T> tmp = dataQueue;
    dataQueue = helpQueue;
    helpQueue = tmp;
}

template<typename T>
void MyStack<T>::push(const T& num) {   // �������������,�������ݶ��Ƿŵ�dataQueue����
    dataQueue.push(num);
}

template<typename T>
T MyStack<T>::pop() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    else {
        while (dataQueue.size() > 1) {  // ��dataQueue
            helpQueue.push(dataQueue.front());
            dataQueue.pop();
        }
        T res = dataQueue.front();    // ���dataQueue�����Ԫ��Ҳ����stack��ջ��Ԫ��
        dataQueue.pop();    // dataQueue�Ѿ�Ϊ��,helpQueue���n-1����
        swapQueue();   // ������������
        return res;
    }
}

template<typename T>
T MyStack<T>::top() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    else {
        while (dataQueue.size() > 1) {  // ��dataQueue
            T data = dataQueue.front();
            dataQueue.pop();
            helpQueue.push(data);
        }
        T res = dataQueue.front();    // ���dataQueue�����Ԫ��Ҳ����stack��ջ��Ԫ��
        dataQueue.pop();    // ��ʱdataQueue�Ѿ�Ϊ��,helpQueue���n-1����
        helpQueue.push(res);    // ��ȡtopԪ����Ҫ��ԭ�����ݷ���
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

