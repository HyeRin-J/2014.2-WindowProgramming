
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "afxtempl.h"
#include "atltypes.h"


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CList<CPoint, CPoint&> list;
	afx_msg void OnMouseLeave();
	BOOL pushed;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CPoint offset;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int hold;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

