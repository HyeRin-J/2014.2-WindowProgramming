// 102.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// 2013136127 ������
// �������� 4��

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
			CMapStringToString alpha, sign; //Ű�� ���ĺ��� ���� Ű�� ��ȣ�� ���
			CString strkey, strValue, print; //Ű, �����Ͱ�, �ӽ÷� �����Ͱ��� ������ ����

			CString str[] = {_T(" "), _T("A"), _T("B"), _T("C"), _T("D"), _T("E"), _T("F"), _T("G"), _T("H"), _T("I"), _T("J"), _T("K"),
				_T("L"), _T("M"), _T("N"), _T("O"), _T("P"), _T("Q"), _T("R"), _T("S"), _T("T"), _T("U"), _T("V"), _T("W"), _T("X"), _T("Y"), _T("Z")};
			CString sig[] = {_T("00000"), _T("00001"), _T("00010"), _T("00011"), _T("00100"), _T("00101"), _T("00110"), _T("00111"), _T("01000"),
				_T("01001"), _T("01010"), _T("01011"), _T("01100"), _T("01101"), _T("01110"), _T("01111"), _T("10000"), _T("10001"), _T("10010"),
				_T("10011"), _T("10100"), _T("10101"), _T("10110"), _T("10111"), _T("11000"), _T("11001"), _T("11010")};

			for(int i=0;i < 27;i++)
			{ 
				alpha.SetAt(str[i], sig[i]); //���ĺ��� Ű��
				sign.SetAt(sig[i], str[i]); //��ȣ�� Ű��
			}

			//����Ʈ�� ������ġ ����
			POSITION pos1 = alpha.GetStartPosition();
			POSITION pos2 = sign.GetStartPosition();

			//�� ����Ʈ ���
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
			CString string[50]; //�˻��� ���� �迭

			printf("���� �Է� => ");
			_tscanf(_T("%s"), &st);
			strkey = st; //�����͸� ã�� Ű��

			cout << "\n��ȯ�� ���� : " << (LPCTSTR)strkey << endl << endl;

			//strkey�� �����ϰ��
			if(strkey >= "A"){
				printf("%s -> ", strkey);
				for(int i=0; i < strkey.GetLength(); i++){ //���ڿ��� �ϳ��� ���� �� �˻�
					string[i] = strkey.Mid(i, 1);
					alpha.Lookup(string[i], print); //�ʿ��� ���ڿ� �˻�
					printf("%s", print);
				}
				printf("\n");
			}
			//strkey�� �����ϰ��
			else{
				printf("%s -> ", strkey);
				for(int i=0; i<strkey.GetLength(); i+=5){ //���ڿ��� �� ���ڸ� 5�ڸ��� ���� �� �˻� 
					string[i] = strkey.Mid(i, 5);
					sign.Lookup(string[i], print); //�ʿ��� ���ڿ� �˻�
					printf("%s", print);
				}
				printf("\n");
			}
		}
	}

	system("pause");
	return nRetCode;
}