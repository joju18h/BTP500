#include <errno.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "client.h"

using namespace std;

key_t key;
int msgid;
bool running;
queue<Message> messageQueue;

void *recv_func(void *arg);

pthread_mutex_t messageQueueMutex;

static void signalHandler(int signo) {
   switch(signo) {
      case SIGINT:
         running = false;
         break;
   }
}

int main(){
    int rc;
    pthread_t tid;

    struct sigaction action;

    action.sa_handler = signalHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    key = ftok("serverclient", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    pthread_mutex_init (&messageQueueMutex, NULL);
    running = true;
    cout<<"Server running"<<endl;

    rc = pthread_create(&tid, NULL, recv_func, NULL);
    if (rc != 0) {
        running = false;
        cerr << "Error creating thread: " << strerror(rc) << endl;
        return -1;
    }
    while(running) {
        while(!messageQueue.empty()) {
            pthread_mutex_lock(&messageQueueMutex);
            Message msg = messageQueue.front();
            messageQueue.pop();
            pthread_mutex_unlock(&messageQueueMutex);
            msg.mtype =  msg.msgBuf.dest;
            msgsnd(msgid, &msg, sizeof(msg.msgBuf), 0);
        }
        sleep(1);
    }
    Message temp;
    sprintf(temp.msgBuf.buf, "Quit");

    for (int i = 0; i < 3; i++) {
        temp.mtype = i + 1;
        msgsnd(msgid, &temp, sizeof(temp.msgBuf), 0);
    }

    pthread_join(tid, NULL);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

void *recv_func(void *arg) {
    while(running) {
        Message msg;
        msgrcv(msgid, &msg, sizeof(msg.msgBuf), 4, 0);
        pthread_mutex_lock(&messageQueueMutex);
        messageQueue.push(msg);
        pthread_mutex_unlock(&messageQueueMutex);
    }
    pthread_exit(NULL);
}

