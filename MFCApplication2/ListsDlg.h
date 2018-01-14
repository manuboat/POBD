#pragma once
#include <vector>
#include <string>

using namespace std;

// CListsDlg dialog

class CListsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListsDlg)

public:
	CListsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CListsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Lists };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL v_FlagCheck1;
	BOOL v_FlagCheck2;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	CString v_output;
};
