// ButtonTestDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ButtonTest.h"
#include "ButtonTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CButtonTestDlg 대화 상자




CButtonTestDlg::CButtonTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CButtonTestDlg::IDD, pParent)
	, currentlength(0), isPlaying(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON6, m_buttonstart);
	DDX_Control(pDX, IDC_EDIT3, m_printedit);
}

BEGIN_MESSAGE_MAP(CButtonTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CButtonTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CButtonTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CButtonTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CButtonTestDlg::OnBnClickedButtonStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CButtonTestDlg 메시지 처리기

BOOL CButtonTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CButtonTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CButtonTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

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
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CButtonTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CButtonTestDlg::OnBnClickedButtonStart(){
	length = GetDlgItemInt(IDC_EDIT1);
	srand(time(NULL));

	for (int i = 0; i < length; i++)
	{
		int var = rand()  % 4 + 1;
		quest.AddTail(var);
	}

	currentlength = 0;

	timeBegin = GetTickCount();

	isPlaying = true;

	changeButtonState();
}

void CButtonTestDlg::OnBnClickedButton1(){
	PushButton(1);
}

void CButtonTestDlg::OnBnClickedButton2(){
	PushButton(2);
}

void CButtonTestDlg::OnBnClickedButton3(){
	PushButton(3);
}

void CButtonTestDlg::OnBnClickedButton4(){
	PushButton(4);
}

bool CButtonTestDlg::PushButton(int num)
{
	if (isPlaying)
	{
		int correct = quest.GetAt(quest.FindIndex(currentlength));

		if (correct == num)
		{
			currentlength++;
		}

		if (currentlength == length)
		{
			isPlaying = false;
			timeEnd = GetTickCount();

			CString str;
			str.Format(_T("결과 : %d"), (timeEnd - timeBegin) / length);
			m_printedit.SetWindowTextW(str);
		}
	}

	changeButtonState();

	return false;
}
void CButtonTestDlg::changeButtonState(void)
{
	m_button1.SetWindowTextW(_T(" "));
	m_button2.SetWindowTextW(_T(" "));
	m_button3.SetWindowTextW(_T(" "));
	m_button4.SetWindowTextW(_T(" "));

	if (isPlaying)
	{
		int correct = quest.GetAt(quest.FindIndex(currentlength));

		if (correct == 1)
		{
			m_button1.SetWindowTextW(_T("X"));
		}
		else if (correct == 2)
		{
			m_button2.SetWindowTextW(_T("X"));
		}
		else if (correct == 3)
		{
			m_button3.SetWindowTextW(_T("X"));
		}
		else if (correct == 4)
		{
			m_button4.SetWindowTextW(_T("X"));
		}
	}
}
