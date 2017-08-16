
// Test2Dlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTest2Dlg 대화 상자
class CTest2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTest2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TEST2_DIALOG };

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
	CSliderCtrl slider1;
	CSliderCtrl slider2;
	CSliderCtrl slider3;
	CSliderCtrl slider4;
	CButton reset;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int pos1;
	int pos2;
	int pos3;
	int pos4;
	void MoveSlider(char);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void Reset(void);
};
