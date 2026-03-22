/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbValve
 *** Description: Пневмоцилиндр с концевиками.
 *** Version:
 ***     2.3: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbValve_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbValve_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbValve, g_nStringIdFbValve)

const CStringDictionary::TStringId FORTE_FbValve::scmDataInputNames[] = {g_nStringIdCommandOpen, g_nStringIdFeedbackOpen, g_nStringIdFeedbackClose, g_nStringIdOnFeedbackOpen, g_nStringIdOnFeedbackClose, g_nStringIdReset, g_nStringIdTimeOpen, g_nStringIdTimeClose, g_nStringIdTs_ms};
const CStringDictionary::TStringId FORTE_FbValve::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_FbValve::scmDataOutputNames[] = {g_nStringIdCoilOpen, g_nStringIdStateOpen, g_nStringIdStateClose, g_nStringIdError};
const CStringDictionary::TStringId FORTE_FbValve::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbValve::scmEIWith[] = {0, 1, 2, 3, 4, 5, 7, 8, 6, scmWithListDelimiter};
const TForteInt16 FORTE_FbValve::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbValve::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbValve::scmEOWith[] = {0, 1, 2, 3, scmWithListDelimiter};
const TForteInt16 FORTE_FbValve::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbValve::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbValve::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  9, scmDataInputNames, scmDataInputTypeIds,
  4, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbValve::scmInternalsNames[] = {g_nStringIdTimer1, g_nStringIdState1};
const CStringDictionary::TStringId FORTE_FbValve::scmInternalsTypeIds[] = {g_nStringIdUDINT, g_nStringIdUINT};
const SInternalVarsInformation FORTE_FbValve::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

const CIEC_UINT FORTE_FbValve::var_const_STATE_RESET = 0_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_VALVE_CLOSING = 1_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_VALVE_CLOSE = 2_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_VALVE_OPENING = 3_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_VALVE_OPEN = 4_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_ERROR_CLOSE = 5_UINT;
const CIEC_UINT FORTE_FbValve::var_const_STATE_ERROR_OPEN = 6_UINT;


