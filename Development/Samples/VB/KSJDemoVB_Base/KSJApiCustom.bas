Attribute VB_Name = "KSJApiCustom"
Option Explicit

'��pData(���ΪnWidth, �߶�ΪnHeight, ����λ��ΪnBitCount)��ͼ����������Ϊ���ΪnStretchWidh, �߶�ΪnStretchHeight�����ݲ���䵽�û������pStretchData������,����λ������
Public Declare Function KSJ_HelperStretchBmp Lib "KSJAPI.dll" (pData As Any, ByVal nWidth As Long, ByVal nHeight As Long,ByVal nBitCount As Long, pStretchData As Any, ByVal nStretchWidth As Long, ByVal nStretchHeight As Long) As Long

'����ͼ��ı�����ȵõ�BMPͼ����ļ�ͷ,��Ϣͷ,����ɫ���ܵ��ֽ���Ŀ
Public Declare Function KSJ_HelperGetBmpFileHeaderSize Lib "KSJAPI.dll" (ByVal nBitCount As Long,ByRef pnTotalBytes As Long) As Long

'�õ�BMPͼ����ļ�ͷ����Ϣͷ
Public Declare Function KSJ_HelperGetBmpFileHeader Lib "KSJAPI.dll" (ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, pHeader As Any) As Long

'�ɼ�һ֡ͼ��ϵͳ������
Public Declare Function KSJ_CaptureRgbDataToClipboard Lib "KSJAPI.dll" (ByVal nChannel As Long) As Long