
/**
 *list链表
 *实现增删改查的功能
 *
 */

#include<iostream>
#include<vector>
const int INF = 0x7f7f7f;
using namespace  std;
template<class T>
struct  Node
{
	Node<T>* left;
	Node<T>* right;
	T val;
	Node(Node* l, Node* r, T val)
	{
		this->left = l;
		this->right = r;
		this->val = val;
	}
};


template<typename T>
class List
{
private: 
	Node<T>* start, * end;
	int size = 0;
public:
	List()
	{
		start= end = nullptr;
	}
	List(const vector<T>&inventory);
	void add(const T& val);
	void insert(const T& val,int index);
	void del(int index);
	void display() const;
};

template<typename T>
List<T>::List(const vector<T>&inventroy)
{
	start = end = nullptr;
	for (int i = 0; i < inventroy.size(); i++)
		add(inventroy[i]);
}

template<typename T>
void List<T>::add(const T& val) 
{
	size++;
	if (start == nullptr && end == nullptr)
	{
		start = end = new Node<T>(nullptr, nullptr, val);
		return;
	}
	Node<T> *newNode = new Node<T>(end, nullptr, val);
	end->right = newNode;
	end = end->right;

}

template<typename T>
void List<T>::insert(const T& val,int index) 
{
	if (index == size)
	{
		add(val);
		return;
	}

	Node<T>* tmpA=start;
	for (int i = 0; i < index; i++)tmpA = tmpA->right;
	Node<T>* tmpB = tmpA->right;
	Node<T>* nodeVal = new Node<T>(tmpA, tmpB, val);
	tmpA->right = nodeVal;
	tmpB->left = nodeVal;
}

template<typename T>
void List<T>::del(int index) 
{
	if (index == 0)
	{
		auto first = start->right;
		delete start;
		start = first;
		return;
	}
	if (index == size)
	{
		auto last = end->left;
		delete end;
		end = last;
		return;
	}
	auto tmp = start;
	for (int i = 0; i < index; i++)tmp = tmp->right;
	auto tmpA = tmp->left;
	auto tmpB = tmp->right;
	delete tmp;
	tmpA->right = tmpB;
	tmpB->left = tmpA;
}

template<typename T>
void List<T>::display() const
{
	for (auto iter = start; iter != end; iter = iter->right)
		cout << iter->val<<" ";
	cout << end->val;
}


int main()
{
	vector<int>tmp = { 1,2,3,4 };
	List<int>list(tmp);
	list.insert(22, 0);
	list.del(0);
	list.display();
}
