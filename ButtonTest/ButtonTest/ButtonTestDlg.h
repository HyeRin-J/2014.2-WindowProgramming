// ButtonTestDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxtempl.h"


// CButtonTestDlg ��ȭ ����
class CButtonTestDlg : public CDialog
{
// �����Դϴ�.
public:
	CButtonTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BUTTONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButtonStart();
	CEdit m_edit;
	CStatic textStatus;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_buttonstart;
	CEdit m_printedit;
	int length;
	bool PushButton(int num);
	bool isPlaying;
	void changeButtonState(void);
	int timeBegin;
	int timeEnd;
	int currentlength;
	CList<int, int&> quest;
};
