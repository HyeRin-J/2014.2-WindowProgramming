
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "RecMove.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView
CChildView::CChildView()
	: pushed(FALSE)
	, hold(-1)
	, offset(0, 0)
{
}
CChildView::~CChildView()
{
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSELEAVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CChildView �޽��� ó����
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);
	return TRUE;
}
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pushed = true;
	pos = list.GetHeadPosition();
	int num = -1;

	while(pos != 0){
		CPoint p = list.GetNext(pos);
		num++;
		if(p.x-20<=point.x && p.x+20>=point.x && p.y-20<=point.y && p.y+20>=point.y){
			hold = num;
			pos = list.GetHeadPosition();
			break;
		}
		else
		{
			hold = -1;
		}
	}
}
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pushed = false;
}
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pushed && hold != -1){//�巡�� ����
		list.SetAt(pos, point);
	}
	Invalidate();

}
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//return CWnd::OnEraseBkgnd(pDC);
	return false;
}
void CChildView::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//CWnd::OnMouseLeave();
	pushed = false;
}
void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	dc.Rectangle(point.x-20, point.y-20, point.x+20, point.y+20);
	list.AddTail(point);

	POSITION position = list.GetHeadPosition();
	while(position != 0)
	{
		CPoint p = list.GetNext(position);
		dc.Rectangle(p.x-20, p.y-20, p.x+20, p.y+20);
	}
	Invalidate();
} 