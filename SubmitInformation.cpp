#include "CM.h"
extern string timeNow = "000"; //Ŀǰʱ��
extern int timeStampNow = 0;   //��ǰ��ʱ���
extern int NumofStudents;
int CheckLeapYear(int beginYear, int internal)
{

    int Count = 0;
    int endYear = beginYear + internal;
    for (size_t i = beginYear; i <= endYear; ++i)
    {
        if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
        {
            ++Count;
        }
    }

    return Count;
}
string TimeStamp_Convert(uint64_t time)
{
    //ʱ���ת����ǰ������    ��������ʱ�䣺1970-1-1 8:00
    stringstream stream;
    string _year;
    string _month;
    string _day;
    string _hour;
    string res;

    int yearCount = 0;
    int monthCount = 0;
    int dayCount = 0;
    int hourCount = 0;

    int gap = 8;
    int DayInternal = 24;                       //һ��
    int CommonYearInternal = DayInternal * 365; //ƽ��
    int LeapYearInternal = DayInternal * 366;   //����

    vector<int> VecMonth =
        {0,
         DayInternal * 31,
         DayInternal * (31 + 28),
         DayInternal * (31 + 28 + 31),
         DayInternal * (31 + 28 + 31 + 30),
         DayInternal * (31 + 28 + 31 + 30 + 31),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30),
         DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)};

    if (time < CommonYearInternal)
    {
        // 1970��֮��
        yearCount = 0;
        for (size_t i = 1; i < VecMonth.size(); ++i)
        {
            if (time <= VecMonth[i])
            {
                monthCount = i;
                break;
            }
            continue;
        }
        // time = VecMonth[monthCount] - time;
        int tmp = monthCount - 1;
        time = time - VecMonth[tmp];
        // day
        time = (time + gap) / DayInternal;
        dayCount = time + 1;
    }
    else
    {
        yearCount = time / CommonYearInternal;
        time = time - yearCount * CommonYearInternal;
        for (size_t i = 1; i < VecMonth.size(); ++i)
        {
            if (time <= VecMonth[i])
            {
                monthCount = i;
                break;
            }
            continue;
        }
        int tmp = monthCount - 1;
        time = time - VecMonth[tmp];

        // day
        dayCount = (time + gap) / DayInternal + 1;
        time = time - (dayCount - 1) * DayInternal + 8;

        int leapyearCount = 0;
        if (leapyearCount = CheckLeapYear(1970, yearCount)) //��������������������
        {
            dayCount -= leapyearCount;
        }
        yearCount += 1970;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (yearCount % 4 == 0 && yearCount % 100 != 0 || yearCount % 400 == 0)
            months[2] = 29;
        if (dayCount < 1)
        {
            dayCount += months[--monthCount];
        }
        // hour
        hourCount = time;
    }

    stream << yearCount;
    stream >> _year;
    stream.clear();
    stream << monthCount;
    stream >> _month;
    stream.clear();
    stream << dayCount;
    stream >> _day;
    stream.clear();
    stream << hourCount;
    stream >> _hour;
    if (monthCount < 10)
        _month = "0" + _month;
    if (dayCount < 10)
        _day = "0" + _day;
    if (hourCount < 10)
        _hour = "0" + _hour;
    res = _year + ":" + _month + ":" + _day + ":" + _hour;
    return res;
}
void setTimeNow()
{
    cout << "����ʱ����밴1������ʱ���밴2:";
    cin.clear();
    uint64_t timeStampNow;
    bool flag = false;
    int n;
    while (true)
    {
        cin >> n;
        cin.clear();
        switch (n)
        {
        case 1:
            cout << "�����뵱ǰʱ�����";
            cin >> timeStampNow;
            setTimeNow(::timeNow, timeStampNow);
            flag = true;
            break;
        case 2:
            cout << "�����뵱ǰʱ�䣨����������1970.1.1.8����";
            getline(cin, ::timeNow);
            setTimeNow(::timeNow, timeStampNow);
            flag = true;
            break;
        default:
            cout << "\n����������������룺";
            cin.clear();
            break;
        }
        if (flag)
            break;
    }
}
uint64_t setTimePCR(string &timeNow)
{
    int year, month, day, hour;
    string time;
    stringstream stream;
    vector<string> splitSemicolon = Util::split(timeNow, "."); // ��Ӣ�ķֺ�Ϊ�ָ������ж��ַ������зָ�
    stream << splitSemicolon[0];
    stream >> year;
    stream.clear();
    stream << splitSemicolon[1];
    stream >> month;
    stream.clear();
    stream << splitSemicolon[2];
    stream >> day;
    stream.clear();
    stream << splitSemicolon[3];
    stream >> hour;
    stream.clear();
    int yearInternal = year - 1970;
    int plus = CheckLeapYear(1970, yearInternal - 1);
    uint64_t timeStampN = (yearInternal * 365 + plus) * 24;
    int dayInternal = 0;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        months[2] = 29;
    for (int i = 1; i < month; ++i)
    {
        dayInternal += months[i];
    }
    dayInternal += day - 1;
    hour = hour - 8;
    timeStampN += dayInternal * 24 + hour;
    return timeStampN;
}
void setTimeNow(string &timeNow, uint64_t timeStampN) //���õ�ǰʱ�亯��
{
    int year, month, day, hour;
    string time;
    //    if (timeStampN != 0) //������õ�ʱ������ʱ�������ֱ����ʱ���ת��
    //    {
    //        timeNow = TimeStamp_Convert(timeStampN);
    //        timeStampNow = timeStampN;
    //        return;
    //    }

    string s;
    stringstream stream;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "."); // ��Ӣ�ķֺ�Ϊ�ָ������ж��ַ������зָ�
    stream << splitSemicolon[0];
    stream >> year;
    stream.clear();
    stream << splitSemicolon[1];
    stream >> month;
    stream.clear();
    stream << splitSemicolon[2];
    stream >> day;
    stream.clear();
    stream << splitSemicolon[3];
    stream >> hour;
    stream.clear();
    int yearInternal = year - 1970;
    int plus = CheckLeapYear(1970, yearInternal - 1);
    timeStampN = (yearInternal * 365 + plus) * 24;
    int dayInternal = 0;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        months[2] = 29;
    for (int i = 1; i < month; ++i)
    {
        dayInternal += months[i];
    }
    dayInternal += day - 1;
    hour = hour - 8;
    timeStampN += dayInternal * 24 + hour;
    timeNow = s;
    cout << "\n���óɹ�����ǰʱ��Ϊ��" << timeNow << "����ǰʱ���Ϊ����λ��Сʱ����" << timeStampN;
}

