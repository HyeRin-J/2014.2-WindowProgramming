// 1-1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// 2013136127 ������
// �������� 1��

#include "stdafx.h"
#include "1-1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			_tprintf(_T("�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			CString book;
			srand((unsigned)time(NULL));
			int position = 0;
			int index, i = 0;
			int num = 0;

			ULONGLONG begin = GetTickCount();
			while (num < 2000)
			{
				for(int i=0; i < 1000; i++){
					char a = rand()%27 + 97;
					if(a == 123)
						a = 32;
					book += a;
				}
				num++;

				ULONGLONG end = GetTickCount();
				ULONGLONG span = end - begin;
				_tprintf(_T("[%d] %d\n"), num, span);
			}
			_tprintf("CString �ִ� ���� : %d(INT_MAX)\n", INT_MAX);

			_tprintf(_T("exo : "));
			while(1) {
				index = book.Find("exo", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // ã�� �ݺ�

			_tprintf(_T("\nkai : "));
			while(1) {
				index = book.Find("kai", position);  // book ���ڿ� �߿��� kai��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // ã�� �ݺ�

			_tprintf(_T("\nlay : "));
			while(1) {
				index = book.Find("lay", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // ã�� �ݺ�

			_tprintf(_T("\ntao : "));
			while(1) {
				index = book.Find("tao", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // ã�� �ݺ�
			system("pause");

			_tprintf("\n");
		}
	}
	else
	{
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		_tprintf(_T("�ɰ��� ����: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
