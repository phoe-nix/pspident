/** funkcii.c
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

/** Стандартные файлы **/
#include <pspkernel.h>
#include <pspctrl.h>
#include <pspsdk.h>

/** Дополнительные файлы **/
#include "glavnoe.h"
#include "..\ident_prx\function.h"

/** Переменные и препроцессинг **/
#define printf pspDebugScreenPrintf 

SceCtrlData pad;

/** Код программы **/
void sysExitCross(char*text)
{
	printf(text);
	printf(active_text_array[STR_PRESS_X_TO_EXIT]);
	do
	{
		sceCtrlReadBufferPositive(&pad, 1);
		sceKernelDelayThread(0.05*1000*1000);
	}
	while(!(pad.Buttons & PSP_CTRL_CROSS));
	sceKernelExitGame();
}

int sysCheckDevice(char path)
{
	if (path == 'm') // ms0
		return 0;
	else if (path == 'e') // ef0
		return 1;
	else // O_o
		return -1;
}

//pspSdkLoadStartModule_Smart
int sysLoadStart(const char*file)
{
	SceUID module_file;
	u8 module_type = 0;

	module_file = sceIoOpen(file, PSP_O_RDONLY, 0777);
	if (module_file >= 0)
	{
		sceIoLseek(module_file, 0x7C, PSP_SEEK_SET);
		sceIoRead(module_file, &module_type, 1);
		sceIoClose(module_file);

		if (module_type == 0x02)
			return pspSdkLoadStartModule(file, PSP_MEMORY_PARTITION_KERNEL);
		else if (module_type == 0x04)
			return pspSdkLoadStartModule(file, PSP_MEMORY_PARTITION_USER);
	}
	else
		sceIoClose(module_file);

	return -1;
}

u32 fncGetScramble(void)
{
	return prxGetScramble();
}

char*fncGetShippedFW(char*buf)
{
	return prxGetShippedFW(buf);
}