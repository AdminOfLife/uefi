/*--------------------------------------------------------------------------------------------------------------------------*/
/*!!Warning: This is a key information asset of Huawei Tech Co.,Ltd                                                         */
/*CODEMARK:kOyQZYzjDpyGdBAEC2GaWuVy7vy/wDnq7gJfHBOj2pBXFF9pJtpDLt9sw5WJiMsUkN5d7jr7
aK5J3kmlnl+vpd1z2bQhhV6cC9dn956MYMwSDGfeyc2k9r9TKK9bTrj6YPvsPEr44pJLAZWy
NJXlVTULGA1ISf9ltqbAGfrSahFBeWVPU8rl/Z2i37aV2wlo/vUTcWxtXwzwiBpTg7ibYk5i
yPWT1Ab0J2Cb4SwFnWpn5lJinT6ELWKC9JV6zoOhgNGWG6BTr0DPHcNhDc0Lmg==*/
/*--------------------------------------------------------------------------------------------------------------------------*/
/*************************************************

Copyright (C), 1988-2010, Huawei Tech. Co., Ltd.

File name: HwProductsPkg\Pv660Evb\Library\OemMiscLibEvb\OemMiscLibEvb.c

Author: uniBIOS-g00179230 (Heyi Guo)    Date: 2014.11.4

Description: 
DTS2015012400081-C00227771-20150124 pangea����Ĭ������1866��Ƶ�ʣ����������ʵ�ֺ�����
DTS2015031709185-C00227771-20150317 ������Ƶ������Ӧѡ��
// uniBIOS_y00216284_043_start DTS2015051309310 BIOS���д���PCLint����  2015-5-13 >>>
*************************************************/
//uniBIOS_y00216284_013_start 2014-12-19 DTS2014121808254 PC-LINT�澯���� 
#include <Uefi.h>
//uniBIOS_z00304930_000_start 2014-12-4 16:17:49
 //Issue ID:DTS2014120204227 Description:
#include <Library/OemMiscLib.h>
//uniBIOS_z00304930_000_end   2014-12-4 16:17:49
#include <Library/DebugLib.h>
#include <Library/SerialPortLib.h>
#include <PlatformArch.h>
#include <Library/PlatformSysCtrlLib.h>
#include <Library/IoLib.h>
#include <Library/OemAddressMapLib.h>
#include <Library/PcdLib.h>
#include <Library/MemoryAllocationLib.h>

// Right now we only support 1P
BOOLEAN OemIsSocketPresent (UINTN Socket)
{
  if (0 == Socket)
  {
    return TRUE;
  }

  return FALSE;
}

UINTN OemGetSocketNumber (VOID)
{
    return 1;
}

// uniBIOS_y00216284_053_start DTS2015070301857 2015-7-4 >>>
// Description:����ʵ�ʵ����������ȡ�ڴ�ͨ����
UINTN OemGetDdrChannel (VOID)
{
    return 2;
}
// uniBIOS_y00216284_053_end 2015-7-4 <<<

//uniBIOS_z00304930_000_start 2014-12-17 10:55:57
 //Issue ID:DTS2014120400124 Description: ʹ��CPLD�ӿ�
VOID OemPostEndIndicator (VOID)
{
}
//uniBIOS_z00304930_000_end   2014-12-17 10:55:57

//uniBIOS_z00304930_000_start 2014-12-4 10:42:42
 //Issue ID:DTS2014120204227 Description:
EFI_STATUS OemSelfTestReport(IN E_SELF_TEST_ITEM Item, IN U_SELF_TEST_PARA Para)
{
    return EFI_SUCCESS;
}

VOID OemSetSelfTestFailFlagAndAlarm()
{
    return;
}

UINT32 OemGetCurrentBiosChannel(VOID)
{
    return 0;
}

//uniBIOS_z00304930_000_start 2014-12-16 10:01:13
 //Issue ID:DTS2014120902872  Description:�䨲???��������a??DT??
EFI_STATUS OemCheckCpld(VOID)
{
    return EFI_SUCCESS;
}

EFI_STATUS OemCheckClock(VOID)
{
    return EFI_SUCCESS;
}
//uniBIOS_z00304930_000_end   2014-12-16 10:01:13
//uniBIOS_z00304930_000_end   2014-12-4 10:42:42

//uniBIOS_z00304930_000_start 2014-12-17 11:32:55
 //Issue ID:DTS2014120801893 Description:����ԭ���ϱ�
E_RESET_CAUSE OemGetCurrentResetCause(VOID)
{
    return RESET_CAUSE_CPLD_BUTT;
}

E_RESET_CAUSE OemGetPer2ResetCause(VOID)
{
    return RESET_CAUSE_CPLD_BUTT;
}

E_RESET_CAUSE OemGetPer3ResetCause(VOID)
{
    return RESET_CAUSE_CPLD_BUTT;
}

UINT32 OemIsWarmBoot(VOID)
{
    return 0;
}

//uniBIOS_z00304930_000_end   2014-12-17 11:32:55

//uniBIOS_c00213799_start 2014-12-18 10:12:13
//Issue ID:DTS2014121800997
//Description:��iWare V200R002C00B950 BIOS��CPU L1/L2 Cache mbist���ܺ���
VOID CoreSelectBoot(VOID)
{
    if (!PcdGet64 (PcdTrustedFirmwareEnable))
    {
        StartupAp ();
    }

    return;
}
//uniBIOS_c00213799_end 2014-12-18 10:12:13

