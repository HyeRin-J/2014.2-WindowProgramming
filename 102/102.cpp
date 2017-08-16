// 102.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 2013136127 주혜린
// 연습문제 4번

#include "stdafx.h"
#include "102.h"
#include <afxcoll.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

template <> UINT AFXAPI HashKey(CString& str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key);
}

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
			CMapStringToString alpha, sign; //키가 알파벳인 경우와 키가 기호인 경우
			CString strkey, strValue, print; //키, 데이터값, 임시로 데이터값을 저장할 변수

			CString str[] = {_T(" "), _T("A"), _T("B"), _T("C"), _T("D"), _T("E"), _T("F"), _T("G"), _T("H"), _T("I"), _T("J"), _T("K"),
				_T("L"), _T("M"), _T("N"), _T("O"), _T("P"), _T("Q"), _T("R"), _T("S"), _T("T"), _T("U"), _T("V"), _T("W"), _T("X"), _T("Y"), _T("Z")};
			CString sig[] = {_T("00000"), _T("00001"), _T("00010"), _T("00011"), _T("00100"), _T("00101"), _T("00110"), _T("00111"), _T("01000"),
				_T("01001"), _T("01010"), _T("01011"), _T("01100"), _T("01101"), _T("01110"), _T("01111"), _T("10000"), _T("10001"), _T("10010"),
				_T("10011"), _T("10100"), _T("10101"), _T("10110"), _T("10111"), _T("11000"), _T("11001"), _T("11010")};

			for(int i=0;i < 27;i++)
			{ 
				alpha.SetAt(str[i], sig[i]); //알파벳을 키로
				sign.SetAt(sig[i], str[i]); //기호를 키로
			}

			//리스트의 시작위치 리턴
			POSITION pos1 = alpha.GetStartPosition();
			POSITION pos2 = sign.GetStartPosition();

			//각 리스트 출력
			while(pos1 != NULL){
				alpha.GetNextAssoc(pos1, strkey, strValue);
				_tprintf(_T("%s -> %s\n"), strkey, strValue);
			}
			printf("\n");
			while(pos2 != NULL){
				sign.GetNextAssoc(pos2, strkey, strValue);
				_tprintf(_T("%s -> %s\n"), strkey, strValue);
			}
			printf("\n");

			TCHAR st[50];
			CString string[50]; //검색을 위한 배열

			printf("문자 입력 => ");
			_tscanf(_T("%s"), &st);
			strkey = st; //데이터를 찾을 키값

			cout << "\n변환할 문자 : " << (LPCTSTR)strkey << endl << endl;

			//strkey가 문자일경우
			if(strkey >= "A"){
				printf("%s -> ", strkey);
				for(int i=0; i < strkey.GetLength(); i++){ //문자열을 하나씩 추출 및 검색
					string[i] = strkey.Mid(i, 1);
					alpha.Lookup(string[i], print); //맵에서 문자열 검색
					printf("%s", print);
				}
				printf("\n");
			}
			//strkey가 숫자일경우
			else{
				printf("%s -> ", strkey);
				for(int i=0; i<strkey.GetLength(); i+=5){ //문자열로 된 숫자를 5자리씩 추출 및 검색 
					string[i] = strkey.Mid(i, 5);
					sign.Lookup(string[i], print); //맵에서 문자열 검색
					printf("%s", print);
				}
				printf("\n");
			}
		}
	}

	system("pause");
	return nRetCode;
}