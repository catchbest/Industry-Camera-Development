
#pragma once

#include <windows.h>

class CKSJLock
{
public:
	CKSJLock();
	virtual ~CKSJLock();

public:
	bool Lock(int nTimeoutMS);
	void Unlock();

	bool TryUsing(int nTimeoutMS = 1000);
	void FinishUsed();

protected:
	bool m_bLocked;

	int  m_nUsingCount;

	CRITICAL_SECTION m_csDataLock;
	CRITICAL_SECTION m_csCountLock;

};
 
