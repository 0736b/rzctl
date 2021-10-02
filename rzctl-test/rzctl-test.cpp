#include <Windows.h>
#include <cstdint>
#include <iostream>
#include <rzctl.h>
#include <Psapi.h>

int main() {
	if (!rzctl::init()) {
		printf("Failed to initalize rzctl");
		return 1;
	}

	printf("Press CTRL + C to exit\n");
	while (true) {
		Sleep(1000);
		printf("Move mouse 10 10\n");
		rzctl::mouse_move(10, 10);
		Sleep(1000);
		printf("Press keyboard key a\n");
		rzctl::keyboard_input(0x1e, KEYBOARD_DOWN);
		Sleep(1);
		rzctl::keyboard_input(0x1e, KEYBOARD_UP);
		Sleep(1000);
		printf("Right click\n");
		rzctl::mouse_click(RIGHT_DOWN);
		Sleep(1);
		rzctl::mouse_click(RIGHT_UP);
		Sleep(1000);
		printf("Left click\n");
		rzctl::mouse_click(LEFT_DOWN);
		Sleep(1);
		rzctl::mouse_click(LEFT_UP);

		// Sleep is needed to avoid razer service overflowing, which delays all your inputs
		Sleep(1);
	}

	return 0;
}