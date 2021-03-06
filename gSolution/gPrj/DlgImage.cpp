// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;


// CDlgImage 대화 상자입니다.

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


// CDlgImage 메시지 처리기입니다.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog() // 애플리케이션이 입력 포커스를 대화 상자의 컨트롤 중 하나로 설정했는지 여부를 지정합니다. 
{
	CDialogEx::OnInitDialog();
	// OnInItDialog = 대화 상자가 표시되기 직전에 발생하는 Create, CreateIndirect 또는 DoModal 호출 중에 대화 상자에 메시지를 보냄.
	// 클래스마법사 > 가상함수 > OnInitDialog 추가

	//MoveWindow(0, 0, 640, 480);     // CWnd의 위치와 넓이를 변경한다.
	// int x      = 왼쪽의 새 위치를 지정한다
	// int y      = 위쪽의 새 위치를 지정한다
	// int nWidth = 너비를 지정한다
	// int Height = 높이를 지정한다
	// 윈도우 고정 = 리소스뷰 > 다이얼로그> 속성 > Title Bar > False 

	InitImage();  // 이미지 생성



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage() // 이미지 그리기.
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);  // nWidth  = 비트맵의 너비
											 // nHeight = 비트맵의 높이
											 // 양수이면 nHeight 비트맵은 상향식 DIB이고 원점은 왼쪽 아래 모서리
											 // 음수이면 nHeight 비트맵은 하향식 DIB이고 원점은 왼쪽 위 모서리
											 // nBpp = 비트맵의 픽셀당 비트수

	if (nBpp == 8) {
		static RGBQUAD rgb[256];                                  // ㄱ RGB값 초기화 .
		for (int i = 0; i < 256; i++)                             // ㅣ
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i; // ㅣ
		m_image.SetColorTable(0, 256, rgb);                       // 」
	}

	int nPitch = m_image.GetPitch();                         // GetPitch = 이미지의 피치를 검색함. 
															 // pitch = 한 비트맵 줄의 시작부분과 다음 비트맵 줄의 시작을 나타내는 두 메모리 주소 사이의 거리(바이트)
	unsigned char* fm = (unsigned char*)m_image.GetBits();   // GetBits  = 지정된 픽셀의 실제 비트 값에 대한 포인터를 검색. ( m_image의 첫번째 포인터를 가지고 옴 )

	memset(fm, 0xff, nWidth*nHeight);         // memset 함수는 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
											  // memory + setting 메모리를 (특정 값으로) 세팅
											  // 첫번째 인자 void *ptr  = 주소를 가리키고있는 포인터가 위치하는 자리
											  // 두번째 인자 value      = 메모리에 셋팅하고자 하는 값을 넣으면 됌
											  // 세번째 인자 size_t num = 길이 ( 바이트 단위로써 메모리의 크기 한조각 단위의 길이를 말함 )
}

void CDlgImage::OnPaint() // CPaintDC 클래스의 디바이스 컨텍스트 개체를 만들어 메시지에 응답하고 뷰의 OnDraw 멤버 함수를 호출한다.
						  // 디바이스 컨텍스트 =  디스플레이 또는 프린터와 같은 디바이스의 그리기 특성에 대한 정보를 포함하는 Windows 데이터 구조
						  // 클래스마법사 > 메시지 > WM_PAINT 추가
{
	CPaintDC dc(this);    // device context for painting
					      // 클라이언트 영역에 출력할 때 WM_PAINT 메시지 핸들러에서만 사용.


	if (m_image) {
		m_image.Draw(dc, 0, 0);  // 원본 디바이스 컨텍스트에서 현재 디바이스 컨텍스트로 비트맵을 복사합니다.
								 // hDestDC = 대상 디바이스 컨텍스트에 대한 핸들
								 // xDest   = 대상 사각형의 왼쪽 위 모서리에 있는 x 좌표
								 // yDest   = 대상 사각형의 왼쪽 위 모서리에 있는 y 좌표

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
	CRect rect;  // CRect = 사각형의 좌측 상단과 우측 하단의 조표를 저장.
				 // CRect (int l, int t, int r, int b)
				 // int l = left  의 위치를 지정
				 // int t = top   의 위치를 지정
				 // int r = right 의 위치를 지정
				 // int b = bottom의 위치를 지정

	CPen pen;									// CPen = Windows 디바이스 컨텍스트에서 선을 그리는 도구
	pen.CreatePen(PS_SOLID, 2, COLOR_BLUE);     // int nPenStyle    = 펜의 스타일을 지정한다
												// PS_SOLID   = 실선 펜      
												// PS_DASH    = 파선 펜      
												// PS_DOT     = 점선 펜 
												// PS_DASHDOT = 대시와 점이 번갈아가는 팬

												// int nWidth = 펜의 너비를 지정한다
												// COLORREF crColor = 펜의 RGB 색을 포함한다

	CPen* pOldPen = pDC->SelectObject(&pen);

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);     // SetRect()         = 사각형을 만드는 함수
													// POINT topLeft     = 포인터의 사각형 왼쪽 위 모퉁이 위치
													// POINT bottomRight = 포인터의 사각형 오른쪽 아래 모퉁이 위치

		rect.InflateRect(2, 2);						// InflateRect() = CRect 측면의 중심에서 멀리 이동하여 확장한다
													// int x         = x의 왼쪽과 오른쪽을 팽창할 단위수를 지정함
													// int y         = y의 위쪽과 아래쪽을 팽창할 단위수를 지정함

		pDC->Ellipse(rect);						    // Ellipsed()     = 사각형에 내접한 타원그리기
													//                  타원의 중심이 지정된 경계사각형의 중심이다
													// LPCRECT lpRect = 타원의 경계 사각형을 지정함
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