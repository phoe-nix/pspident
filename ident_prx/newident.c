/** newident.c
	���� ���� �������� ������ ������� pspIdent-ng �� ���������� Yoti
	���� �������: http://code.google.com/p/pspident; ��������: GPLv3
*/

/** ����������� ����� **/
#include <pspsdk.h>
#include <pspkernel.h>

/** �������������� ����� **/
#include "newident.h"

/** ���������� � ������������� **/
PSP_MODULE_INFO("ident_ng_prx", 0x5006, 1, 0);
PSP_MAIN_THREAD_ATTR(0);

/** ��� ��������� **/
int module_start(SceSize args, void *argp)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}
