/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb2PosControl
 *** Description: Регулятор двухпозиционный.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "Fb2PosControl_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Fb2PosControl_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_Fb2PosControl, g_nStringIdFb2PosControl)

const CStringDictionary::TStringId FORTE_Fb2PosControl::scmDataInputNames[] = {g_nStringIdPV, g_nStringIdSP, g_nStringIdHYST};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmDataOutputNames[] = {g_nStringIdOP};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_Fb2PosControl::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_Fb2PosControl::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_Fb2PosControl::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_Fb2PosControl::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_Fb2PosControl::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_Fb2PosControl::scmInternalsNames[] = {g_nStringIdER};
const CStringDictionary::TStringId FORTE_Fb2PosControl::scmInternalsTypeIds[] = {g_nStringIdREAL};
const SInternalVarsInformation FORTE_Fb2PosControl::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_Fb2PosControl::FORTE_Fb2PosControl(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_ER(0.0_REAL),
    var_PV(0.0_REAL),
    var_SP(0.0_REAL),
    var_HYST(0.0_REAL),
    var_OP(false_BOOL),
    var_conn_OP(var_OP),
    conn_CNF(this, 0),
    conn_PV(nullptr),
    conn_SP(nullptr),
    conn_HYST(nullptr),
    conn_OP(this, 0, &var_conn_OP) {
}

void FORTE_Fb2PosControl::setInitialValues() {
  var_ER = 0.0_REAL;
  var_PV = 0.0_REAL;
  var_SP = 0.0_REAL;
  var_HYST = 0.0_REAL;
  var_OP = false_BOOL;
}

void FORTE_Fb2PosControl::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_Fb2PosControl::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_Fb2PosControl::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_PV, conn_PV);
      readData(1, var_SP, conn_SP);
      readData(2, var_HYST, conn_HYST);
      break;
    }
    default:
      break;
  }
}

void FORTE_Fb2PosControl::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_OP, conn_OP);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_Fb2PosControl::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_PV;
    case 1: return &var_SP;
    case 2: return &var_HYST;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb2PosControl::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_OP;
  }
  return nullptr;
}

CEventConnection *FORTE_Fb2PosControl::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_Fb2PosControl::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_PV;
    case 1: return &conn_SP;
    case 2: return &conn_HYST;
  }
  return nullptr;
}

CDataConnection *FORTE_Fb2PosControl::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_OP;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb2PosControl::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_ER;
  }
  return nullptr;
}

void FORTE_Fb2PosControl::alg_REQ(void) {

  #line 3 "Fb2PosControl.fbt"
  var_ER = func_SUB<CIEC_REAL>(var_SP, var_PV);
  #line 6 "Fb2PosControl.fbt"
  if (func_GE(var_ER, var_HYST)) {
    #line 7 "Fb2PosControl.fbt"
    var_OP = true_BOOL;
  }
  #line 10 "Fb2PosControl.fbt"
  if (func_LE(var_ER, func_MUL<CIEC_REAL>(var_HYST, -1.0_REAL))) {
    #line 11 "Fb2PosControl.fbt"
    var_OP = false_BOOL;
  }
}
