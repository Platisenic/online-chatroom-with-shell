#pragma once

#include <string>
#include <map>
#include <deque>
#include "np_single_proc/numberpipeinfo.hpp"
#include "np_single_proc/userpipeinfo.hpp"
class UserInfo{
public:
    UserInfo() = default;
    UserInfo(int u, bool c){
        userid = u;
        sockfd = 0;
        name = "";
        ip = "";
        port = 0;
        conn = c;
        env["PATH"] = "bin:.";
        totalline = 0;
    }
    void setinfo(int s, std::string n, std::string i, unsigned short p, bool c){
        sockfd = s;
        name = n;
        ip = i;
        port = p;
        conn = c;
        env.clear();
        env["PATH"] = "bin:.";
        pipeManager.clear();
        totalline = 0;
        userPipeManager.clear();
    }

    int userid;
    int sockfd;
    std::string name;
    std::string ip;
    unsigned short port;
    bool conn;
    std::map<std::string, std::string> env;
    std::map<int, NumberPipeInfo> pipeManager;
	int totalline;
    std::vector<UserPipeInfo> userPipeManager;
};
