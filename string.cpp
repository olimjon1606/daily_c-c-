#include <iostream>
#include <string>

using namespace std;

void output(const std::string &str)
{
    cout << str << endl;
}

void to_upper(string &str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
    }
    cout << str << endl;
}
void charac(string &str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        cout << str[i] << endl;
    }
}
std::string in_parens(const std::string &str)
{
    size_t a = str.find('(');

    if (a == std::string::npos)
    {
        return "";
    }

    size_t b = str.find(')', a);

    if (b == std::string::npos)
    {
        return "";
    }

    size_t n = b - a;

    return str.substr(a + 1, n - 1);
}

int main()
{
    string word = "Hello my name is Olimjon";
    to_upper(word);
    charac(word);
    output(in_parens("Get the first text (inbetween parentheses)"));
}