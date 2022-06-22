
// gPrjDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") // Consol 출력하는 코드
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgPrjDlg 대화 상자



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CgPrjDlg 메시지 처리기

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	MoveWindow(0, 0, 1280, 800);  // CWnd의 위치와 넓이를 변경한다.
								  // int x      = 왼쪽의 새 위치를 지정한다
								  // int y      = 위쪽의 새 위치를 지정한다
								  // int nWidth = 너비를 지정한다
								  // int Height = 높이를 지정한다

	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480); // CWnd의 위치와 넓이를 변경한다.
											 // int x      = 왼쪽의 새 위치를 지정한다
											 // int y      = 위쪽의 새 위치를 지정한다
											 // int nWidth = 너비를 지정한다
											 // int Height = 높이를 지정한다


	m_pDiglmageResult = new CDlgImage;
	m_pDiglmageResult->Create(IDD_DLGIMAGE, this);
	m_pDiglmageResult->ShowWindow(SW_SHOW);
	m_pDiglmageResult->ShowWindow(SW_SHOW);
	m_pDiglmageResult->MoveWindow(640, 0, 640, 480); // CWnd의 위치와 넓이를 변경한다.
													 // int x      = 왼쪽의 새 위치를 지정한다
													 // int y      = 위쪽의 새 위치를 지정한다
													 // int nWidth = 너비를 지정한다
													 // int Height = 높이를 지정한다

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CgPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	delete m_pDlgImage;
}


void CgPrjDlg::callFunc(int n)
{
//	int nDate = n;
	cout << n << endl;
}


void CgPrjDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();	  // unsigned = 0 ~ 255 (양수만 표시 가능, 주소값의 경우 음수가 존재하지 않음 )
															              // GetBits  = 지정된 픽셀의 실제 비트 값에 대한 포인터를 검색. 
															              //            ( m_image의 첫번째 포인터를 가지고 옴 )
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	for (int k = 0; k < 100; k++){    // 화면에 100개의 랜덤 점 표시.
		int x = rand() % nWidth;      // rand(); = 랜덤한 숫자를 반환한다 . 반환값은 ( 0 ~ 32767 ) 사이의 값
		int y = rand() % nHeight;
		fm[y * nPitch + x] = 0;
	}

	int nSum = 0;
	for (int j = 0; j < nHeight; j++) {     // 점 갯수 카운팅과 각점의 좌표값 표시하기.
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] == 0) {
				cout << "No." << nSum << " , " << " " << "x : " << i << " , " << "y : " << j << endl;
				nSum++;
			}
		}
	}


	/*memset(fm, 0, 640 * 480); */  // memset 함수는 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
							    // memory + setting 메모리를 (특정 값으로) 세팅
								// void *ptr    = 주소를 가리키고있는 포인터가 위치하는 자리
								// int value    = 메모리에 셋팅하고자 하는 값을 넣으면 됌
								// size_t _Size = 길이 ( 바이트 단위로써 메모리의 크기 한조각 단위의 길이를 말함 )

	m_pDlgImage->Invalidate();  // Invalidate = CWnd의 전체 클라이언트 영역을 무효화 시키는것
								//              화면의 배경색을 포함해서 재출력
}
