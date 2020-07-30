/*
* Copyright (c) 2020 Bitdefender
* SPDX-License-Identifier: Apache-2.0
*/

#pragma once

#include <winerror.h>
#include <string>
#include <vector>

#include "wmi.h"

#define BCD_GUID_BOOTMGR                L"{9dea862c-5cdd-4e70-acc1-f32b344d4795}"
#define BCD_GUID_FWBOOTMGR              L"{a5a30fa2-3d06-4e9f-b5f4-a01df9d1fcba}"
#define BCD_GUID_CURRENT                L"{fa926493-6f1c-4193-a414-58f0b2456d1e}"

enum BcdBootMgrElementTypes {
    BcdBootMgrObjectList_DisplayOrder = 0x24000001,
    BcdBootMgrObjectList_BootSequence = 0x24000002,
    BcdBootMgrObject_DefaultObject = 0x23000003,
    BcdBootMgrInteger_Timeout = 0x25000004,
    BcdBootMgrBoolean_AttemptResume = 0x26000005,
    BcdBootMgrObject_ResumeObject = 0x23000006,
    BcdBootMgrObjectList_ToolsDisplayOrder = 0x24000010,
    BcdBootMgrBoolean_DisplayBootMenu = 0x26000020,
    BcdBootMgrBoolean_NoErrorDisplay = 0x26000021,
    BcdBootMgrDevice_BcdDevice = 0x21000022,
    BcdBootMgrString_BcdFilePath = 0x22000023,
    BcdBootMgrBoolean_ProcessCustomActionsFirst = 0x26000028,
    BcdBootMgrIntegerList_CustomActionsList = 0x27000030,
    BcdBootMgrBoolean_PersistBootSequence = 0x26000031
};

enum BcdLibraryElementTypes {
    BcdLibraryDevice_ApplicationDevice = 0x11000001,
    BcdLibraryString_ApplicationPath = 0x12000002,
    BcdLibraryString_Description = 0x12000004,
    BcdLibraryString_PreferredLocale = 0x12000005,
    BcdLibraryObjectList_InheritedObjects = 0x14000006,
    BcdLibraryInteger_TruncatePhysicalMemory = 0x15000007,
    BcdLibraryObjectList_RecoverySequence = 0x14000008,
    BcdLibraryBoolean_AutoRecoveryEnabled = 0x16000009,
    BcdLibraryIntegerList_BadMemoryList = 0x1700000a,
    BcdLibraryBoolean_AllowBadMemoryAccess = 0x1600000b,
    BcdLibraryInteger_FirstMegabytePolicy = 0x1500000c,
    BcdLibraryInteger_RelocatePhysicalMemory = 0x1500000D,
    BcdLibraryInteger_AvoidLowPhysicalMemory = 0x1500000E,
    BcdLibraryBoolean_DebuggerEnabled = 0x16000010,
    BcdLibraryInteger_DebuggerType = 0x15000011,
    BcdLibraryInteger_SerialDebuggerPortAddress = 0x15000012,
    BcdLibraryInteger_SerialDebuggerPort = 0x15000013,
    BcdLibraryInteger_SerialDebuggerBaudRate = 0x15000014,
    BcdLibraryInteger_1394DebuggerChannel = 0x15000015,
    BcdLibraryString_UsbDebuggerTargetName = 0x12000016,
    BcdLibraryBoolean_DebuggerIgnoreUsermodeExceptions = 0x16000017,
    BcdLibraryInteger_DebuggerStartPolicy = 0x15000018,
    BcdLibraryString_DebuggerBusParameters = 0x12000019,
    BcdLibraryInteger_DebuggerNetHostIP = 0x1500001A,
    BcdLibraryInteger_DebuggerNetPort = 0x1500001B,
    BcdLibraryBoolean_DebuggerNetDhcp = 0x1600001C,
    BcdLibraryString_DebuggerNetKey = 0x1200001D,
    BcdLibraryBoolean_EmsEnabled = 0x16000020,
    BcdLibraryInteger_EmsPort = 0x15000022,
    BcdLibraryInteger_EmsBaudRate = 0x15000023,
    BcdLibraryString_LoadOptionsString = 0x12000030,
    BcdLibraryBoolean_DisplayAdvancedOptions = 0x16000040,
    BcdLibraryBoolean_DisplayOptionsEdit = 0x16000041,
    BcdLibraryDevice_BsdLogDevice = 0x11000043,
    BcdLibraryString_BsdLogPath = 0x12000044,
    BcdLibraryBoolean_GraphicsModeDisabled = 0x16000046,
    BcdLibraryInteger_ConfigAccessPolicy = 0x15000047,
    BcdLibraryBoolean_DisableIntegrityChecks = 0x16000048,
    BcdLibraryBoolean_AllowPrereleaseSignatures = 0x16000049,
    BcdLibraryString_FontPath = 0x1200004A,
    BcdLibraryInteger_SiPolicy = 0x1500004B,
    BcdLibraryInteger_FveBandId = 0x1500004C,
    BcdLibraryBoolean_ConsoleExtendedInput = 0x16000050,
    BcdLibraryInteger_GraphicsResolution = 0x15000052,
    BcdLibraryBoolean_RestartOnFailure = 0x16000053,
    BcdLibraryBoolean_GraphicsForceHighestMode = 0x16000054,
    BcdLibraryBoolean_IsolatedExecutionContext = 0x16000060,
    BcdLibraryBoolean_BootUxDisable = 0x1600006C,
    BcdLibraryBoolean_BootShutdownDisabled = 0x16000074,
    BcdLibraryIntegerList_AllowedInMemorySettings = 0x17000077,
    BcdLibraryBoolean_ForceFipsCrypto = 0x16000079
};

