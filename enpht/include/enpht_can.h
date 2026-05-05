/* Copyright 2025 人形机器人（上海）有限公司
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Designed and built with love @zhihu by @cjrcl.
 */

#pragma once

#include <visatype.h>

#ifdef __cplusplus
extern "C"{
#endif

#define RATE_20KHZ      0
#define RATE_50KHZ      1
#define RATE_100KHZ     2
#define RATE_125KHZ     3
#define RATE_250KHZ     4
#define RATE_500KHZ     5
#define RATE_1000KHZ    6
#define RATE_2000KHZ    7
#define WM_NORMAL       0
#define WM_SLEEP        1
#define WM_LOOP         2
#define WM_LISTEN       3
#define WM_CONFIG       4
#define TRANS_NORMAL    0
#define TRANS_ONCE      1
#define FILTER_NULL     0
#define FILTER_STANDARD 1
#define FILTER_EXTENDED 2
#define STANDARD_FLAG   0
#define EXTENDED_FLAG   1

struct EP_CAN_INIT{
    unsigned int AC[6];
    unsigned int AM;
    unsigned int FilterType;
    unsigned int Bitrate;
    unsigned int SFType;
};

struct EP_CAN_OBJ{
    unsigned int ID : 29;
    unsigned int TimeStamp;
    unsigned char TimeFlag : 1;
    unsigned char RemoteFlag : 1;
    unsigned char ExtendedFlag : 1;
    unsigned char DataLen : 4;
    unsigned char Data[8];
};

struct EP_CAN_OBJ_MULTI_CH{
    unsigned int ch;
    unsigned int ID;
    unsigned int TimeStamp;
    unsigned char TimeFlag;
    unsigned char RemoteFlag;
    unsigned char ExtendedFlag;
    unsigned char DataLen;
    unsigned char Data[8];
};

struct EP_LED_STATE{
    unsigned char IMUState;
    unsigned char VisionModule;
    unsigned char BaseModule;
    unsigned char DataLink;
    unsigned char SystemState;
};

struct EP_CAN_STATE{
    ViUInt32 HwTXCount;
    ViUInt32 HwTXErrorCount;
    ViUInt32 HwRXCount;
    ViUInt32 HwRXErrorCount;
    ViUInt32 HwErrorState;
    ViUInt32 SoftTXCount;
    ViUInt32 SoftTXErrorCount;
    ViUInt32 SoftRXCount;
    ViUInt32 SoftRXErrorCount;
};

ViStatus _VI_FUNC EphCan_USB_AutoConnectToFirst(ViUInt32* cardNum);
ViStatus _VI_FUNC EphCan_USB_AutoConnectToUsbAddr(ViUInt32 usbAddr, ViUInt32* cardNum);
ViStatus _VI_FUNC EphCAN_InitCAN(ViUInt32 cardNum, ViUInt16 ch, struct EP_CAN_INIT* epCanInit);
ViStatus _VI_FUNC EphCAN_Close(ViUInt32 cardNum);
ViStatus _VI_FUNC EphCAN_Reset(ViUInt32 cardNum);
ViStatus _VI_FUNC EphCAN_SetWorkMode(ViUInt32 cardNum, ViUInt16 ch, ViUInt32 workMode);
ViStatus _VI_FUNC EphCAN_GetManuID(ViUInt32 cardNum, ViUInt32* manuID);
ViStatus _VI_FUNC EphCAN_GetDevID(ViUInt32 cardNum, ViUInt32* devID);
ViStatus _VI_FUNC EphCAN_GetVersion(ViUInt32 cardNum, ViUInt32* version, ViUInt32* string);
ViStatus _VI_FUNC EphCAN_StatusGetString(ViStatus hr, char* string);
ViStatus _VI_FUNC EphCAN_TimeGetString(ViUInt32 time, char* string);
ViStatus _VI_FUNC EphCAN_SetLedState(ViUInt32 cardNum, struct EP_LED_STATE* state);
ViStatus _VI_FUNC EphCAN_GetChConfig(ViUInt32 cardNum, ViUInt16 ch, struct EP_CAN_INIT* epCanInit);
ViStatus _VI_FUNC EphCAN_GetAllChTransStatus(ViUInt32 cardNum, ViUInt32* status);
ViStatus _VI_FUNC EphCAN_Transmit(ViUInt32 cardNum, ViUInt16 ch, ViUInt32 frameCount, struct EP_CAN_OBJ* objs);
ViStatus _VI_FUNC EphCAN_Receive(ViUInt32 cardNum, ViUInt16 ch, ViUInt32 length, struct EP_CAN_OBJ* objs, ViUInt32* frameCount);
ViStatus _VI_FUNC EphCAN_TransmitMulti(ViUInt32 cardNum, ViUInt32 frameCount, struct EP_CAN_OBJ_MULTI_CH* objs);
ViStatus _VI_FUNC EphCAN_ReceiveMulti(ViUInt32 cardNum, ViUInt32 mode, ViUInt32 length, struct EP_CAN_OBJ_MULTI_CH* objs, ViUInt32* frameCount);
ViStatus _VI_FUNC EphCAN_GetChanelCount(ViUInt32 cardNum, ViUInt32* chanelCount);
ViStatus _VI_FUNC EphCAN_GetFrameCount(ViUInt32	cardNum, ViUInt16 ch, ViUInt32* frameCount);
ViStatus _VI_FUNC EphCAN_GetModuleTemp(ViUInt32 cardNum, double* temp);
ViStatus _VI_FUNC EphCAN_GetCanState(ViUInt32 cardNum, ViUInt32 ch, struct EP_CAN_STATE* canState);

#ifdef __cplusplus
}
#endif