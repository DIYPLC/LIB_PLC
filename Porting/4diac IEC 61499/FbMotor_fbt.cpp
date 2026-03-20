/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbMotor
 *** Description: Двигатель с частотником и контактором.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbMotor_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbMotor_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbMotor, g_nStringIdFbMotor)

const CStringDictionary::TStringId FORTE_FbMotor::scmDataInputNames[] = {g_nStringIdMotorRun, g_nStringIdVoltageOk, g_nStringIdDriveOk, g_nStringIdContactorOk, g_nStringIdTimeMonitoring, g_nStringIdTimeDelayOn, g_nStringIdTimeDelayOff, g_nStringIdTs_ms, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbMotor::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbMotor::scmDataOutputNames[] = {g_nStringIdMotorOn, g_nStringIdContactorOn, g_nStringIdErrorVoltage, g_nStringIdErrorDrive, g_nStringIdErrorContactor};
const CStringDictionary::TStringId FORTE_FbMotor::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbMotor::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, scmWithListDelimiter};
const TForteInt16 FORTE_FbMotor::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbMotor::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbMotor::scmEOWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbMotor::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbMotor::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbMotor::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  9, scmDataInputNames, scmDataInputTypeIds,
  5, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbMotor::scmInternalsNames[] = {g_nStringIdState1, g_nStringIdTimer1, g_nStringIdTimer2};
const CStringDictionary::TStringId FORTE_FbMotor::scmInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdUDINT, g_nStringIdUDINT};
const SInternalVarsInformation FORTE_FbMotor::scmInternalVars = {3, scmInternalsNames, scmInternalsTypeIds};

const CIEC_UINT FORTE_FbMotor::var_const_STATE_STOP = 0_UINT;
const CIEC_UINT FORTE_FbMotor::var_const_STATE_CONTACTOR_ON = 1_UINT;
const CIEC_UINT FORTE_FbMotor::var_const_STATE_DRIVE_ON = 2_UINT;
const CIEC_UINT FORTE_FbMotor::var_const_STATE_RUN = 3_UINT;
const CIEC_UINT FORTE_FbMotor::var_const_STATE_DRIVE_OFF = 4_UINT;
const CIEC_UINT FORTE_FbMotor::var_const_STATE_CONTACTOR_OFF = 5_UINT;