typedef enum BcdOSLoaderElementTypes {
    BcdOSLoaderDevice_OSDevice                        = 0x21000001,
    BcdOSLoaderString_SystemRoot                      = 0x22000002,
    BcdOSLoaderObject_AssociatedResumeObject          = 0x23000003,
    BcdOSLoaderBoolean_DetectKernelAndHal             = 0x26000010,
    BcdOSLoaderString_KernelPath                      = 0x22000011,
    BcdOSLoaderString_HalPath                         = 0x22000012,
    BcdOSLoaderString_DbgTransportPath                = 0x22000013,
    BcdOSLoaderInteger_NxPolicy                       = 0x25000020,
    BcdOSLoaderInteger_PAEPolicy                      = 0x25000021,
    BcdOSLoaderBoolean_WinPEMode                      = 0x26000022,
    BcdOSLoaderBoolean_DisableCrashAutoReboot         = 0x26000024,
    BcdOSLoaderBoolean_UseLastGoodSettings            = 0x26000025,
    BcdOSLoaderBoolean_AllowPrereleaseSignatures      = 0x26000027,
    BcdOSLoaderBoolean_NoLowMemory                    = 0x26000030,
    BcdOSLoaderInteger_RemoveMemory                   = 0x25000031,
    BcdOSLoaderInteger_IncreaseUserVa                 = 0x25000032,
    BcdOSLoaderBoolean_UseVgaDriver                   = 0x26000040,
    BcdOSLoaderBoolean_DisableBootDisplay             = 0x26000041,
    BcdOSLoaderBoolean_DisableVesaBios                = 0x26000042,
    BcdOSLoaderBoolean_DisableVgaMode                 = 0x26000043,
    BcdOSLoaderInteger_ClusterModeAddressing          = 0x25000050,
    BcdOSLoaderBoolean_UsePhysicalDestination         = 0x26000051,
    BcdOSLoaderInteger_RestrictApicCluster            = 0x25000052,
    BcdOSLoaderBoolean_UseLegacyApicMode              = 0x26000054,
    BcdOSLoaderInteger_X2ApicPolicy                   = 0x25000055,
    BcdOSLoaderBoolean_UseBootProcessorOnly           = 0x26000060,
    BcdOSLoaderInteger_NumberOfProcessors             = 0x25000061,
    BcdOSLoaderBoolean_ForceMaximumProcessors         = 0x26000062,
    BcdOSLoaderBoolean_ProcessorConfigurationFlags    = 0x25000063,
    BcdOSLoaderBoolean_MaximizeGroupsCreated          = 0x26000064,
    BcdOSLoaderBoolean_ForceGroupAwareness            = 0x26000065,
    BcdOSLoaderInteger_GroupSize                      = 0x25000066,
    BcdOSLoaderInteger_UseFirmwarePciSettings         = 0x26000070,
    BcdOSLoaderInteger_MsiPolicy                      = 0x25000071,
    BcdOSLoaderInteger_SafeBoot                       = 0x25000080,
    BcdOSLoaderBoolean_SafeBootAlternateShell         = 0x26000081,
    BcdOSLoaderBoolean_BootLogInitialization          = 0x26000090,
    BcdOSLoaderBoolean_VerboseObjectLoadMode          = 0x26000091,
    BcdOSLoaderBoolean_KernelDebuggerEnabled          = 0x260000a0,
    BcdOSLoaderBoolean_DebuggerHalBreakpoint          = 0x260000a1,
    BcdOSLoaderBoolean_UsePlatformClock               = 0x260000A2,
    BcdOSLoaderBoolean_ForceLegacyPlatform            = 0x260000A3,
    BcdOSLoaderInteger_TscSyncPolicy                  = 0x250000A6,
    BcdOSLoaderBoolean_EmsEnabled                     = 0x260000b0,
    BcdOSLoaderInteger_DriverLoadFailurePolicy        = 0x250000c1,
    BcdOSLoaderInteger_BootMenuPolicy                 = 0x250000C2,
    BcdOSLoaderBoolean_AdvancedOptionsOneTime         = 0x260000C3,
    BcdOSLoaderInteger_BootStatusPolicy               = 0x250000E0,
    BcdOSLoaderBoolean_DisableElamDrivers             = 0x260000E1,
    BcdOSLoaderInteger_HypervisorLaunchType           = 0x250000F0,
    BcdOSLoaderBoolean_HypervisorDebuggerEnabled      = 0x260000F2,
    BcdOSLoaderInteger_HypervisorDebuggerType         = 0x250000F3,
    BcdOSLoaderInteger_HypervisorDebuggerPortNumber   = 0x250000F4,
    BcdOSLoaderInteger_HypervisorDebuggerBaudrate     = 0x250000F5,
    BcdOSLoaderInteger_HypervisorDebugger1394Channel  = 0x250000F6,
    BcdOSLoaderInteger_BootUxPolicy                   = 0x250000F7,
    BcdOSLoaderString_HypervisorDebuggerBusParams     = 0x220000F9,
    BcdOSLoaderInteger_HypervisorNumProc              = 0x250000FA,
    BcdOSLoaderInteger_HypervisorRootProcPerNode      = 0x250000FB,
    BcdOSLoaderBoolean_HypervisorUseLargeVTlb         = 0x260000FC,
    BcdOSLoaderInteger_HypervisorDebuggerNetHostIp    = 0x250000FD,
    BcdOSLoaderInteger_HypervisorDebuggerNetHostPort  = 0x250000FE,
    BcdOSLoaderInteger_TpmBootEntropyPolicy           = 0x25000100,
    BcdOSLoaderString_HypervisorDebuggerNetKey        = 0x22000110,
    BcdOSLoaderBoolean_HypervisorDebuggerNetDhcp      = 0x26000114,
    BcdOSLoaderInteger_HypervisorIommuPolicy          = 0x25000115,
    BcdOSLoaderInteger_XSaveDisable                   = 0x2500012b,

    // undocumented:
    BcdOsLoaderBoolean_DisableDynamicTick             = 0x260000A5
} BcdOSLoaderElementTypes;

