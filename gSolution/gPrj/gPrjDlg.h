// gPrjDlg.h : 헤더 파일
//
#include "DlgImage.h"
#pragma once


// CgPrjDlg 대화 상자
class CgPrjDlg : public CDialogEx
{
	// 생성입니다.
public:
	CgPrjDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.

	CDlgImage *m_pDlgImage;
	CDlgImage *m_pDlglmgResult;
	CPoint CCenter;

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPRJ_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV 지원입니다.


													   // 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
