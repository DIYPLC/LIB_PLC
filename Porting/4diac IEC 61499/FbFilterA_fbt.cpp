/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbFilterA
 *** Description: Фильтр апериодический.
 *** Version:
 ***     2.1: 2026-03-19/VA - LIB_PLC -
 *************************************************************************/

#include "FbFilterA_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbFilterA_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbFilterA, g_nStringIdFbFilterA)

const CStringDictionary::TStringId FORTE_FbFilterA::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdTf, g_nStringIdTs};
const CStringDictionary::TStringId FORTE_FbFilterA::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbFilterA::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbFilterA::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbFilterA::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterA::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterA::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbFilterA::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterA::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterA::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbFilterA::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbFilterA::scmInternalsNames[] = {g_nStringIdTmp};
const CStringDictionary::TStringId FORTE_FbFilterA::scmInternalsTypeIds[] = {g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbFilterA::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbFilterA::FORTE_FbFilterA(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Tmp(0.0_REAL),
    var_In(0.0_REAL),
    var_Tf(1.0_REAL),
    var_Ts(0.1_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Tf(nullptr),
    conn_Ts(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbFilterA::setInitialValues() {
  var_Tmp = 0.0_REAL;
  var_In = 0.0_REAL;
  var_Tf = 1.0_REAL;
  var_Ts = 0.1_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbFilterA::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbFilterA::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbFilterA::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_Tf, conn_Tf);
      readData(2, var_Ts, conn_Ts);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbFilterA::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbFilterA::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_Tf;
    case 2: return &var_Ts;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterA::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbFilterA::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbFilterA::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_Tf;
    case 2: return &conn_Ts;
  }
  return nullptr;
}

CDataConnection *FORTE_FbFilterA::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterA::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Tmp;
  }
  return nullptr;
}

void FORTE_FbFilterA::alg_REQ(void) {

  #line 3 "FbFilterA.fbt"
  if (func_LE(var_Tf, 0.0_REAL)) {
    #line 4 "FbFilterA.fbt"
    var_Out = var_In;
  }
  else {
    #line 6 "FbFilterA.fbt"
    var_Tmp = func_DIV<CIEC_REAL>(func_SUB<CIEC_REAL>(var_In, var_Out), var_Tf);
    #line 7 "FbFilterA.fbt"
    var_Out = func_ADD<CIEC_REAL>(var_Out, func_MUL<CIEC_REAL>(var_Tmp, var_Ts));
  }
}
