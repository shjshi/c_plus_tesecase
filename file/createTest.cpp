/**
前置知识


所有打开的文件都有一个当前文件偏移量（current file offset），以下简称为 cfo。cfo 通常是一个非负整数，
用于表明文件开始处到文件当前位置的字节数。读写操作通常开始于 cfo，并且使 cfo 增大，增量为读写的字节数。文件被打开时，cfo 会被初始化为 0，除非使用了O_APPEND 。
*/

/**
 * 什么是当前文件偏移量？ cfo？
 * 文件当前处到文件当前位置的字节数
 *
*/

/**
 * 使用 lseek 函数可以改变文件的 cfo
 */

/* Standard C header */
#include <stdio.h>
/* Unix header */
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
    // fd表示文件，size表示文件大小
    int fd, size;
    // create
    if ((fd = creat("file.hole", S_IRUSR | S_IWUSR)) < 0) {
        printf("creat error\n");
        return -1;
    }
    return 0;
}