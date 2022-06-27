// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;


// CDlgImage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage �޽��� ó�����Դϴ�.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog() // ���ø����̼��� �Է� ��Ŀ���� ��ȭ ������ ��Ʈ�� �� �ϳ��� �����ߴ��� ���θ� �����մϴ�. 
{
	CDialogEx::OnInitDialog();
	// OnInItDialog = ��ȭ ���ڰ� ǥ�õǱ� ������ �߻��ϴ� Create, CreateIndirect �Ǵ� DoModal ȣ�� �߿� ��ȭ ���ڿ� �޽����� ����.
	// Ŭ���������� > �����Լ� > OnInitDialog �߰�

	//MoveWindow(0, 0, 640, 480);     // CWnd�� ��ġ�� ���̸� �����Ѵ�.
	// int x      = ������ �� ��ġ�� �����Ѵ�
	// int y      = ������ �� ��ġ�� �����Ѵ�
	// int nWidth = �ʺ� �����Ѵ�
	// int Height = ���̸� �����Ѵ�
	// ������ ���� = ���ҽ��� > ���̾�α�> �Ӽ� > Title Bar > False 

	InitImage();  // �̹��� ����



	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgImage::InitImage() // �̹��� �׸���.
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);  // nWidth  = ��Ʈ���� �ʺ�
											 // nHeight = ��Ʈ���� ����
											 // ����̸� nHeight ��Ʈ���� ����� DIB�̰� ������ ���� �Ʒ� �𼭸�
											 // �����̸� nHeight ��Ʈ���� ����� DIB�̰� ������ ���� �� �𼭸�
											 // nBpp = ��Ʈ���� �ȼ��� ��Ʈ��

	if (nBpp == 8) {
		static RGBQUAD rgb[256];                                  // �� RGB�� �ʱ�ȭ .
		for (int i = 0; i < 256; i++)                             // ��
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i; // ��
		m_image.SetColorTable(0, 256, rgb);                       // ��
	}

	int nPitch = m_image.GetPitch();                         // GetPitch = �̹����� ��ġ�� �˻���. 
															 // pitch = �� ��Ʈ�� ���� ���ۺκа� ���� ��Ʈ�� ���� ������ ��Ÿ���� �� �޸� �ּ� ������ �Ÿ�(����Ʈ)
	unsigned char* fm = (unsigned char*)m_image.GetBits();   // GetBits  = ������ �ȼ��� ���� ��Ʈ ���� ���� �����͸� �˻�. ( m_image�� ù��° �����͸� ������ �� )

	memset(fm, 0xff, nWidth*nHeight);         // memset �Լ��� �޸��� ����(��)�� ���ϴ� ũ�⸸ŭ Ư�� ������ ������ �� �ִ� �Լ�
											  // memory + setting �޸𸮸� (Ư�� ������) ����
											  // ù��° ���� void *ptr  = �ּҸ� ����Ű���ִ� �����Ͱ� ��ġ�ϴ� �ڸ�
											  // �ι�° ���� value      = �޸𸮿� �����ϰ��� �ϴ� ���� ������ ��
											  // ����° ���� size_t num = ���� ( ����Ʈ �����ν� �޸��� ũ�� ������ ������ ���̸� ���� )
}

void CDlgImage::OnPaint() // CPaintDC Ŭ������ ����̽� ���ؽ�Ʈ ��ü�� ����� �޽����� �����ϰ� ���� OnDraw ��� �Լ��� ȣ���Ѵ�.
						  // ����̽� ���ؽ�Ʈ =  ���÷��� �Ǵ� �����Ϳ� ���� ����̽��� �׸��� Ư���� ���� ������ �����ϴ� Windows ������ ����
						  // Ŭ���������� > �޽��� > WM_PAINT �߰�
{
	CPaintDC dc(this);    // device context for painting
					      // Ŭ���̾�Ʈ ������ ����� �� WM_PAINT �޽��� �ڵ鷯������ ���.


	if (m_image) {
		m_image.Draw(dc, 0, 0);  // ���� ����̽� ���ؽ�Ʈ���� ���� ����̽� ���ؽ�Ʈ�� ��Ʈ���� �����մϴ�.
								 // hDestDC = ��� ����̽� ���ؽ�Ʈ�� ���� �ڵ�
								 // xDest   = ��� �簢���� ���� �� �𼭸��� �ִ� x ��ǥ
								 // yDest   = ��� �簢���� ���� �� �𼭸��� �ִ� y ��ǥ

	}
	drawDate(&dc);

}

