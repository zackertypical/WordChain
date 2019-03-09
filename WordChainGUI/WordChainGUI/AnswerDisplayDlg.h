#pragma once


// AnswerDisplayDlg 对话框

class AnswerDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AnswerDisplayDlg)

public:
	AnswerDisplayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AnswerDisplayDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANSDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_ansLength;
};
