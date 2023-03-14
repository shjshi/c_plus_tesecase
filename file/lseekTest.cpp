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

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define SRC_FILE_NAME "src_file"
#define DEST_FILE_NAME "dest_file"
//根据传入的参数来设置offset
#define OFFSET (atoi(args[1]))

int main() {
    int src_file, dest_file;
    unsigned char buff[BUFFER_SIZE];
    int real_read_len, off_set;

    src_file = open(SRC_FILE_NAME, O_RDONLY);
    dest_file = open(DEST_FILE_NAME, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE );//owner权限：rw
    if (src_file < 0 || dest_file < 0) {
        fprintf(stderr, "Open file error!\n");
        exit(1);
    }
    off_set = lseek(src_file, -OFFSET, SEEK_END);//注意，这里对offset取了相反数
    printf("lseek() reposisiton the file offset of src_file: %d\n", off_set);
    while((real_read_len = read(src_file, buff, sizeof(buff))) > 0) {
        write(dest_file, buff, real_read_len);
    }
    close(dest_file);
    close(src_file);
    return 0;
}