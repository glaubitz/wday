// Weekday.cpp : Legt das Klassenverhalten für die Anwendung fest.
// 1.00

#include "stdafx.h"
#include "Weekday.h"
#include "WeekdayDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CWeekdayApp

BEGIN_MESSAGE_MAP(CWeekdayApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeekdayApp Konstruktion

CWeekdayApp::CWeekdayApp()
{
	
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CWeekdayApp-Objekt

CWeekdayApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWeekdayApp Initialisierung

BOOL CWeekdayApp::InitInstance()
{
	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Größe Ihrer fertigen 
	//  ausführbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht benötigen, entfernen.

#ifdef _AFXDLL
	Enable3dControls();			// Diese Funktion bei Verwendung von MFC in gemeinsam genutzten DLLs aufrufen
#else
	Enable3dControlsStatic();	// Diese Funktion bei statischen MFC-Anbindungen aufrufen
#endif

	CWeekdayDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	return FALSE;
}
