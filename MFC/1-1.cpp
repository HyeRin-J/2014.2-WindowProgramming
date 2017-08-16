// 1-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 2013136127 주혜린
// 연습문제 1번

#include "stdafx.h"
#include "1-1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 오류 코드를 필요에 따라 수정합니다.
			_tprintf(_T("심각한 오류: MFC를 초기화하지 못했습니다.\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
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
			_tprintf("CString 최대 길이 : %d(INT_MAX)\n", INT_MAX);

			_tprintf(_T("exo : "));
			while(1) {
				index = book.Find("exo", position);  // book 문자열 중에서 exo라는 문자열을 찾음
				if(index == -1)
					break;  // 못 찾았으면 반복 중지
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // 찾기 반복

			_tprintf(_T("\nkai : "));
			while(1) {
				index = book.Find("kai", position);  // book 문자열 중에서 kai라는 문자열을 찾음
				if(index == -1)
					break;  // 못 찾았으면 반복 중지
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // 찾기 반복

			_tprintf(_T("\nlay : "));
			while(1) {
				index = book.Find("lay", position);  // book 문자열 중에서 exo라는 문자열을 찾음
				if(index == -1)
					break;  // 못 찾았으면 반복 중지
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // 찾기 반복

			_tprintf(_T("\ntao : "));
			while(1) {
				index = book.Find("tao", position);  // book 문자열 중에서 exo라는 문자열을 찾음
				if(index == -1)
					break;  // 못 찾았으면 반복 중지
				else{
					_tprintf("%d ", index);
					position += index+1;
				}
			}  // 찾기 반복
			system("pause");

			_tprintf("\n");
		}
	}
	else
	{
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
