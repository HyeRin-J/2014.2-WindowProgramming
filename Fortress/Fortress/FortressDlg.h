
// FortressDlg.h : 헤더 파일
//

#pragma once
#include "User1.h"
#include "User2.h"
#include "afxcmn.h"
#include "afxwin.h"

// CFortressDlg 대화 상자
class CFortressDlg : public CDialogEx
{
// 생성입니다.
public:
	CFortressDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FORTRESS_DIALOG };

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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CUser1 user1;
	CUser2 user2;
	CProgressCtrl hp1;
	CProgressCtrl hp2;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint End;
	CPoint point;
	void KeyDown(MSG pMSG);
	int moveValue;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit Edit1;
	int windPower;
	int windDirection;
	void SetWind(void);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	CButton button1;
	CButton button2;
	CButton button4;
	CButton button5;
	CButton button6;
	CButton button8;
	void Reset(void);
	double x2vx;
	double x2vy;
	CSliderCtrl Wind;
	CProgressCtrl Power1;
	CProgressCtrl Power2;
	int Power;
	bool PUSHED;
};
