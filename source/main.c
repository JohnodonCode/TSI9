#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		printf("\x1b[30;16HPress START to exit.");

		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[1;0HX coordinate: %i       ",touch.px);
		printf("\x1b[2;0HY coordinate: %i       ",touch.py);

		u32 kHeld = hidKeysHeld();
		if (kHeld & KEY_TOUCH)
			printf("\x1b[3;0HActive: TRUE ");
		else
			printf("\x1b[3;0HActive: FALSE");

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
