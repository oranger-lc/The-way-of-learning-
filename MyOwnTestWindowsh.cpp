#include<Windows.h>
#include<iostream>

using namespace std;

int main()
{
	HWND currentWindow;
	POINT mouse;
	RECT clientRect, windowRect;
	int i = 0;
	while (1)
	{
		GetCursorPos(&mouse);
		cout << "my mouse is on x:" << mouse.x << ", y:" << mouse.y << endl;
		currentWindow = WindowFromPoint(mouse);
		GetClientRect(currentWindow, &clientRect);
		GetWindowRect(currentWindow, &windowRect);
		cout << "the client rect left,top,right,bottom:" << clientRect.left << "," << clientRect.top
			<< "," << clientRect.right << "," << clientRect.bottom << endl;
		cout << "the window rect left,top,right,bottom:" << windowRect.left << "," << windowRect.top
			<< "," << windowRect.right << "," << windowRect.bottom << endl;
		SetCursorPos(0, -1);
		
		switch (i)
		{
		case 0: 
			ShowWindow(currentWindow, SW_DENORMAL);
			break;
		case 1:
			ShowWindow(currentWindow, SW_MINIMIZE);
			break;
		case 2:
			ShowWindow(currentWindow, SW_HIDE);
			cout << "has been hided!" << endl;
			system("pause");
		case 3:
			ShowWindow(currentWindow, SW_RESTORE);
			break;
		default:
			break;
		}
		i++;
		i = i % 4;
		system("pause");
	}
	return 0;
}
//ShowWindow的参数说明：
//SW_FORCEMINIMIZE：在WindowNT5.0中最小化窗口，即使拥有窗口的线程被挂起也会最小化。在从其他线程最小化窗口时才使用这个参数。
//SW_MAXIMIZE：最大化指定的窗口。
//SW_MINIMIZE：最小化指定的窗口并且激活在Z序中的下一个顶层窗口。
//SW_RESTORE：激活并显示窗口。如果窗口最小化或最大化，则系统将窗口恢复到原来的尺寸和位置。在恢复最小化窗口时，应用程序应该指定这个标志。
//SW_SHOW：在窗口原来的位置以原来的尺寸激活和显示窗口。
//SW_SHOWDEFAULT：依据在STARTUPINFO结构中指定的SW_FLAG标志设定显示状态，STARTUPINFO 结构是由启动应用程序的程序传递给CreateProcess函数的。
//SW_SHOWMAXIMIZED：激活窗口并将其最大化。
//SW_SHOWMINIMIZED：激活窗口并将其最小化。
//SW_SHOWMINNOACTIVATE：窗口最小化，激活窗口仍然维持激活状态。
//SW_SHOWNA：以窗口原来的状态显示窗口。激活窗口仍然维持激活状态。
//SW_SHOWNOACTIVATE：以窗口最近一次的大小和状态显示窗口。激活窗口仍然维持激活状态。
//SW_SHOWNOMAL：激活并显示一个窗口。如果窗口被最小化或最大化，系统将其恢复到原来的尺寸和大小。应用程序在第一次显示窗口的时候应该指定此标志。
//返回值：如果窗口以前可见，则返回值为非零。如果窗口以前被隐藏，则返回值为零。