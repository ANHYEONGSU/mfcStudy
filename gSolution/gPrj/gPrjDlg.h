// gPrjDlg.h : ��� ����
//
#include "DlgImage.h"
#pragma once


// CgPrjDlg ��ȭ ����
class CgPrjDlg : public CDialogEx
{
	// �����Դϴ�.
public:
	CgPrjDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.

	CDlgImage *m_pDlgImage;
	CDlgImage *m_pDlglmgResult;
	CPoint CCenter;

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPRJ_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV �����Դϴ�.


													   // �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();

	void callFunc(int n);
	afx_msg void OnBnClickedBtnTest();
	afx_msg void OnBnClickedBtnProcess();
	afx_msg void OnBnClickedBtnMakePattern();
	afx_msg void OnBnClickedBtnGetData();
	//   int m_nNum;
	int nGrey = 128;
	int nBlack = 0;
	//bool bDir;
	void drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGrey);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void drawMark(int nCenterX, int nCenterY);
	void darwOutline(int CenterX, int CenterY, int Radius);


	afx_msg void OnBnClickedBtnMark();

private:
public:
	afx_msg void OnEnChangeEditSize();
	int m_nRadius;
	afx_msg void OnBnClickedBtnMark2();
	afx_msg void OnBnClickedBtnLeftCircle();
	afx_msg void OnBnClickedBtnRightCircle();
};
