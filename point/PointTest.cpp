
#include <iostream>
#include <cstdint>

using namespace std;


//
// Created by wisky on 2023/3/10.
//
typedef uint8_t U8;
struct WiskyWaveform {
    int A2CleanOneData_FrameNum;
    int GL16CleanData_FrameNum;

};

int getA2CleanWf(struct WiskyWaveform *mWiskyWaveform) {
    mWiskyWaveform->A2CleanOneData_FrameNum = 2;
}

int getGC16CleanWf(struct WiskyWaveform *mWiskyWaveform) {
    mWiskyWaveform->GL16CleanData_FrameNum = 16;
}


int main() {
    cout << "hello c++" << endl;
    struct WiskyWaveform mWiskyWaveform = {};

    getA2CleanWf(&mWiskyWaveform);
    getGC16CleanWf(&mWiskyWaveform);

    cout << mWiskyWaveform.A2CleanOneData_FrameNum << endl;
    cout << mWiskyWaveform.GL16CleanData_FrameNum << endl;
    return 0;
}