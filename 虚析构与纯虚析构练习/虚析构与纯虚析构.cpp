#include<iostream>
#include<string>
using namespace std;
//�������봿������
class Animal {
public:
	Animal() {
		cout << "Animal�������ĵ���" << endl;
	}
	//��������
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};


Animal :: ~Animal() 

{
	cout << "Animal����������������" << endl;
}
class Cat :public Animal {
public:
	Cat(string name) 
	{
		cout << "cat�������ĵ���" << endl;
		m_Name = new string(name);
	
	}
	virtual void speak() {
		cout << *m_Name<<"Сè��˵��" << endl;
	}

	~Cat() 
	{
	
		if (m_Name !=NULL) {
			cout << "cat���������ĵ���" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};

void test01() 
{
	//�����ڶ���
	Animal* animal = new Cat("Tom");
	animal->speak();
	//�ͷ�
	delete animal;

}
int main()
{
	test01();
	system("pause");
	return 0;
}