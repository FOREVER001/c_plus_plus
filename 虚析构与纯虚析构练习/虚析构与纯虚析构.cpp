#include<iostream>
#include<string>
using namespace std;
//虚析构与纯虚析构
class Animal {
public:
	Animal() {
		cout << "Animal构函数的调用" << endl;
	}
	//纯虚析构
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};


Animal :: ~Animal() 

{
	cout << "Animal纯虚析构函数调用" << endl;
}
class Cat :public Animal {
public:
	Cat(string name) 
	{
		cout << "cat构函数的调用" << endl;
		m_Name = new string(name);
	
	}
	virtual void speak() {
		cout << *m_Name<<"小猫在说话" << endl;
	}

	~Cat() 
	{
	
		if (m_Name !=NULL) {
			cout << "cat析构函数的调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};

void test01() 
{
	//创建在堆区
	Animal* animal = new Cat("Tom");
	animal->speak();
	//释放
	delete animal;

}
int main()
{
	test01();
	system("pause");
	return 0;
}