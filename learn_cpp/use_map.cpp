#include <iostream>
#include <map>

typedef std::map<std::string,std::string> ParameterMap;

void set_parameter(const std::string &name, const std::string &value, ParameterMap &parameter){
     parameter[name] = value;
}


int main ()
{
    ParameterMap first;

    set_parameter("ignore_dbm", "True", first);
    set_parameter("Ignore_Dbm", "False", first);
    set_parameter("Ignore_dbm", "false", first);
    set_parameter("Ignore_Dbm", "false", first);
    set_parameter("ignore_Dbm", "False", first);
    set_parameter("Ignore_Dbm", "False", first);
    for(auto it = first.begin(); it != first.end(); ++it){
        std::cout << it->first << "  " << it->second << std::endl;
    }

    return 0;
}