FORTE_FbValve::FORTE_FbValve(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Timer1(0_UDINT),
    var_State1(0_UINT),
    var_CommandOpen(false_BOOL),
    var_FeedbackOpen(false_BOOL),
    var_FeedbackClose(false_BOOL),
    var_OnFeedbackOpen(false_BOOL),
    var_OnFeedbackClose(false_BOOL),
    var_Reset(false_BOOL),
    var_TimeOpen(5000_UDINT),
    var_TimeClose(5000_UDINT),
    var_Ts_ms(100_UDINT),
    var_CoilOpen(false_BOOL),
    var_StateOpen(false_BOOL),
    var_StateClose(false_BOOL),
    var_Error(false_BOOL),
    var_conn_CoilOpen(var_CoilOpen),
    var_conn_StateOpen(var_StateOpen),
    var_conn_StateClose(var_StateClose),
    var_conn_Error(var_Error),
    conn_CNF(this, 0),
    conn_CommandOpen(nullptr),
    conn_FeedbackOpen(nullptr),
    conn_FeedbackClose(nullptr),
    conn_OnFeedbackOpen(nullptr),
    conn_OnFeedbackClose(nullptr),
    conn_Reset(nullptr),
    conn_TimeOpen(nullptr),
    conn_TimeClose(nullptr),
    conn_Ts_ms(nullptr),
    conn_CoilOpen(this, 0, &var_conn_CoilOpen),
    conn_StateOpen(this, 1, &var_conn_StateOpen),
    conn_StateClose(this, 2, &var_conn_StateClose),
    conn_Error(this, 3, &var_conn_Error) {
}

void FORTE_FbValve::setInitialValues() {
  var_Timer1 = 0_UDINT;
  var_State1 = 0_UINT;
  var_CommandOpen = false_BOOL;
  var_FeedbackOpen = false_BOOL;
  var_FeedbackClose = false_BOOL;
  var_OnFeedbackOpen = false_BOOL;
  var_OnFeedbackClose = false_BOOL;
  var_Reset = false_BOOL;
  var_TimeOpen = 5000_UDINT;
  var_TimeClose = 5000_UDINT;
  var_Ts_ms = 100_UDINT;
  var_CoilOpen = false_BOOL;
  var_StateOpen = false_BOOL;
  var_StateClose = false_BOOL;
  var_Error = false_BOOL;
}

void FORTE_FbValve::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbValve::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbValve::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_CommandOpen, conn_CommandOpen);
      readData(1, var_FeedbackOpen, conn_FeedbackOpen);
      readData(2, var_FeedbackClose, conn_FeedbackClose);
      readData(3, var_OnFeedbackOpen, conn_OnFeedbackOpen);
      readData(4, var_OnFeedbackClose, conn_OnFeedbackClose);
      readData(5, var_Reset, conn_Reset);
      readData(7, var_TimeClose, conn_TimeClose);
      readData(8, var_Ts_ms, conn_Ts_ms);
      readData(6, var_TimeOpen, conn_TimeOpen);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbValve::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_CoilOpen, conn_CoilOpen);
      writeData(1, var_StateOpen, conn_StateOpen);
      writeData(2, var_StateClose, conn_StateClose);
      writeData(3, var_Error, conn_Error);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbValve::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CommandOpen;
    case 1: return &var_FeedbackOpen;
    case 2: return &var_FeedbackClose;
    case 3: return &var_OnFeedbackOpen;
    case 4: return &var_OnFeedbackClose;
    case 5: return &var_Reset;
    case 6: return &var_TimeOpen;
    case 7: return &var_TimeClose;
    case 8: return &var_Ts_ms;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbValve::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CoilOpen;
    case 1: return &var_StateOpen;
    case 2: return &var_StateClose;
    case 3: return &var_Error;
  }
  return nullptr;
}

CEventConnection *FORTE_FbValve::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbValve::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CommandOpen;
    case 1: return &conn_FeedbackOpen;
    case 2: return &conn_FeedbackClose;
    case 3: return &conn_OnFeedbackOpen;
    case 4: return &conn_OnFeedbackClose;
    case 5: return &conn_Reset;
    case 6: return &conn_TimeOpen;
    case 7: return &conn_TimeClose;
    case 8: return &conn_Ts_ms;
  }
  return nullptr;
}

CDataConnection *FORTE_FbValve::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CoilOpen;
    case 1: return &conn_StateOpen;
    case 2: return &conn_StateClose;
    case 3: return &conn_Error;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbValve::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Timer1;
    case 1: return &var_State1;
  }
  return nullptr;
}

