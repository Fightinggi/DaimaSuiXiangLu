#include <iostream>
#include <stack>
#include <string>
using namespace std;

template<typename T>
class Queue {
private:
	stack<T>stackA;	//ջA  ��ջ
	stack<T>stackB;	//ջB  ��ջ
	T back_elem;	//���ڴ洢����ӵ�Ԫ��
public:
	Queue() {};
	void push(T elem);	//����Ԫ��ѹ����У�ѹ��ջA����
	void pop();			//��Ԫ�ص������У���ջB�е�����
	T front();			//����Ԫ��
	T back();			//��βԪ��
	int size()const;    //���г���
	bool empty()const;  //�����Ƿ�Ϊ��
};

/*
��Ӳ���
ʵ�ֶ��е�push������ ÿ�ν�����Ӳ�����������Ӧ�ö�ջA�������Ԫ�ء�����back_elem��ֵ
*/
template<typename T>
void Queue<T>::push(T elem)
{
	stackA.push(elem);//��Ԫ��ѹ�����
	back_elem = elem;	//�洢����ӵ�Ԫ��
}

/*
���Ӳ���
ʵ�ֶ��е�pop������ÿ�ν���ɾ����������ΪջB����pop������
�����ж�ջB�Ƿ�Ϊ�գ�
a.���ջBΪ�գ����ж�A�Ƿ�Ϊ�գ�
		���AҲΪ�գ������������Ϣ����ʱ����Ϊ�ա�
		���A��Ϊ�գ���ջA�е��������ݴ洢��B�С�ִB.push(A.top()), A.pop().Ȼ���ڶ�ջB
			ִ�У�B.pop()�����������е�ͷԪ��ɾ��
b.���ջB��Ϊ�գ� ��ֱ�Ӷ�ջBִ�� B.pop()������
*/
template<typename T>
void Queue<T>::pop()
{
	if (stackB.empty()) {
		// ��stIn��������ֱ��stInΪ��
		while (!stackA.empty()) {
			stackB.push(stackA.top());
			stackA.pop();
		}
	}
	//int result = stackB.top();
	stackB.pop();
}

/*
����Ԫ��
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
��βԪ��
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
���г���
*/
template<typename T>
int Queue<T>::size() const
{
	return stackA.size() + stackB.size();
}

/*
�����Ƿ�Ϊ��
*/
template<typename T>
bool Queue<T>::empty() const {
	return stackA.empty() && stackB.empty();
}



int main()
{
	Queue<int>queue;
	//��Ӳ���
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	cout << "Four times push() After:" << endl;
	//����Ԫ��
	//cout << "The queue front:" << queue.front() << endl;
	//��βԪ��
	cout << "The queue back:" << queue.back() << endl;
	//����size
	cout << "The queue size:" << queue.size() << endl;
	//���Ӳ���
	queue.pop();
	cout << "The queue front:" << queue.front() << endl;
	queue.pop();
	//queue.pop();
	//queue.pop();
	cout << "----------------------------" << endl;
	cout << "Four times pop() After:" << endl;
	//����Ԫ��
	cout << "The queue front:" << queue.front() << endl;
	//��βԪ��
	cout << "The queue back:" << queue.back() << endl;
	//����size
	cout << "The queue size:" << queue.size() << endl;

	//system("pause");
	return 0;
}