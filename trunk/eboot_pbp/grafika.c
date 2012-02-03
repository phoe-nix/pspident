/** grafika.c
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

/** Стандартные файлы **/
#include <pspkernel.h>
#include <string.h>

/** Дополнительные файлы **/
#include "glavnoe.h"

/** Переменные и препроцессинг **/
#define printf pspDebugScreenPrintf 

/** Код программы **/
char ret[DOTS];
char*gfxPrintDots(char*str)
{
	int i;

	for (i = 0; i < DOTS; i++)
		ret[i] = '.';
	ret[DOTS - strlen(str)] = '\0';

	return ret;
}

char*gfxPrintHint_FW(int kernel)
{
	switch (kernel)
	{
		case 0x05000010:
			return "Dark_AleX 4ever!";
		break;

		case 0x06020010:
			return "Слышали про PermaPatch?";
		break;

		case 0x06060010:
			return active_text_array[STR_LAST_VERSION];
		break;

		default:
			return "Стоит обновиться до 6.60 ;)";
		break;
	}
}

void gfxPrintScreen(void)
{
	/// заголовок программы
	/// если определён тип сборки, то выводим его
	/// если типа сборки нет - то только версию
	printf("\n");
	pspDebugScreenSetTextColor(HEADER_COLOR);
	#ifdef VER_BUILD_TYPE
	printf(" pspIdent-ng v" VER_MAJOR_YEAR "." VER_MINOR_WEEK "-" VER_BUILD_TYPE "");
	#else
	printf(" pspIdent-ng v" VER_MAJOR_YEAR "." VER_MINOR_WEEK ")");
	#endif
	pspDebugScreenSetTextColor(DEFAULT_COLOR);
	printf("\n\n");


	/// вывод блока "прошивка"
	/// код перенесён из PSPident без изменений
	/// вывод несколько переписан под новые стандарты
	// первая строка - версия ПО
	int version_num = sceKernelDevkitVersion();
	char*version_str = (char*)&version_num;
	pspDebugScreenSetTextColor(BLOCK1_TEXT);
	printf("%s%s: ", active_text_array[STR_CURRENT_FW], gfxPrintDots(active_text_array[STR_CURRENT_FW]));
	pspDebugScreenSetTextColor(BLOCK1_RESULT);
	printf("%i.%i%i", version_str[3], version_str[2], version_str[1]);
	// подсказка по версии прошивки
	pspDebugScreenSetTextColor(HINT_COLOR);
	printf(" (%s)", gfxPrintHint_FW(version_num));
	printf("\n");
	// вторая строка - ядро
	pspDebugScreenSetTextColor(BLOCK1_TEXT);
	printf("%s%s: ", active_text_array[STR_CURRENT_KERNEL], gfxPrintDots(active_text_array[STR_CURRENT_KERNEL]));
	pspDebugScreenSetTextColor(BLOCK1_RESULT);
	printf("0x%08X", version_num);
	printf("\n");

	// третья строка - вывод родной прошивки
	char buf[8];
	pspDebugScreenSetTextColor(BLOCK1_TEXT);
	printf("%s%s: ", active_text_array[STR_SHIPPED_FW], gfxPrintDots(active_text_array[STR_SHIPPED_FW]));
	pspDebugScreenSetTextColor(BLOCK1_RESULT);
	printf("%s", fncGetShippedFW(buf));
	printf("\n");

	#ifdef DEVELOPER
	// четвёртая строка - вывод ложной прошивки
	// {...вычисление ложной прошивки...}
	pspDebugScreenSetTextColor(BLOCK1_TEXT);
	printf("%s%s: ", active_text_array[STR_FALSE_FW_VERSION], gfxPrintDots(active_text_array[STR_FALSE_FW_VERSION]));
	pspDebugScreenSetTextColor(BLOCK1_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	#endif
	/// вывод блока "прошивка" завершён
	printf("\n");


	/// вывод блока "компоненты"
	// TACHYON
	pspDebugScreenSetTextColor(BLOCK2_TEXT);
	printf("%s%s: ", active_text_array[STR_TACHYON], gfxPrintDots(active_text_array[STR_TACHYON]));
	pspDebugScreenSetTextColor(BLOCK2_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// BARYON
	pspDebugScreenSetTextColor(BLOCK2_TEXT);
	printf("%s%s: ", active_text_array[STR_BARYON], gfxPrintDots(active_text_array[STR_BARYON]));
	pspDebugScreenSetTextColor(BLOCK2_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// POMMEL
	pspDebugScreenSetTextColor(BLOCK2_TEXT);
	printf("%s%s: ", active_text_array[STR_POMMEL], gfxPrintDots(active_text_array[STR_POMMEL]));
	pspDebugScreenSetTextColor(BLOCK2_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// FUSE_CFG
	pspDebugScreenSetTextColor(BLOCK2_TEXT);
	printf("%s%s: ", active_text_array[STR_FUSE_CFG], gfxPrintDots(active_text_array[STR_FUSE_CFG]));
	pspDebugScreenSetTextColor(BLOCK2_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	/// вывод блока "компоненты" завершён
	printf("\n");


	/// вывод блока "прочие части"
	// kirk & spock
	pspDebugScreenSetTextColor(BLOCK3_TEXT);
	printf("%s%s: ", active_text_array[STR_KIRK_AND_SPOCK], gfxPrintDots(active_text_array[STR_KIRK_AND_SPOCK]));
	pspDebugScreenSetTextColor(BLOCK3_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// fuseid
	pspDebugScreenSetTextColor(BLOCK3_TEXT);
	printf("%s%s: ", active_text_array[STR_FUSE_ID], gfxPrintDots(active_text_array[STR_FUSE_ID]));
	pspDebugScreenSetTextColor(BLOCK3_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// ids
	pspDebugScreenSetTextColor(BLOCK3_TEXT);
	printf("%s%s: ", active_text_array[STR_ID_SCRAMBLE], gfxPrintDots(active_text_array[STR_ID_SCRAMBLE]));
	pspDebugScreenSetTextColor(BLOCK3_RESULT);
	printf("0x%08x", fncGetScramble());
	printf("\n");
	// UMD
	pspDebugScreenSetTextColor(BLOCK3_TEXT);
	printf("%s%s: ", active_text_array[STR_UMD_FIRMWARE], gfxPrintDots(active_text_array[STR_UMD_FIRMWARE]));
	pspDebugScreenSetTextColor(BLOCK2_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	/// вывод блока "прочие части" завершён
	printf("\n");


	/// вывод блока "итог"
	// материнская плата
	pspDebugScreenSetTextColor(BLOCK4_TEXT);
	printf("%s%s: ", active_text_array[STR_PSP_MOBO_TYPE], gfxPrintDots(active_text_array[STR_PSP_MOBO_TYPE]));
	pspDebugScreenSetTextColor(BLOCK4_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// модель и регион вида "PSP-1000 (01g)"
	pspDebugScreenSetTextColor(BLOCK4_TEXT);
	printf("%s%s: ", active_text_array[STR_PSP_REGION], gfxPrintDots(active_text_array[STR_PSP_REGION]));
	pspDebugScreenSetTextColor(BLOCK4_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// условная версия консоли вида "Fat v1.0 ("прошиваемая")"
	pspDebugScreenSetTextColor(BLOCK4_TEXT);
	printf("%s%s: ", active_text_array[STR_PSP_VERSION], gfxPrintDots(active_text_array[STR_PSP_VERSION]));
	pspDebugScreenSetTextColor(BLOCK4_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// установка кастомной прошивки
	pspDebugScreenSetTextColor(BLOCK4_TEXT);
	printf("%s%s: ", active_text_array[STR_HACKABLE], gfxPrintDots(active_text_array[STR_HACKABLE]));
	pspDebugScreenSetTextColor(BLOCK4_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	// возможность создания аккумулятора пандоры
	pspDebugScreenSetTextColor(BLOCK4_TEXT);
	printf("%s%s: ", active_text_array[STR_BATTERY], gfxPrintDots(active_text_array[STR_BATTERY]));
	pspDebugScreenSetTextColor(BLOCK4_RESULT);
	printf("%s", active_text_array[STR_NOT_IMPLEMENTED_OR_BROKEN]);
	printf("\n");
	/// вывод блока "итог" завершён
	printf("\n");


	/// работа выполнена =)
	pspDebugScreenSetTextColor(FOOTER_COLOR);
	sysExitCross(active_text_array[STR_ALL_DONE]);
}