void CDlgImage::drawOutline(int nCenterX, int nCenterY, int nRadius)
{
	CClientDC dc(this);

	CPen pen(PS_INSIDEFRAME, 2, COLOR_YELLOW);// (200, 212, 0));
	CBrush* oldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);
	CPen* oldPen = dc.SelectObject(&pen);

	CRect rect(nCenterX - nRadius, nCenterY - nRadius, nCenterX + nRadius, nCenterY + nRadius);

	dc.Ellipse(rect);
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	DeleteObject(oldPen);
	DeleteObject(oldBrush);
}

void CDlgImage::drawMark(int nCenterX, int nCenterY)
{
	CClientDC dc(this);

	CPen pen;

	int nLen = 20;
	pen.CreatePen(PS_SOLID, 2, COLOR_RED);
	CPen *oldPen = dc.SelectObject(&pen);

	dc.MoveTo(nCenterX - nLen, nCenterY);
	dc.LineTo(nCenterX + nLen, nCenterY);

	dc.MoveTo(nCenterX, nCenterY - nLen);
	dc.LineTo(nCenterX, nCenterY + nLen);

	dc.SelectObject(oldPen);

	DeleteObject(oldPen);
}

void CDlgImage::drawDate(CDC* pDC)
{
	CRect rect;  // CRect = �簢���� ���� ��ܰ� ���� �ϴ��� ��ǥ�� ����.
				 // CRect (int l, int t, int r, int b)
				 // int l = left  �� ��ġ�� ����
				 // int t = top   �� ��ġ�� ����
				 // int r = right �� ��ġ�� ����
				 // int b = bottom�� ��ġ�� ����

	CPen pen;									// CPen = Windows ����̽� ���ؽ�Ʈ���� ���� �׸��� ����
	pen.CreatePen(PS_SOLID, 2, COLOR_BLUE);     // int nPenStyle    = ���� ��Ÿ���� �����Ѵ�
												// PS_SOLID   = �Ǽ� ��      
												// PS_DASH    = �ļ� ��      
												// PS_DOT     = ���� �� 
												// PS_DASHDOT = ��ÿ� ���� �����ư��� ��

												// int nWidth = ���� �ʺ� �����Ѵ�
												// COLORREF crColor = ���� RGB ���� �����Ѵ�

	CPen* pOldPen = pDC->SelectObject(&pen);

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);     // SetRect()         = �簢���� ����� �Լ�
													// POINT topLeft     = �������� �簢�� ���� �� ������ ��ġ
													// POINT bottomRight = �������� �簢�� ������ �Ʒ� ������ ��ġ

		rect.InflateRect(2, 2);						// InflateRect() = CRect ������ �߽ɿ��� �ָ� �̵��Ͽ� Ȯ���Ѵ�
													// int x         = x�� ���ʰ� �������� ��â�� �������� ������
													// int y         = y�� ���ʰ� �Ʒ����� ��â�� �������� ������

		pDC->Ellipse(rect);						    // Ellipsed()     = �簢���� ������ Ÿ���׸���
													//                  Ÿ���� �߽��� ������ ���簢���� �߽��̴�
													// LPCRECT lpRect = Ÿ���� ��� �簢���� ������
	}
	pDC->SelectObject(pOldPen);

	DeleteObject(pOldPen);
}

CPoint CDlgImage::getCenter()
{
	return m_nCenter;
}

void CDlgImage::setCenter(int x, int y)
{
	m_nCenter.x = x;
	m_nCenter.y = y;
}

CPoint CDlgImage::getPoint()
{
	return m_nPoint;
}

void CDlgImage::setPoint(int x, int y)
{
	m_nPoint.x = x;
	m_nPoint.y = y;
}

BOOL CDlgImage::getMark()
{
	return m_bMark;
}