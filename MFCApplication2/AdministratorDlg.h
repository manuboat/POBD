#pragma once


// AdministratorDlg dialog

class AdministratorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AdministratorDlg)

public:
	AdministratorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AdministratorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Administrator };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
};
