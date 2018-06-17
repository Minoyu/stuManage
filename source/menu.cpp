#include "../header/main.h"
using namespace std;

//输出分隔*
void printDividerStar(){
    cout<<"*****************************************************";
}

//输出长*
void printShortStar(){
    cout<<"***************";
}

//输出短*
void printLongStar(){
    cout<<"*******************";
}

//输出^并对其
void printItemDot(){
    cout<<"\t^ ";
}


//登录次数计数器
int tryPasswordCount = 0;

/**
 * 输出欢迎及登录界面
 */
void printGreetMenu(){
    string password;

    printLongStar();
    cout<<"欢迎进入学生管理系统";
    printLongStar();
    cout<<endl;

    printItemDot();
    cout<<"Made with ❤ by Minoyu 2018-6-15"<<endl;

    printItemDot();
    cout<<"当前系统时间是:\t";
    cout << getTime();

    printItemDot();
    cout<<"进入该系统设有密码,只有2次机会"<<endl;

    printItemDot();
    cout<<"温馨向您提示,登录密码为: "<<TruePassword<<endl;

    printItemDot();
    cout<<"请您输入密码:";
    cin>>password;
    checkLoginPassword(password);
}


/**
 * 主菜单界面
 */
void printMainMenu(){
    printDividerStar();
    cout<<endl;
    char chooseItemId;
    printLongStar();
    cout<<"欢迎来到学生管理系统";
    printLongStar();
    cout<<endl;
    printDividerStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t1 创建学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t2 显示学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t3 排序学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t4 查询学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t5 删除学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t6 修改学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t0 成功退出系统\t\t";
    printShortStar();
    cout<<endl;

    printDividerStar();
    cout<<endl;
    printDividerStar();
    cout<<endl;

    printItemDot();
    cout<<"请输入您想要完成的操作:";
    cin>>chooseItemId;
    switchFunction(chooseItemId);
}

void printMainMenuMini(){
    char chooseItemId;
    printDividerStar();
    cout<<endl;
    printLongStar();
    cout<<"您可以再次选择选项";
    printLongStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t1 创建学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t2 显示学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t3 排序学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t4 查询学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t5 删除学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t6 修改学生信息\t\t";
    printShortStar();
    cout<<endl;

    printShortStar();
    cout<<"\t\t0 成功退出系统\t\t";
    printShortStar();
    cout<<endl;

    printDividerStar();
    cout<<endl;

    printItemDot();
    cout<<"请输入您想要完成的操作:";
    cin>>chooseItemId;
    switchFunction(chooseItemId);
}