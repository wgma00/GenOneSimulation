#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

void parse_text(std::string str){
    std::stringstream ss(str); 
    std::string t,t2;
    while(std::getline(ss,t, ',')){
        if(t.find("[") != std::string::npos || t.find("{") != std::string::npos){
           getline(ss,t2,','); 
           t = t+','+t2;
        }
        std::cout << t << "\n";
    }
}

int main() {
    std::ifstream in;
    in.open("moves.csv");
    std::string str;
    for(int i = 0;i < 32;i++){
        std::getline(in, str);
        parse_text(str);
    }
    return 0;
}
