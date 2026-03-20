/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbDeriveF
 *** Description: Производная с фильтром.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbDeriveF_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbDeriveF_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbDeriveF, g_nStringIdFbDeriveF)

const CStringDictionary::TStringId FORTE_FbDeriveF::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdKdf, g_nStringIdTs};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbDeriveF::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbDeriveF::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbDeriveF::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbDeriveF::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbDeriveF::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbDeriveF::scmInternalsNames[] = {g_nStringIdDintegral};
const CStringDictionary::TStringId FORTE_FbDeriveF::scmInternalsTypeIds[] = {g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbDeriveF::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbDeriveF::FORTE_FbDeriveF(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Dintegral(0.0_REAL),
    var_In(0.0_REAL),
    var_Kdf(1.0_REAL),
    var_Ts(0.1_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Kdf(nullptr),
    conn_Ts(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbDeriveF::setInitialValues() {
  var_Dintegral = 0.0_REAL;
  var_In = 0.0_REAL;
  var_Kdf = 1.0_REAL;
  var_Ts = 0.1_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbDeriveF::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbDeriveF::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbDeriveF::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_Kdf, conn_Kdf);
      readData(2, var_Ts, conn_Ts);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbDeriveF::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbDeriveF::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_Kdf;
    case 2: return &var_Ts;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDeriveF::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbDeriveF::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbDeriveF::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_Kdf;
    case 2: return &conn_Ts;
  }
  return nullptr;
}

CDataConnection *FORTE_FbDeriveF::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDeriveF::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Dintegral;
  }
  return nullptr;
}

void FORTE_FbDeriveF::alg_REQ(void) {

  #line 3 "FbDeriveF.fbt"
  if (func_LE(var_Kdf, 0.0_REAL)) {
    #line 4 "FbDeriveF.fbt"
    var_Dintegral = 0.0_REAL;
    #line 5 "FbDeriveF.fbt"
    var_Out = 0.0_REAL;
  }
  else {
    #line 7 "FbDeriveF.fbt"
    var_Out = func_MUL<CIEC_REAL>(func_SUB<CIEC_REAL>(var_In, var_Dintegral), var_Kdf);
    #line 8 "FbDeriveF.fbt"
    var_Dintegral = func_ADD<CIEC_REAL>(var_Dintegral, func_MUL<CIEC_REAL>(var_Ts, var_Out));
  }
}
