#pragma once

// CProcess 명령 대상입니다.

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	int getStarInfo(CImage *pImage, int nTh = 100); // nTh 디폴트 값을 설정
};


