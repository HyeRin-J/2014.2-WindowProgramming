// ButtonTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CButtonTestApp:
// �� Ŭ������ ������ ���ؼ��� ButtonTest.cpp�� �����Ͻʽÿ�.
//

class CButtonTestApp : public CWinApp
{
public:
	CButtonTestApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CButtonTestApp theApp;