FORTE_FbMotor::FORTE_FbMotor(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_State1(0_UINT),
    var_Timer1(0_UDINT),
    var_Timer2(0_UDINT),
    var_MotorRun(false_BOOL),
    var_VoltageOk(false_BOOL),
    var_DriveOk(false_BOOL),
    var_ContactorOk(false_BOOL),
    var_TimeMonitoring(1000_UDINT),
    var_TimeDelayOn(1000_UDINT),
    var_TimeDelayOff(5000_UDINT),
    var_Ts_ms(100_UDINT),
    var_Reset(false_BOOL),
    var_MotorOn(false_BOOL),
    var_ContactorOn(false_BOOL),
    var_ErrorVoltage(false_BOOL),
    var_ErrorDrive(false_BOOL),
    var_ErrorContactor(false_BOOL),
    var_conn_MotorOn(var_MotorOn),
    var_conn_ContactorOn(var_ContactorOn),
    var_conn_ErrorVoltage(var_ErrorVoltage),
    var_conn_ErrorDrive(var_ErrorDrive),
    var_conn_ErrorContactor(var_ErrorContactor),
    conn_CNF(this, 0),
    conn_MotorRun(nullptr),
    conn_VoltageOk(nullptr),
    conn_DriveOk(nullptr),
    conn_ContactorOk(nullptr),
    conn_TimeMonitoring(nullptr),
    conn_TimeDelayOn(nullptr),
    conn_TimeDelayOff(nullptr),
    conn_Ts_ms(nullptr),
    conn_Reset(nullptr),
    conn_MotorOn(this, 0, &var_conn_MotorOn),
    conn_ContactorOn(this, 1, &var_conn_ContactorOn),
    conn_ErrorVoltage(this, 2, &var_conn_ErrorVoltage),
    conn_ErrorDrive(this, 3, &var_conn_ErrorDrive),
    conn_ErrorContactor(this, 4, &var_conn_ErrorContactor) {
}

void FORTE_FbMotor::setInitialValues() {
  var_State1 = 0_UINT;
  var_Timer1 = 0_UDINT;
  var_Timer2 = 0_UDINT;
  var_MotorRun = false_BOOL;
  var_VoltageOk = false_BOOL;
  var_DriveOk = false_BOOL;
  var_ContactorOk = false_BOOL;
  var_TimeMonitoring = 1000_UDINT;
  var_TimeDelayOn = 1000_UDINT;
  var_TimeDelayOff = 5000_UDINT;
  var_Ts_ms = 100_UDINT;
  var_Reset = false_BOOL;
  var_MotorOn = false_BOOL;
  var_ContactorOn = false_BOOL;
  var_ErrorVoltage = false_BOOL;
  var_ErrorDrive = false_BOOL;
  var_ErrorContactor = false_BOOL;
}

void FORTE_FbMotor::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbMotor::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbMotor::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_MotorRun, conn_MotorRun);
      readData(1, var_VoltageOk, conn_VoltageOk);
      readData(2, var_DriveOk, conn_DriveOk);
      readData(3, var_ContactorOk, conn_ContactorOk);
      readData(4, var_TimeMonitoring, conn_TimeMonitoring);
      readData(5, var_TimeDelayOn, conn_TimeDelayOn);
      readData(6, var_TimeDelayOff, conn_TimeDelayOff);
      readData(7, var_Ts_ms, conn_Ts_ms);
      readData(8, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbMotor::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_MotorOn, conn_MotorOn);
      writeData(1, var_ContactorOn, conn_ContactorOn);
      writeData(2, var_ErrorVoltage, conn_ErrorVoltage);
      writeData(3, var_ErrorDrive, conn_ErrorDrive);
      writeData(4, var_ErrorContactor, conn_ErrorContactor);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbMotor::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_MotorRun;
    case 1: return &var_VoltageOk;
    case 2: return &var_DriveOk;
    case 3: return &var_ContactorOk;
    case 4: return &var_TimeMonitoring;
    case 5: return &var_TimeDelayOn;
    case 6: return &var_TimeDelayOff;
    case 7: return &var_Ts_ms;
    case 8: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbMotor::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_MotorOn;
    case 1: return &var_ContactorOn;
    case 2: return &var_ErrorVoltage;
    case 3: return &var_ErrorDrive;
    case 4: return &var_ErrorContactor;
  }
  return nullptr;
}

CEventConnection *FORTE_FbMotor::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbMotor::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_MotorRun;
    case 1: return &conn_VoltageOk;
    case 2: return &conn_DriveOk;
    case 3: return &conn_ContactorOk;
    case 4: return &conn_TimeMonitoring;
    case 5: return &conn_TimeDelayOn;
    case 6: return &conn_TimeDelayOff;
    case 7: return &conn_Ts_ms;
    case 8: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbMotor::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_MotorOn;
    case 1: return &conn_ContactorOn;
    case 2: return &conn_ErrorVoltage;
    case 3: return &conn_ErrorDrive;
    case 4: return &conn_ErrorContactor;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbMotor::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_State1;
    case 1: return &var_Timer1;
    case 2: return &var_Timer2;
  }
  return nullptr;
}