typedef enum BcdOSLoader_PAEPolicy {
    PaePolicyDefault       = 0,
    PaePolicyForceEnable   = 1,
    PaePolicyForceDisable  = 2
} BcdOSLoader_PAEPolicy;

// undocumented:
typedef enum BcdOSLoader_X2APICPolicy
{
    X2APICPolicyDefault    = 0,
    X2APICPolicyDisable    = 1,
    X2APICPolicyEnable     = 2
} BcdOSLoader_X2APICPolicy;

enum BcdObjectType
{
    BcdObj_Application = 0x10000000,
    BcdObj_Inherited = 0x20000000,
    BcdObj_Device = 0x30000000
};

enum BcdApplicationObjectType
{
    BcdObjApplication_Firmware = 0x100000,
    BcdObjApplication_Boot = 0x200000,
    BcdObjApplication_LegacyLoader = 0x300000,
    BcdObjApplication_RealModeCode = 0x400000
};

enum BcdInheritObjectType
{
    BcdObjInherit_ByAll = 0x100000,
    BcdObjInherit_ByApplication = 0x200000,
    BcdObjInherit_ByDevice = 0x300000
};

enum BcdObjectApplicationType
{
    BcdObjApp_FirmwareBootManager = 0x1,
    BcdObjApp_WindowsBootManager = 0x2,
    BcdObjApp_WindowsBootLoader = 0x3,
    BcdObjApp_WindowsResumeApplication = 0x4,
    BcdObjApp_MemoryTester = 0x5,
    BcdObjApp_LegacyNtldr = 0x6,
    BcdObjApp_LegacySetupLdr = 0x7,
    BcdObjApp_BootSector = 0x8,
    BcdObjApp_StartupModule = 0x9,
    BcdObjApp_GenericApplication = 0xa
};

