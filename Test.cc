#include <iostream>
#include <map>


int main() {
    std::cout <<"bonjour le monde ....!!!!" <<std::endl;
    std::map<std::string, int >node;

    node["peter"] = 10;
    node["vala"] = 500;
    node["lemaire"] = 100;
    node["levache"] = 1; 

    for(const auto& ess : node){
        std::cout <<"les valeurs : " <<ess.first <<" > " <<ess.second <<std::endl;
    }

    const auto& it = node.find("peter");
    std::cout <<"le truc : " <<it->first <<" > " <<it->second <<std::endl;

    return 0;
}