void FORTE_FbMotor::alg_REQ(void) {

  #line 3 "FbMotor.fbt"
  var_ErrorVoltage = func_NOT<CIEC_BOOL>(var_VoltageOk);
  #line 6 "FbMotor.fbt"
  var_ErrorDrive = func_NOT<CIEC_BOOL>(var_DriveOk);
  #line 12 "FbMotor.fbt"
  if (var_ContactorOn) {
    #line 14 "FbMotor.fbt"
    if (var_ContactorOk) {
      #line 16 "FbMotor.fbt"
      var_Timer2 = 0_UDINT;
      #line 17 "FbMotor.fbt"
      var_ErrorContactor = false_BOOL;
    }
    else {
      #line 19 "FbMotor.fbt"
      if (func_LE(var_Timer2, var_TimeMonitoring)) {
        #line 21 "FbMotor.fbt"
        var_Timer2 = func_ADD<CIEC_UDINT>(var_Timer2, var_Ts_ms);
        #line 22 "FbMotor.fbt"
        var_ErrorContactor = false_BOOL;
      }
      else {
        #line 25 "FbMotor.fbt"
        var_ErrorContactor = true_BOOL;
      }
    }
  }
  else {
    #line 30 "FbMotor.fbt"
    if (func_NOT<CIEC_BOOL>(var_ContactorOk)) {
      #line 32 "FbMotor.fbt"
      var_Timer2 = 0_UDINT;
      #line 33 "FbMotor.fbt"
      var_ErrorContactor = false_BOOL;
    }
    else {
      #line 35 "FbMotor.fbt"
      if (func_LE(var_Timer2, var_TimeMonitoring)) {
        #line 37 "FbMotor.fbt"
        var_Timer2 = func_ADD<CIEC_UDINT>(var_Timer2, var_Ts_ms);
        #line 38 "FbMotor.fbt"
        var_ErrorContactor = false_BOOL;
      }
      else {
        #line 41 "FbMotor.fbt"
        var_ErrorContactor = true_BOOL;
      }
    }
  }
  #line 47 "FbMotor.fbt"
  if (func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_Reset, var_ErrorVoltage), var_ErrorDrive)) {
    #line 48 "FbMotor.fbt"
    var_State1 = var_const_STATE_STOP;
  }
  #line 55 "FbMotor.fbt"
  if (auto st_lv_synthetic_0 = var_State1; false) {
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_STOP)) {
    #line 58 "FbMotor.fbt"
    var_MotorOn = false_BOOL;
    #line 59 "FbMotor.fbt"
    var_ContactorOn = false_BOOL;
    #line 60 "FbMotor.fbt"
    var_Timer1 = 0_UDINT;
    #line 62 "FbMotor.fbt"
    if (var_MotorRun) {
      #line 63 "FbMotor.fbt"
      var_State1 = var_const_STATE_CONTACTOR_ON;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_CONTACTOR_ON)) {
    #line 68 "FbMotor.fbt"
    var_MotorOn = false_BOOL;
    #line 69 "FbMotor.fbt"
    var_ContactorOn = true_BOOL;
    #line 70 "FbMotor.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 72 "FbMotor.fbt"
    if (func_GE(var_Timer1, var_TimeDelayOn)) {
      #line 73 "FbMotor.fbt"
      var_State1 = var_const_STATE_DRIVE_ON;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_DRIVE_ON)) {
    #line 78 "FbMotor.fbt"
    var_MotorOn = true_BOOL;
    #line 79 "FbMotor.fbt"
    var_ContactorOn = true_BOOL;
    #line 80 "FbMotor.fbt"
    var_Timer1 = 0_UDINT;
    #line 81 "FbMotor.fbt"
    var_State1 = var_const_STATE_RUN;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_RUN)) {
    #line 85 "FbMotor.fbt"
    var_MotorOn = true_BOOL;
    #line 86 "FbMotor.fbt"
    var_ContactorOn = true_BOOL;
    #line 87 "FbMotor.fbt"
    var_Timer1 = 0_UDINT;
    #line 89 "FbMotor.fbt"
    if (func_NOT<CIEC_BOOL>(var_MotorRun)) {
      #line 90 "FbMotor.fbt"
      var_State1 = var_const_STATE_DRIVE_OFF;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_DRIVE_OFF)) {
    #line 95 "FbMotor.fbt"
    var_MotorOn = false_BOOL;
    #line 96 "FbMotor.fbt"
    var_ContactorOn = true_BOOL;
    #line 97 "FbMotor.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 99 "FbMotor.fbt"
    if (func_GE(var_Timer1, var_TimeDelayOff)) {
      #line 100 "FbMotor.fbt"
      var_State1 = var_const_STATE_CONTACTOR_OFF;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_CONTACTOR_OFF)) {
    #line 105 "FbMotor.fbt"
    var_MotorOn = false_BOOL;
    #line 106 "FbMotor.fbt"
    var_ContactorOn = false_BOOL;
    #line 107 "FbMotor.fbt"
    var_Timer1 = 0_UDINT;
    #line 109 "FbMotor.fbt"
    var_State1 = var_const_STATE_STOP;
  } else {
    #line 113 "FbMotor.fbt"
    var_State1 = var_const_STATE_STOP;
  }
}
