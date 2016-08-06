#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>
#include "../src/move.cpp"

struct TestMoveParsing{
    bool test_load_moves(){
        std::ifstream in;
        in.open("../data/moves.csv");
        std::vector<Move*>ret;
        std::string str;
        for(int i = 0;i < 3;i++){
            in >> str;
            ret.push_back(new Move(str));
        }
        std::vector<std::string>prog_out = {ret[0]->get_name(),
                                            ret[1]->get_name(),
                                            ret[2]->get_name()};
        std::vector<std::string>correct_out = {"earthquake","bodyslam",
                                               "rockslide"};
        assert(prog_out == correct_out);
        std::cout << "TestMovePrasing: - test_load_moves: AC" << std::endl;
    }
};

int main(){
    TestMoveParsing tmp;
    tmp.test_load_moves();
    return 0;
}
