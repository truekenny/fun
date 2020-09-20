/*
 * gcc example.c -o example -pthread
 *
 * run:
 *   ./example
 * or:
 *   sudo ./example
 *
 * Expected output:
 *   thread
 *
 * Debian 10.3 output:
 *   thread
 *   thread
 *   thread
 *
 * Do u know why? ^.^
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <pthread.h>

void setNobody();

void *i15MinutesHandler(void *_args) {
    while (1) {
        printf("thread\n");

        sleep(900);
    }

    return 0;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, i15MinutesHandler, NULL);

    sleep(1);
    setNobody();

    return EXIT_SUCCESS;
}

void setNobody() {
    const char *name = "nobody";
    struct passwd *p;
    if ((p = getpwnam(name)) != NULL) {
        setgid(p->pw_gid);
        setuid(p->pw_uid);
    };
}
