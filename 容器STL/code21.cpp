#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

/*
学习目标：vector中存放自定义数据类型，并打印输出
*/

//自定义数据类型
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//存放对象
void test01()
{
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    vector<Person> v;
	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

    v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
    //tips:这里的（*it）是和  <Person>的person类型对应的
    for(vector<Person>::iterator it = v.begin();it !=v.end(); it++)
    {
        cout << "Name:"<<(*it).mName<< " Age:"<<(*it).mAge <<endl;    
    }

}
//放对象指针
void test02()
{
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    vector<Person*> v;
	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

    v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
    //tips:这里的（*it）是和  <Person>的person类型对应的
    for(vector<Person*>::iterator it = v.begin();it !=v.end(); it++)
    {
        cout << "Name:"<<(*it)->mName<< " Age:"<<(*it)->mAge <<endl;    
    }

}
int main()
{
    test01();
    
	test02();

	system("pause");

	return 0;

}