/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbEdgePos
 *** Description: Детектор нарастающего фронта.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbEdgePos_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbEdgePos_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbEdgePos, g_nStringIdFbEdgePos)

const CStringDictionary::TStringId FORTE_FbEdgePos::scmDataInputNames[] = {g_nStringIdIn};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmDataInputTypeIds[] = {g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_FbEdgePos::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbEdgePos::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbEdgePos::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbEdgePos::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbEdgePos::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbEdgePos::scmInternalsNames[] = {g_nStringIdIn_previos};
const CStringDictionary::TStringId FORTE_FbEdgePos::scmInternalsTypeIds[] = {g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbEdgePos::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbEdgePos::FORTE_FbEdgePos(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_In_previos(false_BOOL),
    var_In(false_BOOL),
    var_Out(false_BOOL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbEdgePos::setInitialValues() {
  var_In_previos = false_BOOL;
  var_In = false_BOOL;
  var_Out = false_BOOL;
}

void FORTE_FbEdgePos::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbEdgePos::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbEdgePos::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbEdgePos::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbEdgePos::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbEdgePos::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbEdgePos::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbEdgePos::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
  }
  return nullptr;
}

CDataConnection *FORTE_FbEdgePos::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbEdgePos::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In_previos;
  }
  return nullptr;
}

void FORTE_FbEdgePos::alg_REQ(void) {

  #line 3 "FbEdgePos.fbt"
  var_Out = func_AND<CIEC_BOOL>(var_In, func_NOT<CIEC_BOOL>(var_In_previos));
  #line 5 "FbEdgePos.fbt"
  var_In_previos = var_In;
}
