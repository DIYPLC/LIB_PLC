/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbModeSelector
 *** Description: Переключатель режимов работы.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbModeSelector_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbModeSelector_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbModeSelector, g_nStringIdFbModeSelector)

const CStringDictionary::TStringId FORTE_FbModeSelector::scmDataInputNames[] = {g_nStringIdButtonStop, g_nStringIdButtonManual, g_nStringIdButtonAuto, g_nStringIdError, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmDataOutputNames[] = {g_nStringIdLampStop, g_nStringIdLampManual, g_nStringIdLampAuto};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbModeSelector::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbModeSelector::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbModeSelector::scmEOWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbModeSelector::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbModeSelector::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbModeSelector::scmInternalsNames[] = {g_nStringIdState1, g_nStringIdFlagError};
const CStringDictionary::TStringId FORTE_FbModeSelector::scmInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbModeSelector::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

const CIEC_UINT FORTE_FbModeSelector::var_const_STATE_STOP = 0_UINT;
const CIEC_UINT FORTE_FbModeSelector::var_const_STATE_MANUAL = 1_UINT;
const CIEC_UINT FORTE_FbModeSelector::var_const_STATE_AUTO = 2_UINT;


FORTE_FbModeSelector::FORTE_FbModeSelector(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_State1(0_UINT),
    var_FlagError(false_BOOL),
    var_ButtonStop(false_BOOL),
    var_ButtonManual(false_BOOL),
    var_ButtonAuto(false_BOOL),
    var_Error(false_BOOL),
    var_Reset(false_BOOL),
    var_LampStop(false_BOOL),
    var_LampManual(false_BOOL),
    var_LampAuto(false_BOOL),
    var_conn_LampStop(var_LampStop),
    var_conn_LampManual(var_LampManual),
    var_conn_LampAuto(var_LampAuto),
    conn_CNF(this, 0),
    conn_ButtonStop(nullptr),
    conn_ButtonManual(nullptr),
    conn_ButtonAuto(nullptr),
    conn_Error(nullptr),
    conn_Reset(nullptr),
    conn_LampStop(this, 0, &var_conn_LampStop),
    conn_LampManual(this, 1, &var_conn_LampManual),
    conn_LampAuto(this, 2, &var_conn_LampAuto) {
}

void FORTE_FbModeSelector::setInitialValues() {
  var_State1 = 0_UINT;
  var_FlagError = false_BOOL;
  var_ButtonStop = false_BOOL;
  var_ButtonManual = false_BOOL;
  var_ButtonAuto = false_BOOL;
  var_Error = false_BOOL;
  var_Reset = false_BOOL;
  var_LampStop = false_BOOL;
  var_LampManual = false_BOOL;
  var_LampAuto = false_BOOL;
}

void FORTE_FbModeSelector::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbModeSelector::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbModeSelector::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_ButtonStop, conn_ButtonStop);
      readData(1, var_ButtonManual, conn_ButtonManual);
      readData(2, var_ButtonAuto, conn_ButtonAuto);
      readData(3, var_Error, conn_Error);
      readData(4, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbModeSelector::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_LampStop, conn_LampStop);
      writeData(1, var_LampManual, conn_LampManual);
      writeData(2, var_LampAuto, conn_LampAuto);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbModeSelector::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_ButtonStop;
    case 1: return &var_ButtonManual;
    case 2: return &var_ButtonAuto;
    case 3: return &var_Error;
    case 4: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbModeSelector::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_LampStop;
    case 1: return &var_LampManual;
    case 2: return &var_LampAuto;
  }
  return nullptr;
}

CEventConnection *FORTE_FbModeSelector::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbModeSelector::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_ButtonStop;
    case 1: return &conn_ButtonManual;
    case 2: return &conn_ButtonAuto;
    case 3: return &conn_Error;
    case 4: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbModeSelector::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_LampStop;
    case 1: return &conn_LampManual;
    case 2: return &conn_LampAuto;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbModeSelector::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_State1;
    case 1: return &var_FlagError;
  }
  return nullptr;
}

