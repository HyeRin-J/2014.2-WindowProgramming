// ButtonTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ButtonTest.h"
#include "ButtonTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CButtonTestDlg ��ȭ ����




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


// CButtonTestDlg �޽��� ó����

BOOL CButtonTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CButtonTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

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
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
			str.Format(_T("��� : %d"), (timeEnd - timeBegin) / length);
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
