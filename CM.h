#ifndef cm_h
#define cm_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
using std::string;
using namespace std;

//�ࣺѧ��
struct Student
{
    struct information
    {
        string name = "��������";        //����
        string id = "��������";          //ѧ��
        string telephone = "��������";   //�绰
        string school = "��������";      //ѧԺ
        string address = "��������";     //����¥��
        string classnum = "��������";    //�༶��
        string temperature = "��������"; //����
        string vaccine = "��������";     //����ע�����
        struct PCR          //���������
        {
            string date = "��������";        //���һ�κ���������
            string consequence = "��������"; //���һ�κ�������
            uint64_t timeStamp;
        } PCR;
        struct Apply //��У�������
        {
            bool state = false; //�Ƿ�����
            bool check = false; //�Ƿ�����
            string type;        // applyforin applyforout applyforinandout
            bool approval = false;
            string Indate = "��������";
            string Outdate = "��������";
            string reason = "��������";
            string campus = "��������";
        } Apply;
    } information;
    Student *next;
};

//�ࣺ����¥
struct Dorm
{
    struct information
    {
        string name = "��������";     //¥��
        string district = "��������"; //��
        string capacity = "��������"; //����
        string chief = "��������";    //¥��
    } information;
    Dorm *next;
};

class Util //��Ϣ�зֹ���
{
    // ����ͷ�ļ�  <sstream>  <vector>  <string>
public:
    // �����Ե���char�ַ���Ϊ�ָ�����string�ַ������зָ �����ָ�������vector�У����շ���vector<string>
    static std::vector<string> split(const std::string &s, char delimiter)
    {                                      //  n.	��������ָ���;
        std::vector<string> tokens;        // ��Ž��
        std::string token;                 // �Ӵ�
        std::istringstream tokenStream(s); //ʹ��string s��ʼ��������, ��׼��ͷ�ļ� <sstream>
        while (std::getline(tokenStream, token,
                            delimiter))
        {                       //  ����������������char��delimiterʱ ��ֹͣ �ѽ��������token��, (ͬʱ�������������char), ������<string>
            if (!token.empty()) //��Ϊ������������delimiter���������ʱ��token���ǿգ����������Ҫ����tokens����
                tokens.push_back(token);
        }
        return tokens;
    }

    // ������string��Ϊ�ָ�����string�ַ������зָ �����ָ�������vector�У����շ���vector<string>
    static std::vector<string> split(const std::string &s, const std::string &delimiter)
    {                                                                               //  n.	��������ָ���;
        std::vector<string> tokens;                                                 // ��Ž��
        std::string token;                                                          // �Ӵ�
        int i = 0, start = 0, sSize = (int)s.size(), dSize = (int)delimiter.size(); // startΪ�ַ��Ӵ�����ʼλ��
        while (i < sSize)
        {
            if (isDelimiter2(s, i, delimiter))
            {                                       // �˴�Ҳ����ʹ��isDelimiter(s, i, delimiter)  ��������˷ָ���
                token = s.substr(start, i - start); // �ָ��ַ���
                if (!token.empty())
                { // ��Ϊ������������delimiter���������ʱ��token���ǿգ����������Ҫ����tokens����
                    tokens.push_back(token);
                }
                i += dSize; // �����ָ����ĳ���
                start = i;  // �����Ӵ�����ʼλ��
            }
            else
            {
                i++;
            }
        }
        token = s.substr(start, i - start); // �ָ��ַ���
        if (!token.empty())
        { //��Ϊ������������delimiter���������ʱ��token���ǿգ����������Ҫ����tokens����
            tokens.push_back(token);
        }
        return tokens;
    }

private:
    // �����ж��ַ���s���±�i��ʼ�ģ���Ϊdelimiter���ַ��Ӵ��Ƿ��delimiterȫ��
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

    // �����ж��ַ���s���±�i��ʼ�ģ���Ϊdelimiter���ַ��Ӵ��Ƿ��delimiterȫ��
    static bool isDelimiter2(const std::string &s, int i, const std::string &delimiter)
    {

        return s.substr(i, delimiter.size()) == delimiter;
    }
};

//������뻺����
void clean();

//��Ϣ����ģ��
void help();
void helpofinput();
void helpofstudentinput();
void inputinformation();
void helpofpcrinput();
void inputPCR();
void helpofdorminput();
void inputinformationofdorm();

//�ڶ�����
void helpofsubmit();
void searchforstu(Student *);
void classSearchPCR(Student *);
void dormSearchPCR(Student *);
void SearchExpire(Student *);
void setTimeNow(string &timeNow, uint64_t timeStampN); //����ʱ��
void setTimeNow();
::uint64_t setTimePCR(string &);

//�������֣�����У����
void inandout(Student *head);
void helpforstu();
void searchforper(Student *head);
void applyforinandout(Student *head);
void app(Student *head);
void del(Student *head);
void change(Student *head);
void check(Student *cnt);

#endif
