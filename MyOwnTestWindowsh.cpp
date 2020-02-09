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
//ShowWindow�Ĳ���˵����
//SW_FORCEMINIMIZE����WindowNT5.0����С�����ڣ���ʹӵ�д��ڵ��̱߳�����Ҳ����С�����ڴ������߳���С������ʱ��ʹ�����������
//SW_MAXIMIZE�����ָ���Ĵ��ڡ�
//SW_MINIMIZE����С��ָ���Ĵ��ڲ��Ҽ�����Z���е���һ�����㴰�ڡ�
//SW_RESTORE�������ʾ���ڡ����������С������󻯣���ϵͳ�����ڻָ���ԭ���ĳߴ��λ�á��ڻָ���С������ʱ��Ӧ�ó���Ӧ��ָ�������־��
//SW_SHOW���ڴ���ԭ����λ����ԭ���ĳߴ缤�����ʾ���ڡ�
//SW_SHOWDEFAULT��������STARTUPINFO�ṹ��ָ����SW_FLAG��־�趨��ʾ״̬��STARTUPINFO �ṹ��������Ӧ�ó���ĳ��򴫵ݸ�CreateProcess�����ġ�
//SW_SHOWMAXIMIZED������ڲ�������󻯡�
//SW_SHOWMINIMIZED������ڲ�������С����
//SW_SHOWMINNOACTIVATE��������С�����������Ȼά�ּ���״̬��
//SW_SHOWNA���Դ���ԭ����״̬��ʾ���ڡ��������Ȼά�ּ���״̬��
//SW_SHOWNOACTIVATE���Դ������һ�εĴ�С��״̬��ʾ���ڡ��������Ȼά�ּ���״̬��
//SW_SHOWNOMAL�������ʾһ�����ڡ�������ڱ���С������󻯣�ϵͳ����ָ���ԭ���ĳߴ�ʹ�С��Ӧ�ó����ڵ�һ����ʾ���ڵ�ʱ��Ӧ��ָ���˱�־��
//����ֵ�����������ǰ�ɼ����򷵻�ֵΪ���㡣���������ǰ�����أ��򷵻�ֵΪ�㡣