void FORTE_FbModeSelector::alg_REQ(void) {

  #line 4 "FbModeSelector.fbt"
  var_FlagError = func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(var_ButtonStop, var_ButtonAuto), func_AND<CIEC_BOOL>(var_ButtonStop, var_ButtonManual));
  #line 7 "FbModeSelector.fbt"
  if (func_OR<CIEC_BOOL>(var_Reset, var_FlagError)) {
    #line 8 "FbModeSelector.fbt"
    var_State1 = var_const_STATE_STOP;
    #line 9 "FbModeSelector.fbt"
    var_LampStop = true_BOOL;
    #line 10 "FbModeSelector.fbt"
    var_LampManual = false_BOOL;
    #line 11 "FbModeSelector.fbt"
    var_LampAuto = false_BOOL;
  }
  else {
    #line 14 "FbModeSelector.fbt"
    if (auto st_lv_synthetic_0 = var_State1; false) {
    } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_STOP)) {
      #line 16 "FbModeSelector.fbt"
      var_LampStop = true_BOOL;
      #line 17 "FbModeSelector.fbt"
      var_LampManual = false_BOOL;
      #line 18 "FbModeSelector.fbt"
      var_LampAuto = false_BOOL;
      #line 20 "FbModeSelector.fbt"
      if (var_ButtonManual) {
        #line 21 "FbModeSelector.fbt"
        var_State1 = var_const_STATE_MANUAL;
        #line 22 "FbModeSelector.fbt"
        var_LampStop = false_BOOL;
        #line 23 "FbModeSelector.fbt"
        var_LampManual = true_BOOL;
        #line 24 "FbModeSelector.fbt"
        var_LampAuto = false_BOOL;
      }
      #line 27 "FbModeSelector.fbt"
      if (func_AND<CIEC_BOOL>(var_ButtonAuto, func_NOT<CIEC_BOOL>(var_Error))) {
        #line 28 "FbModeSelector.fbt"
        var_State1 = var_const_STATE_AUTO;
        #line 29 "FbModeSelector.fbt"
        var_LampStop = false_BOOL;
        #line 30 "FbModeSelector.fbt"
        var_LampManual = false_BOOL;
        #line 31 "FbModeSelector.fbt"
        var_LampAuto = true_BOOL;
      }
    } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_MANUAL)) {
      #line 35 "FbModeSelector.fbt"
      var_LampStop = false_BOOL;
      #line 36 "FbModeSelector.fbt"
      var_LampManual = true_BOOL;
      #line 37 "FbModeSelector.fbt"
      var_LampAuto = false_BOOL;
      #line 39 "FbModeSelector.fbt"
      if (var_ButtonStop) {
        #line 40 "FbModeSelector.fbt"
        var_State1 = 0_UINT;
        #line 41 "FbModeSelector.fbt"
        var_LampStop = true_BOOL;
        #line 42 "FbModeSelector.fbt"
        var_LampManual = false_BOOL;
        #line 43 "FbModeSelector.fbt"
        var_LampAuto = false_BOOL;
      }
      #line 46 "FbModeSelector.fbt"
      if (func_AND<CIEC_BOOL>(var_ButtonAuto, func_NOT<CIEC_BOOL>(var_Error))) {
        #line 47 "FbModeSelector.fbt"
        var_State1 = var_const_STATE_AUTO;
        #line 48 "FbModeSelector.fbt"
        var_LampStop = false_BOOL;
        #line 49 "FbModeSelector.fbt"
        var_LampManual = false_BOOL;
        #line 50 "FbModeSelector.fbt"
        var_LampAuto = true_BOOL;
      }
    } else if (func_EQ(st_lv_synthetic_0, var_const_STATE_AUTO)) {
      #line 54 "FbModeSelector.fbt"
      var_LampStop = false_BOOL;
      #line 55 "FbModeSelector.fbt"
      var_LampManual = false_BOOL;
      #line 56 "FbModeSelector.fbt"
      var_LampAuto = true_BOOL;
      #line 58 "FbModeSelector.fbt"
      if (func_OR<CIEC_BOOL>(var_ButtonStop, var_Error)) {
        #line 59 "FbModeSelector.fbt"
        var_State1 = var_const_STATE_STOP;
        #line 60 "FbModeSelector.fbt"
        var_LampStop = true_BOOL;
        #line 61 "FbModeSelector.fbt"
        var_LampManual = false_BOOL;
        #line 62 "FbModeSelector.fbt"
        var_LampAuto = false_BOOL;
      }
      #line 65 "FbModeSelector.fbt"
      if (var_ButtonManual) {
        #line 66 "FbModeSelector.fbt"
        var_State1 = var_const_STATE_MANUAL;
        #line 67 "FbModeSelector.fbt"
        var_LampStop = false_BOOL;
        #line 68 "FbModeSelector.fbt"
        var_LampManual = true_BOOL;
        #line 69 "FbModeSelector.fbt"
        var_LampAuto = false_BOOL;
      }
    } else {
      #line 73 "FbModeSelector.fbt"
      var_State1 = var_const_STATE_STOP;
    }
  }
}
