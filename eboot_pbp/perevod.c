/** perevod.c
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

/** Стандартные файлы **/
#include <psputility_sysparam.h>

/** Дополнительные файлы **/
#include "perevod.h"

/** Переменные и препроцессинг **/
char*passive_text_array[2][LAST_STRING] =
{
	{	// русский
		"\0",

		", нажмите X для выхода...\n",
		" > Ошибка запуска модуля",
		" > Всё готово",
		"Ложная прошивка",
		"Версия прошивки",
		"Системное ядро",
		"сломано =(",
		"свежак!",
		"Tachyon (CPU&GPU)",
		"Baryon (SYSCON)",
		"Pommel (GPIO)",
		"FuseCFG",
		"Kirk & Spock (крипто-пара)",
		"FuseID",
		"ID Scramble",
		"Прошивка UMD привода",
		"{текста нет}",
		"Родная прошивка",
		"Модель материнской платы",
		"Модель и регион консоли",
		"Условная версия консоли",
		"Установка кастомной прошивки",
		"Работа с аккумулятором",

		NULL
	},

	{	// english
		"\0",

		", press X to exit...\n",
		" > Error when starting module",
		" > All done",
		"False FW version",
		"Your FW version",
		"System kernel",
		"broken =(",
		"fresh!",
		"Tachyon (CPU&GPU)",
		"Baryon (SYSCON)",
		"Pommel (GPIO)",
		"FuseCFG",
		"Kirk & Spock (crypto pair)",
		"FuseID",
		"ID Scramble",
		"UMD drive firmware",
		"{no text}",
		"Shipped firmware",
		"MotherBoard version",
		"Model & region",
		"PSP version",
		"Ability to install cIPL-based CFW",
		"Battery abilites",

		NULL
	}
};

/** Код программы **/
void lngLoadStrings(void)
{
	int i, lang;

	sceUtilityGetSystemParamInt(PSP_SYSTEMPARAM_ID_INT_LANGUAGE, &lang);

	if (lang == PSP_SYSTEMPARAM_LANGUAGE_RUSSIAN)
		lang = 0;
	else
		lang = 1;

	for (i = 0; i < LAST_STRING; i++)
		active_text_array[i] = passive_text_array[lang][i];
}
