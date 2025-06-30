// Курсовой проект «Парсер INI-файлов»

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

using ValKey = pair<string, string>;
using ListVK = list<ValKey>;
using Section = pair<string, ListVK>;
using IniData = vector<Section>; // список секций INI файла

class FirstIs
{
public:
    FirstIs(std::string const& s) : s_(s) {}

    template<class Pair>
    bool operator()(Pair const& p) const { return p.first == s_; }

    string const& s_;
};

class IniParser {
    string file_name_;

public:
    IniData data;
    IniParser(string file_name) : file_name_(file_name) {
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
            add_section(str);

        }
        else if (str.find('=') < str.size()) {
            string tempstr = str;
            string key = str.erase(str.find('='), str.size());
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            string value = tempstr.erase(0, tempstr.find('=') + 1);
            add_key(key);
            add_value(value);
        }
    }

    //add_section будет вызываться в тот момент, когда парсер распознает очередную секцию
    void add_section(string p) {
        data.push_back(Section(p, ListVK()));
    }
    // add_key будет вызван в тот момент, когда парсер распознает имя нового параметра
    void add_key(string p) {
        data.back().second.push_back(ValKey(p, string()));
    }
    // add_value будет вызван в тот момент, когда парсер распознает значение параметра
    void add_value(string p) {
        data.back().second.back().second.assign(p);
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

    bool find_value(string const s, string const p, string& res)
    {
        
        auto sit = data.rbegin();
        for (sit = data.rbegin(); sit != data.rend(); sit++) {

            if (sit->first == s) {
                ListVK::const_iterator it = find_if(sit->second.begin(), sit->second.end(), FirstIs(p));
                if (it == sit->second.end())
                    continue;
                else {
                    res = it->second;
                    return true;
                }
            }
            else if (sit == data.rend()) {
                return false;
            }
            else continue;
        }
        return false;
    }

public:
    //1. Основной шаблон, по которому будет проводиться сопоставление
    template<typename T>
    T get_value(const string& section, const string& var) {
        static_assert(sizeof(T) == -1, "не реализован тип для get_value"); // Тут только одно предупреждение, чтобы сказать, что надо пользоваться уже заданными конвертациями
    }

private:
    string get_value_string(const string& section, const string& var) {
        string res;
        if (find_value(section, var, res)) {
            return res;
        }
        else {
            return "0";
        }
    }
};
//2. конкретный шаблон для стринга
template<>
string IniParser::get_value(const string& section, const string& var) {
    return get_value_string(section, var);
}
//3. конкретный шаблон для инта
template<>
int IniParser::get_value(const string& section, const string& var) {
    int val;
    string str_val = get_value_string(section, var);
    val = stoi(str_val);
    return val;
}

template<>
double IniParser::get_value(const string& section, const string& var) {
    double val;
    string str_val = get_value_string(section, var);
    val = stold(str_val);
    return val;
}

int main()
{
    setlocale(LC_ALL, "rus");

    string file;

    //file = "Test.ini";
    cout << "Введите название ini файла: " << file << endl;
    cin >> file;
    cout << "Файл содержит: " << endl;
    IniParser parser(file);

    parser.pars_sort();
    parser.print_inidata();

    cout << "Section1, string, var2 = " << parser.get_value<string>("Section1", "var2") << endl;
    cout << "Section3, double, mur = " << parser.get_value<double>("Section3", "mur") << endl;
    cout << "Section1, int, var1 = " << parser.get_value<int>("Section1", "var1") << endl;

    string section;
    string parameter;
    // находим параметр, заданный ранее и вывести его значение
    while (parameter != "0") {
        string res;
        cout << "Введите section (0 - выход): ";
        cin >> section;
        if (section == "0") return 0;
        cout << "Введите parameter  (0 - выход): ";
        cin >> parameter;

        cout << section << " параметр " << parameter << " = " << parser.get_value<string>(section, parameter) << endl;
    }

    return EXIT_SUCCESS;
}