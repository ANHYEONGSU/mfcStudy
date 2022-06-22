// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


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
	InitImage();



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
	CPaintDC dc(this); // device context for painting
					   // Ŭ���̾�Ʈ ������ ����� �� WM_PAINT �޽��� �ڵ鷯������ ���.


	if (m_image) {
		m_image.Draw(dc, 0, 0);  // ���� ����̽� ���ؽ�Ʈ���� ���� ����̽� ���ؽ�Ʈ�� ��Ʈ���� �����մϴ�.
							     // hDestDC = ��� ����̽� ���ؽ�Ʈ�� ���� �ڵ�
								 // xDest   = ��� �簢���� ���� �� �𼭸��� �ִ� x ��ǥ
								 // yDest   = ��� �簢���� ���� �� �𼭸��� �ִ� y ��ǥ
	}
	drawDate(&dc);
}

void CDlgImage::drawDate(CDC* pDC)
{
	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0xff, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(2, 2);
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);
}