#include "CM.h"

extern const Student *headofstu;
extern int NumofStudents;
extern string timeNow;   //Ŀǰʱ��
extern int timeStampNow; //��ǰ��ʱ���
int main()
{
    cout << "��ʦ��¼�밴 1��ѧ����¼�밴 2" << endl;
    cout << "�����룺";
    int r;
    cin >> r;
    if (r == 1)
    {
        while (true)
        {
            help();
            int n;
            cin >> n;
            switch (n)
            {
            case 1: //��Ϣ����ģ��
            {
                bool flag = false;
                while (true)
                {
                    helpofinput();
                    cin >> n;
                    switch (n)
                    {
                    case 1:
                        clean();
                        helpofstudentinput();
                        inputinformation();
                        clean();
                        break;
                    case 2:
                        clean();
                        helpofpcrinput();
                        inputPCR();
                        clean();
                        break;
                    case 3:
                        clean();
                        helpofdorminput();
                        inputinformationofdorm();
                        clean();
                        break;
                    case 4:
                        flag = true;
                        break;
                    default:
                        cout << "������Ч�����������룺";
                        break;
                    }
                    if (flag)
                        break;
                }
                break;
            }
            case 2: //��Ϣ�ϱ�����ģ��
            {
                bool flag = false;
                while (true)
                {
                    helpofsubmit();
                    cin >> n;
                    switch (n)
                    {
                    case 1:
                        clean();
                        searchforstu((Student *)headofstu);
                        clean();
                        break;
                    case 2:
                        clean();
                        classSearchPCR((Student *)headofstu);
                        clean();
                        break;
                    case 3:
                        clean();
                        dormSearchPCR((Student *)headofstu);
                        clean();
                        break;
                    case 4:
                        clean();
                        SearchExpire((Student *)headofstu);
                        clean();
                        break;
                    case 5:
                        flag = true;
                        break;
                    default:
                        cout << "������Ч�����������룺";
                        break;
                    }
                    if (flag)
                        break;
                }
            }
            break;
            case 3: //����У�Ź���ģ��
                cout << "����Ϊ����ʾ���ύ����ѧ������Ϣ��" << endl;
                inandout((Student *)headofstu);
                break;
            case 4: //
                /* code */
                break;
            case 5: //ʱ������ģ��
                setTimeNow();
                cout << "��ǰʱ�������λ��Сʱ��Ϊ��" << timeStampNow << endl
                     << "��ǰʱ��Ϊ��" << timeNow << endl;
                break;
            default:
                cout << "���������룡";
                break;
            }
        }
    }
    else if (r == 2)
    {
        string s;
        while (true)
        {
            cout << "������ѧ�ţ�";
            cin >> s;
            bool flag = false; //ƥ��ѧ��
            Student *pp = (Student *)headofstu;
            for (int i = 0; i < NumofStudents; ++i)
            {
                if (pp->information.id != s)
                {
                    pp = pp->next;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag) //����ҵ���ѧ��ѧ��
            {
                while (true)
                {
                    bool flag1 = false;
                    helpforstu();
                    int n;
                    cin >> n;
                    switch (n)
                    {
                    case 1: //ѧ��������Ϣ��ѯģ��
                        clean();
                        searchforper(pp);
                        flag1 = true;
                        break;
                    case 2:
                        clean();
                        applyforinandout(pp); //ѧ������С����ģ��
                        flag1 = true;
                        break;
                    default:
                        cout << "���������룡";
                        break;
                    }
                    if (flag1)
                        break;
                }
            }
            else
            {
                cout << "���޴��ˣ����������룡" << endl;
            }
        }
    }
    return 0;
}
