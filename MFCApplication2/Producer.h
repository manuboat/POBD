#pragma once


// CProducer dialog

class CProducerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProducerDlg)

public:
	CProducerDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProducerDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
