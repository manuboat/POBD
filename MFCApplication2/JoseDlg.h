#pragma once


// JoseDlg dialog

class JoseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(JoseDlg)

public:
	JoseDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~JoseDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
