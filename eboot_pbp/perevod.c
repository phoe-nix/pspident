/** perevod.c
	���� ���� �������� ������ ������� pspIdent-ng �� ���������� Yoti
	���� �������: http://code.google.com/p/pspident; ��������: GPLv3
*/

/** ����������� ����� **/
#include <psputility_sysparam.h>

/** �������������� ����� **/
#include "perevod.h"

/** ���������� � ������������� **/
char*passive_text_array[2][LAST_STRING] =
{
	{	// �������
		"\0",

		", ������� X ��� ������...\n",
		" > ������ ������� ������",
		" > �� ������",
		"������ ��������",
		"������ ��������",
		"��������� ����",
		"������� =(",
		"������!",
		"Tachyon (CPU&GPU)",
		"Baryon (SYSCON)",
		"Pommel (GPIO)",
		"FuseCFG",
		"Kirk & Spock (������-����)",
		"FuseID",
		"ID Scramble",
		"�������� UMD �������",
		"{������ ���}",
		"������ ��������",
		"������ ����������� �����",
		"������ � ������ �������",
		"�������� ������ �������",
		"��������� ��������� ��������",
		"������ � �������������",

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

/** ��� ��������� **/
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