void classSearchPCR(Student *head)
{
    cout << "������༶�ţ����践����һ�������롮-1������";
    string classNum;
    cin >> classNum;
    if (classNum == "-1")
        ;
    else
    {
        Student *cnt = head->next;
        int numOfClass = 0, numOfDone = 0;
        while (cnt != NULL)
        {
            if (cnt->information.classnum == classNum)
            {
                ++numOfClass;
                if (timeNow.substr(0, 10) == cnt->information.PCR.date.substr(0, 10)) //����ж������������������ʽ����
                {
                    ++numOfDone;
                }
            }
            cnt = cnt->next;
        }
        cout << classNum << "��" << timeNow.substr(0, 10) << "Ӧ��" << numOfClass << "�ˣ�ʵ��" << numOfDone << "�ˡ�" << endl;
    }
}

void dormSearchPCR(Student *head)
{
    cout << "����������¥���ţ���ʽ��X��XX�������践����һ�������롮-1������";
    string dormitory;
    cin >> dormitory;
    if (dormitory == "-1")
        ;
    else
    {
        Student *cnt = head->next;
        int numOfDorm = 0, numOfDone = 0;
        while (cnt != NULL)
        {
            if (cnt->information.address == dormitory)
            {
                ++numOfDorm;
                if (timeNow.substr(0, 10) == cnt->information.PCR.date.substr(0, 10)) //����ж������������������ʽ����
                {
                    ++numOfDone;
                }
            }
            cnt = cnt->next;
        }
        cout << dormitory << "����¥" << timeNow.substr(0, 10) << "Ӧ��" << numOfDorm << "�ˣ�ʵ��" << numOfDone << "�ˡ�" << endl;
    }
}

void SearchExpire(Student *head)
{
    Student *cnt = head->next;
    string id;
    while (true)
    {
        cin.clear();
        cnt = head->next;
        cout << "������ѧ�ţ����践����һ�������롮-1������";
        cin >> id;
        if (id == "-1")
            break;
        else
        {
            while (cnt != NULL)
            {
                if (cnt->information.id == id)
                    break;
                cnt = cnt->next;
            }
            if (cnt == NULL)
                cout << "\nѧ�Ų����ڣ�����������" << endl;
            else
            {
                int duration = timeStampNow - cnt->information.PCR.timeStamp;
                cout << "\n���ϴκ���ʱ��Ϊ" << cnt->information.PCR.date << "��";
                if (duration > 72)
                    cout << "���ĺ����Ѿ����ڣ��뾡����к�����飡";
                else
                    cout << "���������ⱨ�浽�ڻ���" << 72 - duration << "Сʱ��";
            }
        }
    }
}

void searchforstu(Student *head)
{
    string s;
    while (true)
    {
        cout << "������ѧ�ţ�";
        cin >> s;
        bool flag = false; //ƥ��ѧ��
        Student *pp = head;
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
            cout << "ѧԺ��" << pp->information.school << endl;
            cout << "������" << pp->information.name << endl;
            cout << "ѧ�ţ�" << pp->information.id << endl;
            cout << "�绰��" << pp->information.telephone << endl;
            cout << "����¥����" << pp->information.address << endl;
            cout << "�༶�ţ�" << pp->information.classnum << endl;
            cout << "���£�" << pp->information.temperature << endl;
            cout << "����ע�������" << pp->information.vaccine << endl;
            cout << "���һ�κ��������ڣ�" << pp->information.PCR.date << endl;
            cout << "���һ�κ���������" << pp->information.PCR.consequence << endl;
        }
        else
        {
            cout << "���޴��ˣ����������룡" << endl;
        }
    }
}