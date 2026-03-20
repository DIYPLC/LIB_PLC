/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbCounter
 *** Description: Счетчик импульсов.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbCounter_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbCounter_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbCounter, g_nStringIdFbCounter)

const CStringDictionary::TStringId FORTE_FbCounter::scmDataInputNames[] = {g_nStringIdINC, g_nStringIdDEC, g_nStringIdRESET, g_nStringIdSETVALUE, g_nStringIdVALUE};
const CStringDictionary::TStringId FORTE_FbCounter::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdDINT};
const CStringDictionary::TStringId FORTE_FbCounter::scmDataOutputNames[] = {g_nStringIdCNT, g_nStringIdOVERFLOW};
const CStringDictionary::TStringId FORTE_FbCounter::scmDataOutputTypeIds[] = {g_nStringIdDINT, g_nStringIdBOOL};
const TDataIOID FORTE_FbCounter::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbCounter::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbCounter::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbCounter::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbCounter::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbCounter::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbCounter::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbCounter::scmInternalsNames[] = {g_nStringIdINCPrevios, g_nStringIdDECPrevios};
const CStringDictionary::TStringId FORTE_FbCounter::scmInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbCounter::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

const CIEC_DINT FORTE_FbCounter::var_const_LIMIT_MAX = 2147483647_DINT;
const CIEC_DINT FORTE_FbCounter::var_const_LIMIT_MIN = -2147483648_DINT;


FORTE_FbCounter::FORTE_FbCounter(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_INCPrevios(false_BOOL),
    var_DECPrevios(false_BOOL),
    var_INC(false_BOOL),
    var_DEC(false_BOOL),
    var_RESET(false_BOOL),
    var_SETVALUE(false_BOOL),
    var_VALUE(0_DINT),
    var_CNT(0_DINT),
    var_OVERFLOW(false_BOOL),
    var_conn_CNT(var_CNT),
    var_conn_OVERFLOW(var_OVERFLOW),
    conn_CNF(this, 0),
    conn_INC(nullptr),
    conn_DEC(nullptr),
    conn_RESET(nullptr),
    conn_SETVALUE(nullptr),
    conn_VALUE(nullptr),
    conn_CNT(this, 0, &var_conn_CNT),
    conn_OVERFLOW(this, 1, &var_conn_OVERFLOW) {
}

void FORTE_FbCounter::setInitialValues() {
  var_INCPrevios = false_BOOL;
  var_DECPrevios = false_BOOL;
  var_INC = false_BOOL;
  var_DEC = false_BOOL;
  var_RESET = false_BOOL;
  var_SETVALUE = false_BOOL;
  var_VALUE = 0_DINT;
  var_CNT = 0_DINT;
  var_OVERFLOW = false_BOOL;
}

void FORTE_FbCounter::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbCounter::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbCounter::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_INC, conn_INC);
      readData(1, var_DEC, conn_DEC);
      readData(2, var_RESET, conn_RESET);
      readData(3, var_SETVALUE, conn_SETVALUE);
      readData(4, var_VALUE, conn_VALUE);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbCounter::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_CNT, conn_CNT);
      writeData(1, var_OVERFLOW, conn_OVERFLOW);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbCounter::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_INC;
    case 1: return &var_DEC;
    case 2: return &var_RESET;
    case 3: return &var_SETVALUE;
    case 4: return &var_VALUE;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbCounter::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CNT;
    case 1: return &var_OVERFLOW;
  }
  return nullptr;
}

CEventConnection *FORTE_FbCounter::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbCounter::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INC;
    case 1: return &conn_DEC;
    case 2: return &conn_RESET;
    case 3: return &conn_SETVALUE;
    case 4: return &conn_VALUE;
  }
  return nullptr;
}

CDataConnection *FORTE_FbCounter::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNT;
    case 1: return &conn_OVERFLOW;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbCounter::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_INCPrevios;
    case 1: return &var_DECPrevios;
  }
  return nullptr;
}

void FORTE_FbCounter::alg_REQ(void) {

  #line 3 "FbCounter.fbt"
  if (func_AND<CIEC_BOOL>(var_INC, func_NOT<CIEC_BOOL>(var_INCPrevios))) {
    #line 4 "FbCounter.fbt"
    if (func_GE(var_CNT, var_const_LIMIT_MAX)) {
      #line 5 "FbCounter.fbt"
      var_CNT = var_const_LIMIT_MAX;
      #line 6 "FbCounter.fbt"
      var_OVERFLOW = true_BOOL;
    }
    else {
      #line 8 "FbCounter.fbt"
      var_CNT = func_ADD<CIEC_DINT>(var_CNT, 1_DINT);
      #line 9 "FbCounter.fbt"
      var_OVERFLOW = false_BOOL;
    }
  }
  #line 14 "FbCounter.fbt"
  if (func_AND<CIEC_BOOL>(var_DEC, func_NOT<CIEC_BOOL>(var_DECPrevios))) {
    #line 15 "FbCounter.fbt"
    if (func_LE(var_CNT, var_const_LIMIT_MIN)) {
      #line 16 "FbCounter.fbt"
      var_CNT = var_const_LIMIT_MIN;
      #line 17 "FbCounter.fbt"
      var_OVERFLOW = true_BOOL;
    }
    else {
      #line 19 "FbCounter.fbt"
      var_CNT = func_SUB<CIEC_DINT>(var_CNT, 1_DINT);
      #line 20 "FbCounter.fbt"
      var_OVERFLOW = false_BOOL;
    }
  }
  #line 25 "FbCounter.fbt"
  if (var_SETVALUE) {
    #line 26 "FbCounter.fbt"
    var_CNT = var_VALUE;
  }
  #line 30 "FbCounter.fbt"
  if (var_RESET) {
    #line 31 "FbCounter.fbt"
    var_CNT = 0_DINT;
  }
  #line 35 "FbCounter.fbt"
  var_INCPrevios = var_INC;
  #line 36 "FbCounter.fbt"
  var_DECPrevios = var_DEC;
}
