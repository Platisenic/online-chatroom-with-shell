#pragma once

#include "sys/shm.h"
#define MAX_USERS 36
#define MAX_MSG_NUM 32
#define MAX_MSG_SIZE 1600
#define MAX_NAME_SIZE 32
#define MAX_IP_SIZE 32
#define MAX_FIFO_NAME 32

enum MSGTYPES{
    DEFAULT = 0,
	LOGOUT,
    JUST_PIPED
};

struct UserPipeInfo{
    char FIFOname[MAX_FIFO_NAME];
    int recvfd;
    bool exist;
};

struct UserInfo{
    pid_t pid;
    int userid;
    char name[MAX_NAME_SIZE];
    char ip[MAX_IP_SIZE];
    unsigned short port;
    bool conn;
    char msgbuffer[MAX_MSG_NUM][MAX_MSG_SIZE];
    int msgsenderid[MAX_MSG_NUM];
    int piperecvid[MAX_MSG_NUM];
    enum::MSGTYPES msgtypes[MAX_MSG_NUM];
    int readEnd;
    int writeEnd;
};

struct ShareMemory{
    UserInfo users[MAX_USERS];
    UserPipeInfo userPipeManager[MAX_USERS][MAX_USERS];
};