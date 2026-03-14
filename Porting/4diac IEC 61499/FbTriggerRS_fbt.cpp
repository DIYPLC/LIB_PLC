/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbTriggerRS
 *** Description: RS- Триггер с приоритетом на сброс.
 *** Version:
 ***     2.1: 2026-03-14/VA - LIB_PLC -
 *************************************************************************/

#include "FbTriggerRS_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbTriggerRS_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbTriggerRS, g_nStringIdFbTriggerRS)

const CStringDictionary::TStringId FORTE_FbTriggerRS::scmDataInputNames[] = {g_nStringIdSet, g_nStringIdRst};
const CStringDictionary::TStringId FORTE_FbTriggerRS::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbTriggerRS::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbTriggerRS::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbTriggerRS::scmEIWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbTriggerRS::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTriggerRS::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbTriggerRS::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbTriggerRS::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbTriggerRS::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbTriggerRS::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbTriggerRS::FORTE_FbTriggerRS(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_Set(false_BOOL),
    var_Rst(false_BOOL),
    var_Out(false_BOOL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_Set(nullptr),
    conn_Rst(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbTriggerRS::setInitialValues() {
  var_Set = false_BOOL;
  var_Rst = false_BOOL;
  var_Out = false_BOOL;
}

void FORTE_FbTriggerRS::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbTriggerRS::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbTriggerRS::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_Set, conn_Set);
      readData(1, var_Rst, conn_Rst);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbTriggerRS::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbTriggerRS::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Set;
    case 1: return &var_Rst;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTriggerRS::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbTriggerRS::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbTriggerRS::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Set;
    case 1: return &conn_Rst;
  }
  return nullptr;
}

CDataConnection *FORTE_FbTriggerRS::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbTriggerRS::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbTriggerRS::alg_REQ(void) {

  #line 3 "FbTriggerRS.fbt"
  var_Out = func_AND<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_Out, var_Set), func_NOT<CIEC_BOOL>(var_Rst));
}
