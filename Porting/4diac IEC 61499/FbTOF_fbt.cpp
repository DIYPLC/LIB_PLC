/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbTOF
 *** Description: Таймер с задержкой на выключение.
 *** Version:
 ***     2.2: 2026-03-14/VA - LIB_PLC -
 *************************************************************************/

#include "FbTOF_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbTOF_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbTOF, g_nStringIdFbTOF)

const CStringDictionary::TStringId FORTE_FbTOF::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdTimeDelayOff, g_nStringIdTs_ms};
const CStringDictionary::TStringId FORTE_FbTOF::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_FbTOF::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbTOF::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbTOF::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbTOF::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTOF::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbTOF::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbTOF::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTOF::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbTOF::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbTOF::scmInternalsNames[] = {g_nStringIdTimer1};
const CStringDictionary::TStringId FORTE_FbTOF::scmInternalsTypeIds[] = {g_nStringIdUDINT};
const SInternalVarsInformation FORTE_FbTOF::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbTOF::FORTE_FbTOF(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Timer1(0_UDINT),
    var_In(false_BOOL),
    var_TimeDelayOff(5000_UDINT),
    var_Ts_ms(100_UDINT),
    var_Out(false_BOOL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_TimeDelayOff(nullptr),
    conn_Ts_ms(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbTOF::setInitialValues() {
  var_Timer1 = 0_UDINT;
  var_In = false_BOOL;
  var_TimeDelayOff = 5000_UDINT;
  var_Ts_ms = 100_UDINT;
  var_Out = false_BOOL;
}

void FORTE_FbTOF::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbTOF::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbTOF::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_TimeDelayOff, conn_TimeDelayOff);
      readData(2, var_Ts_ms, conn_Ts_ms);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbTOF::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbTOF::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_TimeDelayOff;
    case 2: return &var_Ts_ms;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTOF::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbTOF::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbTOF::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_TimeDelayOff;
    case 2: return &conn_Ts_ms;
  }
  return nullptr;
}

CDataConnection *FORTE_FbTOF::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTOF::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Timer1;
  }
  return nullptr;
}

void FORTE_FbTOF::alg_REQ(void) {

  #line 2 "FbTOF.fbt"
  if (func_GT(var_TimeDelayOff, 0_UDINT)) {
    #line 3 "FbTOF.fbt"
    if (var_In) {
      #line 4 "FbTOF.fbt"
      var_Out = true_BOOL;
      #line 5 "FbTOF.fbt"
      var_Timer1 = 0_UDINT;
    }
    else {
      #line 7 "FbTOF.fbt"
      if (var_Out) {
        #line 8 "FbTOF.fbt"
        if (func_GE(var_Timer1, var_TimeDelayOff)) {
          #line 9 "FbTOF.fbt"
          var_Out = false_BOOL;
          #line 10 "FbTOF.fbt"
          var_Timer1 = 0_UDINT;
        }
        else {
          #line 12 "FbTOF.fbt"
          var_Out = true_BOOL;
          #line 13 "FbTOF.fbt"
          var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
        }
      }
      else {
        #line 16 "FbTOF.fbt"
        var_Out = false_BOOL;
        #line 17 "FbTOF.fbt"
        var_Timer1 = 0_UDINT;
      }
    }
  }
  else {
    #line 21 "FbTOF.fbt"
    var_Out = var_In;
    #line 22 "FbTOF.fbt"
    var_Timer1 = 0_UDINT;
  }
}
