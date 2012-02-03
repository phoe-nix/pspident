/** perevod.h
	���� ���� �������� ������ ������� pspIdent-ng �� ���������� Yoti
	���� �������: http://code.google.com/p/pspident; ��������: GPLv3
*/

// ���� ��������� �������� ��������
enum
{
	END_OF_LINE = 0,

	STR_PRESS_X_TO_EXIT,
	STR_ERROR_WHEN_RUNNING,
	STR_ALL_DONE,
	STR_FALSE_FW_VERSION,
	STR_CURRENT_FW,
	STR_CURRENT_KERNEL,
	STR_NOT_IMPLEMENTED_OR_BROKEN,
	STR_LAST_VERSION,
	STR_TACHYON,
	STR_BARYON,
	STR_POMMEL,
	STR_FUSE_CFG,
	STR_KIRK_AND_SPOCK,
	STR_FUSE_ID,
	STR_ID_SCRAMBLE,
	STR_UMD_FIRMWARE,
	STR_NO_TEXT,
	STR_SHIPPED_FW,
	STR_PSP_MOBO_TYPE,
	STR_PSP_REGION,
	STR_PSP_VERSION,
	STR_HACKABLE,
	STR_BATTERY,

	END_OF_TEXT,
	LAST_STRING
};

// ������ ����� �������� ���������
char*active_text_array[LAST_STRING];

// ������� ����������� ����� � ���������� �����
void lngLoadStrings(void);
