/*电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作 
*/
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// 抽象基类 CPU
class CPU 
{
public:
    virtual void calculate() = 0; // 纯虚函数，计算
    virtual ~CPU() {} // 虚析构函数
};
// 抽象基类显卡
class GPU
{
public:
    virtual void display() = 0; // 纯虚函数，显示
    virtual ~GPU() {} // 虚析构函数
};
// 抽象基类内存条
class Memory
{
public:
    virtual void store() = 0; // 纯虚函数，存储
    virtual ~Memory() {} // 虚析构函数
};
class Computer
{
public:
    Computer(CPU* cpu, GPU* gpu, Memory* memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    void work()
    {
        //让零件工作
        m_cpu->calculate();
        m_gpu->display();
        m_memory->store();
    }
    ~Computer()
    {
        // 释放零件指针
        if(m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL; // 避免悬空指针
        }
        // 释放显卡指针
        if(m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL; // 避免悬空指针
        }
        // 释放内存条指针
        if(m_memory != NULL)    
        {
            delete m_memory;
            m_memory = NULL; // 避免悬空指针
        }
    }

private:
    CPU* m_cpu; // CPU指针
    GPU* m_gpu; // 显卡指针
    Memory* m_memory; // 内存条指针
};
//具体厂商
// Intel厂商的CPU
class IntelCPU : public CPU 
{
public:
    virtual void calculate() override 
    {
        cout << "Intel CPU 正在计算..." << endl;
    }
};
// Intel厂商的显卡
class IntelGPU : public GPU
{
public:
    virtual void display() override 
    {
        cout << "Intel GPU 正在显示..." << endl;
    }
};
// Intel厂商的内存条
class IntelMemory : public Memory
{
public:
    virtual void store() override
    {
        cout << "Intel Memory 正在存储..." << endl;
    }
};
//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo CPU 正在计算...！" << endl;
	}
};

class LenovoGPU:public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo GPU 正在显示...！" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void store()
	{
		cout << "Lenovo Memory 正在存储...！" << endl;
	}
};
void test01()
{
    //第一台电脑零件
    CPU* intelCpu = new IntelCPU;
    GPU* intelGpu = new IntelGPU;
    Memory* intelMemory = new IntelMemory;
    cout << "组装第一台电脑..." << endl;
    Computer* computer1 = new Computer(intelCpu, intelGpu, intelMemory); // 电脑组装完成
    computer1->work(); // 电脑开始工作
    delete computer1; // 释放内存
    cout << "第一台电脑组装完成..." << endl;
    cout << "---------------------------------" << endl;
    //第二台电脑零件
    Computer* computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    computer2->work();
    delete computer2;
    cout << "第二台电脑组装完成..." << endl;
    cout << "---------------------------------" << endl;
    //第三台电脑零件
    Computer* computer3 = new Computer(new IntelCPU, new LenovoGPU, new LenovoMemory);
    computer3->work();
    delete computer3;
    cout << "第三台电脑组装完成..." << endl;
    cout << "---------------------------------" << endl;

}
int main()
{
    // 设置控制台编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);
    test01();
    cout << "电脑组装测试完成！" << endl;
    system("pause");

    return 0;
}