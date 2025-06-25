// Курсовой проект «Парсер INI-файлов»

#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

typedef  pair<string, string> ValKey;
typedef  list<ValKey> ListVK;
typedef  pair<string, ListVK> Section;
typedef  vector<Section> IniData; // список секций INI файла
//add_section будет вызываться в тот момент, когда парсер распознает очередную секцию
class add_section
{
public:
    add_section(IniData& data) : data_(data) {}
    void operator()(auto p) const
    {
        data_.push_back(Section(p->c_str(), ListVK()));
    }
    IniData& data_;
};
// add_key будет вызван в тот момент, когда парсер распознает имя нового параметра
class add_key
{
public:
    add_key(IniData& data) : data_(data) {}
    void operator()(auto p) const
    {
        data_.back().second.push_back(ValKey(p->c_str(), string()));
    }

    IniData& data_;
};
// add_value будет вызван в тот момент, когда парсер распознает значение параметра
class add_value
{
public:
    add_value(IniData& data) : data_(data) {}
    void operator()(auto p) const
    {
        data_.back().second.back().second.assign(p->c_str());
    }
    IniData& data_;
};

class ini_parser {
    string file_name_;

public:
    IniData data;
    ini_parser(string file_name) : file_name_(file_name) {
        ifstream in(file_name);
        if (!in)
        {
            cout << "Немогу открыть файл \"" << file_name << '\"' << endl;
        }

        std::string s;
        while (!in.eof())
        {
            std::getline(in, s);
            if (s.find(';') < s.size()) {
                s.erase(s.find(';'), s.size());
            }
            parser(s);
        }
    }

    void parser(string str) {
        if (str.find('[') < str.size()) {
            str.erase(remove(str.begin(), str.end(), '['), str.end());
            str.erase(remove(str.begin(), str.end(), ']'), str.end());
            auto s = make_shared<string>(str);
            add_section sect(data);
            sect(s);
        }
        else if (str.find('=') < str.size()) {
            string tempstr = str;
            string key = str.erase(str.find('='), str.size());
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            string value = tempstr.erase(0, tempstr.find('=') + 1);
            auto k = make_shared<string>(key);
            auto v = make_shared<string>(value);
            add_key Key(data);
            add_value Value(data);
            Key(k);
            Value(v);
        }
    }

    void pars_sort() {
        sort(data.begin(), data.end());
    }

    void print_inidata() {
        cout << endl;
        cout << "IniData section: " << endl;
        for (const auto& i : data) {
            cout << i.first << endl;
            for (const auto& j : i.second) {
                cout << j.first << " = " << j.second << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
};

class first_is
{
public:
    first_is(std::string const& s) : s_(s) {}

    template<class Pair>
    bool operator()(Pair const& p) const { return p.first == s_; }

    string const& s_;
};

bool find_value(IniData ini, string const s, string const p, string& res)
{
    first_is sec(s);
    auto sit = ini.rbegin();
    for (sit = ini.rbegin(); sit != ini.rend(); sit++) {

        if (sit->first == s) {
            ListVK::const_iterator it = find_if(sit->second.begin(), sit->second.end(), first_is(p));
            if (it == sit->second.end())
                continue;
            else {
                res = it->second;
                return true;
            }
        }
        else if (sit == ini.rend()) {
            return false;
        }
        else continue;

    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");

    string file;

    //file = "Test.ini";
    cout << "Введите название ini файла: " << file << endl;
    cin >> file;
    cout << "Файл содержит: " << endl;
    ini_parser parser(file);

    parser.pars_sort();
    parser.print_inidata();

    string section;
    string parameter;
    string res;
    // находим параметр, заданный ранее и вывести его значение
    while (parameter != "0") {
        string res;
        cout << "Введите section (0 - выход): ";
        cin >> section;
        if (section == "0") return 0;
        cout << "Введите parameter  (0 - выход): ";
        cin >> parameter;

        if (find_value(parser.data, section, parameter, res)) {
            cout << "Значение переменной " << parameter << " = " << res << endl;
        }
        else {
            cout << "Параметр " << parameter << " не найден" << endl;
            cout << "Нажмине 0 для выхода" << endl;
            cout << endl;
        }
    }

    return EXIT_SUCCESS;
}