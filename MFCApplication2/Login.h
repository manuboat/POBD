#pragma once
#include "afxwin.h"


// CLogin dialog

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLogin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnCbnSelchangeCombo1();
	CString str1, str2, str3;
	CComboBox m_comboBoxCtrl;
	CString m_username;
	CString m_password;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnBnClickedButtonRegister();
};
