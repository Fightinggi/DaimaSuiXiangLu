#include <iostream>
#include <stack>
#include <string>
using namespace std;

template<typename T>
class Queue {
private:
	stack<T>stackA;	//栈A  入栈
	stack<T>stackB;	//栈B  出栈
	T back_elem;	//用于存储新添加的元素
public:
	Queue() {};
	void push(T elem);	//将新元素压入队列（压入栈A）中
	void pop();			//将元素弹出队列（从栈B中弹出）
	T front();			//队首元素
	T back();			//队尾元素
	int size()const;    //队列长度
	bool empty()const;  //队列是否为空
};

/*
入队操作
实现队列的push操作， 每次进行添加操作，都会相应得对栈A进行添加元素。并对back_elem赋值
*/
template<typename T>
void Queue<T>::push(T elem)
{
	stackA.push(elem);//将元素压入队列
	back_elem = elem;	//存储新添加的元素
}

/*
出队操作
实现队列的pop操作，每次进行删除操作，因为栈B负责pop操作。
首先判断栈B是否为空？
a.如果栈B为空，则判断A是否为空？
		如果A也为空，则输出错误信息，此时队列为空。
		如果A不为空，则将栈A中的所有数据存储到B中。执B.push(A.top()), A.pop().然后在对栈B
			执行，B.pop()操作，将队列的头元素删除
b.如果栈B不为空， 则直接对栈B执行 B.pop()操作。
*/
template<typename T>
void Queue<T>::pop()
{
	if (stackB.empty()) {
		// 从stIn导入数据直到stIn为空
		while (!stackA.empty()) {
			stackB.push(stackA.top());
			stackA.pop();
		}
	}
	//int result = stackB.top();
	stackB.pop();
}

/*
队首元素
*/
template<typename T>
T Queue<T>::front()
{
	if (!stackB.empty())
	{
		return stackB.top();
	}
	else if (!stackA.empty())
	{
		while (!stackA.empty())
		{
			stackB.push(stackA.top());
			stackA.pop();
		}
		return stackB.top();
	}
	else
	{
		std::cout << "error front(),empty queue!" << std::endl;
	}
}

/*
队尾元素
*/
template<typename T>
T Queue<T>::back()
{
	if (!empty())
	{
		return back_elem;
	}
	else
	{
		std::cout << "error back(),empty queue!" << std::endl;
	}
}

/*
队列长度
*/
template<typename T>
int Queue<T>::size() const
{
	return stackA.size() + stackB.size();
}

/*
队列是否为空
*/
template<typename T>
bool Queue<T>::empty() const {
	return stackA.empty() && stackB.empty();
}



int main()
{
	Queue<int>queue;
	//入队操作
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	cout << "Four times push() After:" << endl;
	//队首元素
	//cout << "The queue front:" << queue.front() << endl;
	//队尾元素
	cout << "The queue back:" << queue.back() << endl;
	//队列size
	cout << "The queue size:" << queue.size() << endl;
	//出队操作
	queue.pop();
	cout << "The queue front:" << queue.front() << endl;
	queue.pop();
	//queue.pop();
	//queue.pop();
	cout << "----------------------------" << endl;
	cout << "Four times pop() After:" << endl;
	//队首元素
	cout << "The queue front:" << queue.front() << endl;
	//队尾元素
	cout << "The queue back:" << queue.back() << endl;
	//队列size
	cout << "The queue size:" << queue.size() << endl;

	//system("pause");
	return 0;
}