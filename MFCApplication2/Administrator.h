#pragma once


// CAdministrator dialog

class CAdministratorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdministratorDlg)

public:
	CAdministratorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAdministratorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
