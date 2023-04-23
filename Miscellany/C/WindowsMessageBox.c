#include <windows.h>

int main(void) {

	MessageBoxW(
		NULL,
		L"Bobo will return, right?",
		L"Choose!",
		MB_YESNOCANCEL
	);

	return EXIT_SUCCESS;
}