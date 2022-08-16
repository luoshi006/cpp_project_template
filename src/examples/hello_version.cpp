#include <iostream>
#include "git_version.h"

using namespace GitVersion;

int main(int argc, const char** argv) {
    std::cout<<"Hello world!"<<std::endl;
    std::cout<<"git version: "<<get_git_version()<<std::endl;
    std::cout<<"git revision: "<<get_git_commit()<<std::endl;
    std::cout<<"git branch: "<<get_git_branch()<<std::endl;
    std::cout<<"git date: "<<get_git_date()<<std::endl;
    std::cout<<"build time: "<<get_build_time()<<std::endl;
    std::cout<<"build host: "<<get_build_hostname()<<std::endl;
    return 0;
}