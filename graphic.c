#include<groupB.h>

#pragma warning (disable:4996)

#define putchxy(x,y,c) {gotoxy(x,y); putch(c);}

void window_graphic();


int main() {
	setcursortype(NOCURSOR);
	window_graphic();
		
}

void window_graphic() {

	while (1) {
		int i;
		int y = 0;

		for (i = 0; i < 60; i++)
		{
			putchxy(i, 0, '-');
		}
		for (i = 0; i < 20; i++)
		{
			putchxy(0, i, '|')
		}
		for (i = 0; i < 20; i++)
		{
			putchxy(60, i, '|')
		}
		for (i = 0; i < 60; i++)
		{
			putchxy(i, 20, '-')
		}

		gotoxy(61, y + 2); printf("+-  SCORE BOARD  -+ ");
		gotoxy(61, y + 3); printf("|    S ○ ○ ○   | ");
		gotoxy(61, y + 4); printf("|    B ○ ○ ○   | ");
		gotoxy(61, y + 5); printf("+-----------------+ ");
		gotoxy(61, y + 8); printf(" YOUR SCORE :");

		gotoxy(61, y + 15); printf("숫자 4개를 입력하시오.");
	
		Sleep(1);
	}
}
