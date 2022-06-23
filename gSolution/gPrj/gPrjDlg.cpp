
// gPrjDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std; // std:: �ۼ��� �����ϰ� ���ش�

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") // Consol â�� ����ϴ� �ڵ�
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CgPrjDlg ��ȭ ����



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


// CgPrjDlg �޽��� ó����

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	MoveWindow(0, 0, 1280, 800);  // CWnd�� ��ġ�� ���̸� �����Ѵ�.
								  // int x      = ������ �� ��ġ�� �����Ѵ�
								  // int y      = ������ �� ��ġ�� �����Ѵ�
								  // int nWidth = �ʺ� �����Ѵ�
								  // int Height = ���̸� �����Ѵ�

	m_pDlgImage = new CDlgImage;             // new�� ����ؼ� ��ü�� ����
											 // new�� ����ϸ� �׻� delete �� ���־�� �޸� ���� �߻����� �ʴ´�

	m_pDlgImage->Create(IDD_DLGIMAGE, this); // Create() �Լ��� ����ؼ� �����츦 ����
											 // ù��° ���ڰ� = ID 
											 // �ι�° ���ڰ� = ������ (this = ������ ���̾�α� ������ )

	m_pDlgImage->ShowWindow(SW_SHOW);        // ShowWindow() = ������ �������� ǥ�� ���¸� �����Ѵ�
	                                         // SW_SHOW      = �����츦 ����ũ��� �����ش�

	m_pDlgImage->MoveWindow(0, 0, 640, 480); // CWnd�� ��ġ�� ���̸� �����Ѵ�.
											 // int x      = ������ �� ��ġ�� �����Ѵ�
											 // int y      = ������ �� ��ġ�� �����Ѵ�
											 // int nWidth = �ʺ� �����Ѵ�
											 // int Height = ���̸� �����Ѵ�

	m_pDlglmgResult = new CDlgImage;
	m_pDlglmgResult->Create(IDD_DLGIMAGE, this);
	m_pDlglmgResult->ShowWindow(SW_SHOW);  
	m_pDlglmgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgPrjDlg::OnDestroy()         // WM_DESTROY �޼����� �ش� �����쿡 ���޵Ǹ� OnDestroy �Լ��� ȣ���Ѵ�
{                                  // Ŭ���������� > �޽��� > WM_DESTROY > �߰�
	CDialogEx::OnDestroy();

	if(m_pDlgImage)		delete m_pDlgImage;      // new�� ����ϸ� �׻� delete �� ���־�� �޸� ���� �߻����� �ʴ´� .
	if(m_pDlglmgResult) delete m_pDlglmgResult;  // 2���� new�� �����߱� ������ 2���� delete�� ���־�� �Ѵ�
}


void CgPrjDlg::callFunc(int n)
{
//	int nDate = n;
	cout << n << endl;
}


void CgPrjDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();	  // unsigned = 0 ~ 255 (����� ǥ�� ����, �ּҰ��� ��� ������ �������� ���� )
															              // GetBits  = ������ �ȼ��� ���� ��Ʈ ���� ���� �����͸� �˻�. 
															              //            ( m_image�� ù��° �����͸� ������ �� )

	int nWidth = m_pDlgImage->m_image.GetWidth();     // ������ ��ǥ�� ȣ��
	int nHeight = m_pDlgImage->m_image.GetHeight();   // ������ ��ǥ�� ȣ��
	int nPitch = m_pDlgImage->m_image.GetPitch();     // ������ ��ǥ�� ȣ��

	memset(fm, 0x00, nWidth * nHeight);// memset �Լ��� �޸��� ����(��)�� ���ϴ� ũ�⸸ŭ Ư�� ������ ������ �� �ִ� �Լ�
									   // memory + setting �޸𸮸� (Ư�� ������) ����
									   // void *ptr    = �ּҸ� ����Ű���ִ� �����Ͱ� ��ġ�ϴ� �ڸ�
									   // int value    = �޸𸮿� �����ϰ��� �ϴ� ���� ������ ��
									   // size_t _Size = ���� ( ����Ʈ �����ν� �޸��� ũ�� ������ ������ ���̸� ���� )
	

	for (int k = 0; k < MAX_POINT; k++){    // ȭ�鿡 100���� ���� �� ǥ��.
		int x = rand() % nWidth;      // rand(); = ������ ���ڸ� ��ȯ�Ѵ� . ��ȯ���� ( 0 ~ 32767 ) ������ ��
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand() % 0xff;
	}

	int nIndex = 0;
	int nTh = 100;
	for (int j = 0; j < nHeight; j++) {     // �� ���� ī���ð� ������ ��ǥ�� ǥ���ϱ�.
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] > nTh) {
				if (m_pDlglmgResult->m_nDataCount < MAX_POINT) {
					cout << nIndex << ":" << i << "," << j << endl;
					m_pDlglmgResult->m_ptData[nIndex].x = i;
					m_pDlglmgResult->m_ptData[nIndex].y = j;
					m_pDlglmgResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}
	m_pDlgImage->Invalidate();  // Invalidate = CWnd�� ��ü Ŭ���̾�Ʈ ������ ��ȿȭ ��Ű�°�
								//              ȭ���� ������ �����ؼ� �����
	m_pDlglmgResult->Invalidate();
}
