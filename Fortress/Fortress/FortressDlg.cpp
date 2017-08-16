
// FortressDlg.cpp : ���� ����
//
#include "stdafx.h"
#include "Fortress.h"
#include "FortressDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CFortressDlg ��ȭ ����
CFortressDlg::CFortressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFortressDlg::IDD, pParent)
	, moveValue(0)
	, windPower(0)
	, windDirection(0)
	, x2vx(0)
	, x2vy(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFortressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, hp1);
	DDX_Control(pDX, IDC_PROGRESS2, hp2);
	DDX_Control(pDX, IDC_BUTTON1, button1);
	DDX_Control(pDX, IDC_BUTTON2, button2);
	DDX_Control(pDX, IDC_BUTTON4, button4);
	DDX_Control(pDX, IDC_BUTTON5, button5);
	DDX_Control(pDX, IDC_BUTTON6, button6);
	DDX_Control(pDX, IDC_BUTTON8, button8);
	DDX_Control(pDX, IDC_SLIDER1, Wind);
	DDX_Control(pDX, IDC_PROGRESS5, Power1);
	DDX_Control(pDX, IDC_PROGRESS6, Power2);
}

BEGIN_MESSAGE_MAP(CFortressDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &CFortressDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFortressDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CFortressDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CFortressDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CFortressDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CFortressDlg::OnBnClickedButton8)
END_MESSAGE_MAP()

// CFortressDlg �޽��� ó����
BOOL CFortressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWind();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}
void CFortressDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.
UINT __throwing(LPVOID arg){
	CFortressDlg* dlg = (CFortressDlg*)arg;

	while(dlg->user1.item.moving || dlg->user2.item.moving)
	{
		if(dlg->user1.item.moving){
			if(dlg->windDirection == 0)
				dlg->user1.item.vx -= (double)dlg->windPower/50;
			else
				dlg->user1.item.vx += (double)dlg->windPower/50;

			dlg->point = CPoint(dlg->user1.item.x, dlg->user1.item.y);
			dlg->user1.item.Move();
			if((dlg->user1.item.x >= dlg->user2.x-20 && dlg->user1.item.x <= dlg->user2.x+20) && (dlg->user1.item.y <= dlg->user2.y+20 && dlg->user1.item.y >= dlg->user2.y-20)){
				dlg->user2.hp -= dlg->user1.item.damage;
				dlg->SetWind();
				dlg->user1.item.Reset(dlg->user1.x, dlg->user1.y);
				dlg->user1.item.moving = false;
			}
			if(dlg->user1.item.x >= dlg->user2.x+20 || dlg->user1.item.y >= dlg->user2.y+20){
				dlg->SetWind();
				dlg->user1.item.Reset(dlg->user1.x, dlg->user1.y);
				dlg->user1.item.moving = false;
			}
		}
		else if(dlg->user2.item.moving){
			if(dlg->windDirection == 0)
				dlg->user2.item.vx -= (double)dlg->windPower/50;
			else
				dlg->user2.item.vx += (double)dlg->windPower/50;

			dlg->point = CPoint(dlg->user2.item.x, dlg->user2.item.y);
			dlg->user2.item.Move();
			if((dlg->user2.item.x <= dlg->user1.x+20 && dlg->user2.item.x >= dlg->user1.x-20) && (dlg->user2.item.y <= dlg->user1.y+20 && dlg->user2.item.y >= dlg->user1.y-20)){
				dlg->user1.hp -= dlg->user2.item.damage;
				dlg->SetWind();
				dlg->user2.item.Reset(dlg->user2.x, dlg->user2.y);
				dlg->user2.item.moving = false;
			}
			if(dlg->user2.item.x <= dlg->user1.x-20 || dlg->user2.item.y >= dlg->user1.y+20){
				dlg->SetWind();
				dlg->user2.item.Reset(dlg->user2.x, dlg->user2.y);
				dlg->user2.item.moving = false;
			}
		}
		dlg->Invalidate();
		Sleep(30);
	}
	return 0;
}
void CFortressDlg::OnPaint()
{
	hp1.SetPos(user1.hp);
	hp2.SetPos(user2.hp);
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	dc.Rectangle(user1.x-20, user1.y-20, user1.x+20, user1.y+20);
	dc.Rectangle(user2.x-20, user2.y-20, user2.x+20, user2.y+20);

	if(user1.item.moving || user2.item.moving){
		if(user1.item.itemnum == 1 || user2.item.itemnum == 1)
			dc.Ellipse(point.x-15, point.y-15, point.x+15, point.y+15);
		else
			dc.Ellipse(point.x-10, point.y-10, point.x+10, point.y+10);
	}

	if(user1.hp == 0){
		AfxMessageBox(_T("User2 Win!"));
		Reset();
	}
	if(user2.hp == 0){
		AfxMessageBox(_T("User1 Win!"));
		Reset();
	}

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CFortressDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CFortressDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Invalidate();
	CClientDC dc(this);
	CPen myPen(PS_SOLID,3,RGB(0,0,0));
	CPen *pOldPen=dc.SelectObject(&myPen);
	End = CPoint(point.x, point.y);

	if(user1.turn){
		if(End.x <= 100)	End.x = 100;
		else if(End.y >= 300)	End.y = 300;
		dc.MoveTo(user1.x, user1.y);
		dc.LineTo(End);
	}
	else if(user2.turn){
		if(End.x >= 700)	End.x = 700;
		else if(End.y >= 300)	End.y = 300;
		dc.MoveTo(user2.x, user2.y);
		dc.LineTo(End);
	}

	//CDialogEx::OnMouseMove(nFlags, point);
}
void CFortressDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	PUSHED = true;
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CFortressDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int num = 0;
	End = point;
	PUSHED = false;

	if(point.x <= user1.x){
		End.x = user1.x;
	}
	if(point.x >= user2.x){
		End.x = user2.x;
	}
	if(point.y >= user1.y){
		End.y = user1.y;
	}
	if(user1.turn){
		user1.item.vx = (End.x - user1.x) * 0.02;
		user1.item.vy = (End.y - user1.y) * 0.05;
		user1.item.moving = true;
		user1.moving = true;
		user1.turn = false;
		Power1.EnableWindow(false);
		user2.turn = true;
	}
	else if(user2.turn){
		user2.item.vx = (End.x - user2.x) * 0.02;
		user2.item.vy = (End.y - user2.y) * 0.05;
		user2.item.moving = true;
		user2.moving = true;
		user1.turn = true;
		Power2.EnableWindow(false);
		user2.turn = false;
	}

	Invalidate();

	CWinThread* pThread = AfxBeginThread(__throwing, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	pThread->ResumeThread();
	//CDialogEx::OnLButtonUp(nFlags, point);
}

