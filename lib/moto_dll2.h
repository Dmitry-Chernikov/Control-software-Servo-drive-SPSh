//interface for 3rd party applications
//TODO: add all interface functions

#ifndef _MOTO_DLL_2_H_
#define _MOTO_DLL_2_H_

typedef void (__stdcall *READ_CALLBACK)(int, int, double, void *, int);

#define MOTO_DLL_2_API __declspec( dllimport )

#define ERR_OK 0
#define ERR_CANT_GET_PARAMS -2
#define ERR_CANT_OPEN_PORT -1
#define ERR_CANT_SET_BUFSIZE -3
#define ERR_CANT_SET_PARAMS -4
#define ERR_CANT_SET_TIMEOUTS -5
#define ERR_INTERNAL_FAULT -300
#define ERR_INVALID_PARAM -301
#define ERR_PORT_CLOSED -302
#define ERR_ALREADY_OPEN -303
#define ERR_INVALID_INVERTER -600
#define ERR_BUSY -700
#define ERR_EMPTY_SCRIPT -701
#define ERR_OBSOLETE -702
#define ERR_GENERIC -703
#define ERR_NOT_IMPLEMENTED -704

#define ERR_PORT_DEAD -16
#define ERR_TIMEOUT -17
#define ERR_BAD_ADDR -18
#define ERR_TOO_LONG -19
#define ERR_FRAMING_ERROR -20

MOTO_DLL_2_API int _cdecl InitParser();

MOTO_DLL_2_API int _cdecl ReadVal(int inv,char *name,double *val);
MOTO_DLL_2_API int _cdecl WriteVal(int inv,char *name,double val);

MOTO_DLL_2_API int _cdecl ExecScript(int param,char *param1,double param2,double *param3);
MOTO_DLL_2_API int _cdecl LoadProgram(int motor,int bank, short *program, int *version);
MOTO_DLL_2_API int _cdecl WriteProgram(int motor,int bank,short *program,int len, int version);

MOTO_DLL_2_API int _cdecl StartWaitStep(int param ,READ_CALLBACK onPoint);
MOTO_DLL_2_API int _cdecl StopWaitStep(int param);

MOTO_DLL_2_API int _cdecl OpenPort(int num);
MOTO_DLL_2_API int _cdecl ClosePort(int num);

MOTO_DLL_2_API int _cdecl AddParamToStream(int inv,char *name,READ_CALLBACK onPoint);
MOTO_DLL_2_API int _cdecl RemoveParamFromStream(int inv,char *name);

MOTO_DLL_2_API int _cdecl EnumDevices(bool doClosePorts);
MOTO_DLL_2_API int _cdecl GetPortName(int inv,char *buf);

MOTO_DLL_2_API void _cdecl CloseParser();

MOTO_DLL_2_API int _cdecl GetParamAddress(int param,char *param1,int *param2);

MOTO_DLL_2_API int _cdecl StartStream(int inv);
MOTO_DLL_2_API int _cdecl StopStream(int inv);

MOTO_DLL_2_API int _cdecl SetOpenGLPixelFormat(struct HDC__ *param);

MOTO_DLL_2_API int _cdecl StartTrajectory();
MOTO_DLL_2_API int _cdecl StopTrajectory();

MOTO_DLL_2_API int _cdecl SetCANBaudRate(int param,bool param1);
MOTO_DLL_2_API int _cdecl GetParamMotorValue(int param,int param1,double param2,double *param3);
MOTO_DLL_2_API int _cdecl ModifyPriority(int param,int param1);

MOTO_DLL_2_API int _cdecl StartPLC(int inv, int plcnum);
MOTO_DLL_2_API int _cdecl StopPLC(int inv);

MOTO_DLL_2_API int _cdecl AddDevice(char const *param);


MOTO_DLL_2_API int _UploadDeviceFirmware();
MOTO_DLL_2_API int _GetMotoDllMessage();
MOTO_DLL_2_API int _StartDumpCAN();
MOTO_DLL_2_API int _StopDumpCAN();
MOTO_DLL_2_API int _ResetToFactoryDefault();
MOTO_DLL_2_API int _WriteValNoSave();

#endif