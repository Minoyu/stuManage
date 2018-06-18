//
// Created by minoyu on 18-6-11.
//
#ifndef STUMANAGE_MAIN_H
#define STUMANAGE_MAIN_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#define TruePassword "gjyforever"
#define TryPasswordTimes 2
using namespace std;

/**
 * 菜单布局相关
 */
void printDividerStar();
void printShortStar();
void printLongStar();
void printItemDot();

void printGreetMenu();
void printMainMenu();
void printMainMenuMini();

/**
 * 相关功能函数
 */
//声明全局变量
extern int tryPasswordCount;
void checkLoginPassword(string password);
char* getTime();
void switchFunction(char chooseItemId);

/**
 * 学生相关
 */
/*****************************************************
 * 学生类
 */
class student{
    friend class studentList;
private:
    string name;
    string id;
    int cppScore,mathScore,enScore;
    //指向下一个学生的指针
    student * next;
public:
    void add();
    void readFile(istream & in);

    //打印学生信息
    void display();
    //与传入的对象交换信息
    void swap(student *toExchange);
};

/**************************************************
 * 学生列表类
 */
class studentList{
private:
    student * first;
    student * last;
    int num;
    ifstream in;
    ofstream out;

public:
    studentList();              //学生列表类构造函数
    ~studentList();             //析构函数
    void add();                 //向表中增加学生成绩记录
    void edit();                //修改学生成绩记录
    void removeLast();          //向表中删除最后一个节点
    void remove();              //向表中删除学生成绩记录
    void searchById();          //学号查询学生成绩记录
    void searchByName();        //姓名查询学生成绩记录
    void sortById();            //按学号排序学生成绩记录
    void sortByCpp();           //按Cpp排序学生成绩记录
    void sortByMath();          //按Math排序学生成绩记录
    void sortByEn();            //按En排序学生成绩记录
    void show();                //显示学生信息
    void save();                //保存学生信息

};
extern studentList stuL;
void createStudent();
void editStudent();
void deleteStudent();
void searchStudents();
void sortStudents();
void switchSearchFun(char chooseWayId);
void switchSortFun(char chooseWayId);
void showAllStudents();
//打印学生信息表头
void printStudentTableTitle();
void printStudentTableFoot();

#endif //STUMANAGE_MAIN_H
