// SnapStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ksjdemovc.h"
#include "SnapStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapStatic

CSnapStatic::CSnapStatic() : m_pPreviewBmpInfo( NULL ), m_pPreviewBmpData( NULL )
{
	m_pPreviewBmpInfo    = (LPBITMAPINFO)new char[ sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD) ];
	memset( (VOID*)m_pPreviewBmpInfo, 0, sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD) );

	if( m_pPreviewBmpInfo == NULL )
	{
		return ;
	}

	m_pPreviewBmpInfo->bmiHeader.biSize			    = sizeof(tagBITMAPINFOHEADER);
	m_pPreviewBmpInfo->bmiHeader.biPlanes			= 1;
	m_pPreviewBmpInfo->bmiHeader.biCompression		= BI_RGB;
	m_pPreviewBmpInfo->bmiHeader.biSizeImage		= 0;
	m_pPreviewBmpInfo->bmiHeader.biXPelsPerMeter	= 0;
	m_pPreviewBmpInfo->bmiHeader.biYPelsPerMeter	= 0;
	m_pPreviewBmpInfo->bmiHeader.biClrUsed			= 0;
	m_pPreviewBmpInfo->bmiHeader.biClrImportant	    = 0;

	m_pPreviewBmpInfo->bmiHeader.biWidth			= 0;
	m_pPreviewBmpInfo->bmiHeader.biHeight			= 0;
	m_pPreviewBmpInfo->bmiHeader.biBitCount		    = 0;
	m_pPreviewBmpInfo->bmiHeader.biSizeImage        = 0;  //m_nWidth * m_nHeight * ( m_nBitCount >> 3 );
	for ( int i=0; i<256; i++ )
	{
		m_pPreviewBmpInfo->bmiColors[i].rgbBlue	     = (BYTE) i;
		m_pPreviewBmpInfo->bmiColors[i].rgbGreen	 = (BYTE) i;
		m_pPreviewBmpInfo->bmiColors[i].rgbRed	     = (BYTE) i;
		m_pPreviewBmpInfo->bmiColors[i].rgbReserved  = (BYTE) i;
	}
}

CSnapStatic::~CSnapStatic()
{
	if( m_pPreviewBmpInfo )
	{
		delete m_pPreviewBmpInfo;
		m_pPreviewBmpInfo = NULL;
	}
}


BEGIN_MESSAGE_MAP(CSnapStatic, CStatic)
	//{{AFX_MSG_MAP(CSnapStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapStatic message handlers

void CSnapStatic::LoadImage(BYTE *pImageData, int nCaptureWidth, int nCaptureHeight, int nBitCount)
{
	// Memery out.
	if (m_pPreviewBmpData)     
	{
		delete[] m_pPreviewBmpData;
		m_pPreviewBmpData = NULL;
	}
	m_pPreviewBmpInfo->bmiHeader.biWidth			= nCaptureWidth;
	m_pPreviewBmpInfo->bmiHeader.biHeight			= nCaptureHeight;
	m_pPreviewBmpInfo->bmiHeader.biBitCount		    = nBitCount;
	m_pPreviewBmpInfo->bmiHeader.biSizeImage        = nCaptureWidth * nCaptureHeight * ( nBitCount >> 3 );

	m_pPreviewBmpData = new BYTE[m_pPreviewBmpInfo->bmiHeader.biSizeImage];
	memcpy(m_pPreviewBmpData, pImageData, m_pPreviewBmpInfo->bmiHeader.biSizeImage);

	Invalidate();
	UpdateWindow();
}

void CSnapStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if( m_pPreviewBmpData == NULL || m_pPreviewBmpInfo == NULL )    return;

	CRect    rtClient;
	GetClientRect( &rtClient );
	::SetStretchBltMode( dc.GetSafeHdc(), COLORONCOLOR );
	::StretchDIBits( dc.GetSafeHdc(), 0, 0, rtClient.Width(), rtClient.Height(), 0, 0, m_pPreviewBmpInfo->bmiHeader.biWidth, m_pPreviewBmpInfo->bmiHeader.biHeight, m_pPreviewBmpData, m_pPreviewBmpInfo, DIB_RGB_COLORS, SRCCOPY );

	
	// TODO: Add your message handler code here
	
	// Do not call CStatic::OnPaint() for painting messages
}
