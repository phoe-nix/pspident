/** funkcii.h
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

// функция выхода из программы по нажатию на крест
void sysExitCross(char*text);

// функция распознавания устройства, откуда была запущена программа
int sysCheckDevice(char path);

// функция умного запуска и загрузки модулей
int sysLoadStart(const char*file);

// получаем ids значение
u32 fncGetScramble(void);

// получаем родную прошивку
char*fncGetShippedFW(char*buf);
