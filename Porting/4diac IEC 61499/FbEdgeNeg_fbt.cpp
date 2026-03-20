/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbEdgeNeg
 *** Description: Детектор ниспадающего фронта (среза).
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbEdgeNeg_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbEdgeNeg_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbEdgeNeg, g_nStringIdFbEdgeNeg)

const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmDataInputNames[] = {g_nStringIdIn};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmDataInputTypeIds[] = {g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbEdgeNeg::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbEdgeNeg::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbEdgeNeg::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbEdgeNeg::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbEdgeNeg::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmInternalsNames[] = {g_nStringIdIn_previos};
const CStringDictionary::TStringId FORTE_FbEdgeNeg::scmInternalsTypeIds[] = {g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbEdgeNeg::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbEdgeNeg::FORTE_FbEdgeNeg(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_In_previos(false_BOOL),
    var_In(false_BOOL),
    var_Out(false_BOOL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbEdgeNeg::setInitialValues() {
  var_In_previos = false_BOOL;
  var_In = false_BOOL;
  var_Out = false_BOOL;
}

void FORTE_FbEdgeNeg::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbEdgeNeg::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbEdgeNeg::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbEdgeNeg::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbEdgeNeg::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbEdgeNeg::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbEdgeNeg::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbEdgeNeg::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
  }
  return nullptr;
}

CDataConnection *FORTE_FbEdgeNeg::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbEdgeNeg::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In_previos;
  }
  return nullptr;
}

void FORTE_FbEdgeNeg::alg_REQ(void) {

  #line 3 "FbEdgeNeg.fbt"
  var_Out = func_AND<CIEC_BOOL>(var_In_previos, func_NOT<CIEC_BOOL>(var_In));
  #line 5 "FbEdgeNeg.fbt"
  var_In_previos = var_In;
}
