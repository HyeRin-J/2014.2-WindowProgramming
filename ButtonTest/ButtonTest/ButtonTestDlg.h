// ButtonTestDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "afxtempl.h"


// CButtonTestDlg 대화 상자
class CButtonTestDlg : public CDialog
{
// 생성입니다.
public:
	CButtonTestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BUTTONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
