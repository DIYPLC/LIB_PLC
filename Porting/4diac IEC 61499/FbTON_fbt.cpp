/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbTON
 *** Description: Таймер с задержкой на включение.
 *** Version:
 ***     2.2: 2026-03-14/VA - LIB_PLC -
 *************************************************************************/

#include "FbTON_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbTON_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbTON, g_nStringIdFbTON)

const CStringDictionary::TStringId FORTE_FbTON::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdTimeDelayOn, g_nStringIdTs_ms};
const CStringDictionary::TStringId FORTE_FbTON::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_FbTON::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbTON::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbTON::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbTON::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTON::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbTON::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbTON::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTON::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbTON::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbTON::scmInternalsNames[] = {g_nStringIdTimer1};
const CStringDictionary::TStringId FORTE_FbTON::scmInternalsTypeIds[] = {g_nStringIdUDINT};
const SInternalVarsInformation FORTE_FbTON::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbTON::FORTE_FbTON(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Timer1(0_UDINT),
    var_In(false_BOOL),
    var_TimeDelayOn(5000_UDINT),
    var_Ts_ms(100_UDINT),
    var_Out(false_BOOL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_TimeDelayOn(nullptr),
    conn_Ts_ms(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbTON::setInitialValues() {
  var_Timer1 = 0_UDINT;
  var_In = false_BOOL;
  var_TimeDelayOn = 5000_UDINT;
  var_Ts_ms = 100_UDINT;
  var_Out = false_BOOL;
}

void FORTE_FbTON::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbTON::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbTON::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_TimeDelayOn, conn_TimeDelayOn);
      readData(2, var_Ts_ms, conn_Ts_ms);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbTON::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbTON::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_TimeDelayOn;
    case 2: return &var_Ts_ms;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTON::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbTON::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbTON::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_TimeDelayOn;
    case 2: return &conn_Ts_ms;
  }
  return nullptr;
}

CDataConnection *FORTE_FbTON::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTON::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Timer1;
  }
  return nullptr;
}

void FORTE_FbTON::alg_REQ(void) {

  #line 2 "FbTON.fbt"
  if (func_GT(var_TimeDelayOn, 0_UDINT)) {
    #line 3 "FbTON.fbt"
    if (var_In) {
      #line 4 "FbTON.fbt"
      if (var_Out) {
        #line 5 "FbTON.fbt"
        var_Out = true_BOOL;
        #line 6 "FbTON.fbt"
        var_Timer1 = 0_UDINT;
      }
      else {
        #line 8 "FbTON.fbt"
        if (func_GE(var_Timer1, var_TimeDelayOn)) {
          #line 9 "FbTON.fbt"
          var_Out = true_BOOL;
          #line 10 "FbTON.fbt"
          var_Timer1 = 0_UDINT;
        }
        else {
          #line 12 "FbTON.fbt"
          var_Out = false_BOOL;
          #line 13 "FbTON.fbt"
          var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
        }
      }
    }
    else {
      #line 17 "FbTON.fbt"
      var_Out = false_BOOL;
      #line 18 "FbTON.fbt"
      var_Timer1 = 0_UDINT;
    }
  }
  else {
    #line 21 "FbTON.fbt"
    var_Out = var_In;
    #line 22 "FbTON.fbt"
    var_Timer1 = 0_UDINT;
  }
}
