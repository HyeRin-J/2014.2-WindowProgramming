
// RecMove.h : RecMove ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CRecMoveApp:
// �� Ŭ������ ������ ���ؼ��� RecMove.cpp�� �����Ͻʽÿ�.
//

class CRecMoveApp : public CWinApp
{
public:
	CRecMoveApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRecMoveApp theApp;
