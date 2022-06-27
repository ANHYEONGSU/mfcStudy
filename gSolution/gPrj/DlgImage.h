#pragma once

#define MAX_POINT   1000
// CDlgImage 대화 상자입니다.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;              // CImage 클래스를 m_image라는 변수로 선언;
	CWnd* m_pParent;           // CWnd형태의 변수를 선언;
	int m_nDataCount = 0;        // 그리는 최대 갯수 값 초기화
	CPoint m_ptData[MAX_POINT];
	int m_nDataDraw = 0;

	int m_nRadius = 0;
	BOOL m_bMark = false;
	CPoint m_nCenter;
	CPoint m_nPoint;

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();

private:


public:
	afx_msg void OnPaint();

	void setCenter(int x, int y);
	void setPoint(int x, int y);
	BOOL getMark();
	CPoint getCenter();
	CPoint getPoint();
	void InitImage();
	void drawDate(CDC* pDC);
	void drawMark(int nCenterX, int nCenterY);
	void drawOutline(int nCenterX, int nCenterY, int nRadius);

};