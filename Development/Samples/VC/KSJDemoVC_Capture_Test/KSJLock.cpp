
#include "stdafx.h"
#include "KSJLock.h"


CKSJLock::CKSJLock() : m_bLocked(false),
m_nUsingCount(0)
{
	InitializeCriticalSection(&m_csDataLock);
	InitializeCriticalSection(&m_csCountLock);
}

CKSJLock::~CKSJLock()
{
	DeleteCriticalSection(&m_csDataLock);
	DeleteCriticalSection(&m_csCountLock);
}

bool CKSJLock::Lock(int nTimeoutMS)
{
	bool bSuccessed = false;

	EnterCriticalSection(&m_csDataLock);

	for (int i = 0; i<nTimeoutMS; ++i)
	{
		if (m_nUsingCount <= 0)
		{
			m_bLocked = true;
			bSuccessed = true;
			break;
		}

		Sleep(1);
	}

	LeaveCriticalSection(&m_csDataLock);

	return bSuccessed;
}

void CKSJLock::Unlock()
{
	m_bLocked = false;
}

bool CKSJLock::TryUsing(int nTimeoutMS)
{
	bool bSuccessed = false;

	EnterCriticalSection(&m_csDataLock);

	for (int i = 0; i<nTimeoutMS; ++i)
	{
		if (!m_bLocked)
		{
			bSuccessed = true;
			break;
		}

		Sleep(1);
	}

	if (bSuccessed)
	{
		EnterCriticalSection(&m_csCountLock);
		++m_nUsingCount;
		LeaveCriticalSection(&m_csCountLock);
	}

	LeaveCriticalSection(&m_csDataLock);

	return bSuccessed;
}

void CKSJLock::FinishUsed()
{
	EnterCriticalSection(&m_csCountLock);

	if (m_nUsingCount > 0) --m_nUsingCount;

	LeaveCriticalSection(&m_csCountLock);
}
