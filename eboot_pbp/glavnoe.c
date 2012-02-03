/** glavnoe.c
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

/** Стандартные файлы **/
#include <pspkernel.h>

/** Дополнительные файлы **/
#include "glavnoe.h"

/** Переменные и препроцессинг **/
PSP_MODULE_INFO("pspident", 0, VER_MAJOR, VER_MINOR);
PSP_MAIN_THREAD_ATTR(0);
PSP_HEAP_SIZE_KB(20480);

/** Код программы **/
/*
SceModule*sceKernelFindModuleByName(const char*modname)
	Find a module by it's name.
	Parameters:
		modname - The name of the module.
	Returns:
		Pointer to the SceModule structure if found, otherwise NULL.

int sceKernelStopModule(SceUID modid, SceSize argsize, void*argp, int*status, SceKernelSMOption*option)
	Stop a running module.

int sceKernelUnloadModule(SceUID modid)
	Unload a stopped module.
*/
/*
struct SceModule*next (?)
	unsigned short	attribute
	unsigned char	version[2]
	char			modname[27]
	char			terminal
	unsigned int	unknown1
	unsigned int	unknown2
	SceUID			modid
	unsigned int	unknown3[4]
	void *			ent_top
	unsigned int	ent_size
	void *			stub_top
	unsigned int	stub_size
	unsigned int	unknown4[4]
	unsigned int	entry_addr
	unsigned int	gp_value
	unsigned int	text_addr
	unsigned int	text_size
	unsigned int	data_size
	unsigned int	bss_size
	unsigned int	nsegment
	unsigned int	segmentaddr[4]
	unsigned int	segmentsize[4]
*/
int main(int argc, char*argv[])
{
	pspDebugScreenInit();
	pspDebugScreenClear();
	lngLoadStrings();

	/*if (sceKernelFindModuleByName("prxshot") == NULL)
		// выгрузить модуль
	*/

	/*if (sysLoadStart("prx_shot.prx") < 0)
		sysExitCross(active_text_array[STR_ERROR_WHEN_RUNNING]);
	else
		gfxPrintScreen();*/

	if (sysLoadStart("ident_ng.prx") < 0)
		sysExitCross(active_text_array[STR_ERROR_WHEN_RUNNING]);
	else
		gfxPrintScreen();

	return 0;
}
