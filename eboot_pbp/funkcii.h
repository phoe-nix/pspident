/** funkcii.h
	���� ���� �������� ������ ������� pspIdent-ng �� ���������� Yoti
	���� �������: http://code.google.com/p/pspident; ��������: GPLv3
*/

// ������� ������ �� ��������� �� ������� �� �����
void sysExitCross(char*text);

// ������� ������������� ����������, ������ ���� �������� ���������
int sysCheckDevice(char path);

// ������� ������ ������� � �������� �������
int sysLoadStart(const char*file);

// �������� ids ��������
u32 fncGetScramble(void);

// �������� ������ ��������
char*fncGetShippedFW(char*buf);
