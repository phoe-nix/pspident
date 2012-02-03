/** newident.c
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

/** Стандартные файлы **/
#include <pspsdk.h>
#include <pspkernel.h>

/** Дополнительные файлы **/
#include "newident.h"

/** Переменные и препроцессинг **/
PSP_MODULE_INFO("ident_ng_prx", 0x5006, 1, 0);
PSP_MAIN_THREAD_ATTR(0);

/** Код программы **/
int module_start(SceSize args, void *argp)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}
