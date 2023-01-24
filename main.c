//
// Created by Piotr Krzyszowski.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include "printer.h"
#include "logLibrary.h"
#include "staticData.h"
#include "configuration.h"
#include "validation.h"

struct msgbuf {
    long type;
    char cmd[maxSize];
    char fifo[maxSize];
} message;

struct senderStructure {
    char buf[maxBufferSize];
    char usr[maxSize];
    char cmd[maxSize];
    char fifo[maxSize];
    char ans[maxAnswearSize];
} senderStructure;

void prepareSenderData() {
    int i = 0, j = 0;

    while (senderStructure.buf[i] != ' ') {
        senderStructure.usr[j++] = senderStructure.buf[i++];
    }

    i += 2;
    j = 0;
    while (senderStructure.buf[i] != '"') {
        senderStructure.cmd[j++] = senderStructure.buf[i++];
    }

    i += 3;
    j = 0;
    while (senderStructure.buf[i] != '"') {
        senderStructure.fifo[j++] = senderStructure.buf[i++];
    }
}

void unlinkWithError(char *error){
    perror(error);
    unlink(senderStructure.fifo);
}

void sender() {

    while (1) {

        printf(requestInfo);

        scanf("%[^\n]s", senderStructure.buf);
        scanf("%*c");

        if (!strcmp(senderStructure.buf, "exit")) {
            printf(exit);
            break;
        }

        if (!checkInput(senderStructure.buf)) {
            printf(wrongInput);
            continue;
        }

        prepareSenderData();

        printf(inputMessage
               senderStructure.usr, senderStructure.cmd, senderStructure.fifo);

        if (mkfifo(senderStructure.fifo, 0666) < 0) {
            perror(creatingFIFOError);
            continue;
        }

        message.type = 1;
        strcpy(message.cmd, senderStructure.cmd);
        strcpy(message.fifo, senderStructure.fifo);

        int usrMsgKey = findKey(senderStructure.usr);
        if (usrMsgKey < 0) {
            unlinkWithError(findingQueueKeyError);
            continue;
        }

        int usrMsgId = msgget(usrMsgKey, IPC_CREAT | 0666);
        if (usrMsgId < 0) {
            unlinkWithError(openingMessageQueueError);
            continue;
        }

        if (msgsnd(usrMsgId, &message, sizeof(message), 0) < 0) {
            unlinkWithError(sendingMessageQueueError);
            continue;
        }

        int fifoFd = open(senderStructure.fifo, O_RDONLY);
        if (fifoFd < 0) {
            unlinkWithError(openingFIFOError);
            continue;
        }

        if (read(fifoFd, senderStructure.ans, maxAnswearSize) < 0) {
            unlinkWithError(readingFIFOError);
            continue;
        }

        close(fifoFd);
        unlink(senderStructure.fifo);

        printf(fifoAnswer, senderStructure.ans);
    }
}



int main(int argc, char *argv[]) {
    printArgs(argc, argv);

    if (argc != 2) {
        printf(wrongProcessNumber);
        return 1;
    }


    int qkey = findKey(argv[1]);
    if (qkey < 0) {
        perror(findingQueueKeyError);
        return 1;
    }


    int qid = msgget(qkey, IPC_CREAT | 0666);
    if (0 > qid) {
        perror(creatingQueueError);
        return 1;
    }
    printf(createdQueueId, qid);


    int pid = fork();
    switch (pid) {
        case -1:
            perror(forkingProcessError);
            msgctl(qid, IPC_RMID, NULL);
            return 1;
        default:
            sender();
    }


    msgctl(qid, IPC_RMID, NULL);

    kill(pid, SIGKILL);

    return 0;
}