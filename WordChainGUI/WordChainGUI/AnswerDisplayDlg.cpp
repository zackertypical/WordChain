// AnswerDisplayDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WordChainGUI.h"
#include "AnswerDisplayDlg.h"
#include "afxdialogex.h"


// AnswerDisplayDlg �Ի���

IMPLEMENT_DYNAMIC(AnswerDisplayDlg, CDialogEx)

AnswerDisplayDlg::AnswerDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ANSDIALOG, pParent)
	, m_ansLength(0)
{

}

AnswerDisplayDlg::~AnswerDisplayDlg()
{
}

void AnswerDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, m_ansLength);
}


BEGIN_MESSAGE_MAP(AnswerDisplayDlg, CDialogEx)
END_MESSAGE_MAP()


// AnswerDisplayDlg ��Ϣ�������
