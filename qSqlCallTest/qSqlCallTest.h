// qSqlCallTest.h : main header file for the QSQLCALLTEST application
//

#if !defined(AFX_QSQLCALLTEST_H__754890EC_AE67_4260_8298_6325778B1461__INCLUDED_)
#define AFX_QSQLCALLTEST_H__754890EC_AE67_4260_8298_6325778B1461__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQSqlCallTestApp:
// See qSqlCallTest.cpp for the implementation of this class
//

class CQSqlCallTestApp : public CWinApp
{
public:
	CQSqlCallTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQSqlCallTestApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQSqlCallTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QSQLCALLTEST_H__754890EC_AE67_4260_8298_6325778B1461__INCLUDED_)
