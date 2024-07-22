#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(2, "usage: sleep ticks\n");
        exit(0);
    }

    // 将命令行参数转换为整数
    int ticks = atoi(argv[1]);

    // 调用系统调用 sleep，暂停当前进程指定数量的 ticks
    sleep(ticks);

    exit(0);
}