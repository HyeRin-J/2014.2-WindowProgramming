// Chapter2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Chapter2.h"

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
			CList <int, int&> list1, list2, list3, list4;
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
			_tprintf(_T("CString �ִ� ���� : %d(INT_MAX)\n"), INT_MAX);

			_tprintf(_T("exo : "));
			while(1) {
				index = book.Find("exo", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					list1.AddTail(index); //list�� ����
					position = index+3;
				}
			}  // ã�� �ݺ�
			//���
			POSITION pos = list1.GetHeadPosition();
			while(pos != NULL)
				_tprintf("%d ", list1.GetNext(pos));

			position = 0;
			_tprintf(_T("\nkai : "));
			while(1) {
				index = book.Find("kai", position);  // book ���ڿ� �߿��� kai��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					list2.AddTail(index); //list�� ����
					position = index+3;
				}
			}  // ã�� �ݺ�
			//���
			pos = list2.GetHeadPosition();
			while(pos != NULL)
				_tprintf("%d ", list2.GetNext(pos));

			position = 0;
			_tprintf(_T("\nlay : "));
			while(1) {
				index = book.Find("lay", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					list3.AddTail(index); //list�� ����
					position = index+3;
				}
			}  // ã�� �ݺ�
			//���
			pos = list3.GetHeadPosition();
			while(pos != NULL)
				_tprintf("%d ", list3.GetNext(pos));

			position = 0;
			_tprintf(_T("\ntao : "));
			while(1) {
				index = book.Find("tao", position);  // book ���ڿ� �߿��� exo��� ���ڿ��� ã��
				if(index == -1)
					break;  // �� ã������ �ݺ� ����
				else{
					list4.AddTail(index); //list�� ����
					position = index+3;
				}
			}  // ã�� �ݺ�
			//���
			pos = list4.GetHeadPosition();
			while(pos != NULL)
				_tprintf("%d ", list4.GetNext(pos));

			_tprintf("\n");
			system("pause");
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
