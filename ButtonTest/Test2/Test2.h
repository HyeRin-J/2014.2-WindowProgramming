
// Test2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTest2App:
// �� Ŭ������ ������ ���ؼ��� Test2.cpp�� �����Ͻʽÿ�.
//

class CTest2App : public CWinApp
{
public:
	CTest2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	BOOL PreTranslateMessage(MSG* pMsg);
};

extern CTest2App theApp;