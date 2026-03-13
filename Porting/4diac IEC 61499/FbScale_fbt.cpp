/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbScale
 *** Description: Масштабирование InMin...InMax -> OutMin...OutMax.
 *** Version:
 ***     2.1: 2026-03-13/VA - LIB_PLC -
 *************************************************************************/

#include "FbScale_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbScale_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbScale, g_nStringIdFbScale)

const CStringDictionary::TStringId FORTE_FbScale::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdInMax, g_nStringIdInMin, g_nStringIdOutMax, g_nStringIdOutMin};
const CStringDictionary::TStringId FORTE_FbScale::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbScale::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbScale::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbScale::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbScale::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbScale::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbScale::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbScale::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbScale::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbScale::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbScale::FORTE_FbScale(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_In(0.0_REAL),
    var_InMax(27648.0_REAL),
    var_InMin(0.0_REAL),
    var_OutMax(20.0_REAL),
    var_OutMin(4.0_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_InMax(nullptr),
    conn_InMin(nullptr),
    conn_OutMax(nullptr),
    conn_OutMin(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbScale::setInitialValues() {
  var_In = 0.0_REAL;
  var_InMax = 27648.0_REAL;
  var_InMin = 0.0_REAL;
  var_OutMax = 20.0_REAL;
  var_OutMin = 4.0_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbScale::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbScale::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbScale::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_InMax, conn_InMax);
      readData(2, var_InMin, conn_InMin);
      readData(3, var_OutMax, conn_OutMax);
      readData(4, var_OutMin, conn_OutMin);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbScale::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbScale::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_InMax;
    case 2: return &var_InMin;
    case 3: return &var_OutMax;
    case 4: return &var_OutMin;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbScale::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbScale::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbScale::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_InMax;
    case 2: return &conn_InMin;
    case 3: return &conn_OutMax;
    case 4: return &conn_OutMin;
  }
  return nullptr;
}

CDataConnection *FORTE_FbScale::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbScale::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbScale::alg_REQ(void) {

  #line 3 "FbScale.fbt"
  if (func_EQ(var_InMax, var_InMin)) {
    #line 5 "FbScale.fbt"
    var_Out = 0.0_REAL;
  }
  else {
    #line 8 "FbScale.fbt"
    var_Out = func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(func_SUB<CIEC_REAL>(var_OutMax, var_OutMin), func_DIV<CIEC_REAL>(func_SUB<CIEC_REAL>(var_In, var_InMin), func_SUB<CIEC_REAL>(var_InMax, var_InMin))), var_OutMin);
  }
}
