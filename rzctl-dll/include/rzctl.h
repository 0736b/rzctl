#pragma once

#define IOCTL_MOUSE 0x88883020

#define MAX_VAL 65536

#define DllExport   __declspec( dllexport )

#include <cstdint>

class RZCONTROL_IOCTL_STRUCT
{
public:
	int32_t unk0; //0x0000
	int32_t unk1; //0x0004
	int32_t max_val_or_scan_code; //0x0008
	int32_t click_mask; //0x000C
	int32_t unk3; //0x0010
	int32_t x; //0x0014
	int32_t y; //0x0018
	int32_t unk4; //0x001C
}; //Size: 0x0020

enum RZCONTROL_TYPE {
	RZCONTROL_KEYBOARD = 1,
	RZCONTROL_MOUSE = 2
};

enum MOUSE_CLICK {
	LEFT_DOWN = 1,
	LEFT_UP = 2,
	RIGHT_DOWN = 4,
	RIGHT_UP = 8,
	SCROLL_CLICK_DOWN = 16,
	SCROLL_CLICK_UP = 32,
	BACK_DOWN = 64,
	BACK_UP = 128,
	FOWARD_DOWN = 256,
	FOWARD_UP = 512,
	SCROLL_DOWN = 4287104000,
	SCROLL_UP = 7865344
};

enum KEYBOARD_INPUT_TYPE {
	KEYBOARD_DOWN = 0,
	KEYBOARD_UP = 1
};

namespace rzctl {
	/*
	* finds the symbolic link that contains name RZCONTROL and opens a handle to the respective device
	*/
	extern "C" DllExport bool init();

	/*
	* if going from point, x and y will be the offset from current mouse position
	* otherwise it will be a number in range of 1 to 65536, where 1, 1 is top left of screen
	* if using multiple monitors the input values remain the same, but outcome different, i just don't recommend bothering with this bs
	* note: x and/or y can not be 0 unless going from start point	
	*/
	extern "C" DllExport void mouse_move(int x, int y, bool from_start_point = true);
	extern "C" DllExport void mouse_click(int click_mask);
	/*
	* Refer to Scan Code Table in https://download.microsoft.com/download/1/6/1/161ba512-40e2-4cc9-843a-923143f3456c/scancode.doc
	*/
	extern "C" DllExport void keyboard_input(short scan_code, KEYBOARD_INPUT_TYPE up_down);

	/*
	* communicates to the device
	*/
	void _impl_mouse_ioctl(RZCONTROL_IOCTL_STRUCT* pMi);
}