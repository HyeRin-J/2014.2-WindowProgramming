
// Test2Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTest2Dlg ��ȭ ����
class CTest2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTest2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEST2_DIALOG };

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