void FORTE_FbValve::alg_REQ(void) {

  #line 2 "FbValve.fbt"
  var_CoilOpen = var_CommandOpen;
  #line 5 "FbValve.fbt"
  if (var_Reset) {
    #line 6 "FbValve.fbt"
    var_State1 = var_const_STATE_RESET;
  }
  #line 10 "FbValve.fbt"
  if (auto st_lv_synthetic_0 = var_State1; false) {
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_RESET)) {
    #line 12 "FbValve.fbt"
    var_Timer1 = 0_UDINT;
    #line 13 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 14 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 15 "FbValve.fbt"
    var_Error = false_BOOL;
    #line 17 "FbValve.fbt"
    if (var_CommandOpen) {
      #line 18 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_OPENING;
    }
    else {
      #line 20 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_CLOSING;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_VALVE_CLOSING)) {
    #line 24 "FbValve.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 25 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 26 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 27 "FbValve.fbt"
    var_Error = false_BOOL;
    #line 30 "FbValve.fbt"
    if (func_OR<CIEC_BOOL>(var_FeedbackClose, func_AND<CIEC_BOOL>(func_NOT<CIEC_BOOL>(var_OnFeedbackClose), func_GE(var_Timer1, var_TimeClose)))) {
      #line 31 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_CLOSE;
    }
    #line 34 "FbValve.fbt"
    if (func_AND<CIEC_BOOL>(var_OnFeedbackClose, func_GE(var_Timer1, var_TimeClose))) {
      #line 35 "FbValve.fbt"
      var_State1 = var_const_STATE_ERROR_CLOSE;
    }
    #line 38 "FbValve.fbt"
    if (var_CommandOpen) {
      #line 39 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_OPENING;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_VALVE_CLOSE)) {
    #line 43 "FbValve.fbt"
    var_Timer1 = 0_UDINT;
    #line 44 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 45 "FbValve.fbt"
    var_StateClose = true_BOOL;
    #line 46 "FbValve.fbt"
    var_Error = false_BOOL;
    #line 48 "FbValve.fbt"
    if (var_CommandOpen) {
      #line 49 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_OPENING;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_VALVE_OPENING)) {
    #line 53 "FbValve.fbt"
    var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
    #line 54 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 55 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 56 "FbValve.fbt"
    var_Error = false_BOOL;
    #line 59 "FbValve.fbt"
    if (func_OR<CIEC_BOOL>(var_FeedbackOpen, func_AND<CIEC_BOOL>(func_NOT<CIEC_BOOL>(var_OnFeedbackOpen), func_GE(var_Timer1, var_TimeOpen)))) {
      #line 60 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_OPEN;
    }
    #line 63 "FbValve.fbt"
    if (func_AND<CIEC_BOOL>(var_OnFeedbackOpen, func_GE(var_Timer1, var_TimeOpen))) {
      #line 64 "FbValve.fbt"
      var_State1 = var_const_STATE_ERROR_OPEN;
    }
    #line 67 "FbValve.fbt"
    if (func_NOT<CIEC_BOOL>(var_CommandOpen)) {
      #line 68 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_CLOSING;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_VALVE_OPEN)) {
    #line 72 "FbValve.fbt"
    var_Timer1 = 0_UDINT;
    #line 73 "FbValve.fbt"
    var_StateOpen = true_BOOL;
    #line 74 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 75 "FbValve.fbt"
    var_Error = false_BOOL;
    #line 77 "FbValve.fbt"
    if (func_NOT<CIEC_BOOL>(var_CommandOpen)) {
      #line 78 "FbValve.fbt"
      var_State1 = var_const_STATE_VALVE_CLOSING;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_ERROR_CLOSE)) {
    #line 82 "FbValve.fbt"
    var_Timer1 = 0_UDINT;
    #line 83 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 84 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 85 "FbValve.fbt"
    var_Error = true_BOOL;
    #line 89 "FbValve.fbt"
    if (func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_FeedbackClose, var_CommandOpen), func_NOT<CIEC_BOOL>(var_OnFeedbackClose))) {
      #line 90 "FbValve.fbt"
      var_State1 = var_const_STATE_RESET;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_ERROR_OPEN)) {
    #line 94 "FbValve.fbt"
    var_Timer1 = 0_UDINT;
    #line 95 "FbValve.fbt"
    var_StateOpen = false_BOOL;
    #line 96 "FbValve.fbt"
    var_StateClose = false_BOOL;
    #line 97 "FbValve.fbt"
    var_Error = true_BOOL;
    #line 101 "FbValve.fbt"
    if (func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_FeedbackOpen, func_NOT<CIEC_BOOL>(var_CommandOpen)), func_NOT<CIEC_BOOL>(var_OnFeedbackOpen))) {
      #line 102 "FbValve.fbt"
      var_State1 = var_const_STATE_RESET;
    }
  } else {
    #line 106 "FbValve.fbt"
    var_State1 = var_const_STATE_RESET;
  }
}