enum BcdDeviceElementType
{
    BcdDevElem_BootDevice = 0x1,
    BcdDevElem_FileDevice = 0x2,
    BcdDevElem_PartitionDevice = 0x3,
    BcdDevElem_RamdiskDevice = 0x4,
    BcdDevElem_UnknownDevice = 0x5
};

class BcdStore;

class BcdObject
{
    friend class BcdStore;

public:
    HRESULT GetType(DWORD &Type);

    HRESULT GetGuid(std::wstring &Guid);

    HRESULT GetIntegerElement(DWORD Element, std::wstring &Data);

    HRESULT GetBooleanElement(DWORD Element, BOOLEAN &Data);

    HRESULT GetStringElement(DWORD Type, std::wstring &Data);

    HRESULT GetObjectListElement(DWORD Type, SAFEARRAY* &Data);

    HRESULT SetIntegerElement(DWORD Element, QWORD Data);

    HRESULT SetBooleanElement(DWORD Element, BOOLEAN Data);

    HRESULT SetStringElement(DWORD Element, std::wstring const& Data);

    HRESULT SetObjectListElement(DWORD Element, SAFEARRAY* Data);

    HRESULT DeleteElement(DWORD Element);

protected:
    BcdObject(WmiBridge* wmiManager);

    HRESULT Init(IWbemClassObject* ObjectInstance);

private:
    HRESULT GetElementInternal(std::wstring const& ParamName, DWORD Element, VARIANT &Data);

    HRESULT SetElementInternal(std::wstring const& ActualFunc, std::wstring const& ParamName, DWORD Element, const VARIANT &Data, CIMTYPE DataType);

    CComPtr<IWbemClassObject>   m_wmiBcdObject;
    CComPtr<IWbemClassObject>   m_wmiBcdObjectClass;
    WmiBridge*                  m_wmiBridge;
};


class BcdStore
{
public:
    BcdStore();

    HRESULT OpenStore(std::wstring const& StorePath);

    VOID    CloseStore();

    HRESULT EnumerateObjects(DWORD Type, std::vector<BcdObject*> &ObjectList);

    HRESULT OpenObject(std::wstring const& Guid, BcdObject* &Object);

    VOID    DisposeOfObject(BcdObject* &Object);

    HRESULT CopyObject(std::wstring const& SourceGuid, std::wstring &NewGuid);

    HRESULT DeleteObject(std::wstring const& Guid);

protected:

private:
    WmiBridge                   m_wmiBridge;
    CComPtr<IWbemClassObject>   m_wmiBcdStore;
    CComPtr<IWbemClassObject>   m_wmiBcdStoreClass;
};
