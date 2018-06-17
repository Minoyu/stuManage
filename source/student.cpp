//
// Created by minoyu on 18-6-11.
//
#include "../header/main.h"

/******************************************************
 * 学生类添加函数
 */
void student::add() {
    printItemDot();
    cout<<"请输入学生姓名:";
    cin>>name;
    string tempId="";
    int tempScore=0;
    //学号处理
    printItemDot();
    cout<<"请输入学生学号(十位):";
    cin>>tempId;
    while(tempId.length()!=10){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    id = tempId;

    //成绩处理
    printItemDot();
    cout<<"请输入C++课程的期末成绩:";
    cin>>tempScore;
    while(tempScore<0||tempScore>100){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生成绩输入有误,成绩范围0~100,请再次尝试:";
        cin>>tempScore;
    }
    cppScore = tempScore;

    printItemDot();
    cout<<"请数学课程的期末成绩:";
    cin>>tempScore;
    while(tempScore<0||tempScore>100){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生成绩输入有误,成绩范围0~100,请再次尝试:";
        cin>>tempScore;
    }
    mathScore = tempScore;

    printItemDot();
    cout<<"请英语课程的期末成绩:";
    cin>>tempScore;
    while(tempScore<0||tempScore>100){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生成绩输入有误,成绩范围0~100,请再次尝试:";
        cin>>tempScore;
    }
    enScore = tempScore;
    next=NULL;
}

/**********************************************************
 * 学生类接口定义
 */
void student::readFile(istream & in)
{
    in>>name>>id>>cppScore>>mathScore>>enScore;
}

void student::display(){
    cout<<id<<"\t"<<name<<"  \t"<<cppScore<<"   \t"<<mathScore<<"   \t"<<enScore;
    cout<<endl;
}

//与传入的对象交换信息 用于简单排序法时交换
void student::swap(student *toExchange) {
    string tempName,tempId;
    int tempCppScore,tempMathScore,tempEnScore;
    tempName=name;name=toExchange->name;toExchange->name=tempName;
    tempId=id;id=toExchange->id;toExchange->id=tempId;
    tempCppScore=cppScore;cppScore=toExchange->cppScore;toExchange->cppScore=tempCppScore;
    tempMathScore=mathScore;mathScore=toExchange->mathScore;toExchange->mathScore=tempMathScore;
    tempEnScore=enScore;enScore=toExchange->enScore;toExchange->enScore=tempEnScore;
}

/*******************************************************
 * 学生列表类构造函数
 */
studentList::studentList() {
    in.open("stuDate.txt");
    if (!in){
        cout<<"*欢迎新用户,请先输入用户信息再使用.";
        printShortStar();
        cout<<endl;
        first =NULL;
        last =NULL;
        num = 0;
    }else{
        first = new student;
        last = first;
        num = 0;
        while (!in.eof()){
            last->readFile(in);
            //数据结束 但会余留一个空节点
            if(last->id[0]!=NULL){
                last->next=new student;
                last=last->next;
            }
        }
        //删除空节点
        stuL.removeLast();

        in.close();
        cout<<"*欢迎再次使用,读取学生信息成功.";
        printShortStar();
        cout<<endl;
    }

}

/**
 *通过Id添加学生信息
 */
void studentList::add(){
    student * t =new student;
    t->add();
    student * p = first;
    while(p){
        if(p->id==t->id)
        {
            printItemDot();
            cout<<"注意:\n    学号输入错误或该学生已经存在\n    如需添加，请先删除原纪录再重新录入!"<<endl;
            return;
        }
        p=p->next;
    }
    num++;
    if(first==NULL)
    {
        first=last=t;
        cout<<"*学生信息创建成功:) ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        last->display();
        printStudentTableFoot();
    }
    else
    {
        last->next=t;
        last=last->next;
        cout<<"*学生信息创建成功:) ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        last->display();
        printStudentTableFoot();
    }
}

/**
 *通过Id修改学生信息
 */
void studentList::edit() {
    string tempId;
    char isCheck;
    student *t = first;

    printDividerStar();
    cout<<endl;
    printItemDot();cout<<"请输入要修改的学生学号:";
    cin>>tempId;
    //学号验证
    while(tempId.length()!=10){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    while(t){
        if (t->id==tempId){
            break;
        }
        t=t->next;
    }

    //t已跑到最后为空
    if (!t){
        printItemDot();
        cout<<"注意:\n    未找到您所要修改的学生\n     请确认学号后重试"<<endl;
        return;
    }else{
        cout<<"*已为您查询到该学生 ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        t->display();
        printStudentTableFoot();
    }
    cout<<endl;
    printItemDot();cout<<"确认修改此学生吗(y/n):";
    cin>>isCheck;
    switch (isCheck){
        case 'Y':
        case 'y': {
            //确认修改
            printItemDot();
            cout << "修改学生姓名:";
            cin >> t->name;
            int tempScore = 0;

            //成绩处理
            printItemDot();
            cout << "修改C++课程的期末成绩:";
            cin >> tempScore;
            while (tempScore < 0 || tempScore > 100) {
                printLongStar();
                cout << endl;
                printItemDot();
                cout << "学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin >> tempScore;
            }
            t->cppScore = tempScore;

            printItemDot();
            cout << "修改数学课程的期末成绩:";
            cin >> tempScore;
            while (tempScore < 0 || tempScore > 100) {
                printLongStar();
                cout << endl;
                printItemDot();
                cout << "学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin >> tempScore;
            }
            t->mathScore = tempScore;

            printItemDot();
            cout << "修改英语课程的期末成绩:";
            cin >> tempScore;
            while (tempScore < 0 || tempScore > 100) {
                printLongStar();
                cout << endl;
                printItemDot();
                cout << "学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin >> tempScore;
            }
            t->enScore = tempScore;

            printItemDot();
            cout << "学生信息已成功修改." << endl;
            printStudentTableTitle();
            t->display();
            printStudentTableFoot();
        }
            break;
        case 'N':
        case 'n':
        default :
            printItemDot();
            cout<<"学生信息修改已取消.";
            break;
    }
}

/**
 * 删除最后一个节点
 */
void studentList::removeLast(){
    //删除空节点 p为倒数第二个
    student *p=first;
    while(p->next->next!=NULL){
        p=p->next;
    }
    free(p->next);
    p->next=NULL;
    last=p;
}

/**
 *通过Id删除学生信息
 */
void studentList::remove(){
    string tempId;
    cout<<"*准备删除学生信息 ";
    printShortStar();
    cout<<endl;
    printItemDot();
    cout<<"请输入要删除的学生的学号: ";
    cin>>tempId;
    student *t = first;
    student *p=NULL;
    while(t){
        if(t->id==tempId)
            break;
        p=t;
        t=t->next;
    }
    //t到最后为空
    if(!t){
        printItemDot();
        cout<<"注意:\n    未找到要删除的学生\n     请确认学号后重试"<<endl;
        return;
    }
    //第一个就相同
    if(!p) {
        first=first->next;
        printItemDot();
        cout<<"恭喜:\n    您已成功删除学生"<<tempId<<endl;
        delete t;
    }
    else{
        //把t的下一个地址赋给p的next
        p->next=t->next;
        printItemDot();
        cout<<"恭喜:\n    您已成功删除学生"<<tempId<<endl;
        delete t;
    }
    num--;
}

/**
 *通过Id搜索学生
 */
void studentList::searchById() {
    string tempId;
    student *t = first;

    printDividerStar();
    cout<<endl;
    printItemDot();cout<<"请输入要查找的学生学号:";
    cin>>tempId;
    //学号验证
    while(tempId.length()!=10){
        printLongStar();
        cout<<endl;
        printItemDot();
        cout<<"学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    while(t){
        if (t->id==tempId){
            break;
        }
        t=t->next;
    }

    //t已跑到最后为空
    if (!t){
        printItemDot();
        cout<<"注意:\n    未找到您所要查找的学生\n     请确认学号后重试"<<endl;
        return;
    }else{
        cout<<"*已为您查询到以下学生 ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        t->display();
        printStudentTableFoot();
    }

}

/**
 *通过Name搜索学生
 */
void studentList::searchByName() {
    string tempName;
    student *t = first;
    student *p[] ={NULL};
    int foundCount = 0;

    printDividerStar();
    cout<<endl;
    printItemDot();cout<<"请输入要查找的学生姓名:";
    cin>>tempName;
    while(t){
        if (t->name==tempName){
            p[foundCount]=t;
            foundCount++;
        }
        t=t->next;
    }

    //t已跑到最后为空
    if (!p[0]){
        printItemDot();
        cout<<"注意:\n    未找到您所要查找的学生\n     请确认姓名后重试"<<endl;
        return;
    }else{
        cout<<"*已为您查询到以下学生 ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        for (int i = 0; i < foundCount ; ++i) {
            p[i]->display();
        }
        printStudentTableFoot();
    }
}

/**
 *通过Id排序学生
 */
void studentList::sortById() {
    student *t=first;
    student *p=NULL;

    //无数据后的退出
    if(t==NULL){
        printItemDot();
        cout<<"注意:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for (;t->next!=NULL;t=t->next) {
        for (p=t->next;p!=NULL;p=p->next) {
            if (p->id > t->id){
                p->swap(t);
            }
        }
    }

    cout<<"*已按C++成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();

}

/**
 *通过Cpp排序学生
 */
void studentList::sortByCpp() {
    student *t=first;
    student *p=NULL;

    //无数据后的退出
    if(t==NULL){
        printItemDot();
        cout<<"注意:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for (;t->next!=NULL;t=t->next) {
        for (p=t->next;p!=NULL;p=p->next) {
            if (p->cppScore > t->cppScore){
                p->swap(t);
            }
        }
    }

    cout<<"*已按C++成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();

}

/**
 *通过Math排序学生
 */
void studentList::sortByMath() {
    student *t=first;
    student *p=NULL;

    //无数据后的退出
    if(t==NULL){
        printItemDot();
        cout<<"注意:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for (;t->next!=NULL;t=t->next) {
        for (p=t->next;p!=NULL;p=p->next) {
            if (p->mathScore > t->mathScore){
                p->swap(t);
            }
        }
    }

    cout<<"*已按数学成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();
}

/**
 *通过En排序学生
 */
void studentList::sortByEn() {
    student *t=first;
    student *p=NULL;

    //无数据后的退出
    if(t==NULL){
        printItemDot();
        cout<<"注意:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for (;t->next!=NULL;t=t->next) {
        for (p=t->next;p!=NULL;p=p->next) {
            if (p->enScore > t->enScore){
                p->swap(t);
            }
        }
    }

    cout<<"*已按英语成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();
}

/**
 *通过Name搜索学生
 */
void studentList::show() {
    printStudentTableTitle();
    student *t = first;
    if (t){
        while (t){
            t->display();
            t=t->next;
        }
    }else{
        printItemDot();
        cout<<"注意:当前无学生信息"<<endl;
    }
    printStudentTableFoot();
}

/**
 * 文件流保存学生
 */
void studentList::save()
{
    student *t=first;
    out.open("stuDate.txt");
    for(;t!=NULL;t=t->next)
        out<<t->name<<"\t"<<t->id<<"\t"<<t->cppScore<<"\t"
           <<t->mathScore<<"\t"<<t->enScore<<'\n';
    out.close();
}

studentList::~studentList()
{
    save();
}

/**
 * 创建学生信息相关逻辑
 */
void createStudent(){
    cout<<"*正在创建学生信息 ";
    printShortStar();
    cout<<endl;
    stuL.add();
}

/**
 * 删除学生信息相关逻辑
 */
void deleteStudent(){
    stuL.remove();
}

/**
 * 显示学生信息相关逻辑
 */
void showAllStudents(){
    cout<<"*显示所有学生信息 ";
    printShortStar();
    cout<<endl;
    stuL.show();
}

/**
 * 修改学生信息相关逻辑
 */
void editStudent(){
    cout<<"*进入修改学生信息 ";
    printShortStar();
    cout<<endl;
    stuL.edit();

}

/**
 * 查询学生信息逻辑
 */
void searchStudents(){
    char chooseWayId;
    cout<<"*如何查询学生信息 ";
    printShortStar();
    cout<<endl;
    cout<<endl;
    printItemDot();printLongStar();cout<<endl;
    printItemDot();cout<<"❤ 1.按学生的姓名查找(支持重名)"<<endl;
    printItemDot();cout<<"❤ 2.按学生的学号查找(学号唯一)"<<endl;
    printItemDot();cout<<"❤ 3.显示所有学生信息"<<endl;
    printItemDot();printLongStar();cout<<endl;
    cout<<endl;
    printItemDot();cout<<"请选择查找方式:";
    cin>>chooseWayId;
    switchSearchFun(chooseWayId);
}

/**
 * 切换查询方式函数
 * @param chooseWayId
 */
void switchSearchFun(char chooseWayId){
    switch (chooseWayId){
        case '1':
            //按姓名
            stuL.searchByName();
            break;
        case '2':
            //按学号
            stuL.searchById();
            break;
        case '3':
            //全部
            showAllStudents();
            break;
        default:
            printItemDot();cout<<"无您所输入的选项,请确认后重试:";
            cin>>chooseWayId;
            switchSearchFun(chooseWayId);
    }
}


/**
 * 排序学生信息逻辑
 */
void sortStudents(){
    char chooseWayId;
    cout<<"*如何排序学生信息 ";
    printShortStar();
    cout<<endl;
    cout<<endl;
    printItemDot();printLongStar();cout<<endl;
    printItemDot();cout<<"❤ 1.按学生的C++成绩"<<endl;
    printItemDot();cout<<"❤ 2.按学生的数学成绩"<<endl;
    printItemDot();cout<<"❤ 3.按学生的英语成绩"<<endl;
    printItemDot();cout<<"❤ 4.按学生的学号"<<endl;
    printItemDot();printLongStar();cout<<endl;
    cout<<endl;
    printItemDot();cout<<"请选择排序方式:";
    cin>>chooseWayId;
    switchSortFun(chooseWayId);
}

/**
 * 切换排序方式函数
 * @param chooseWayId
 */
void switchSortFun(char chooseWayId){
    switch (chooseWayId){
        case '1':
            //按Cpp
            stuL.sortByCpp();
            break;
        case '2':
            //按数学
            stuL.sortByMath();
            break;
        case '3':
            //按英语
            stuL.sortByEn();
            break;
        case '4':
            //按学号
            stuL.sortById();
            break;
        default:
            printItemDot();cout<<"无您所输入的选项,请确认后重试:";
            cin>>chooseWayId;
            switchSortFun(chooseWayId);
    }
}

void printStudentTableTitle(){
    cout<<endl;
    cout<<"------------------学生列表------------------"<<endl;
    cout<<"\t"<<"学号"<<"  \t"<<"姓名"<<"  \t"<<"C++"<<"  \t"<<"数学"<<"  \t"<<"英语"<<endl;
}

void printStudentTableFoot(){
    cout << "------------------列表结束------------------" << endl;
    cout<<endl;
}