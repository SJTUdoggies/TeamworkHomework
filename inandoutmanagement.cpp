#include "CM.h"

void inandout(Student *head)
{
    int r;
    Student *cnt = head->next;
    while (cnt != NULL)
    {
        if (cnt->information.Apply.state == true)
        {
            cout << "ѧԺ��" << cnt->information.school << "  ������" << cnt->information.name << "  ѧ�ţ�" << cnt->information.id
                 << "  ����У����" << cnt->information.Apply.campus << "  ����ԭ��" << cnt->information.Apply.reason << "  �������ͣ�" << cnt->information.Apply.type;
            if (cnt->information.Apply.type == "applyforin")
                cout << "������Уʱ�䣺" << cnt->information.Apply.Indate << endl;
            else if (cnt->information.Apply.type == "applyforout")
                cout << "�����Уʱ�䣺" << cnt->information.Apply.Outdate << endl;
            else if (cnt->information.Apply.type == "applyforinandout")
                cout << "������Уʱ�䣺" << cnt->information.Apply.Indate << " "
                     << "�����Уʱ�䣺" << cnt->information.Apply.Outdate << endl;
            cout << "����������ͨ���밴 1����ͨ���밴 2����";
            int n;
            bool flag = false;
            while (true)
            {
                cin >> n;
                switch (n)
                {
                case 1:
                    flag = true;
                    cnt->information.Apply.check = true;
                    break;
                case 2:
                    flag = true;
                    cnt->information.Apply.check = false;
                    break;
                default:
                    cout << "�Ƿ�����!����������:";
                    break;
                }
                if (flag)
                    break;
            }
        }
        cnt = cnt->next;
        cout << "���������밴 1���˳��밴 0��";
        while (true)
        {
            cin >> r;
            bool flag1 = false;
            switch (r)
            {
            case 1:
                flag1 = true;
                break;
            case 0:
                return;
            default:
                cout << "�Ƿ�����!����������:";
                break;
            }
            if (flag1)
                break;
        }
    }
    cout << "���д���������ȫ������" << endl;
}

void searchforper(Student *cnt)
{
    cout << "ѧԺ��" << cnt->information.school << endl;
    cout << "������" << cnt->information.name << endlv;
    cout << "ѧ�ţ�" << cnt->information.id << endl;
    cout << "�绰��" << cnt->information.telephone << endl;
    cout << "����¥����" << cnt->information.address << endl;
    cout << "�༶�ţ�" << cnt->information.classnum << endl;
    cout << "���£�" << cnt->information.temperature << endl;
    cout << "����ע�������" << cnt->information.vaccine << endl;
    cout << "���һ�κ��������ڣ�" << cnt->information.PCR.date << endl;
    cout << "���һ�κ���������" << cnt->information.PCR.consequence << endl;
}

void applyforinandout(Student *head)
{
    int n;
    bool flag = false;
    while (true)
    {
        cout << "�ύ�����밴 1" << endl;
        cout << "ɾ�������밴 2" << endl;
        cout << "�޸������밴 3" << endl;
        cout << "��ѯ�����밴 4" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            app(head);
            flag = true;
            break;
        case 2:
            del(head);
            flag = true;
            break;
        case 3:
            change(head);
            flag = true;
            break;
        case 4:
            check(head);
            flag = true;
            break;
        default:
            break;
        }
        if (flag)
            break;
    }
}

void app(Student *head)
{
    int r;
    head->information.Apply.state = true;
    cout << "����������У����";
    cin >> head->information.Apply.campus;
    cout << "������У�밴 1��" << endl;
    cout << "�����У�밴 2��" << endl;
    cout << "�������У�밴 3��" << endl;
    cout << "�����룺";
    cin >> r;
    switch (r)
    {
    case 1:
        head->information.Apply.type == "applyforin";
        cout << "������������Уʱ�䣨xxxx.xx.xx����";
        cin >> head->information.Apply.Indate;
        break;
    case 2:
        head->information.Apply.type == "applyforout";
        cout << "�����������Уʱ�䣨xxxx.xx.xx����";
        cin >> head->information.Apply.Outdate;
        break;
    case 3:
        head->information.Apply.type == "applyforinandout";
        cout << "������������Уʱ�䣨xxxx.xx.xx����";
        cin >> head->information.Apply.Indate;
        cout << "�����������Уʱ�䣨xxxx.xx.xx����";
        cin >> head->information.Apply.Outdate;
        break;
    }
    cout << "����������ԭ��";
    cin >> head->information.Apply.reason;
}

void del(Student *head)
{
    head->information.Apply.state = false;
}

void change(Student *head)
{
    int r;
    bool flag2 = false;
    cout << "�޸�У���밴 1" << endl;
    cout << "�޸Ľ���У����/ʱ���밴 2" << endl;
    cout << "�޸�ԭ���밴 3" << endl;
    cout << "�����룺";
    while (true)
    {
        cin >> r;
        switch (r)
        {
        case 1:
            cout << "����������У����";
            cin >> head->information.Apply.campus;
            flag2 = true;
            break;
        case 2:
            cout << "������У�밴 1��" << endl;
            cout << "�����У�밴 2��" << endl;
            cout << "�������У�밴 3��" << endl;
            cout << "�����룺";
            cin >> r;
            switch (r)
            {
            case 1:
                head->information.Apply.type == "applyforin";
                cout << "������������Уʱ�䣨xxxx.xx.xx����";
                cin >> head->information.Apply.Indate;
                break;
            case 2:
                head->information.Apply.type == "applyforout";
                cout << "�����������Уʱ�䣨xxxx.xx.xx����";
                cin >> head->information.Apply.Outdate;
                break;
            case 3:
                head->information.Apply.type == "applyforinandout";
                cout << "������������Уʱ�䣨xxxx.xx.xx����";
                cin >> head->information.Apply.Indate;
                cout << "�����������Уʱ�䣨xxxx.xx.xx����";
                cin >> head->information.Apply.Outdate;
                break;
            }
            flag2 = true;
            break;
        case 3:
            cout << "����������ԭ��";
            cin >> head->information.Apply.reason;
            flag2 = true;
            break;
        default:
            cout << "�Ƿ����룡";
            break;
        }
        if (flag2)
            break;
    }
}

void check(Student *cnt)
{
    cout << "ѧԺ��" << cnt->information.school << "  ������" << cnt->information.name << "  ѧ�ţ�" << cnt->information.id
         << "  ����У����" << cnt->information.Apply.campus << "  ����ԭ��" << cnt->information.Apply.reason << "  �������ͣ�" << cnt->information.Apply.type;
    if (cnt->information.Apply.type == "applyforin")
        cout << "������Уʱ�䣺" << cnt->information.Apply.Indate << endl;
    else if (cnt->information.Apply.type == "applyforout")
        cout << "�����Уʱ�䣺" << cnt->information.Apply.Outdate << endl;
    else if (cnt->information.Apply.type == "applyforinandout")
        cout << "������Уʱ�䣺" << cnt->information.Apply.Indate << " "
             << "�����Уʱ�䣺" << cnt->information.Apply.Outdate << endl;
    cout << "����״̬��";
    if (cnt->information.Apply.check)
        cout << "��ͨ��";
    else
        cout << "δͨ��";
}