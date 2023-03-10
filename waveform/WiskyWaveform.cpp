#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "WiskyWaveform.h"

#undef NDEBUG
#undef LOG_TAG
#define LOG_TAG "WISKYWF"
//#include <log/log.h>
//#include <utils/Log.h>

#define WISKY_WAVEFORM_A2CLEAN_PATH "/product/firmware/30-A2-clear.bin"
#define WISKY_WAVEFORM_GL16CLEAN_PATH "/product/firmware/30-gl16-clear.bin"


int readWiskyFile(const char *path, void **buf, size_t *buf_size)
{
	size_t file_size;
	ssize_t nread;
	int fd, ret = 0;
	off_t off;
	//printf("readfile\n");	

	fd = open(path, O_RDONLY);
	
	if (fd < 0){
        printf("readfile fd %d\n",fd);
		return errno;
	}
		
	off = lseek(fd, 0, SEEK_END);
    printf("readfile off %d\n",(int)off);
	if (off < 0) {
		ret = errno;
		goto err;
	}
	file_size = off;   
	//printf("0621T1 readfile file_size %d *buf_size %d  *buf=  %d\n",file_size,*buf_size,*buf);	
	if (file_size > *buf_size) {
		//*buf = realloc(*buf, file_size);
		*buf = malloc(file_size);
		//printf("readfile *buf %d\n",*buf);	
		if (!*buf) {
			ret = ENOMEM;
			goto err;
		}
	}
	*buf_size = file_size;

	nread = pread(fd, *buf, file_size, 0);
    printf("readfile nread %d\n",(int)nread);
	if (nread != off) {
		ret = errno;
		goto err;
	}
    printf("readfile ret %d\n",ret);

	ret = 0;

err:
	close(fd);

	return ret;
}

//---waveformNo为0时，输出查询到的waveformTotal、waveformNo、(texBuf，w, h)；
//---waveformNo不为0时，通过正确的waveformTotal、waveformNo输出其他(texBuf，w, h)；
int decodeMode(void *buf, int decodeMode, int temp,void **texBuf, int *w, int *h, int* waveformNo, int* waveformTotal){
	int ret = 0;

	return ret;
}

/**
* 获取A2	清屏模式的 waveform
* 
* mWiskyWaveform 地址，存放waveform的数据结构
*/
int getA2CleanWf(struct WiskyWaveform* mWiskyWaveform){
	static void* wfDataVoid = NULL;
	static size_t wfDataSize = 0;
	U8* wfData = NULL;
	U8* wfDataPos = NULL;

    int ret = readWiskyFile(WISKY_WAVEFORM_A2CLEAN_PATH, &wfDataVoid, &wfDataSize);
    if (ret) {
        printf("readfile wisky waveform ret:%d", ret);
        return -1;
    }

	wfData = (U8 *)wfDataVoid;

	// for(int i=0; i<wfDataSize; i++){
	// 	ALOGD("i:%d: %d", i, wfData[i]);
	// }
	mWiskyWaveform->A2CleanOneData_FrameNum = wfData[4];

	int rowHi = wfData[5];
	int rowLo = wfData[6];
	int colHi = wfData[7];
	int colLo = wfData[8];

	int row = rowHi<<8 | rowLo;
	int col = colHi<<8 | colLo;
    printf("colorFraNo1 row:%d, col:%d", row, col);

	mWiskyWaveform->A2CleanOneData_H = row;
	mWiskyWaveform->A2CleanOneData_W = col;
	mWiskyWaveform->A2CleanOneData_Size = row*col;
	mWiskyWaveform->A2CleanOneData = wfData+9;

	wfDataPos = wfData + 8 + mWiskyWaveform->A2CleanOneData_Size + 1;//colorFraNo2
    printf("colorFraNo2 %d", *wfDataPos);

	mWiskyWaveform->A2CleanTwoData_FrameNum = *(wfDataPos+1);

	wfDataPos = wfDataPos+2;

	row = ((int)(*wfDataPos))<<8 | ((int)(*(wfDataPos+1)));
	col = ((int)(*(wfDataPos+2)))<<8 | ((int)(*(wfDataPos+3)));

    printf("colorFraNo2 row:%d, col:%d", row, col);

	mWiskyWaveform->A2CleanTwoData_H = row;
	mWiskyWaveform->A2CleanTwoData_W = col;
	mWiskyWaveform->A2CleanTwoData_Size = row*col;

	mWiskyWaveform->A2CleanTwoData = wfDataPos+4;

	wfDataPos = wfDataPos + 3 + mWiskyWaveform->A2CleanTwoData_Size + 1;//checkBytesNum

    printf("checkBytesNum %d, A2CleanOneData_FrameNum %d, A2CleanTwoData_FrameNum %d",
		((int)(*wfDataPos))<<8 | ((int)(*(wfDataPos+1))), mWiskyWaveform->A2CleanOneData_FrameNum,
		mWiskyWaveform->A2CleanTwoData_FrameNum);
	return 0;
}

int getGL16CleanWf(struct WiskyWaveform* mWiskyWaveform){
	static void* wfDataVoid = NULL;
	static size_t wfDataSize = 0;
	U8* wfData = NULL;
	U8* wfDataPos = NULL;

    int ret = readWiskyFile(WISKY_WAVEFORM_GL16CLEAN_PATH, &wfDataVoid, &wfDataSize);
    if (ret) {
        printf("readfile wisky waveform ret:%d", ret);
        return -1;
    }

	wfData = (U8 *)wfDataVoid;

	// for(int i=0; i<wfDataSize; i++){
	// 	ALOGD("i:%d: %d", i, wfData[i]);
	// }
	mWiskyWaveform->GL16CleanData_FrameNum = wfData[4];

	int rowHi = wfData[5];// 每行多少个数据
	int rowLo = wfData[6];// 每列多少个数据
	int colHi = wfData[7];// 第一张表数据
	int colLo = wfData[8];// 第二组彩色帧

	// 左移8位=高位删除，低位补0
	int row = rowHi<<8 | rowLo;
	int col = colHi<<8 | colLo;
    printf("getGL16CleanWf row:%d, col:%d", row, col);

	mWiskyWaveform->GL16CleanData_H = row;
	mWiskyWaveform->GL16CleanData_W = col;
	mWiskyWaveform->GL16CleanData_Size = row*col;
	mWiskyWaveform->GL16CleanData = wfData+9;

	// ALOGD("getGL16CleanWf GL16CleanData_W:%d, GL16CleanData_H:%d", mWiskyWaveform->GL16CleanData_W, mWiskyWaveform->GL16CleanData_H);
	// for(int i=0; i<100; i++){
	// 	ALOGD("i:%d, %d", i, *(mWiskyWaveform->GL16CleanData+i));
	// }

	wfDataPos = wfData + 8 + mWiskyWaveform->GL16CleanData_Size + 1;//colorFraNo2

    printf("checkBytesNum %d, GL16CleanData_FrameNum %d", ((int)(*wfDataPos))<<8 | ((int)(*(wfDataPos+1))),
		mWiskyWaveform->GL16CleanData_FrameNum);
	return 0;
}

int testFunc(int value){
	printf("wldebug printf test c func testFunc:%d", value);
    printf("wldebug ALOGD test c func testFunc:%d", value);
    printf("wldebug ALOGD test c func testFunc:%d", value);
	return 3;
}