//uniBIOS_z00304930_000_start 2014-12-18 10:32:10
 //Issue ID:DTS2014121801315 Description:biosupdate������������bios�л�
VOID OemBiosSwitch(UINT32 Master)
{
    return;
}
//uniBIOS_z00304930_000_end   2014-12-18 10:32:10

 //Issue ID:DTS2015042006493    Description:��iWare V200R002C00B980 BIOS�����տ�ԴҪ��Դ���ṹ��������
VOID OemWriteProtectSet(BOOLEAN val)
{
    return;
}
/*******************************************************************************
 �� �� ��  : OemIsSpiFlashWriteProtected
 ��������  : �Ƿ���Ŀ��Ҫspi flashд�������ܣ����뷵��TRUE,�񷵻�FALSE
 �������  : ��  
 �������  : TRUE/FALSE
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��12��17��
    ��    ��   : l00306713
    �޸�����   : �����ɺ���
*******************************************************************************/
BOOLEAN OemIsSpiFlashWriteProtected(VOID)
{
    return FALSE;
}

VOID OpenAlarmLed(VOID)
{
    //UINT8 Value;
    //��������澯��
    //Value = ReadCpldReg(CPLD_BIOS_WR_REG);
    //Value |= CPLD_ALARM_LED_FIG;
    //WriteCpldReg(CPLD_BIOS_WR_REG, Value);
    
    return ;
}

//uniBIOS_z00304930_000_start 2015-1-23 14:33:20
 //Issue ID:DTS2015012306969  Description:CK420չƵ�����к���
EFI_STATUS OemCk420Read(UINT16 InfoOffset, UINT32 ulLength, UINT8 *pBuf)
{
    return EFI_SUCCESS;
}

EFI_STATUS OemCk420Write(UINT16 InfoOffset, UINT32 ulLength, UINT8 *pBuf)
{
    return EFI_SUCCESS;
}

VOID OemPcieCardReset(UINT32 Reset)
{
    return;
}
//uniBIOS_z00304930_000_end   2015-1-23 14:33:20


//uniBIOS_y00216284_023_start DTS2015030207984 2015-3-9 15:27:28
//Description: �̹� C02����hilink5��hilink6����һ��SAS������SAS1��
//�ڼ���Sata����ʱSAS1��Ӧ��8��phyȫ����ʹ�ܣ����hilink5��Ӧ��phy���ֶ��phychange
UINT8 OemAhciStartPort(VOID)
{
    return 0;
}
//uniBIOS_y00216284_023_end 2015-3-9 15:27:28




UINT16 OemSataNum = 0;
UINT16 OemSataDesSize = 0;
UINT16 OemPXENum = 0;
UINT16 OemPXEDesSize = 0;
UINT8 OemFirstBootId = 0;

EFI_STATUS OemGetSataBootNum(UINTN SataDesSize)
{
    if( SataDesSize/sizeof(UINT16) > 0)
    {
        OemSataDesSize = SataDesSize;
        OemSataNum = OemSataDesSize/sizeof(UINT16);
    }
    else{    
        OemSataNum = 0;    
    }

    return EFI_SUCCESS;
}

EFI_STATUS OemGetPXEBootNum(UINTN PXESize)
{
    if( PXESize/sizeof(UINT16) > 0)
    {
        OemPXEDesSize = PXESize;
        OemPXENum = OemPXEDesSize/sizeof(UINT16);
    }else{
        OemPXENum = 0;
    }

    return EFI_SUCCESS;
}

EFI_STATUS OemPreStartBootOptionAction(UINT16 BootOptionId)
{
    return EFI_SUCCESS;
}

EFI_STATUS OemBootOrderSeting(IN OUT UINT16* BootOrderFinal, UINTN BootOrderSize, BOOLEAN *IsFlashBootFirst, BOOLEAN *FlashBootSupport)
{
    *FlashBootSupport = FALSE;
    if(BootOrderFinal == NULL || BootOrderSize == 0)
    {
        return EFI_INVALID_PARAMETER;
    }
    return EFI_SUCCESS;    
}

VOID OemScrubFlagConfig(pGBL_DATA pGblData)
{
    return;     
}
//uniBIOS_y00216284_044_end 2015-5-14 <<<
//uniBIOS_l00306713_000_start 2015-6-16 17:34:20
 //Issue ID:DTS2015051503878    Description:��iWare V200R002C00B980 BIOS���޸�lemon����BIOS�����뿪Դ��ͻ 
BOOLEAN IsNeedSkipVariableSpaceOperation()
{
    return FALSE;
}
//uniBIOS_l00306713_000_end   2015-6-16 17:34:20

//uniBIOS__l00228991_start DTS2015072808846 2015-8-6 18:33:18
//Description:����Lemon����BMC����SetupĬ��ֵ�Ĺ���
BOOLEAN OemIsLoadDefault()
{
    return FALSE;
}
//uniBIOS__l00228991_end   2015-8-6 18:33:18

BOOLEAN OemIsInitEth(UINT32 Port)
{
    return TRUE;
}

