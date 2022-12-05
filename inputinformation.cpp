#include "CM.h"

//¼��ѧ������
extern int NumofStudents = 0;
//ѧ��ͷ����ָ��
extern Student *pofstu{};
extern Student *rearofstu = new Student;
extern const Student *headofstu = rearofstu;

//¼������¥��
extern int NumofDorms = 0;
//����ͷ����ָ��
extern Dorm *pofdorm{};
extern Dorm *rearofdorm = new Dorm;
extern const Dorm *headofdorm = rearofdorm;

//¼��ѧ����Ϣ
void inputinformation()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "��"); // �����ķֺ�Ϊ�ָ������ж��ַ������зָ�
    NumofStudents += splitSemicolon.size();               //����¼��ѧ������
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        pofstu = new Student;
        rearofstu->next = pofstu;
        rearofstu = pofstu;
        // �����Ķ���Ϊ�ָ������ַ������зָ�
        vector<string> splitComma = Util::split(splitSemicolon[i], "��");
        for (int j = 0; j < splitComma.size(); ++j)
        {
            // ������ð��Ϊ�ָ������ַ������зָ�
            vector<string> splitColon = Util::split(splitComma[j], "��");
            if (splitColon[0] == "����")
            {
                pofstu->information.name = splitColon[1];
            }
            else if (splitColon[0] == "ѧ��")
            {
                pofstu->information.id = splitColon[1];
            }
            else if (splitColon[0] == "�绰")
            {
                pofstu->information.telephone = splitColon[1];
            }
            else if (splitColon[0] == "ѧԺ")
            {
                pofstu->information.school = splitColon[1];
            }
            else if (splitColon[0] == "����¥��")
            {
                pofstu->information.address = splitColon[1];
            }
            else if (splitColon[0] == "�༶")
            {
                pofstu->information.classnum = splitColon[1];
            }
            else if (splitColon[0] == "����")
            {
                pofstu->information.temperature = splitColon[1];
            }
        }
    }
    cout << "num:" << NumofStudents;
}
//¼�������Ϣ
void inputPCR()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "��"); // �����ķֺ�Ϊ�ָ������ж��ַ������зָ�
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        // �����Ķ���Ϊ�ָ������ַ������зָ�
        vector<string> splitComma = Util::split(splitSemicolon[i], "��");
        //�ҵ�ѧ��ѧ�Ų��洢
        string idforpcr;
        for (int j = 0; j < splitComma.size(); ++j)
        {
            bool flag1 = false;
            // ������ð��Ϊ�ָ������ַ������зָ�
            vector<string> splitColon = Util::split(splitComma[j], "��");
            if (splitColon[0] == "ѧ��")
            {
                idforpcr = splitColon[1];
                flag1 = true;
            }
            if (flag1)
                break;
        }
        //����ѧ�������ݿ�����Ϣ���бȶ�
        bool flag2 = false;
        Student *p1 = (Student *)headofstu;
        for (int i = 0; i < NumofStudents; ++i)
        {
            if (p1->information.id != idforpcr)
            {
                p1 = p1->next;
            }
            else
            {
                flag2 = true;
                break;
            }
        }
        if (flag2) //����ҵ���ѧ��ѧ��
        {
            for (int j = 0; j < splitComma.size(); ++j)
            {
                // ������ð��Ϊ�ָ������ַ������зָ�
                vector<string> splitColon = Util::split(splitComma[j], "��");
                if (splitColon[0] == "����")
                {
                    p1->information.PCR.date = splitColon[1];
                    p1->information.PCR.timeStamp = setTimePCR(p1->information.PCR.date);
                }
                else if (splitColon[0] == "���")
                {
                    p1->information.PCR.consequence = splitColon[1];
                }
            }
        }
        else //���δ�ҵ���ѧ��ѧ��
        {
            cout << "û�������ݿ����ҵ�ѧ��Ϊ��" << idforpcr << "��ѧ��" << endl;
        }
    }
}
//¼��¥����Ϣ
void inputinformationofdorm()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "��"); // �����ķֺ�Ϊ�ָ������ж��ַ������зָ�
    NumofDorms += splitSemicolon.size();                  //����¼������¥��
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        pofdorm = new Dorm;
        rearofdorm->next = pofdorm;
        rearofdorm = pofdorm;
        // �����Ķ���Ϊ�ָ������ַ������зָ�
        vector<string> splitComma = Util::split(splitSemicolon[i], "��");
        for (int j = 0; j < splitComma.size(); ++j)
        {
            // ������ð��Ϊ�ָ������ַ������зָ�
            vector<string> splitColon = Util::split(splitComma[j], "��");
            if (splitColon[0] == "¥��")
            {
                pofdorm->information.name = splitColon[1];
            }
            else if (splitColon[0] == "����")
            {
                pofdorm->information.district = splitColon[1];
            }
            else if (splitColon[0] == "����")
            {
                pofdorm->information.capacity = splitColon[1];
            }
            else if (splitColon[0] == "¥��")
            {
                pofdorm->information.chief = splitColon[1];
            }
        }
    }
}

void clean()
{
    char c;
    while ((c = getchar()) != '\n')
        ;
}
