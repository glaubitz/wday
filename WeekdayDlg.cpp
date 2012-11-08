// WeekdayDlg.cpp : Implementierungsdatei

#include "stdafx.h"
#include "Weekday.h"
#include "WeekdayDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

SYSTEMTIME the_time;

/////////////////////////////////////////////////////////////////////////////
// CWeekdayDlg Dialogfeld

CWeekdayDlg::CWeekdayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWeekdayDlg::IDD, pParent)
{
	GetSystemTime (&the_time);
	//{{AFX_DATA_INIT(CWeekdayDlg)
	m_day = the_time.wDay;
	m_month = the_time.wMonth;
	m_year = the_time.wYear;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_outstring = _T("Your Weekday");
	//}}AFX_DATA_INIT
}

void CWeekdayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeekdayDlg)
	DDX_Text(pDX, IDC_EDITDAY, m_day);
	DDV_MinMaxInt(pDX, m_day, 1, 31);
	DDX_Text(pDX, IDC_EDITMONTH, m_month);
	DDV_MinMaxInt(pDX, m_month, 1, 12);
	DDX_Text(pDX, IDC_EDITYEAR, m_year);
	DDV_MinMaxInt(pDX, m_year, 0, 3000);
	DDX_Text(pDX, IDC_WDAY, m_outstring);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWeekdayDlg, CDialog)
	//{{AFX_MSG_MAP(CWeekdayDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WEEKDAY, OnWeekday)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeekdayDlg Nachrichten-Handler

BOOL CWeekdayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
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
			pSysMenu->RemoveMenu (2,MF_BYPOSITION);
			pSysMenu->RemoveMenu (3,MF_BYPOSITION);
		}
	}

	// Set Icon for the Main-Window
	SetIcon(m_hIcon, TRUE);		// Use large symbol
	SetIcon(m_hIcon, TRUE);		// Use small symbol
	
	return TRUE;
}

void CWeekdayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWeekdayDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// draw icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CWeekdayDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CWeekdayDlg::OnWeekday()
{
	UpdateData(TRUE); // Get data from main window
	/*if (m_year > -1 && m_year < 3001 && m_month > 0 && m_month < 13 && m_day > 0 && m_day < 32) {*/
	m_outstring = wdgetday (m_year, m_month, m_day);
	UpdateData(FALSE);
}

void CWeekdayDlg::OnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// Window CAboutDlg 

CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CAboutDlg 

void CAboutDlg::OnOK() 
{
	CDialog::OnOK();
}