void CFortressDlg::KeyDown(MSG pMSG)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(pMSG.wParam){
	case VK_LEFT:
		if(user1.moving && user1.turn){
			user1.x -= 2;
			moveValue++;
			if(moveValue >= 10) {moveValue = 0; user1.moving = false;}
		}
		else if(user2.moving && user2.turn){
			user2.x -= 2;
			moveValue++;
			if(moveValue >= 10){moveValue = 0; user2.moving = false;}
		}
		break;
	case VK_RIGHT:
		if(user1.moving && user1.turn){
			user1.x += 2;
			moveValue++;
			if(moveValue >= 10) {moveValue = 0; user1.moving = false;}
		}
		else if(user2.moving && user2.turn){
			user2.x += 2;
			moveValue++;
			if(moveValue >= 10){moveValue = 0; user2.moving = false;}
		}
		break;
	}
}

BOOL CFortressDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(pMsg->message == WM_KEYDOWN){ 
		KeyDown(*pMsg);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CFortressDlg::SetWind(void)
{
	srand(time(NULL));
	windDirection = rand()%2;
	windPower = rand()%4;

	if(windDirection == 0){
		switch(windPower){
		case 0:
			Wind.SetPos(50);
			break;
		case 1:
			Wind.SetPos(40);
			break;
		case 2:
			Wind.SetPos(20);
			break;
		case 3:
			Wind.SetPos(0);
			break;
		}
	}
	else{
		switch(windPower){
		case 0:
			Wind.SetPos(50);
			break;
		case 1:
			Wind.SetPos(70);
			break;
		case 2:
			Wind.SetPos(85);
			break;
		case 3:
			Wind.SetPos(100);
			break;
		}
	}
}
void CFortressDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user1.turn){
		user1.item.SetItem(1);
		button1.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user1.turn){
		user1.item.SetItem(2);
		button2.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user1.turn){
		user1.hp += 30;
		user1.turn = false;
		user2.turn = true;
		button4.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user2.turn){
		user2.item.SetItem(1);
		button5.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user2.turn){
		user2.item.SetItem(2);
		button6.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(user2.turn){
		user2.hp += 30;
		user2.turn = false;
		user1.turn = true;
		button8.EnableWindow(false);
	}
}
void CFortressDlg::Reset(void)
{
	user1.hp = 100;
	user2.hp = 100;
	user1.x = 100;
	user1.y = 300;
	user2.x = 700;
	user2.y = 300;
	button1.EnableWindow(true);
	button2.EnableWindow(true);
	button4.EnableWindow(true);
	button5.EnableWindow(true);
	button6.EnableWindow(true);
	button8.EnableWindow(true);
	SetWind();
}