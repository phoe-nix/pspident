/** grafika.h
	Этот файл является частью проекта pspIdent-ng за авторством Yoti
	Сайт проекта: http://code.google.com/p/pspident; лицензия: GPLv3
*/

// шаманство с цветами
#ifndef COLORS
	#define RGB(r,g,b)		(0xFF000000|((b)<<16)|((g)<<8)|(r))

	#define RED				RGB(255, 0, 0)
	#define BLUE			RGB(50, 140, 255)
	#define GRAY			RGB(127, 127, 127)
	#define BLACK			RGB(0, 0, 0)
	#define GREEN			RGB(0, 255, 0)
	#define WHITE			RGB(255, 255, 255)
	#define ORANGE			RGB(255, 127, 0)
	#define VIOLET			RGB(127, 0, 255)

	#define COLORS			1

	#define HEADER_COLOR	VIOLET
	#define FOOTER_COLOR	VIOLET
	#define DEFAULT_COLOR	WHITE
	#define HINT_COLOR		GRAY
	#define BLOCK1_TEXT		ORANGE
	#define BLOCK1_RESULT	WHITE
	#define BLOCK2_TEXT		RED
	#define BLOCK2_RESULT	WHITE
	#define BLOCK3_TEXT		BLUE
	#define BLOCK3_RESULT	WHITE	
	#define BLOCK4_TEXT		GREEN
	#define BLOCK4_RESULT	WHITE	
#endif

// отрисовка экрана после запуска
void gfxPrintScreen(void);

// заполняем нужное количество точек
char*gfxPrintDots(char*str);

// выводим совет по прошивке на базе текущей версии
char*gfxPrintHint_FW(int kernel);
