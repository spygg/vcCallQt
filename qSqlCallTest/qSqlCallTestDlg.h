// qSqlCallTestDlg.h : header file
//

#if !defined(AFX_QSQLCALLTESTDLG_H__83EEC3C5_F690_49C9_9ED5_C2B265607818__INCLUDED_)
#define AFX_QSQLCALLTESTDLG_H__83EEC3C5_F690_49C9_9ED5_C2B265607818__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQSqlCallTestDlg dialog

class CQSqlCallTestDlg : public CDialog
{
// Construction
public:
	CQSqlCallTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQSqlCallTestDlg)
	enum { IDD = IDD_QSQLCALLTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQSqlCallTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQSqlCallTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QSQLCALLTESTDLG_H__83EEC3C5_F690_49C9_9ED5_C2B265607818__INCLUDED_)
