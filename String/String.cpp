#include <iostream>

namespace my
{
    class String
    {
    private:
        char *value;

    public:
        String()
        {
            value = nullptr;
        }
        String(const char *temp)
        {
            value = const_cast<char *>(temp);
        }
        String(const String &obj)
        {
            value = obj.value;
        }
        void operator=(String &obj)
        {
            value = obj.value;
        }
        friend std::ostream &operator<<(std::ostream &out, const String &obj);
        friend std::istream &operator>>(std::istream &in, const String &obj);
        friend bool operator==(String &obj1, String &obj2);
        inline unsigned int size()
        {
            int count{0};
            char *tp = new char;
            tp = value;
            while (*tp != '\0')
            {
                count++;
                tp++;
            }
            return count;
        }
        friend char *operator+(String &obj1, String &obj2);
    };
    bool operator==(String &obj1, String &obj2)
    {
        const unsigned int a = obj1.size();
        const unsigned int b = obj2.size();
        char *tp1 = obj1.value;
        char *tp2 = obj2.value;
        if (a != b)
        {

            bool temp = true;
            int i{0};
            while (i != std::min(a, b))
            {
                if (*tp1 != *tp2)
                {
                    temp = false;
                    return temp;
                }
                tp1++;
                tp2++;
                i++;
            }
            return temp;
        }
        bool temp = true;
        int i{0};
        while (i != a)
        {
            if (*obj1.value != *obj2.value)
            {
                temp = false;
                return temp;
            }
            tp1++;
            tp2++;
            i++;
        }
        return temp;
    }
    char *operator+(String &obj1, String &obj2)
    {
        const unsigned int m = obj1.size();
        const unsigned int n = obj2.size();
        char *temp = new char[m+n];
        int i{0};
        char *tp1 = obj1.value;
        char *tp2 = obj2.value;
        while (*tp1 != '\0')
        {
            temp[i] = *tp1;
            tp1++;
            i++;
        }
        while (*tp2 != '\0')
        {
            temp[i] = *tp2;
            tp2++;
            i++;
        }

        return temp;
    }
    std::ostream &operator<<(std::ostream &out, const String &obj)
    {
        out << obj.value;
        return out;
    }
    std::istream &operator>>(std::istream &in, const String &obj)
    {
        in >> obj.value;
        return in;
    }
}

int main()
{
    my::String s1{"Satej"};
    std::cout << s1.size()<<std::endl;
    my::String s2 = "Satslkj";
    if (s1 == s2)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
    my::String s3 = s2 + s1;
    std::cout << s3;

    return 0;
}
