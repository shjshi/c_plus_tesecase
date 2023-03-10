#ifndef WISKY_WAVEFORM_H
#define WISKY_WAVEFORM_H
#include <iostream>
#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

typedef uint8_t U8;
struct WiskyWaveform
{

	//---A2 clean tex data
	U8 *A2CleanOneData;
	int A2CleanOneData_Size;
	int A2CleanOneData_H;
	int A2CleanOneData_W;
	int A2CleanOneData_FrameNum;

	U8 *A2CleanTwoData;
	int A2CleanTwoData_Size;
	int A2CleanTwoData_H;
	int A2CleanTwoData_W;
	int A2CleanTwoData_FrameNum;

	//---GL16 clean
	U8 *GL16CleanData;
	int GL16CleanData_Size;
	int GL16CleanData_H;
	int GL16CleanData_W;
	int GL16CleanData_FrameNum;

};

int readWiskyFile(const char *path, void **buf, size_t *buf_size);
int decodeMode(void *buf, int decodeMode, int temp,void **texBuf, int *w, int *h, int* waveformNo, int* waveformTotal);
int getA2CleanWf(struct WiskyWaveform* mWiskyWaveform);
int getGL16CleanWf(struct WiskyWaveform* mWiskyWaveform);

int testFunc(int value);


#ifdef __cplusplus
}
#endif

#endif