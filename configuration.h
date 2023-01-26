//
// Created by Piotr Krzyszowski.
//

int checkValidProcessName(const char *buf,char *pn, const char *p) {
    return p[strlen(pn)] != ' ' || (p - buf - 1 >= 0 && buf[p - buf - 1] != '\n');
}

int getBeginOfKey(const char *buf,char *pn, const char *p){
    return strlen(buf) - strlen(p) + strlen(pn) + 3;
}

#include <sys/fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "logLibrary.h"
#include "staticData.h"

int findKey(char *pn) {
    int fd = open(configFile, O_RDONLY);

    if (fd < 1) {
        perror(openingFileError);
        return -1;
    }

    char buf[maxFileSize];
    int i = 0;

    while (read(fd, &buf[i], 1) > 0)
        i++;

    char *p = strstr(buf, pn);
    if (p == NULL) {
        printf(processNotFound);
        close(fd);
        return -1;
    }

    if (checkValidProcessName(buf,pn,p)) {
        printf(wrongProcessName);
        close(fd);
        return -1;
    }


    i = getBeginOfKey(buf,pn,p);
    int qKey = 0;

    while (buf[i] != '\n') {
        qKey *= 10;
        qKey += buf[i] - ASCI;
        i++;
    }

    printf(queueKey, qKey);

    close(fd);
    return qKey;
}
