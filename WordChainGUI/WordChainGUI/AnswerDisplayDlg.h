#pragma once


// AnswerDisplayDlg �Ի���

class AnswerDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AnswerDisplayDlg)

public:
	AnswerDisplayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AnswerDisplayDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANSDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_ansLength;
};
