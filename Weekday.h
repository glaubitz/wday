// Weekday.h : Main header file for the Weekday application
//

#if !defined(AFX_WEEKDAY_H__83B06B02_C46E_11D3_8CF7_B47EFFC00000__INCLUDED_)
#define AFX_WEEKDAY_H__83B06B02_C46E_11D3_8CF7_B47EFFC00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CWeekdayApp:
// Siehe Weekday.cpp für die Implementierung dieser Klasse
//

class CWeekdayApp : public CWinApp
{
public:
	CWeekdayApp();

// Overloaded functions
	public:
	virtual BOOL InitInstance();


// Implementation

	DECLARE_MESSAGE_MAP()
};

char * wdgetday (int year,int month,int day);

#endif // !defined(AFX_WEEKDAY_H__83B06B02_C46E_11D3_8CF7_B47EFFC00000__INCLUDED_)
