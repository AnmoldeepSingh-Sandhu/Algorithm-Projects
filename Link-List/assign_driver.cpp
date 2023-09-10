#include "assign_obj.h"
#include <iostream>

int main(){
    assign_obj ao1("dsdfdfshfbdfmjykiuuy");
    assign_obj ao2("pqwecmasdckjldjf");
    std::cout << ao1 << std::endl;
    ao1.compact();
    ao2.compact();
    std::cout << ao1 << std::endl;
    assign_obj ao3 = ao1;
    ao3 = ao3 + ao2;
    std::cout << ao2 << std::endl;
    std::cout << ao3 << std::endl;
    ao3.e_add('z');
    ao3.f_add('g');
    ao3.f_add('t');
    ao3.e_add('z');
    ao3.f_add('u');
    ao3.e_add('i');
    ao3.f_add('Z');
    std::cout << ao3 << std::endl;
    ao3.compact();
    std::cout << ao3 << std::endl;
    return 0;
}