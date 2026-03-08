/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbBlink
 *** Description: Мигающий светодиод.
 *** Version:
 ***     1.2: 2026-03-08/VA - LIB_PLC -
 *************************************************************************/

#include "FbBlink_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbBlink_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbBlink, g_nStringIdFbBlink)

const CStringDictionary::TStringId FORTE_FbBlink::scmDataInputNames[] = {g_nStringIdTimeOn, g_nStringIdTimeOff, g_nStringIdTs_ms, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbBlink::scmDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbBlink::scmDataOutputNames[] = {g_nStringIdBlinkLamp};
const CStringDictionary::TStringId FORTE_FbBlink::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbBlink::scmEIWith[] = {0, 1, 2, 3, scmWithListDelimiter};
const TForteInt16 FORTE_FbBlink::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbBlink::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbBlink::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbBlink::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbBlink::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbBlink::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  4, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbBlink::scmInternalsNames[] = {g_nStringIdTimer1, g_nStringIdState1};
const CStringDictionary::TStringId FORTE_FbBlink::scmInternalsTypeIds[] = {g_nStringIdUDINT, g_nStringIdUINT};
const SInternalVarsInformation FORTE_FbBlink::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

const CIEC_UINT FORTE_FbBlink::var_const_STATE_RESET = 0_UINT;
const CIEC_UINT FORTE_FbBlink::var_const_STATE_ON = 1_UINT;
const CIEC_UINT FORTE_FbBlink::var_const_STATE_OFF = 2_UINT;


FORTE_FbBlink::FORTE_FbBlink(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Timer1(0_UDINT),
    var_State1(0_UINT),
    var_TimeOn(2000_UDINT),
    var_TimeOff(2000_UDINT),
    var_Ts_ms(100_UDINT),
    var_Reset(false_BOOL),
    var_BlinkLamp(false_BOOL),
    var_conn_BlinkLamp(var_BlinkLamp),
    conn_CNF(this, 0),
    conn_TimeOn(nullptr),
    conn_TimeOff(nullptr),
    conn_Ts_ms(nullptr),
    conn_Reset(nullptr),
    conn_BlinkLamp(this, 0, &var_conn_BlinkLamp) {
}

void FORTE_FbBlink::setInitialValues() {
  var_Timer1 = 0_UDINT;
  var_State1 = 0_UINT;
  var_TimeOn = 2000_UDINT;
  var_TimeOff = 2000_UDINT;
  var_Ts_ms = 100_UDINT;
  var_Reset = false_BOOL;
  var_BlinkLamp = false_BOOL;
}

void FORTE_FbBlink::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbBlink::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbBlink::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_TimeOn, conn_TimeOn);
      readData(1, var_TimeOff, conn_TimeOff);
      readData(2, var_Ts_ms, conn_Ts_ms);
      readData(3, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbBlink::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_BlinkLamp, conn_BlinkLamp);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbBlink::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_TimeOn;
    case 1: return &var_TimeOff;
    case 2: return &var_Ts_ms;
    case 3: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbBlink::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_BlinkLamp;
  }
  return nullptr;
}

CEventConnection *FORTE_FbBlink::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbBlink::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_TimeOn;
    case 1: return &conn_TimeOff;
    case 2: return &conn_Ts_ms;
    case 3: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbBlink::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_BlinkLamp;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbBlink::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Timer1;
    case 1: return &var_State1;
  }
  return nullptr;
}

void FORTE_FbBlink::alg_REQ(void) {

  #line 2 "FbBlink.fbt"
  if (var_Reset) {
    #line 3 "FbBlink.fbt"
    var_State1 = var_const_STATE_RESET;
  }
  #line 6 "FbBlink.fbt"
  if (auto st_lv_synthetic_0 = var_State1; false) {
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_RESET)) {
    #line 8 "FbBlink.fbt"
    var_BlinkLamp = false_BOOL;
    #line 9 "FbBlink.fbt"
    var_Timer1 = 0_UDINT;
    #line 10 "FbBlink.fbt"
    var_State1 = var_const_STATE_ON;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_ON)) {
    #line 13 "FbBlink.fbt"
    var_BlinkLamp = true_BOOL;
    #line 14 "FbBlink.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 15 "FbBlink.fbt"
    if (func_GE(var_Timer1, var_TimeOn)) {
      #line 16 "FbBlink.fbt"
      var_State1 = var_const_STATE_OFF;
      #line 17 "FbBlink.fbt"
      var_Timer1 = 0_UDINT;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_OFF)) {
    #line 21 "FbBlink.fbt"
    var_BlinkLamp = false_BOOL;
    #line 22 "FbBlink.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 23 "FbBlink.fbt"
    if (func_GE(var_Timer1, var_TimeOff)) {
      #line 24 "FbBlink.fbt"
      var_State1 = var_const_STATE_ON;
      #line 25 "FbBlink.fbt"
      var_Timer1 = 0_UDINT;
    }
  } else {
    #line 29 "FbBlink.fbt"
    var_State1 = var_const_STATE_RESET;
  }
}
