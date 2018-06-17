//
// Created by minoyu on 18-6-11.
//
#include "../header/main.h"

/**
 * 得到时间
 * @return 时间字符串地址
 */
char* getTime(){
    time_t now = time(0);
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    return dt;
}

/**
 * 密码验证逻辑
 */
void checkLoginPassword(string password){

    if (strcmp(password.c_str(),TruePassword)==0){
        printDividerStar();
        cout<<endl;
        cout<<endl;
        printItemDot();
        cout<<"密码正确,成功登录"<<endl;
        cout<<endl;
        printMainMenu();
    }else{
        //如果密码输入错误
        tryPasswordCount++;
        if (TryPasswordTimes-tryPasswordCount>0){
            printDividerStar();
            cout<<endl;
            printItemDot();
            cout<<"密码错误,您还有"<<TryPasswordTimes-tryPasswordCount<<"次机会重试,请再次输入:"<<endl;
            printItemDot();
            cin>>password;
            checkLoginPassword(password);
        } else{
            printDividerStar();
            cout<<endl;
            cout<<endl;
            printItemDot();
            cout<<"对不起,您为非法用户,告辞~\n"<<endl;
            printDividerStar();
            exit(0);
        }
    }
}


/**
 * 功能切换函数
 * @param chooseItemId
 */
void switchFunction(char chooseItemId){
    switch (chooseItemId){
        case '1':
            //创建学生信息
            createStudent();
            break;
        case '2':
            //显示学生信息
            showAllStudents();
            break;
        case '3':
            //排序学生信息
            sortStudents();
            break;
        case '4':
            //查询学生信息
            searchStudents();
            break;
        case '5':
            //删除学生信息
            deleteStudent();
            break;
        case '6':
            //修改学生信息
            editStudent();
            break;
        case '0':{
            //最后文件流保存学生
            stuL.save();
            //退出系统
            printItemDot();cout<<"数据已经保存成功咯"<<endl;
            printItemDot();cout<<"感谢你的使用,告辞"<<endl;
            exit(0);
        }
            break;
        default:
            //输出提示,再次输入
            cout<<endl;
            printDividerStar();
            cout<<endl;
            cout<<endl;
            printItemDot();
            cout<<"姨,未找到您所输入的选项,请重新输入:";
            cin>>chooseItemId;
            switchFunction(chooseItemId);
            break;
    }
}

