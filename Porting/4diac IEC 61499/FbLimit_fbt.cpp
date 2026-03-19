/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbLimit
 *** Description: Амплитудный ограничитель.
 *** Version:
 ***     2.1: 2026-03-19/VA - LIB_PLC -
 *************************************************************************/

#include "FbLimit_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbLimit_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbLimit, g_nStringIdFbLimit)

const CStringDictionary::TStringId FORTE_FbLimit::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdOutMax, g_nStringIdOutMin};
const CStringDictionary::TStringId FORTE_FbLimit::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbLimit::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbLimit::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbLimit::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbLimit::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbLimit::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbLimit::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbLimit::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbLimit::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbLimit::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbLimit::FORTE_FbLimit(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_In(0.0_REAL),
    var_OutMax(100.0_REAL),
    var_OutMin(0.0_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_OutMax(nullptr),
    conn_OutMin(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbLimit::setInitialValues() {
  var_In = 0.0_REAL;
  var_OutMax = 100.0_REAL;
  var_OutMin = 0.0_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbLimit::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbLimit::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbLimit::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_OutMax, conn_OutMax);
      readData(2, var_OutMin, conn_OutMin);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbLimit::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbLimit::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_OutMax;
    case 2: return &var_OutMin;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbLimit::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbLimit::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbLimit::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_OutMax;
    case 2: return &conn_OutMin;
  }
  return nullptr;
}

CDataConnection *FORTE_FbLimit::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbLimit::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbLimit::alg_REQ(void) {

  #line 3 "FbLimit.fbt"
  if (func_GE(var_In, var_OutMax)) {
    #line 4 "FbLimit.fbt"
    var_Out = var_OutMax;
  }
  else {
    #line 6 "FbLimit.fbt"
    if (func_LE(var_In, var_OutMin)) {
      #line 7 "FbLimit.fbt"
      var_Out = var_OutMin;
    }
    else {
      #line 9 "FbLimit.fbt"
      var_Out = var_In;
    }
  }
}
