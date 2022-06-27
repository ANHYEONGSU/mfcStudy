#pragma once

#define MAX_POINT   1000
// CDlgImage ��ȭ �����Դϴ�.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();

	CImage m_image;              // CImage Ŭ������ m_image��� ������ ����;
	CWnd* m_pParent;           // CWnd������ ������ ����;
	int m_nDataCount = 0;        // �׸��� �ִ� ���� �� �ʱ�ȭ
	CPoint m_ptData[MAX_POINT];
	int m_nDataDraw = 0;

	int m_nRadius = 0;
	BOOL m_bMark = false;
	CPoint m_nCenter;
	CPoint m_nPoint;

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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