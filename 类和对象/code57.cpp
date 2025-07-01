/*
**案例描述：**
制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料
利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
//抽象基类
class Drink {
public:
    virtual void boilWater() = 0; //煮水
    virtual void brew() = 0;      //冲泡
    virtual void pourInCup() = 0; //倒入杯中
    virtual void addCondiments() = 0; //加入辅料
    //模板方法
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
};
//制作咖啡
class Coffee : public Drink {
public:
	//烧水
	virtual void boilWater() {
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void brew() {
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void pourInCup() {
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void addCondiments() {
		cout << "加入牛奶!" << endl;
	}
};

//制作茶水
class Tea : public Drink {
public:
	//烧水
	virtual void boilWater() {
		cout << "煮自来水!" << endl;
	}
	//冲泡
	virtual void brew() {
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void pourInCup() {
		cout << "将茶水倒入杯中!" << endl;
	}
	//加入辅料
	virtual void addCondiments() {
		cout << "加入枸杞!" << endl;
	}
};
//制作饮品的模板方法
void makeDrink(Drink* drink) 
{
    drink->prepareRecipe();
    delete drink; // 清理内存
}
void test01() {
	makeDrink(new Coffee);
	cout << "--------------" << endl;
	makeDrink(new Tea);
	cout << "--------------" << endl;
}
void makeDrink(Drink &drink)
{
    drink.prepareRecipe(); // 清理内存
}
void test02() {
	Coffee coffee;
	Tea tea;
	makeDrink(coffee);
	cout << "--------------" << endl;
	makeDrink(tea);
    cout << "--------------" << endl;
}

int main() {
	// 设置控制台编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);
	
	test01();
    test02();
	
	system("pause");
	return 0;
}

