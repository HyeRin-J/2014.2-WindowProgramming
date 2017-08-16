
// FortressDlg.cpp : 구현 파일
//
#include "stdafx.h"
#include "Fortress.h"
#include "FortressDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
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

// CFortressDlg 대화 상자
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

// CFortressDlg 메시지 처리기
BOOL CFortressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetWind();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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
// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
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

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFortressDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CFortressDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PUSHED = true;
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CFortressDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(user1.turn){
		user1.item.SetItem(1);
		button1.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(user1.turn){
		user1.item.SetItem(2);
		button2.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(user1.turn){
		user1.hp += 30;
		user1.turn = false;
		user2.turn = true;
		button4.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(user2.turn){
		user2.item.SetItem(1);
		button5.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(user2.turn){
		user2.item.SetItem(2);
		button6.EnableWindow(false);
	}
}
void CFortressDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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