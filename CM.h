#ifndef cm_h
#define cm_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
using std::string;
using namespace std;

//类：学生
struct Student
{
    struct information
    {
        string name = "暂无数据";        //姓名
        string id = "暂无数据";          //学号
        string telephone = "暂无数据";   //电话
        string school = "暂无数据";      //学院
        string address = "暂无数据";     //寝室楼栋
        string classnum = "暂无数据";    //班级号
        string temperature = "暂无数据"; //体温
        string vaccine = "暂无数据";     //疫苗注射情况
        struct PCR                       //核酸检测情况
        {
            string date = "暂无数据";        //最近一次核酸检测日期
            string consequence = "暂无数据"; //最近一次核酸检测结果
            uint64_t timeStamp;
        } PCR;
        struct Apply //出校申请情况
        {
            bool state = false; //是否申请
            bool check = false; //是否审批
            string type;        // applyforin applyforout applyforinandout
            bool approval = false;
            string Indate = "暂无数据";
            string Outdate = "暂无数据";
            string reason = "暂无数据";
            string campus = "暂无数据";
        } Apply;
    } information;
    Student *next;
};

//类：宿舍楼
struct Dorm
{
    struct information
    {
        string name = "暂无数据";      //楼名
        string district = "暂无数据";  //区
        string capacity = "暂无数据";  //容量
        string chief = "暂无数据";     //楼长
        string startdate = "暂无数据"; //开始封闭时间
        string enddate = "暂无数据";   //结束封闭时间
        bool flag;                     //封控情况
    } information;
    Dorm *next;
};

//日期处理结构体
struct date
{
    int year;
    int month;
    int day;
};

class Util //信息切分工具
{
    // 所需头文件  <sstream>  <vector>  <string>
public:
    // 函数以单个char字符作为分隔符对string字符串进行分割， 并将分割结果存入vector中，最终返回vector<string>
    static std::vector<string> split(const std::string &s, char delimiter)
    {                                      //  n.	定界符，分隔符;
        std::vector<string> tokens;        // 存放结果
        std::string token;                 // 子串
        std::istringstream tokenStream(s); //使用string s初始化输入流, 标准库头文件 <sstream>
        while (std::getline(tokenStream, token,
                            delimiter))
        {                       //  对于输入流，遇到char的delimiter时 就停止 把结果储存在token中, (同时舍弃遇到的这个char), 定义于<string>
            if (!token.empty()) //因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
                tokens.push_back(token);
        }
        return tokens;
    }

    // 函数以string作为分隔符对string字符串进行分割， 并将分割结果存入vector中，最终返回vector<string>
    static std::vector<string> split(const std::string &s, const std::string &delimiter)
    {                                                                               //  n.	定界符，分隔符;
        std::vector<string> tokens;                                                 // 存放结果
        std::string token;                                                          // 子串
        int i = 0, start = 0, sSize = (int)s.size(), dSize = (int)delimiter.size(); // start为字符子串的起始位置
        while (i < sSize)
        {
            if (isDelimiter2(s, i, delimiter))
            {                                       // 此处也可以使用isDelimiter(s, i, delimiter)  如果遇到了分隔符
                token = s.substr(start, i - start); // 分割字符串
                if (!token.empty())
                { // 因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
                    tokens.push_back(token);
                }
                i += dSize; // 跳过分隔符的长度
                start = i;  // 更新子串的起始位置
            }
            else
            {
                i++;
            }
        }
        token = s.substr(start, i - start); // 分割字符串
        if (!token.empty())
        { //因为会遇到连续的delimiter的情况，这时候token就是空，这种情况不要放入tokens当中
            tokens.push_back(token);
        }
        return tokens;
    }

private:
    // 函数判断字符串s从下标i开始的，长为delimiter的字符子串是否和delimiter全等
    static bool isDelimiter(const std::string &s, int i, const std::string &delimiter)
    {
        int j = 0, sSize = (int)s.size(), dSize = (int)delimiter.size();
        while (i < sSize && j < dSize)
        {
            if (s[i] != delimiter[j])
            {
                return false;
            }
            else
            {
                j++;
                i++;
            }
        }
        return j == dSize;
    }

    // 函数判断字符串s从下标i开始的，长为delimiter的字符子串是否和delimiter全等
    static bool isDelimiter2(const std::string &s, int i, const std::string &delimiter)
    {

        return s.substr(i, delimiter.size()) == delimiter;
    }
};

//清空输入缓冲区
void clean();

//信息导入模块
void help();
void helpofinput();
void helpofstudentinput();
void inputinformation();
void helpofpcrinput();
void inputPCR();
void helpofdorminput();
void inputinformationofdorm();

//第二部分
void helpofsubmit();
void searchforstu(Student *);
void classSearchPCR(Student *);
void dormSearchPCR(Student *);
void SearchExpire(Student *);
void setTimeNow(string &timeNow, uint64_t timeStampN); //设置时间
void setTimeNow();
::uint64_t setTimePCR(string &);
void getTimeNow();

//第三部分：进出校审批
void inandout(Student *head);
void helpforstu();
void searchforper(Student *head);
void applyforinandout(Student *head);
void app(Student *head);
void del(Student *head);
void change(Student *head);
void check(Student *cnt);

//第四部分
date trans1(string d);                //时间字符串转数字
string trans2(date a);                //数字转时间字符串
string datechange(string a);          //日期向后5天函数
string datechange1(string a);         //日期增加1天函数
void modify(Dorm *head);              //楼栋封控状态更改函数
void output(Dorm *head);              //楼栋状态展示函数
void range(Dorm *head);               //解封时间排序函数
bool comparedate(string a, string b); //比较日期先后函数，a在b后面返回true；否则返回false
void display(Dorm a);                 //楼栋信息输出

#endif
