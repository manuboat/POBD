#pragma once


// CContactDlg dialog

class CContactDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CContactDlg)

public:
	CContactDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CContactDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Contact };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonQuery();
	CString m_name;
	CString m_mail;
	long m_mobile;
	CString m_file;
};
