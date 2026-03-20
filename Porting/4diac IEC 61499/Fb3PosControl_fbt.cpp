/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb3PosControl
 *** Description: Регулятор трехпозиционный.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "Fb3PosControl_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Fb3PosControl_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_Fb3PosControl, g_nStringIdFb3PosControl)

const CStringDictionary::TStringId FORTE_Fb3PosControl::scmDataInputNames[] = {g_nStringIdPV, g_nStringIdSP, g_nStringIdDBand, g_nStringIdHystPos, g_nStringIdHystNeg};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmDataOutputNames[] = {g_nStringIdOpPos, g_nStringIdOpNeg};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_Fb3PosControl::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_Fb3PosControl::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_Fb3PosControl::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_Fb3PosControl::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_Fb3PosControl::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_Fb3PosControl::scmInternalsNames[] = {g_nStringIdER};
const CStringDictionary::TStringId FORTE_Fb3PosControl::scmInternalsTypeIds[] = {g_nStringIdREAL};
const SInternalVarsInformation FORTE_Fb3PosControl::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_Fb3PosControl::FORTE_Fb3PosControl(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_ER(0.0_REAL),
    var_PV(0.0_REAL),
    var_SP(0.0_REAL),
    var_DBand(2.0_REAL),
    var_HystPos(1.0_REAL),
    var_HystNeg(1.0_REAL),
    var_OpPos(false_BOOL),
    var_OpNeg(false_BOOL),
    var_conn_OpPos(var_OpPos),
    var_conn_OpNeg(var_OpNeg),
    conn_CNF(this, 0),
    conn_PV(nullptr),
    conn_SP(nullptr),
    conn_DBand(nullptr),
    conn_HystPos(nullptr),
    conn_HystNeg(nullptr),
    conn_OpPos(this, 0, &var_conn_OpPos),
    conn_OpNeg(this, 1, &var_conn_OpNeg) {
}

void FORTE_Fb3PosControl::setInitialValues() {
  var_ER = 0.0_REAL;
  var_PV = 0.0_REAL;
  var_SP = 0.0_REAL;
  var_DBand = 2.0_REAL;
  var_HystPos = 1.0_REAL;
  var_HystNeg = 1.0_REAL;
  var_OpPos = false_BOOL;
  var_OpNeg = false_BOOL;
}

void FORTE_Fb3PosControl::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_Fb3PosControl::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_Fb3PosControl::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_PV, conn_PV);
      readData(1, var_SP, conn_SP);
      readData(2, var_DBand, conn_DBand);
      readData(3, var_HystPos, conn_HystPos);
      readData(4, var_HystNeg, conn_HystNeg);
      break;
    }
    default:
      break;
  }
}

void FORTE_Fb3PosControl::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_OpPos, conn_OpPos);
      writeData(1, var_OpNeg, conn_OpNeg);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_Fb3PosControl::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_PV;
    case 1: return &var_SP;
    case 2: return &var_DBand;
    case 3: return &var_HystPos;
    case 4: return &var_HystNeg;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb3PosControl::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_OpPos;
    case 1: return &var_OpNeg;
  }
  return nullptr;
}

CEventConnection *FORTE_Fb3PosControl::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_Fb3PosControl::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_PV;
    case 1: return &conn_SP;
    case 2: return &conn_DBand;
    case 3: return &conn_HystPos;
    case 4: return &conn_HystNeg;
  }
  return nullptr;
}

CDataConnection *FORTE_Fb3PosControl::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_OpPos;
    case 1: return &conn_OpNeg;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb3PosControl::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_ER;
  }
  return nullptr;
}

void FORTE_Fb3PosControl::alg_REQ(void) {

  #line 3 "Fb3PosControl.fbt"
  var_ER = func_SUB<CIEC_REAL>(var_SP, var_PV);
  #line 6 "Fb3PosControl.fbt"
  if (func_GE(var_ER, func_ADD<CIEC_REAL>(var_DBand, var_HystPos))) {
    #line 7 "Fb3PosControl.fbt"
    var_OpPos = true_BOOL;
  }
  #line 11 "Fb3PosControl.fbt"
  if (func_LE(var_ER, func_SUB<CIEC_REAL>(var_DBand, var_HystPos))) {
    #line 12 "Fb3PosControl.fbt"
    var_OpPos = false_BOOL;
  }
  #line 16 "Fb3PosControl.fbt"
  if (func_LE(var_ER, func_SUB<CIEC_REAL>(func_SUB<CIEC_REAL>(0.0_REAL, var_DBand), var_HystNeg))) {
    #line 17 "Fb3PosControl.fbt"
    var_OpNeg = true_BOOL;
  }
  #line 21 "Fb3PosControl.fbt"
  if (func_GE(var_ER, func_ADD<CIEC_REAL>(func_SUB<CIEC_REAL>(0.0_REAL, var_DBand), var_HystNeg))) {
    #line 22 "Fb3PosControl.fbt"
    var_OpNeg = false_BOOL;
  }
}
