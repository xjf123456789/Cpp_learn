/*
#### 3.4.1 案例描述
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

#### 3.4.2 实现步骤
1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分
*/

#include <deque>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
//选手类
class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name   = name;
        this->m_Score  = score;
    }
    string m_Name; //姓名
    int m_Score; //平均分
};
void createPerson(vector<Person>&v)
{
    string nameSeed = "ABCDE";
    for(int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name,score);
        //将创建的person对象 放入到容器中
        v.push_back(p);
    }
}

//打分
void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin();it != v.end();it++)
    {
        //将评委的分数放入到deque容器中
        deque<int>d;
        for(int i= 0;i < 10; i++)
        {
            int score = rand()% 41 + 60; //60~100
            d.push_back(score);
        }
    	sort(d.begin(), d.end());
        //去除最高和最低分
		d.pop_back();
		d.pop_front();
        		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每个评委的分数
		}
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}
void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    srand((unsigned int)time(NULL));

    //1、创建5名选手
    vector<Person> v;
    createPerson(v);
    setScore(v);

	//3、显示最后得分
	showScore(v);

	system("pause");

	return 0;


}