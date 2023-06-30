#include <iostream>
#include <string>
#include <random>

int random(int min, int max){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    return dist6(rng);
}

bool in(char a, std::string b){
    for(int i = 0; i < b.size(); i++){
        if(a == b[i]){
            return true;
        }
    }
    return false;
}

bool in(std::string a, std::string b){

}

int main(){
    //all symbols
    std::string key_num = "0123456789";
    std::string key_a = "abcdefghijklmnopqrstuvwxyz";
    std::string key_A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string key_sym = "_-()";

    //main menu
    std::cout << "Welcome to console password generator" << std::endl;
    std::cout << "Enter keys to generate password" << std::endl;
    std::cout << "-n : in your password was attended numbers" << std::endl;
    std::cout << "-a : in your password was attended lower case" << std::endl;
    std::cout << "-A : in your password was attended upper case" << std::endl;
    std::cout << "-s : in your password was attended symbols" << std::endl;
    std::string keys = "naAs";
    getline(std::cin, keys);
    std::string key_all = "";
    //generate password
    if(in('n', keys))
        key_all += key_num;
    if(in('a', keys))
        key_all += key_a;
    if(in('A', keys))
        key_all += key_A;
    if(in('s', keys))
        key_all += key_sym;
    std::cout << "Enter size of your password" << std::endl;
    int size;
    std::cin >> size;
    std::cout << "GENERATE..." << std::endl;
    std::string password = "";
    for(int i = 0; i < size; i++){
        password += key_all[random(0,key_all.size())];
    }
    std::cout << password << std::endl;
    return 0;
}