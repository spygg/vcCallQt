// qSqlCallTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "qSqlCallTest.h"
#include "qSqlCallTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQSqlCallTestApp

BEGIN_MESSAGE_MAP(CQSqlCallTestApp, CWinApp)
	//{{AFX_MSG_MAP(CQSqlCallTestApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQSqlCallTestApp construction

CQSqlCallTestApp::CQSqlCallTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CQSqlCallTestApp object

CQSqlCallTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CQSqlCallTestApp initialization

BOOL CQSqlCallTestApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	bool bok = false;
	
	char dbName[255] = {0};
	char type[20] = {0};	//"QSQLITE"
	char host[20] = {0};   //"127.0.0.1",
	char szPort[20] = {0};
	char userName[50] = {0};
	char passWd[50] = {0};
	
	LoadIniFile("DataBase", "CurrentDriver", type);
	LoadIniFile(type, "DBName", dbName);
	LoadIniFile(type, "ServerName", host);
	LoadIniFile(type, "Port", szPort);
	LoadIniFile(type, "UserName", userName);
	LoadIniFile(type, "PassWord", passWd);
	
	CSql sql;
	bok = sql.connectDataBase(dbName, type, host, atoi(szPort), userName, passWd);
	
	if(!bok){
		AfxMessageBox(sql.lastError().toLocal8Bit().constData());
		return FALSE;
	}
	
	
	//QSqlQuery *query = new QSqlQuery();
	QSqlQuery query;
	bok = sql.exec(&query, "select * from testTable");

	if(bok){
		while(query.next()){
			TRACE("%d, %s\n", query.value(0).toInt(),query.value(1).toString().toLocal8Bit().constData());
		}
	}
	else{
		TRACE("¥ÌŒÛ‘≠“Ú: %s\n", query.lastError());
	}

	
	//delete query;
	
	//sql.closeDataBase();
	

	CQSqlCallTestDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.


	return FALSE;
}

BOOL CQSqlCallTestApp::ExitInstance()
{

	return CWinApp::ExitInstance();
}
