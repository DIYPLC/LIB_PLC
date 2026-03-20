/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbDeadBand
 *** Description: Зона нечувствительности.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbDeadBand_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbDeadBand_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbDeadBand, g_nStringIdFbDeadBand)

const CStringDictionary::TStringId FORTE_FbDeadBand::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdERMAX, g_nStringIdERMIN};
const CStringDictionary::TStringId FORTE_FbDeadBand::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbDeadBand::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbDeadBand::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbDeadBand::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbDeadBand::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDeadBand::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbDeadBand::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbDeadBand::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDeadBand::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbDeadBand::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbDeadBand::FORTE_FbDeadBand(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_In(0.0_REAL),
    var_ERMAX(0.001_REAL),
    var_ERMIN(-0.001_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_ERMAX(nullptr),
    conn_ERMIN(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbDeadBand::setInitialValues() {
  var_In = 0.0_REAL;
  var_ERMAX = 0.001_REAL;
  var_ERMIN = -0.001_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbDeadBand::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbDeadBand::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbDeadBand::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_ERMAX, conn_ERMAX);
      readData(2, var_ERMIN, conn_ERMIN);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbDeadBand::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbDeadBand::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_ERMAX;
    case 2: return &var_ERMIN;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDeadBand::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbDeadBand::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbDeadBand::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_ERMAX;
    case 2: return &conn_ERMIN;
  }
  return nullptr;
}

CDataConnection *FORTE_FbDeadBand::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDeadBand::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbDeadBand::alg_REQ(void) {

  #line 3 "FbDeadBand.fbt"
  if (func_AND<CIEC_BOOL>(func_LT(var_ERMIN, var_In), func_LT(var_In, var_ERMAX))) {
    #line 4 "FbDeadBand.fbt"
    var_Out = 0.0_REAL;
  }
  else {
    #line 6 "FbDeadBand.fbt"
    var_Out = var_In;
  }
}
